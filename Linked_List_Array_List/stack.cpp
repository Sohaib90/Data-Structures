#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

template <class T>
Stack<T>::Stack()
{
    ListItem <T> *temp = list.getHead();
    temp = NULL;
}

template <class T>
Stack<T>::Stack(const Stack<T>& otherStack):list(otherStack.list)
{
}

template <class T>
Stack<T>::~Stack()
{
}

template <class T>
void Stack<T>::push(T item)
{
    list.insertAtHead(item);
}

template <class T>
T Stack<T>::top()
{
    ListItem <T> *p = new ListItem<T> (NULL);

    p= list.getHead();

     T t=p->value;
        return t;
}

template <class T>
T Stack<T>::pop()
{
   ListItem <T> *p = new ListItem<T> (NULL);

        p=list.getHead();

        T t=p->value;
        list.deleteHead();
        return t;
    }

template <class T>
int Stack<T>::length()
{
   return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (list.length()==0)
        return true;
    else
        return false ;
}

#endif
