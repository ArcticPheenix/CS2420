#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"

HashTable<double>& initHashTable();
std::ifstream* readFile(std::string file);
void parseElements(std::ifstream& input);
void parseFormulas(std::ifstream& input);
double computeAtomicSum(std::string formula);

int main()
{
	HashTable<double>& myTable = initHashTable();
	return 0;
}

/*
	Initialize hash table
	Read in periodic table data from file
	Store data in hash table
	Return reference to valid hash table
*/
HashTable<double>& initHashTable()
{
	//TODO
}

/*
	File handler function
	Return pointer to valid file stream
*/
std::ifstream* readFile(std::string file)
{
	std::ifstream* inputFileStream = new std::ifstream(file);
	if (inputFileStream->good()) { return inputFileStream; }
	else { return nullptr; }
}

/*
	Parses input stream for periodic table data
	Inserts parsed data into hash table
*/
void parseElements(std::ifstream& input)
{
	//TODO
}

/*
	Parses input stream for chemical formula data
	Computes approximate atomic weight of molecule
	Prints result to console
*/
void parseFormulas(std::ifstream& input)
{
	//TODO
}

double computeAtomicSum(std::string formula)
{
	//TODO
}