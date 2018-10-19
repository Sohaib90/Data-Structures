#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void quickSort(long arr[], int left, int right) {

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
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

vector<long> QuickSortArray(vector<long> nums)
{
	
	vector <long> sorted_nums;
	int pivot_select;
	long *array = new long [nums.size()] ;

		for (int i=0;i<nums.size();i++)
		 array[i] = nums[i] ;

		int start=0 , end = nums.size()-1 ;

		quickSort(array, start, end);

		for (int i=0 ; i<nums.size(); i++)
			sorted_nums.push_back(array[i]) ;

		return sorted_nums ;

}


// A single pair is stored in a Vector<long>
// You have to return a vector of all pairs.
vector< vector<long> > smartSearch(vector<long> nums, long k)
{

		vector<long> new_vector = QuickSortArray(nums);

		
	
		vector <vector<long> > finalpairs;
		
		vector <long> diff;
		for (int i = 0; i < nums.size(); i++)
		diff.push_back(abs(k-nums[i]));
		long sum=k;
		for (int i=0;i<new_vector.size();i++)

		{
			vector <long> pairs;
			if (binary_search(new_vector.begin(),new_vector.end(),diff[i]))
			{
				if(sum>new_vector[i]){
				
				pairs.push_back(new_vector[i]);
				pairs.push_back(abs(k - new_vector[i]));
				finalpairs.push_back(pairs);
				}
				else
				continue;
			
			}
			else
				continue;

		}

	return finalpairs;
}


int main()
{
    vector<long> nums;
    ifstream in("random.txt");
    long n;
    while(in >> n)
        nums.push_back(n);
    in.close();

    long k;
    cout << "Enter the value of K: ";
    cin >> k;

    vector< vector<long> > result = smartSearch(nums, k);

    for(int i = 0; i < result.size(); i++)
        cout << result[i][0] << ", " << result[i][1] << endl;

    return 0;
}
