#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
using namespace std ;

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL ;

}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
        ListItem <T>*temp = otherLinkedList.head ;

            if (temp==NULL)
                head =NULL;
            else
            {
                head = new ListItem <T> (temp->value);
                ListItem <T> *copied = head ;



                while (temp->next !=NULL)
                {
                    temp = temp->next ;
                    copied->next = new ListItem <T> (temp->value) ;
                    copied = copied->next ;
                }
            }


}

template <class T>
LinkedList<T>::~LinkedList()
{
        ListItem <T> *temp = head;
	if (head==NULL)
	   return;

	while (temp->next !=NULL)
	{
		head=head->next;
		delete temp;
		temp = head;
	}

}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
        ListItem <T> *tempo = new ListItem <T>(item) ;
	if (head == NULL)
		{
		   head = tempo ;
		}
	else
		{

			tempo->next = head ;
			head->prev = tempo ;
			head = tempo ;
		}

}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
    if (head == NULL)
		{
			insertAtHead(item) ;
		}
	else
		{
			ListItem <T> *temp = head ;
			ListItem <T> *temp2 = new ListItem <T> (item);

		while(temp->next !=NULL)
		{
			temp = temp->next;
	        }

			temp->next = temp2;
			temp2->prev= temp ;
			temp2->next =NULL ;
		}
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
        if (head== NULL)
		insertAtHead(toInsert) ;

	else
	{

	ListItem <T> *temp = head ;


	while (temp->value != afterWhat)
		temp = temp->next ;

	if (temp->value == afterWhat && temp->next != NULL)
	{
		ListItem <T> *temp2 = new ListItem <T> (toInsert);
		temp2->next = temp->next;
		(temp->next)->prev = temp2 ;
		temp2 -> prev = temp;
		temp -> next = temp2;
	}

	else if (temp->value == afterWhat && temp->next == NULL)
	{
		ListItem <T> *temp2 = new ListItem <T> (toInsert);
		temp2 ->next = NULL ;
		temp2 -> prev = temp;
		temp ->next = temp2;

	}

	else
    return ;
	}

}

template <class T>
void LinkedList<T>::insertSorted(T item)
{

    ListItem <T> *temp = head;


    if (head==NULL)
       insertAtHead(item) ;
else {
    while (temp->next !=NULL)
            temp = temp->next ;

    if(item > (temp->value))
        insertAtTail(item);

     else
    {
        ListItem <T > *point= head ;
        while (point !=NULL)
        {
            if(point->value>=item)
            {


            if (point->prev == NULL)
                    insertAtHead(item) ;

            else
                {
                    ListItem <T> *temp2 = new ListItem <T> (item);
                   (point->prev)->next = temp2 ;
                    temp2->prev = point->prev ;
                    temp2->next = point;
                    point->prev = temp2 ;


                }
                 break;
            }
            point = point->next ;
        }

    }

}
}

template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
		if (head==NULL)
			return NULL ;

		else
			return head ;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{

    if (head == NULL)
		return NULL ;
	else
	{
		ListItem <T> *tempo = head ;

		while (tempo->next != NULL)
			tempo = tempo->next ;

		return tempo;
	}

}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
    if (head==NULL)
		return NULL;
	else
	{
		ListItem <T> *temp=head;
		while (temp->value !=item)
		   {
			if (temp->next !=NULL)
			temp = temp->next ;

			else
			{
				temp=temp->next;
				break;
			}
			}
			return temp;
		}

	}


template <class T>
void LinkedList<T>::deleteElement(T item)
{
       ListItem <T> *temp = head ;
		if (head ==NULL)
			return;
		else
		{
			while (temp->value != item)
			{
				if(temp->next !=NULL)
					temp = temp->next;

				else
					break;
			}
			if (temp !=NULL && temp->next != NULL)
			{
				(temp->prev)->next = temp->next;
				(temp->next)->prev = temp->prev;
				delete temp;
			}
			else if( temp==head)
			{
				deleteHead();

			}
			else if (temp->next==NULL)
			{
				deleteTail();
			}


		}
}


template <class T>
void LinkedList<T>::deleteHead()
{
    ListItem <T> *temp = head ;
		if (head==NULL)
			return;
		else
		{
			temp = head->next;
			delete head ;
			head = temp ;

		}

}

template <class T>
void LinkedList<T>::deleteTail()
{
    ListItem <T> *temp = head ;

		if (head==NULL)
			return ;

		else
		{
			while (temp->next !=NULL)
				temp = temp->next ;

			(temp->prev)->next = NULL ;
			 //temp->prev =NULL ;
                delete temp;
		}
}

template <class T>
int LinkedList<T>::length()
{
        int counter = 0;
        ListItem <T> *temp = head ;

		if (head==NULL)
			return 0;

		else
		{
			while (temp!=NULL)
			{
				counter++;
				temp =temp->next ;
			}
			return counter ;
		}

}

template <class T>
void LinkedList<T>::reverse()
{
            ListItem <T> *tail = head;
            tail->prev =NULL ;
            ListItem <T> *temp = head ;

            while (tail->next !=NULL)
                tail = tail->next ;

            head = tail ;
            tail = temp;

            ListItem <T> *temp2 = head;

            while (temp2!= NULL)
            {
                temp=temp2->next;
                temp2->next=temp2->prev;
                temp2->prev=temp;
                temp2= temp2->next ;

            }




}

template <class T>
void LinkedList<T>::parityArrangement()
{
   ListItem<T>* temp=head;

	for(int i=0;i<length();i++)
	{
		if(temp->value%2!=0)
		{
			insertAtTail(temp->value);
			deleteElement(temp->value);
		}
		temp=temp->next;
	}
}

#endif

