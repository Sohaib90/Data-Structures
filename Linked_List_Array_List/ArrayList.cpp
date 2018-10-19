#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "ArrayList.h"
using namespace std;

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& otherArrayList)
{
    int c = otherArrayList.size ;
	array = new T[c] ;

	size = otherArrayList.size ;

		for ( int i=0; i <size ; i++)
			array[i] = otherArrayList.array[i] ;

}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete [] array ;
	array = NULL ;
	size = 0 ;

}

template <class T>
void ArrayList<T>::insertAtHead(T item)
{
	if (size==0 || array == NULL)
		{
			array[0]= item;
			size++ ;
		}
    else if (size==capacity)
	{
			resize();
			for(int i=size-1 ;i>= 0;i--)
		{
			array[i+1]=array[i];

		}
		array[0]=item;
		size++ ;
	}

	else if(size<capacity)
		{
		for(int i=size-1 ;i>= 0;i--)
		{
			array[i+1]=array[i];

		}
		array[0]=item;
		size++ ;
		}
}
template <class T>
void ArrayList<T>::insertAtTail(T item)
{


    if (size==0)
	{

		insertAtHead(item);

	}

	else if (size==capacity)
	{
			resize();
			array[size]= item ;
        	size++;
	}

	else if(size<capacity)
    {
        array[size]= item ;
        size++;
    }


}

template <class T>
void ArrayList<T>::insertAfter(T toInsert, T afterWhat)
{

    if (size==0||array==NULL)
        {
        	array[0]= toInsert;
        	size++ ;
		}
    else if (size==capacity)
        {

            resize() ;
            int j;
        for (int i = 0 ; i<size ; i++)
        {
            if(array[i]==afterWhat)
            {
                j=i+1 ;
                break;
            }
        }
                for (int p = size ; p > j ; p--)
                {
                    array[p] = array[p-1];
                }
                array[j] = toInsert;
                size++ ;
        }

            else
            {
                int j;
        for (int i = 0 ; i<size ; i++)
        {
            if(array[i]==afterWhat)
            {
                j=i+1 ;
                break;
            }
        }
                for (int p = size ; p > j ; p--)
                {
                    array[p] = array[p-1];
                }
                array[j] = toInsert;
                size++ ;
            }

            }


template <class T>
void ArrayList<T>::insertSorted(T item)
{
    if (size==0)
        insertAtHead(item);
    else if (array[size-1]<item)
    {
        insertAtTail(item);
    }
    else
    {
        int index= 0;
        for (int i =0 ; i <size ; i++)
        {
            if((array[i]<item) && (array[i+1]>item)){
                index = i ;
                break;
            }
        }
        insertAfter(item,array[index]);

    }

}

template <class T>
T ArrayList<T>::getAt(int i)
{
        return array[i] ;
}

template <class T>
int ArrayList<T>::searchFor(T item)
{

    int i= 0 ;

        for (int i = 0 ; i < size ; i++)
        {
            if (array[i]==item)
                return i ;
        }



    }


template <class T>
void ArrayList<T>::deleteElement(T item)
{
        int index = 0 ;

            for (int p =0; p<size ; p++)
            {
                if(array[p]==item)
                {
                    index =p;
                    break;
                }
            }

            deleteAt(index) ;


            }



template <class T>
void ArrayList<T>::deleteAt(int i)
{
        for (int j= i ; j<size ;j++)
            array[j]=array[j+1];

        size-- ;

}

template <class T>
void ArrayList<T>::deleteHead()
{
    for (int i = 0 ; i <size ; i++)
        array[i]= array[i+1] ;

        size-- ;

}

template <class T>
void ArrayList<T>::deleteTail()
{
        size--;
}

template <class T>
void ArrayList<T>::resize()
{

     if (size==capacity)
	{
		T *Array2 = new T[capacity*2] ;
		capacity=capacity*2;

		for (int i =0 ; i <size ; i++)
			Array2[i] = array[i] ;

		delete [] array;
		array = Array2 ;


	}


}

template <class T>
int ArrayList<T>::length()
{
    return size ;

}

template <class T>
void ArrayList<T>::reverse()
{
    T *Array2 = new T[size] ;

    for (int i = size ; i >=0 ; i--)
        Array2[size-i] = array[i-1];

    delete [] array ;
    array = Array2 ;


}

#endif
