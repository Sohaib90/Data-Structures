#include "openAddress.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

OpenAddress::OpenAddress(int A)
{	
	tableSize = 20000;
    hashTable = new string[tableSize];
    a = A;
    collisions=0;
    currsize=0;

}

void OpenAddress::Load(char* file)
{
    ifstream loading;
    string data;
    loading.open(file);

	    while (getline(loading,data))
		{
		    insertItem(data);
		}
		
		loading.close();
}

int OpenAddress::hash(string powers)
{
	
	int length= powers.size();
	unsigned int hashnum(0);
	
	for (int i=0; i <length ;i++)
	{
		hashnum= hashnum+ (pow(a,i)*powers[i]);
	}
	
	return hashnum%tableSize;
}

long OpenAddress::getSize()
{
	return tableSize;
}

void OpenAddress :: resize()
{
	if(currsize==tableSize)
	{
		tableSize=2*tableSize;
		string * newarray=new string [tableSize];
	
		for (int i=0;i<currsize;i++)
		{
			newarray[i]=hashTable[i];
		}
		hashTable=newarray;
	}
}

void OpenAddress :: insertItem(string Word)
{
	resize();
	int hashKey = hash(Word);
	
	if(hashTable[hashKey]=="")
	{
		hashTable[hashKey] = Word;
		currsize++ ;
	}
	
	else if (hashTable[hashKey] != "")
	{
		collisions++;
		int k(0);
		
		for (int i=hashKey+1; i<tableSize; i++)
		{
			if (hashTable[i]=="")	
			{
				k=1;
				hashTable[i]=Word;
				currsize++;
				break;				
			}
			else
			collisions++;
			
		}
		
		if (k==0) 
		{
			for (int i=0;i<hashKey;i++) //circling
			{
				if (hashTable[i]=="")	
				{
					hashTable[i]=Word;
					currsize++;
					break;				
				}
				else
				collisions++;
			}
		}
		
	}
		
}

string OpenAddress :: lookUp (string Word)
{
	int hashKey=hash(Word);
	 
	 if (hashTable[hashKey]==Word)
	 	return Word;
	 
	 
	 else
	 {
	 	int k(0);
		
		for (int i=hashKey+1; i<tableSize; i++)
		{
			if (hashTable[i]==Word)	
			{
				k=1;
				return Word;				
			}
		}
		
		if (k==0) 
		{
			for (int i=0;i<hashKey;i++) //circling
			{
				if (hashTable[i]==Word)	
				{
					return Word;				
				}
			}
		}	
	}
}

int OpenAddress :: Collisions()
{
	return collisions++ ;
}
