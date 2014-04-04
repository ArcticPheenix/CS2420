/*
Class: CS2420
Instructor: Todd Peterson
Student: Christopher Kelly
Project: AVL Tree

I hereby swear that all code contained within this project was wrtten soley by me.
*/

#include <iostream>
#include <cstdlib>
#include "AVLTree.h"

void printMenu();
void testInsert(AvlTree<int> &tree, int value);
void testPrint(AvlTree<int> &tree);

int main()
{
	const int RANDOM_SIZE = 5;
	AvlTree<int>* testTree = new AvlTree<int>();
	char option = NULL;
	while (option != 'Q')
	{
		printMenu();
		std::cin >> option;
		switch (option)
		{
		case 'I':
			int value;
			std::cout << "Enter number to add to tree: ";
			std::cin >> value;
			testInsert(*testTree, value);
			break;
		case 'P':
			std::cout << "Printing the tree... " << std::endl;
			testPrint(*testTree);
			break;
		case 'Q':
			break;
		default:
			std::cout << "Invalid selection!" << std::endl;
			break;
		}
	}
	return 0;
}

void printMenu()
{
	std::cout << "\nTest Menu" << std::endl;
	std::cout << "(I) Insert value into tree" << std::endl;
	std::cout << "(P) Print tree" << std::endl;
	std::cout << "(Q) Quit program" << std::endl;
}

void testInsert(AvlTree<int> &tree, int value)
{
	std::cout << "Inserting " << value << " into tree..." << std::endl;
	tree.insert(value);
}

void testPrint(AvlTree<int> &tree)
{
	tree.print();
}