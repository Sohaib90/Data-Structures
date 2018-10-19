#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"
#include "list.cpp"
#include <time.h>
#include "HashC.cpp"


//=====================================================================================
vector<long> InsertionSort(vector<long> nums)
{
	long *array = new long [nums.size()] ;

	for (int i=0; i <nums.size(); i++)
	{
		array[i] = nums[i];

	}

	for (int i=1; i< nums.size(); i++)
	{
		int j=i ;

		while (j>0 && array[j] < array[j-1]) //until the condition satisfies it will run
		{
			int temp= array[j] ;
			array[j] = array[j-1];
			array[j-1]= temp;
			j--;

		}
	}

	vector <long> new_vector;

	for(int i=0; i<nums.size();i++)
	{
		new_vector.push_back(array[i]);

	}

	return new_vector ;

}

//=====================================================================================

void split_list (ListItem <long> *head, ListItem<long> **front_half, ListItem <long> **back_half)
{
	ListItem <long> *fast;
	ListItem <long> *slow;

	if (head==NULL || head->next ==NULL)
	{
		*front_half = head;
		*back_half = NULL;
	}

	else
	{
		slow= head;
		fast = head->next;

		//we have to advance fast two nodes and slow one node

		while (fast !=NULL)
		{
			fast = fast->next;

			if(fast!=NULL)
			{
				fast = fast->next;
				slow = slow->next ;
			}
		}
	}
	//cut the linked list into two linked list by slow && fast pointers

	*front_half = head;
	*back_half = slow->next;
	slow->next = NULL ;

}

ListItem <long> *merge_list (ListItem <long> *a, ListItem <long> *b)
{
	ListItem <long> *node= NULL;

	if(a==NULL)
	return b;

	else if (b==NULL)
	return a;

	// recursively join the linked list

	if(a->value <= b->value)
	{
		node = a;
		node->next = merge_list(a->next,b);
	}

	else
	{
		node = b;
		node->next = merge_list(a,b->next);
	}

	return node;
}

void mergesort(ListItem <long> ** node)
{
  ListItem<long>* head = *node;
  ListItem<long>* a;
  ListItem<long>* b;

  //base case for length 0 or 1
  if ((head == NULL) || (head->next == NULL))
  {
    return;
  }

  //split
  split_list(head, &a, &b);

  // Recursively sort the sublists
  mergesort(&a);
  mergesort(&b);

  // answer will the merged sorted lists
  *node = merge_list(a, b);
}



vector<long> MergeSort(vector<long> nums)
{
	List<long> new_list;
	vector <long> new_vector;

	for (int i=0;i<nums.size();i++)
		new_list.insertAtHead(nums[i]);

	ListItem <long> *temp= new_list.getHead();
	mergesort (&temp);

		for (int i=0;i<nums.size();i++)
		{
			new_vector.push_back(temp->value);
			temp= temp->next;
		}
		return new_vector ;

}

//=====================================================================================

long median(long array[], long index1, long index2, long index3)
{
	int new_array[3];
	new_array[0] = array[index1];
	new_array[1] = array[index2];
	new_array[2] = array[index3];

	for (int i=1; i< 3; i++)
	{
		int j=i ;

		while (j>0 && new_array[j] < new_array[j-1]) //until the condition satisfies it will run
		{
			int temp= new_array[j] ;
			new_array[j] = new_array[j-1];
			new_array[j-1]= temp;
			j--;

		}
	}

	int median= new_array[1] ;

	if(median== array[index1])
		return index1;
	if (median== array[index2]);
		return index2;

		return index3;

}



