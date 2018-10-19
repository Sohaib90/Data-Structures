#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

int counter = 0 ;

template <class T>
Queue<T>::Queue()
{
    ListItem <T> *temp = list.getHead();
    temp = NULL;
}

template <class T>
Queue<T>::Queue(const Queue<T>& otherQueue): list(otherQueue.list)
{
}

template <class T>
Queue<T>::~Queue()
{
}

template <class T>
void Queue<T>::enqueue(T item)
{
    list.insertAtTail(item);
}

template <class T>
T Queue<T>::front()
{
    ListItem <T> *potti = list.getHead() ;
    T value = potti->value ;
    return value ;
}

template <class T>
T Queue<T>::dequeue()
{
    T val = front();
    list.deleteHead();
    counter = 0 ;
    return val;

}

template <class T>
int Queue<T>::length()
{
    return list.length();
}

template <class T>
bool Queue<T>::isEmpty()
{
    if (list.length()==0)
        return true ;
    else
        return false ;

}

template <class T>
void Queue<T>::AddVip(T item)
{
    if (counter>0)
	{
			int a=counter;
			ListItem<T> *lol=list.getHead();
			while (a!=1)
			{
                lol=lol->next;
                a--;
			}
			list.insertAfter(item,lol->value);
			counter++;

	}
	else
	{
		list.insertAtHead(item);
		counter++;
	}
}


#endif
