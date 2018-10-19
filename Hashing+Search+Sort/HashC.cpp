#include "Chaining.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

HashC::HashC(int _a)
{
	tableSize = _a ;
	collisions=0;
	a = _a ;
	hashTable = new List <long> [tableSize];
	
	for (int i =0 ;i <tableSize ;i++)
	hashTable[i].head =NULL;
	
}

void HashC :: Load(char *file)
{
//	ifstream loading;
//	loading.open(file);
//	string data;
//	
//	while(getline(loading,data))
//	{
//		    insert(data);
//	}
//	loading.close() ;
//	
}
//
int HashC :: hash(string powers)
{
//		int length= powers.size();
//	unsigned int hashnum(0);
//	
//	for (int i=0; i <length ;i++)
//	{
//		hashnum= hashnum+ (pow(a,i)*powers[i]);
//	}
//	
//	return hashnum%tableSize;
}

void HashC::insert(long word)
{
	unsigned int hashKey= word%tableSize;
	if (hashTable[hashKey].head==NULL)
	{
		hashTable[hashKey].insertAtHead(word);
	}
	else
	{
		hashTable[hashKey].insertAtTail(word);
		collisions ++ ;
	}
	
}

ListItem <string>* HashC:: lookup(string lost)
{
//	int hashKey = hash(lost);
//	return hashTable[hashKey].searchFor(lost);
	
}

int HashC :: Collisions()
{
	return collisions;
	
}

