// DSAAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "trie.h"
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
	cout << "The following words from your file were not found." << endl;
	ifstream readYourFile;
	readYourFile.open(filename);
	string x;
	while (readYourFile >> x)
	{
		if (!trie->search(x))
		{
			cout << x << endl;
		}
	}
	readYourFile.close();
}

// Display all words that start with a certain letter
void gimmeWords(Trie* trie, const string letter)
{
	cout << "Words found that start with " + letter + "." << endl;
}

int main()
{ 
	// Init Trie object
	Trie* dict = new Trie();

	// Init Dictionary
	initDictionary(dict,"RandomWords100.txt");

	// ------------------------------------------------------//
	//  Requirement One: Spellchecker, return true if found in dict, false if not
	cout << "Please enter a word to check:" << endl;
	string wordToCheck;
	cin >> wordToCheck;
	if (dict->search(wordToCheck))
	{
		cout << "Word is correct." << endl;
	}
	else
	{
		cout << "No such word, stupid." << endl;
	}
	// ---------------------------------------------------------//
	// Requirement Two: Read from text file, diplay incorrect words
	readYourFile(dict, "TestText.txt");
	// ---------------------------------------------------------//
	// Requirement Three: Suggest word display
	cout << "Please input word you with to search:" << endl;
	string input;
	cin >> input;
	dict->searchClosest(dict, input);
	// ---------------------------------------------------------//
	// Additional Requirement: Insertion error check
	cout << "Please input word you wish to search for insertion errors:" << endl;
	string input2;
	cin >> input2;
	dict->searchErrorInsertion(input2);
	// -----------------------------------------------------------//
	// Additional Requirement: Deletion error check
	cout << "Please input word you wish to search for deletion errors:" << endl;
	string input3;
	cin >> input3;
	dict->searchErrorDeletion(input3);
	// ------------------------------------------------------------//
	cout << "Please input word you wish to search for substitution errors:" << endl;
	string input4;
	cin >> input4;
	dict->searchErrorSubstitution(input4);

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
