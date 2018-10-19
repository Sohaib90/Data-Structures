#ifndef CHAINING__H
#define CHAINING__H
#include <iostream>
#include "list.cpp" // Your Own Implementation
#include <cstring>

using namespace std;

class HashC
{
	public:
		long tableSize;
		int collisions;
		int a;
		List<long>* hashTable;

		HashC(int _a);
		void Load(char* file); // Load a file of Strings into your Hash table
		int hash(string); // Given a String, return its hash
		void insert(long word); // Takes a hash of 'word' and inserts it into hashTable accordingly
		ListItem<string>* lookup(string);
		int Collisions(); // Return number of collisions in hashTable
};
#endif
