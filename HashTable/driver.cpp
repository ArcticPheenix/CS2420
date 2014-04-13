#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"

HashTable<double>& initHashTable();
std::ifstream* readFile(std::string file);
void parseElements(std::ifstream& input, HashTable<double>& table);
void parseFormulas(std::ifstream& input, HashTable<double>& table);
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
	HashTable<double>& myTable = HashTable<double>();
	std::cout << "Reading in file: PeriodicTableElements.txt" << std::endl;
	std::ifstream* pteFileStream = readFile("PeriodicTableElements.txt");
	if (pteFileStream != nullptr)
	{
		std::cout << "Read successful. Parsing file..." << std::endl;
		parseElements(*pteFileStream, myTable);
		std::cout << "Hash table created and populated." << std::endl;
		return myTable;
	}
	else
	{
		std::cout << "Error with input file stream." << std::endl;
		return myTable;
	}
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
void parseElements(std::ifstream& input, HashTable<double>& table)
{
	//TODO
}

/*
	Parses input stream for chemical formula data
	Computes approximate atomic weight of molecule
	Prints result to console
*/
void parseFormulas(std::ifstream& input, HashTable<double>& table)
{
	//TODO
}

double computeAtomicSum(std::string formula)
{
	//TODO
	return -1.0;
}