void quickSort(long arr[], int left, int right, int select) {


	if (select ==1)
	{
	  int i = left, j = right;
      int tmp;
      int pivot = arr[right];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      // recursion
      if (left < j)
            quickSort(arr, left, j,select);
      if (i < right)
            quickSort(arr, i, right, select);
}

if (select ==3)
{
	  int i = left, j = right;
      int tmp;
      int first =rand () % (right-left+1) + left;
	  int second = rand () % (right-left+1) + left;
	  int third = rand () % (right-left+1) + left;

		if(first==second)
		{
			second = rand () % (right-left+1) + left;
		}

		if(third==first || third==second)
		{
			third=rand () % (right-left+1) + left;
		}

      long pivot = median(arr,first,second, third);

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(arr, left, j,select);
      if (i < right)
            quickSort(arr, i, right, select);
}


if (select ==2)
	{
	  int i = left, j = right;
      int tmp;
      int pivot = arr[left];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(arr, left, j,select);
      if (i < right)
            quickSort(arr, i, right, select);
}

}



vector<long> QuickSortArray(vector<long> nums)
{
	int select ;
	vector <long> sorted_nums;
	int pivot_select;
	long *array = new long [nums.size()] ;

		for (int i=0;i<nums.size();i++)
		 array[i] = nums[i] ;

		 cout << "Press 1 to keep the pivot at the end, 2 for keeping it at the start and 3 for median of any three's index " << endl;
		 cin >> select ;

		int start=0 , end = nums.size()-1 ;

		quickSort(array, start, end, select);

		for (int i=0 ; i<nums.size(); i++)
			sorted_nums.push_back(array[i]) ;

		return sorted_nums ;

}

//=====================================================================================


vector<long> QuickSortList(vector<long> nums)
{
	List<long> new_list;
	vector <long> new_vector;

	for (int i=0;i<nums.size();i++)
		new_list.insertAtHead(nums[i]);
		
}

//=====================================================================================

void  balance(long arr[],long size)
{
	int parent,leftchild,rightchild;
 	int tree= size;
	for (int i=tree/2; i>=1 ;i--)
	{
		parent=i;
		leftchild=2*i;
		rightchild=(2*i)+1;
		if (leftchild<tree && arr[parent]>arr[leftchild])
		{
			int temp;
			temp= min(arr[leftchild],arr[rightchild]);
			if(temp== arr[leftchild])
			{
			parent=leftchild;
			int val=arr[i];
			arr[i]=arr[parent];
			arr[parent]=val;
			balance(arr,tree);
			}
			else
			{
			parent=rightchild;
			int val=arr[i];
			arr[i]=arr[parent];
			arr[parent]=val;
			balance(arr,tree);
			}
		}
		else if (rightchild<tree && arr[parent]>arr[rightchild])
		{
			int temp;
			temp= min(arr[leftchild],arr[rightchild]);
			if(temp== arr[leftchild])
			{
			parent=leftchild;
			int val=arr[i];
			arr[i]=arr[parent];
			arr[parent]=val;
			balance(arr,tree);
			}
			else
			{
			parent=rightchild;
			int val=arr[i];
			arr[i]=arr[parent];
			arr[parent]=val;
			balance(arr,tree);
			}
	}
}
}

vector<long> HeapSort(vector<long> nums)
{
		long arr[nums.size()+1];
		for (int i=0;i<nums.size();i++)
		{
			arr[i+1]=nums[i];
		}

	vector <long> my_vector;
  	for (int i=nums.size()+1 ; i>1 ; i--)
  	{
  		balance(arr,i);
  		my_vector.push_back(arr[1]);
  		arr[1]=arr[i-1];

	}

	return my_vector ;

}

//=====================================================================================
vector<long> BucketSort(vector<long> nums, int max)
{
	vector <long> my_vector;
	HashC buckets(max);

	for (int i=0;i<nums.size();i++)
	{
		buckets.insert(nums[i]);
	}

	for (int i=0; i<max; i++)
	{
		if(buckets.hashTable[i].head !=NULL)
		{
			ListItem <long> * temp=	buckets.hashTable[i].head;

			while (temp!=NULL)
			{
				my_vector.push_back(temp->value);
				temp=temp->next;
			}
		}

	}

	return my_vector;

}


#endif
