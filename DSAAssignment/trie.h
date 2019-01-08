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
	// Delete word from dictionary
	bool deletion(Trie*&, string);
	// Search from dictionary
	const bool search(const string);
	// 
};
