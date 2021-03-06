// DSAAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "trie.h"
#include <stdlib.h> // Just to flush the screen
using namespace std;

// Data Init
const void initDictionary(Trie*& trie, const string filename)
{
	// Read from file, and initialize to trie
	ifstream readFile;
	readFile.open(filename);
	string x;
	while (readFile >> x)
	{
		trie->insert(x);
	}
	readFile.close();
}

// File read and compare to dict
const void readYourFile(Trie* trie, const string filename)
{
	std::cout << "The following words from your file were not found." << endl;
	ifstream readYourFile;
	readYourFile.open(filename);
	string x;
	while (readYourFile >> x)
	{
		if (!trie->search(x))
		{
			std::cout << x << endl;
		}
	}
	readYourFile.close();
}

// Display all words that start with a certain letter
void gimmeWords(Trie* trie, const string letter)
{
	std::cout << "Words found that start with " + letter + "." << endl;
}

string displayMenuInitDict(Trie*& dict)
{
	bool menu2 = true;
	string input2 = "0";
	std::cout << "//--------------------------------------------------------//" << endl;
	std::cout << "These are the available text files" << endl;
	std::cout << "1. dictionary.txt" << endl;
	std::cout << "2. RandomWords100.txt" << endl;
	std::cout << "3. RandomWords1000.txt" << endl;
	std::cout << "4. RandomWords3000.txt" << endl;
	std::cout << "//--------------------------------------------------------//" << endl;
	std::cout << "Please select text file you would like to initiate: ";
	std::cin >> input2;
	switch (stoi(input2))
	{
	case 1:
		menu2 = false;
		// Update Trie object
		dict = new Trie();
		// Init Dictionary
		initDictionary(dict, "dictionary.txt");
		return "dictionary.txt";
		break;
	case 2:
		menu2 = false;
		// Update Trie object
		dict = new Trie();
		// Init Dictionary
		initDictionary(dict, "RandomWords100.txt");
		return "RandomWords100.txt";
		break;
	case 3:
		menu2 = false;
		// Update Trie object
		dict = new Trie();
		// Init Dictionary
		initDictionary(dict, "RandomWords1000.txt");
		return "RandomWords1000.txt";
		break;
	case 4:
		menu2 = false;
		// Update Trie object
		dict = new Trie();
		// Init Dictionary
		initDictionary(dict, "RandomWords3000.txt");
		return "RandomWords3000.txt";
		break;
	}
	return "No File";
}

void addWordToDict(string _string) 
{
	std::cout << "Please specify Dictionary .txt file to append to." << endl; //e.g. dictionary.txt
	string txtFile;
	cin >> txtFile;
	ofstream appendFile;
	appendFile.open(txtFile, std::ios_base::app);
	appendFile << std::endl;
	appendFile << _string;
	appendFile.close();
}

void displayMenuOperations(string initDict, Trie* trie)
{
	bool menu1 = true;
	while (menu1)
	{
		std::cout << initDict + " has been selected." << endl;
		std::cout << "//--------------------------------------------------------//" << endl;
		std::cout << "1. Check if word is in dictionary." << endl;
		std::cout << "2. Check TestText.txt against dictionary." << endl;
		std::cout << "3. Find words with prefix." << endl;
		std::cout << "4. Check word for insertion error." << endl;
		std::cout << "5. Check word for deletion error." << endl;
		std::cout << "6. Check word for substitution error." << endl;
		std::cout << "7. Check word for transposition error." << endl;
		std::cout << "8. Add word to dictionary text file." << endl;
		std::cout << "//--------------------------------------------------------//" << endl;
		std::cout << "Please choose mode of operation: ";
		string input1 = "0";
		std::cin >> input1;
		// Switch variables
		string wordToCheck; // Case 1
		string inputCase3; // Case 3
		string inputCase4; // Case 4
		string inputCase5; // Case 5
		string inputCase6; // Case 6
		string inputCase7; // Case 7
		// -----------------------------------------------------------//
		switch (stoi(input1))
		{
		case 1:
			// -----------------------------------------------------------//
			//  Requirement One: Spellchecker, return true if found in dict, false if not
			std::cout << "Please enter a word to check:" << endl;
			std::cin >> wordToCheck;
			if (trie->search(wordToCheck))
			{
				std::cout << "Word is correct." << endl;
			}
			else
			{
				std::cout << "No such word, stupid." << endl;
			}
			// -----------------------------------------------------------//
			break;
		case 2:
			// -----------------------------------------------------------//
			// Requirement Two: Read from text file, diplay incorrect words
			readYourFile(trie, "TestText.txt");
			// -----------------------------------------------------------//
			break;
		case 3:
			// -----------------------------------------------------------//
			// Requirement Three: Suggest word display
			std::cout << "Please input word you wish to search:" << endl;
			std::cin >> inputCase3;
			trie->searchClosest(trie, inputCase3);
			// -----------------------------------------------------------//
			break;
		case 4:
			// -----------------------------------------------------------//
			// Additional Requirement: Insertion error check
			std::cout << "Please input word you wish to search for insertion errors:" << endl;
			
			std::cin >> inputCase4;
			trie->searchErrorInsertion(inputCase4);
			// -----------------------------------------------------------//
			break;
		case 5:
			// -----------------------------------------------------------//
			// Additional Requirement: Deletion error check
			std::cout << "Please input word you wish to search for deletion errors:" << endl;
			std::cin >> inputCase5;
			trie->searchErrorDeletion(inputCase5);
			// -----------------------------------------------------------//
			break;
		case 6:
			// -----------------------------------------------------------//
			// Additional Requirement: Substitution error check
			std::cout << "Please input word you wish to search for substitution errors:" << endl;
			std::cin >> inputCase6;
			trie->searchErrorSubstitution(inputCase6);
			// -----------------------------------------------------------//
			break;
		case 7:
			// -----------------------------------------------------------//
			// Additional Requirement: Transposition error check
			std::cout << "Please input word you wish to search for transposition errors:" << endl;
			std::cin >> inputCase7;
			trie->searchErrorTransposition(inputCase7);
			// -----------------------------------------------------------//
			break;
		case 8:
			// -----------------------------------------------------------//
			// Add word to txt file
			std::cout << "Please input word you wish to add:" << endl;
			std::cin >> inputCase7;
			addWordToDict(inputCase7);
			// -----------------------------------------------------------//
			break;
		}
	}
}


int main()
{ 
	// Init Trie object
	Trie* dict = new Trie();
	// Init Dict init menu
	string initDict = displayMenuInitDict(dict);
	// Init Dict
	displayMenuOperations(initDict, dict);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
