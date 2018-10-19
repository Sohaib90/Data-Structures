#ifndef __AVL_CPP
#define __AVL_CPP
#include "avl.h"
#include "time.h"
#include <fstream>

template <class T>
AvL<T>::AvL()
{
    root=NULL;
}

template <class T>
AvL<T>::~AvL()
{
}

template <class T>
AvLNode<T>* AvL<T>::search(T k)
{
    AvLNode <T> *temp = root ;

    if(temp->key == k)
        return root ;
    else
    {
        while (temp->left!=NULL && temp->right !=NULL)
        {
            if(k > temp->key)
            {
                if(temp->right !=NULL)
                    temp= temp->right ;
            }

            else if (k < temp->key)
            {
                if (temp->left !=NULL)
                    temp= temp->left ;
            }

            if (k == temp->key)
                return temp ;
        }
            return NULL ;

        }
}


template <class T>
void AvL<T>::replace(T ok, T nk)
{
}

template <class T>
void AvL<T>::delete_node(T k)
{
    AvLNode<T> *temp = search(k);
    AvLNode <T> *poop ;
    if (root==NULL)
        return ;

        if(temp->right==NULL && temp->left ==NULL)
                {
                    if(temp->parent->left == temp)
                    {
                        temp->parent->left =NULL ;
                        AvLNode <T> *poop = temp->parent;
                        delete temp ;
                    }
                    else
                    {
                        temp->parent->right= NULL;
                        AvLNode <T> *poop = temp->parent;
                        delete temp ;
                    }
                }
        else if (temp->right == NULL && temp->left !=NULL)
        {
            if(temp->parent->left == temp)
            {
                temp->parent->left = temp->left;
                temp->left->parent = temp->parent;
                AvLNode <T> *poop = temp->left;
                delete temp;
            }
            else
            {
                temp->parent->right = temp->left;
                temp->left->parent = temp->parent;
                AvLNode <T> *poop = temp->left;
                delete temp;
            }
        }

        else if (temp->left ==NULL && temp->right !=NULL)
        {
            if(temp->parent->right == temp)
            {
                temp->parent->right = temp->right;
                temp->right->parent = temp->parent;
                AvLNode <T> *poop = temp->right;
                delete temp;
            }
            else
            {
                temp->parent->left = temp->right;
                 temp->right->parent = temp->parent;
                 AvLNode <T> *poop = temp->right;
                delete temp;
            }
        }

        else if (temp->left !=NULL && temp->right !=NULL)
        {
            AvLNode<T> * MIN= temp->right;
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
                        AvLNode <T> *poop = MIN->parent;
                        delete MIN;
                    }
                    else
                    {
                        MIN->parent->right= NULL;
                        AvLNode <T> *poop = MIN->parent;
                        delete MIN ;
                    }
                }

                else if (MIN->left ==NULL && MIN->right !=NULL)
            {

            if(MIN->parent->right == MIN)
                {
                MIN->parent->right = MIN->right;
                MIN->right->parent = MIN->parent;
                AvLNode <T> *poop = MIN;
                delete MIN;
                }
            else
                {
                MIN->parent->left = MIN->right;
                MIN->right->parent = MIN->parent;
                AvLNode <T> *poop = MIN;
                delete MIN;
                }
            }
        }


        while (poop->parent !=NULL)
        {
            balance_check(poop);
            poop=poop->parent ;
        }

        if(poop->parent == NULL)
            balance_check(poop);


}

template <class T>
void AvL<T>::insert(string val, T k)
{
    //----------------------------------------------------------------//
    AvLNode <T> *node = new AvLNode <T> (val,k);
    AvLNode <T> *temp = root;
    AvLNode <T> *poop ;

    if (root==NULL)
    {
        root=new AvLNode<T>(val,k);
        poop= root ;
    }

    else
    {
        AvLNode <T> *temp = root;
        AvLNode <T> *node = new AvLNode <T> (val,k);


        while (temp!=NULL)
        {
            if (k > temp->key)
            {
                if(temp->right !=NULL)
                {
                 temp= temp->right;
                }

                else
                    {
                    temp->right = node ;
                    node->parent = temp;
                    poop = temp->right ;
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
                    poop= temp->left ;
                    break ;
                }
            }
        }
    }

//-----------------------------------------------------------------//

        while (poop->parent !=NULL)
        {
            balance_check(poop);
            poop=poop->parent ;
        }

        if(poop->parent == NULL)
            balance_check(poop);

}

template<class T>
int AvL<T>::nodeHeight(AvLNode<T> *n)
{
    int leftwing,rightwing ;

    if (n== NULL)
        return -1;

    leftwing = nodeHeight(n->left);
    rightwing = nodeHeight(n->right);
    return max(leftwing,rightwing)+1;

}

template<class T>
AvLNode<T>* AvL<T>::getRoot()
{
	return root;
}

template<class T>
void AvL<T>::leftRotate(AvLNode <T> *n)
{
    AvLNode <T> *temp = n->right;
   n->right = temp->left;

   if(temp->left != NULL)
      temp ->left->parent = n;

     if(n->parent == NULL)
   {
      root = temp;
      temp->parent = NULL;
   }
   else if(n->parent->left == n)
   {


            n->parent->left = temp;
            temp->parent=n->parent;
   }
   else{
      n->parent->right = temp;
      temp->parent=n->parent;
        }

   temp->left = n;
    n->parent = temp;

}

template<class T>
void AvL<T>::rightRotate(AvLNode <T> *n)
{
    AvLNode <T> *temp = n->left;
       n->left = temp->right;

   if(temp->right != NULL)
    temp->right->parent = n;

   if(n->parent == NULL)
   {
      root = temp;
      temp->parent = NULL;
   }

   else if(n->parent->left == n)

      {
        n->parent->left = temp;
      temp->parent=n->parent;
      }

   else
   {
       n->parent->right = temp;
        temp->parent=n->parent;

   }
        temp->right = n;
   n->parent = temp;
}

template<class T>
void AvL<T>::balance_check(AvLNode <T> *n)
{
    int waza = difference_height(n);

    if (waza >1)
    {
        if(nodeHeight(n->right->right)> nodeHeight(n->right->left)) //RR heavy
                leftRotate(n);

        else if(nodeHeight(n->right->right)< nodeHeight(n->right->left))//right left case
        {
            rightRotate(n->right);
            leftRotate(n);
        }
    }
    else if (waza < -1)
    {
        if(nodeHeight(n->left->right)< nodeHeight(n->left->left)) //left left case
         {
             rightRotate(n);

         }
        else if (nodeHeight(n->left->right)> nodeHeight(n->left->left)) //left-right case
        {
            leftRotate(n->left);
            rightRotate(n);

        }
    }
}

template <class T>
int AvL<T>::difference_height(AvLNode <T> *temp)
{
    int l_height = nodeHeight (temp->left);
    int r_height = nodeHeight (temp->right);
    int diff=  r_height - l_height ;
    return diff;
}
#endif
