#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "HashTable.h"

HashTable<double>& initHashTable();
std::ifstream* readFile(std::string file);
bool isNumber(char value);
bool isUpper(char value);
bool isLower(char value);
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
	system("PAUSE");
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
		double result = computeAtomicSum(formula, table);
		std::cout << "Atomic weight of " << formula << " is: " << result << std::endl;
	}
}

double computeAtomicSum(std::string formula, HashTable<double>& table)
{
	double currentSum = 0;
	int multiplier = 1;
	std::stringstream ss;
	for (unsigned i = 0; i < formula.size(); i++)
	{
		if (isUpper(formula[i]))
		{
			if (isUpper(formula[i + 1])) { continue; }
			else if (isLower(formula[i + 1]))
			{
				ss.clear();
				ss << formula[i] << formula[i + 1];
				currentSum += table[ss.str()];	// Retrieve value of key, and add to currentSum
			}
			else if (isNumber(formula[i + 1])) { continue; }
			else
			{
				ss.clear();
				ss << formula[i];
				currentSum += table[ss.str()];	// Retrieve value of key, and add to currentSum
			}
		}
		else if (isLower(formula[i])) { continue; }
		else if (isNumber(formula[i]))
		{
			if (isNumber(formula[i + 1]))
			{
				ss.clear();
				ss << formula[i] << formula[i + 1];
				multiplier = atoi(ss.str().c_str());
				currentSum *= multiplier;
			}
			else
			{
				ss.clear();
				ss << formula[i];
				multiplier = atoi(ss.str().c_str());
				currentSum *= multiplier;
			}
		}
	}
	return currentSum;
}

bool isNumber(char value)
{
	if (((int)value > 47) && ((int)value < 58)) { return true; }
	else { return false; }
}

bool isUpper(char value)
{
	if (((int)value > 64) && ((int)value < 91)) { return true; }
	else { return false; }
}

bool isLower(char value)
{
	if (((int)value > 96) && ((int)value < 123)) { return true; }
	else { return false; }
}