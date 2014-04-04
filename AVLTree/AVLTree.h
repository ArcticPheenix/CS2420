/*
Class: CS2420
Instructor: Todd Peterson
Student: Christopher Kelly
Project: AVL Tree

I hereby swear that all code contained within this project was wrtten soley by me.
*/
#include <iomanip>

#ifndef AVLTREE_NODE_H
#define AVLTREE_NODE_H

template <typename T>
class Node
{
public:
	T data;
	Node *lChild, *rChild;
	int height;
	Node(T value);
};

template <typename T>
Node<T>::Node(T value)
{
	data = value;
	lChild = nullptr;
	rChild = nullptr;
	height = 1;
}
#endif

#ifndef AVLTREE_CLASS_H
#define AVLTREE_CLASS_H

template <typename T>
class AvlTree
{
public:
	AvlTree();
	~AvlTree();
	void insert(T value);
	void print();
private:
	Node<T>* root;
	void printHelper(Node<T>* n, int indent);
	void adjustHeight(Node<T>* n);
	void insertHelper(Node<T>* n, T value, Node<T>*& returnChild );
	void destroy(Node<T>* n);
	Node<T>* rebalance(Node<T>* n);
	Node<T>* rotateLeftRight(Node<T>* n);
	Node<T>* rotateRightLeft(Node<T>* n);
	Node<T>* rotateLeft(Node<T>* n);
	Node<T>* rotateRight(Node<T>* n);
};

template <typename T>
AvlTree<T>::AvlTree()
{
	root = nullptr;
}

template <typename T>
AvlTree<T>::~AvlTree()
{
	//TODO
	//Walk tree and remove nodes
	Node<T>* tempNode = root;
	destroy(tempNode);
}

// Insert node with value into tree
// Adjust height of nodes in tree
// Rebalace tree, if necessary
template <typename T>
void AvlTree<T>::insert(T value)
{
	if (root == nullptr)
	{
		Node<T>* newNode = new Node<T>(value);
		root = newNode;
	}
	else
	{
		Node<T>* helperNode = nullptr;
		insertHelper(root, value, helperNode);
	}
}

// Recursively walks the tree until it finds a valid place for given data
template <typename T>
void AvlTree<T>::insertHelper(Node<T>* n, T value, Node<T>*& returnChild)
{
	if (value < n->data)
	{
		if (n->lChild != nullptr)
		{
			insertHelper(n->lChild, value, returnChild);
		}
		else
		{
			Node<T>* newNode = new Node<T>(value);
			n->lChild = newNode;
		}
		if ((n->lChild != returnChild) && (returnChild != nullptr))
		{
			n->lChild = returnChild;
			adjustHeight(n);
			n = rebalance(n);
			returnChild = n;
		}
		else
		{
			adjustHeight(n);
			n = rebalance(n);
			returnChild = n;
		}
	}
	else 
	{
		if (n->rChild != nullptr)
		{
			insertHelper(n->rChild, value, returnChild);
		}
		else
		{
			Node<T>* newNode = new Node<T>(value);
			n->rChild = newNode;
		}
		if ((n->rChild != returnChild) && (returnChild != nullptr))
		{
			n->rChild = returnChild;
			adjustHeight(n);
			n = rebalance(n);
			returnChild = n;
		}
		else
		{
			adjustHeight(n);
			n = rebalance(n);
			returnChild = n;
		}
	}
}

// Calculate height of current node based upon height of child nodes (if any)
template <typename T>
void AvlTree<T>::adjustHeight(Node<T>* n)
{
	if ((n->lChild == nullptr) && (n->rChild == nullptr))
	{
		return;
	}
	else if ((n->lChild != nullptr) && (n->rChild != nullptr))
    {
        if (n->lChild->height > n->rChild->height)
        {
            n->height = n->lChild->height + 1;
        }
        else if (n->lChild->height < n->rChild->height)
        {
            n->height = n->rChild->height + 1;
        }
        else
        {
            n->height = n->lChild->height + 1;
        }
    }
    else if ((n->lChild != nullptr) && (n->rChild == nullptr))
    {
        n->height = n->lChild->height + 1;
    }
    else
    {
        n->height = n->rChild->height + 1;
    }
}

