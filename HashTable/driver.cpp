#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "HashTable.h"

HashTable<double>& initHashTable();
std::ifstream* readFile(std::string file);
void parseElements(std::ifstream& input, HashTable<double>& table);
void parseFormulas(std::ifstream& input, HashTable<double>& table);
double computeAtomicSum(std::string formula, HashTable<double>& table);

int main()
{
	HashTable<double>& myTable = initHashTable();
	std::cout << "Reading in file: forumulas.txt" << std::endl;
	std::ifstream* formulasFileStream = readFile("formulas.txt");
	if (formulasFileStream != nullptr)
	{
		std::cout << "Read successful. Parsing file..." << std::endl;
		parseFormulas(*formulasFileStream, myTable);
		formulasFileStream->close();
		formulasFileStream = nullptr;
		delete formulasFileStream;
	}
	else
	{
		std::cout << "Error with input file stream." << std::endl;
		formulasFileStream->close();
		formulasFileStream = nullptr;
		delete formulasFileStream;
		return -1;
	}
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
		pteFileStream->close();
		pteFileStream = nullptr;
		delete pteFileStream;
		return myTable;
	}
	else
	{
		std::cout << "Error with input file stream." << std::endl;
		pteFileStream->close();
		pteFileStream = nullptr;
		delete pteFileStream;
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
	std::string elementRecord;
	std::string element;
	std::string weight;
	while (input.good())
	{
		input >> element;
		input >> weight;
		double w = atof(weight.c_str());
		table.insert(element, w);
	}
}

/*
	Parses input stream for chemical formula data
	Computes approximate atomic weight of molecule
	Prints result to console
*/
void parseFormulas(std::ifstream& input, HashTable<double>& table)
{
	std::string formula;
	while (input.good())
	{
		input >> formula;
		computeAtomicSum(formula, table);
	}
}

double computeAtomicSum(std::string formula, HashTable<double>& table)
{
	//TODO
	for (int i = 0; i < formula.size(); i++)
	{

	}
	return -2.0;
}