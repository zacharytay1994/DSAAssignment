#pragma once
#include <iostream>
#include <string>
using namespace std;

const int CHAR_SIZE = 128;

// trie node
class Trie {
private:
public:
	bool isLeaf;
	Trie* character[CHAR_SIZE];

	// Contructor
	Trie();
	// Insert new word in dictionary
	void insert(const string);
	// Search from dictionary
	const bool search(const string);
	// Display all words from closest input
	const void searchClosest(Trie*, const string);
	// Find and display words from closest address
	void traverse(string, Trie*);
	// Search with insertion error check
	const bool searchErrorInsertion(string);
	// Search with deletion error check
	const bool searchErrorDeletion(string);
	// Search with substitution error check
	const bool searchErrorSubstitution(string);
	// Search with transposition error check
	const bool searchErrorTransposition(string);
};
