#ifndef __TREE_CPP
#define __LIST_CPP
#include "tree.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

Tree::Tree()
{
    head= NULL;
}

Tree::Tree(string file)
{

    head=NULL;
    ifstream directory;
    directory.open("input_test.txt");
    string input;

    while (getline(directory,input))
        insert(input);

    directory.close();
}
Tree::~Tree()
{
}

void Tree::insert(string item)
{

    vector<string> myvector;
    string line;
    istringstream ss;
    ss.str(item); // makes the entire contents of the stringstream as a string :)

    while(getline(ss,line,'/'))
        myvector.push_back(line);

    TreeItem *temp= head;

    if(head==NULL)
        head= new TreeItem(myvector[0]);
    else
    {
        for (int i=0; i<myvector.size(); i++)
        {
            while(temp->value != myvector[i])
            {
                if(temp->NextS !=NULL)
                    temp=temp->NextS;
                else
                    break;
            }

            if (temp->value == myvector[i])
            {

                if(temp->FChild !=NULL)
                    temp =temp->FChild;
                else
                {
                    temp->FChild= new TreeItem (myvector[i+1]);
                    (temp->FChild)->Parent = temp;
                }
            }
            else
            {
                 temp->NextS=new TreeItem(myvector[i]);
                (temp->NextS)->Parent=temp->Parent;


            }
        }
    }
}

vector<string> Tree::Locate(string qry)
{
    vector<string> trace;
    TreeItem* temp=Search(head,qry);

        while(temp!=NULL)
        {
            trace.push_back(temp->value);
            temp=temp->Parent;
        }
    return trace;
}

string Tree::LComAc(string a, string b)
{
    string ancestor ;
    vector <string> one = Locate(a);
    vector <string> two = Locate(b);

    for(int i=0 ; i <one.size();i++)
    {
        for(int j=0 ; j<two.size(); j++)
        {
            if(one[i]==two[j])
            {
                ancestor = one[i];
                return ancestor;
            }
        }
    }

}

TreeItem* Tree::getHead()
{
	return head;
}

int Tree::countFiles()
{
    int counting;
    counting = filecount(head);
    counting--;
    return counting;

}


TreeItem* Tree::Search(TreeItem* temp,string qry)
{
    TreeItem* searched=NULL;
    if (temp->value==qry)
    {
        return temp;
    }
    if(temp->FChild!=NULL)
    {
        searched=Search(temp->FChild,qry);
    }
    if(searched!=NULL)
    {
        return searched;
    }
    if (temp->NextS!=NULL)
    {
        searched=Search(temp->NextS,qry);
    }
    return searched;
}

int Tree::filecount(TreeItem* temp)
{
    TreeItem* filie=temp;
    int files=0;
    if(filie==NULL)
        return 0;
    else
    {
        if(filie->FChild==NULL)
        {
            if(filie->NextS==NULL)
                return files++;
            else
                files++;
        }
        else if (filie->FChild!=NULL)
            files= filecount(filie->FChild);

        if(filie->NextS!=NULL)
            files = files + filecount(filie->NextS);

    }
    return files;
}

#endif
