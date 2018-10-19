#include "LinkedList.cpp"
#include <iostream>
#include <math.h>
using namespace std;



int polHashCode (string powers, int a)

{
	int length= powers.size();
	int hash(0);
	
	for (int i=0; i <length ;i++)
	{
		hash= hash+ (pow(a,i)*powers[i]);
	}
	
	return hash;
		
}

int Divisonmethod(string powers,int a, int N)

{
	
	int hashCode= polHashCode(powers,a);
	int HashDivision= hashCode%N;
	return HashDivision;
	
}

int main()
{
	int number = Divisonmethod("Sohaib",20,100);
	cout << number << endl;
	
	
}
