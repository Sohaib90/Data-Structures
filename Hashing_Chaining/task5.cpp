#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "openAddress.cpp"
#include "doubleHash.cpp"
#include "HashC.cpp"
#include "time.h"

using namespace std;

int main()
{
	vector <string> data;
	string sentence;
	ifstream instream;

	instream.open("names.txt");
	while(getline(instream,sentence))
	{
		data.push_back(sentence);

	}

	cout << "Enter the optimum value of the parameter a between 10-50" << endl ;
	int a;
	cin >> a;
	HashC table1(a);
	OpenAddress table2(a);
	DoubleHash table3(a);

	startTimer() ;
	for (int i=0; i<data.size(); i++)
		table1.insert(data[i]);

	cout << "The number of colllisions in the hash table are : " << table1.Collisions() << endl;
	cout << "And insertion time for insertion in the hash table using chaining is : " ;
	stopTimer();

	startTimer();
	for (int i=0; i<data.size(); i++)
		table2.insertItem(data[i]);

	cout << "The number of collisions in the hash table are : " << table2.Collisions() << endl;
	cout << "And insertion time for insertion in the hash table using open addressing is : " ;
	stopTimer();


	startTimer();
	for (int i=0; i<data.size(); i++)
		table3.insertItem(data[i]);

	cout << "The number of colllisions in the hash table are : " << table3.Collisions() << endl;
	cout << "And insertion time for insertion in the hash table using double hash is : " ;
	stopTimer();



	string decision= "yes" ;

	while (done != "no")
	{
		cout << "enter the name of the student you want to search :" << endl;
		string name;
		cin >> name;

		startTimer();
		table1.lookup(name);
		cout << "searching time for " << table1.lookup(name)->value<< " in Chaining is : ";
		 stopTimer();
		// end time

		// start time
		startTimer();
		table2.lookUp(name);
			cout << "searching time for " << table2.lookUp(name)<< " in OpenAddressing : ";
			stopTimer();
		//end time

		// start time
		startTimer();
		table3.lookUp(name);
	cout << "searching time for " << table3.lookUp(name)<< " in doubleHashing : ";
	stopTimer();
		//end time

	cout << "do you want to search again? (yes/no)"<< endl;
	cin >> done;

	}




}
