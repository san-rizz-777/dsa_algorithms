#include<bits/stdc++.h>

using namespace std;

void insertionSort(vector<int>&arr)
{
	int n = arr.size();
	//Iterate from the range 0 to n-1
	//Place the element i in it's right place 
	//Shift all elements greater than it to the right
	for(int i=1;i<n;i++)
	{
	               int j=i-1;
		       int key = arr[i];
	       while(j>=0 && arr[j]>key)
	       {
	                arr[j+1] = arr[j];  //shift to right
	                j--;       		 //decrement j
	       }

	       //place it to j+1
	       arr[j+1] = key;
	}

	//print the array
	for(auto it : arr)         cout<<it<<" ";
	cout<<"\n";
}


int main()
{       
	int n;
	cout<<"Enter the no. of elements!!\n";
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter the elements!!!\n";
	for(int i=0;i<n;i++)   cin>>arr[i];
	insertionSort(arr);
	return 0;
}
