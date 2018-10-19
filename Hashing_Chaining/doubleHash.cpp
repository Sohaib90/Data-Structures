#include <fstream>
#include <math.h>
#include "doubleHash.h"

DoubleHash::DoubleHash(int A)
{	
	tableSize = 20000;
    hashTable = new string[tableSize];
    a = A;
    collisions=0;
    currsize=0;	
    
    	for (int i = 0; i < tableSize; i++)
		hashTable[i]=" ";

}

void DoubleHash::Load(char *file)
{
	ifstream loading;
	loading.open(file);
	string data;
	
	while(getline(loading,data))
	{
		    insertItem(data);
	}
	loading.close() ;
}

long DoubleHash::getSize()
{
	return tableSize;
}

void DoubleHash::resize()
{
		if(currsize==tableSize)
	{
		tableSize=2*tableSize;
		string * newarray=new string [tableSize];
			for (int i = 0; i < tableSize; i++)
		newarray[i]=" ";

	
		for (int i=0;i<currsize;i++)
		{
			newarray[i]=hashTable[i];
		}
		hashTable=newarray;
	}	
}

void DoubleHash::insertItem(string Word)
{
	resize();
	unsigned int HashKey;
 	int i=0;
	for (i=0;i<100;i++)
	{
			HashKey=(hash1(Word) + i*hash2(Word))% tableSize;

	 		if(hashTable[HashKey]==" ")
			{
				hashTable[HashKey]=Word;
				currsize++;
				break;
			}
			else if (hashTable[HashKey]!=" ")
			{
				collisions++;
			}
	}
	if (i==100)
	{
		hashTable[tableSize-1]=Word;
		currsize++;
	}
}

int DoubleHash::hash1(string powers)
{
	int length= powers.size();
	unsigned int hashnum(0);
	
	for (int i=0; i <length ;i++)
	{
		hashnum= hashnum+ (pow(a,i)*powers[i]);
	}
	
	return hashnum%tableSize;
	
}

int DoubleHash::hash2(string powers)
{
	unsigned int hash2=0;
		
		for(int i=0; i<powers.size(); i++)
		{
			hash2 ^= (hash2 << 5) + (hash2 >> 2) + powers[i];
		}
		return hash2% tableSize;
}

string DoubleHash::lookUp(string Word)
{
	unsigned int HashKey;
	int i;
	for ( i=0; i<100; i++)
	{

	 HashKey=(hash1(Word) + i*hash2(Word)) % tableSize;
	 if (hashTable[HashKey]==Word)
	 {
		return Word;
	 	break;
	}
	}
	
	if (i==100)
	{
	int k(0);
		
		for (int i=HashKey+1; i<tableSize; i++)
		{
			if (hashTable[i]==Word)	
			{
				k=1;
				return Word;				
			}
		}
		
		if (k==0) 
		{
			for (int i=0;i<HashKey;i++) //circling
			{
				if (hashTable[i]==Word)	
				{
					return Word;				
				}
			}
		}	
	}	
}

int DoubleHash::Collisions()
{
	return collisions++ ;
}
