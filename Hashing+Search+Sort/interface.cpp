#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include "sorts.cpp"

using namespace std;

int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y);
vector<long> GenerateRandom(long n, long d);
vector<long> GenerateSorted(long n);
vector<long> GenerateReverseSorted(long n);
vector<long> GenerateAlmostSorted(long n, int s);

//=====================================================================================

int main()
{

	struct timeval start, end, diff;

	string str; string str1; string str2;
	long n;

	vector<long> num;

	cout<<endl;
	cout<<"What type of vector would you like: "<<endl;
	cout<<"1) Random"<<endl;
	cout<<"2) Sorted"<<endl;
	cout<<"3) Reverse Sorted"<<endl;
	cout<<"4) Almost Sorted"<<endl;

	getline(cin, str);

	cout<<"Enter size, it can only be 10, 10000, or 100000";
	cin>>n;

	if(str == "1")
	{
		long d;
		cout<<"Enter randomizer (d>n): "; cin>>d;
		num = GenerateRandom(n, d);
	}
	else if(str == "2")
	{
		num = GenerateSorted(n);
	}
	else if(str == "3")
	{
		num = GenerateReverseSorted(n);
	}
	else if(str == "4")
	{
		long s;
		cout<<"Enter inversion number: "; cin>>s;
		num = GenerateAlmostSorted(n, s);
	}

// to display the created vector

	cout<<"unsorted vector:"<<endl;
	for(int i=0; i<num.size(); i++)
	{
		cout<<num[i]<<" ";
	}
	cout<<endl<<endl;

//=====================================================================================

	if(str1 == "1" && size==10)
	{
		num = InsertionSort(num);
	}
	else if(str1 == "1" && size==10000)
	{
		num = MergeSort(num);
	}
	else if(str1 == "1" && size==100000)
	{
		num = InsertionSort(num);
	}
	else if(str1 == "2" && size==10)
	{
	
		num = InsertionSort(num);
	}
	else if(str1 == "2" && size==10000)
	{
		
		num = InsertionSort(num);
	}
	else if(str1 == "2" && size== 100000)
	{
		
		num = InsertionSort(num, 509);
	}
		else if(str1 == "3" && size==10)
	{
		
		num = MergeSort(num);
	}
	else if(str1 == "3" && size==10000)
	{
		
		num = MergeSort(num);
	}
	else if(str1 == "3" && size== 100000)
	{
		num = InsertionSort(num);
	}
		else if(str1 == "4" && size==10)
	{
		
		num = MergeSort(num);
	}
	else if(str1 == "4" && size==10000)
	{
		
		num = MergeSort(num);
	}
	else if(str1 == "4" && size== 100000)
	{
	
		num = InsertionSort(num);
	}
	else
	{
		cout<<"Invalid option selected!"<<endl;
		return -1;
	}

	gettimeofday(&end, NULL);
	timeval_subtract(&diff, &end, &start);

// to display the returned (hopefully) sorted vector

	cout<<"sorted vector:"<<endl;
	for(int i=0; i<num.size(); i++)
	{
		cout<<num[i]<<" ";
	}
	cout<<endl;


	cout<<endl<<"Sorted in "<<diff.tv_sec<<" seconds and "<<diff.tv_usec<<" microseconds."<<endl<<endl;

    return 0;
}

//=====================================================================================
//Vector Generation Functions

vector<long> GenerateRandom(long d, long n)
{
    vector<long> nums;
    long k, residue;
    for (k = 0; k < d; k++)
    {
        residue = (long) (((long long)k * (long long) n) % d);
        nums.push_back(residue);
    }
    return nums;
}

vector<long> GenerateSorted(long n)
{
    vector<long> nums;
    for (long k = 0; k < n; k++)
    {
        nums.push_back(k);
    }
    return nums;
}

vector<long> GenerateReverseSorted(long n)
{
    vector<long> nums;
    for (long k = n; k > 0; k--)
    {
        nums.push_back(k);
    }
    return nums;
}

vector<long> GenerateAlmostSorted(long n, int s)
{
    vector<long> nums;
    srand ( time(NULL) );
    for (long k = n; k > 0; k--)
    {
        nums.push_back(k);
    }
    int k1, k2;
    long tmp;
    for (size_t i = 0; i < s; i++)
    {
        k1 = rand() % n;
        k2 = rand() % n;
        tmp = nums[k2];
        nums[k2] = nums[k1];
        nums[k1] = tmp;
    }
    return nums;
}

//=====================================================================================
//Timer Function

int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y)
{

        // Perform the carry for the later subtraction by updating y.
        if (x->tv_usec < y->tv_usec)
        {
                int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
                y->tv_usec -= 1000000 * nsec;
                y->tv_sec += nsec;
        }
        if (x->tv_usec - y->tv_usec > 1000000)
        {
                int nsec = (x->tv_usec - y->tv_usec) / 1000000;
                y->tv_usec += 1000000 * nsec;
                y->tv_sec -= nsec;
        }

        // Compute the time remaining to wait.
        // tv_usec is certainly positive. 
        result->tv_sec = x->tv_sec - y->tv_sec;
        result->tv_usec = x->tv_usec - y->tv_usec;

        // Return 1 if result is negative.
        return x->tv_sec < y->tv_sec;
}