// Rebalance the subtree if unbalanced
template <typename T>
Node<T>* AvlTree<T>::rebalance(Node<T>* n)
{
	Node<T>* tempNode = n;
    // Check height of child nodes
    // If absolute difference of height is > 1
    // Call appropriate rotation function(s)
	//adjustHeight(n);
    if (n->height == 1) { return n; }
    
	// Determine balance of subtree
    int balanceFactor = 0;
    if ((n->lChild != nullptr) && (n->rChild != nullptr))
    {
        balanceFactor = n->lChild->height - n->rChild->height;
    }
    else if ((n->lChild != nullptr) && (n->rChild == nullptr))
    {
        balanceFactor = n->lChild->height - 0;
    }
    else
    {
        balanceFactor = 0 - n->rChild->height;
    }

	if (balanceFactor > 1)
	{
		// Subtree is imbalanced on the left
		if ((n->lChild->rChild != nullptr) && ((n->lChild->lChild->height - n->lChild->rChild->height) < 0)) { tempNode = rotateRightLeft(n); } // Sub-subtree is imbalanced right
		else { tempNode = rotateRight(n); }
	}
	if (balanceFactor < -1)
	{
		// Subtree is imbalanced on the right
		if ((n->rChild->lChild != nullptr) && ((n->rChild->lChild->height - n->rChild->rChild->height) > 0)) { tempNode = rotateLeftRight(n); } // Sub-subtree is imbalanced right
		else { tempNode = rotateLeft(n); }
	}

	return tempNode;
}

// Perform a left rotation on given subtree
// Return Node<T>* so that the parent node can update child linkage
template <typename T>
Node<T>* AvlTree<T>::rotateLeft(Node<T>* n)
{
    Node<T>* tempNode = n->rChild;
	if (n == root) { root = tempNode; }
    n->rChild = tempNode->lChild;
    tempNode->lChild = n;
	tempNode->height = 1;
	n->height = 1;
	adjustHeight(n);
	adjustHeight(tempNode);
    return tempNode;
}

// Perform a right rotation on given subtree
// Return Node<T>* so that the parent node can update child linkage
template <typename T>
Node<T>* AvlTree<T>::rotateRight(Node<T>* n)
{
    Node<T>* tempNode = n->lChild;
	if (n == root) { root = tempNode; }
    n->lChild = tempNode->rChild;
    tempNode->rChild = n;
	tempNode->height = 1;
	n->height = 1;
	adjustHeight(n);
	adjustHeight(tempNode);
    return tempNode;
}

// Peform left-right rotation on given subtree
// Return Node<T>* so that the parent node can update child linkage
template <typename T>
Node<T>* AvlTree<T>::rotateLeftRight(Node<T>* n)
{
    n->rChild = rotateRight(n->rChild);
    return rotateLeft(n);
}

// Perform right-left rotation on given subtree
// Return Node<T>* so that the parent node can update child linkage
template <typename T>
Node<T>* AvlTree<T>::rotateRightLeft(Node<T>* n)
{
    n->lChild = rotateLeft(n->lChild);
    return rotateRight(n);
}

template <typename T>
void AvlTree<T>::print()
{
	printHelper(root, 0);
}

template <typename T>
void AvlTree<T>::printHelper(Node<T>* n, int indent=0)
{
	if (n != nullptr)
	{
		if (n->lChild) printHelper(n->lChild, indent + 4);
		if (n->rChild) printHelper(n->rChild, indent + 4);
		if (indent)
		{
			std::cout << std::setw(indent) << ' ';
		}
		std::cout << n->data << "\n ";
	}
}

template <typename T>
void AvlTree<T>::destroy(Node<T>* n)
{
	while (n != nullptr)
	{
		destroy(n->lChild);
		destroy(n->rChild);
		delete n;
	}
}
#endif