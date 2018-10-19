#include <iostream>
#include "bst.cpp"
#include "bst.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
void recursivePrint(bst_node<int>* loc, int);


int main()

{
    bst<int> BST;
    bst_node <int> *temp;
    startTimer();

    int counter(0),key,indent,newkey;
    string name,mystring,student ;
    ifstream input ;
    stringstream lol;
    vector <string> myvector;

    input.open("names.txt");

    while(getline(input,name,'~'))
    {
       myvector.push_back(name);

    }

    vector<string> rollnumber ;
    vector <string> studentname;
      for (int i=0; i<myvector.size(); i++)
      {
          if(i%2==0)
            studentname.push_back(myvector[i]);
          else
            rollnumber.push_back(myvector[i]);

      }

      vector <int> rollnumber1;
       for (int i=0; i<rollnumber.size(); i++)
       {
           int num = atoi(rollnumber[i].c_str());
           rollnumber1.push_back(num);
       }

        cout << "STUDENT SIZE  " << studentname.size() << endl;
        cout << "ROLL NUMBER SIZE  " << rollnumber.size() << endl;
        cout << "ROLL NUMBER modified integer walay SIZE  " << rollnumber1.size() << endl;

    cout << endl ;
    stopTimer();
    input.close();
    cout << "FILE LOADED SUCCESSFULLY " << endl;
    cout << "THERE ARE " << myvector.size() << " KEYS/PAIRS IN THE FILE ...." << endl;

    for (int i=0; i<studentname.size(); i++)

    {
        BST.insert(studentname[i],rollnumber1[i]);
    }

    int done(1);
    while (done)
    {

        int choice=0;
        cout << endl <<
			"- Press 1 to Insert another key/value Pair" << endl <<
			"- Press 2 to search for a value using its key" << endl <<
			"- Press 3 to delete a key/value pair" << endl <<
			"- Press 4 to update the key of an existing value" << endl <<
			"- Press 5 to see the current height of the Tree" << endl <<
            "~ Press 6 to exit ." << endl << "> ";


        cin >> choice;
        if(choice==1)

        {
            startTimer();
            cout << "Enter Key to Insert : " ;
            cin >> key ;
            cout << "enter name : " ;
            cin >> student;
            BST.insert(student,key);
            stopTimer();
        }


        else if (choice==2)
        {
            startTimer();
            cout << "Enter key to search for value " ;
            cin >> key ;

            temp= BST.search(key);

                if(temp==NULL)
                    cout << "NOT FOUND" << endl ;
                else
                {
                    cout << "Value found is : " ;

                    cout << temp->value << endl;
                    stopTimer();
                }
        }

        else if(choice==3)
        {

            cout << endl << "Please enter a key to delete: ";
				cin >> key;
				temp = BST.search(key);
				if (temp==NULL) {
					cout << "Not found!" << endl << endl;
				}
				else {
					BST.delete_node(key);
					cout << "Successfully Deleted " << endl;

				}
        }

        else if (choice==4)
        {
                cout << endl << "Please enter a key to update: ";
				cin >> key;
				temp = BST.search(key);
				if (temp==NULL) {
					cout << "Not found!" << endl << endl;
				}
				else {
					mystring = temp->value;
					cout << "Enter new key: ";
					cin >> newkey;
					cout << "Successfully Updated key for " << mystring << " !" << endl << endl;
					BST.replace(key, newkey);
				}
			}

            else if (choice==5)
            {
                cout << "Current height of tree is: " << BST.height(BST.getroot()) << endl << endl;
            }

            else if(choice==6)
            {
                done=0;
            }
        }
    }
