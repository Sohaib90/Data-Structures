#ifndef __BST_CPP
#define __BST_CPP
#include <iostream>
#include "bst.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include "time.h"
using namespace std;
template <class T>
bst<T>::bst()
{
    root= NULL ;
}


template <class T>
void bst<T>::insert(string val,int key1)
{
    if (root==NULL)
    {
        root=new bst_node<T>(val,key1);
    }

    else
    {
        bst_node <T> *temp = root;
        bst_node <T> *node = new bst_node <T> (val,key1);
        while (temp!=NULL)
        {
            if (key1 > temp->key)
            {
                if(temp->right !=NULL)
                {
                 temp= temp->right;
                }

                else
                    {
                    temp->right = node ;
                    node->parent = temp;
                    break ;
                    }
            }
            else
            {
                if(temp->left!=NULL)
                {
                 temp= temp->left;
                }
                else{
                    temp->left = node ;
                    node->parent = temp;
                    break ;
                }
            }
        }
    }
}
template <class T>
bst_node<T>* bst<T>::search(T key1)
{
    bst_node <T> *temp = root ;

    if(root->key == key1)
        return root ;

    else
    {
        while (temp!=NULL)
        {
            if(key1 > temp->key)
            {
                if(temp->key !=NULL)
                    temp= temp->right ;
            }


            else if (key1 < temp->key)
            {
                if (temp->key !=NULL)
                    temp= temp->left ;
            }

            if (key1 == temp->key)
                return temp ;
        }
            //return NULL ;

    }




}

template <class T>
void bst<T>::delete_node(T key1)
{
    bst_node <T> *temp = search(key1);
    if (root==NULL)
        return ;

        if(temp->right==NULL && temp->left ==NULL)
                {
                    if(temp->parent->left == temp)
                    {
                        temp->parent->left =NULL ;
                        delete temp ;
                    }
                    else
                    {
                        temp->parent->right= NULL;
                        delete temp ;
                    }
                }
        else if (temp->right == NULL && temp->left !=NULL)
        {
            if(temp->parent->left == temp)
            {
                temp->parent->left = temp->left;
                temp->left->parent = temp->parent;
                delete temp;
            }
            else
            {
                temp->parent->right = temp->left;
                temp->left->parent = temp->parent;
                delete temp;
            }
        }

        else if (temp->left ==NULL && temp->right !=NULL)
        {
            if(temp->parent->right == temp)
            {
                temp->parent->right = temp->right;
                temp->right->parent = temp->parent;
                delete temp;
            }
            else
            {
                temp->parent->left = temp->right;
                 temp->right->parent = temp->parent;
                delete temp;
            }
        }

        else if (temp->left !=NULL && temp->right !=NULL)
        {
            bst_node<T> * MIN= temp->right;
            while (MIN->left !=NULL)
            {
                MIN = MIN->left ;
            }
            temp->value=MIN->value;
            temp->key=MIN->key;

             if(MIN->right==NULL && MIN->left ==NULL)
                {
                    if(MIN->parent->left == MIN)
                    {
                        MIN->parent->left =NULL ;
                        delete MIN;
                    }
                    else
                    {
                        MIN->parent->right= NULL;
                        delete MIN ;
                    }
                }

                else if (MIN->left ==NULL && MIN->right !=NULL)
            {

            if(MIN->parent->right == MIN)
                {
                MIN->parent->right = MIN->right;
                MIN->right->parent = MIN->parent;
                delete MIN;
                }
            else
                {
                MIN->parent->left = MIN->right;
                MIN->right->parent = MIN->parent;
                delete MIN;
                }
            }
        }
   }


template <class T>
int bst<T>::height( bst_node<T> *temp)
{
    int leftwing,rightwing ;

    if (temp== NULL)
        return -1;

    leftwing = height(temp->left);
    rightwing = height(temp->right);
    return max(leftwing,rightwing)+1 ;


}

template<class T>
void bst<T>::replace(T old_key,T new_key)
{
    string newval= (search(old_key))->value;
    delete_node(old_key);
    insert(newval,new_key);
}

template <class T>
bst_node<T>* bst<T>::getroot()
{
    return root ;
}
#endif
