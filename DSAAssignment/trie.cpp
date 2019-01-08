#include "pch.h"
#include "trie.h"

Trie::Trie()
{
	this->isLeaf = false; // this = address of object, sets to root
	
	// Initializes character addresses to null
	for (int i = 0; i < CHAR_SIZE; i++)
	{
		this->character[i] = nullptr; // nullptr is the same as NULL but newer
	}
}

void Trie::insert(string key)
{
	// Create pointer pointing to address of root node (this)
	Trie* current = this;
	for (int i = 0; i < key.length(); i++)
	{
		// Create node if path not found
		if (current->character[key[i]] == nullptr) // Checks if address of index Letter is null
		{
			current->character[key[i]] = new Trie(); // Sets index Letter of character array to new trie
		}
		current = current->character[key[i]]; // Traverse from root to existing or newly created trie address
	}

	// Mark current node as leaf
	current->isLeaf = true;
}

bool Trie::search(string key)
{
	// If object trie is empty
	if (this == nullptr)
	{
		return false;
	}

	Trie* current = this; // Get root address
	for (int i = 0; i < key.length(); i++)
	{
		// traverse to next node
		current = current->character[key[i]];

		if (current == nullptr) // If next node is null, meaning word not registered
		{
			return false;
		}
	}
	return current->isLeaf; // If entire word is found, last letter->isLeaf would return true
}
