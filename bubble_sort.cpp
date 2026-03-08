#include<bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>&arr)
{
	int n = arr.size();

	///Now the buuble sort 
	/////TC - worst - O(n^2)  but in best one O(n)
	for(int i=n-1;i>=0;i--)
	{       bool swap_ = false;
		for(int j=0;j<i;j++)
		{
			///keep on swapping
			///until you put the maximum element in range at the end 
			if(arr[j]>arr[j+1])
			{
			      swap_ = true;
			      swap(arr[j], arr[j+1]);
			}
		}

		if(!swap_)   break;
	}		

	//printing
	for(auto it : arr)        cout<<it<<" ";
       cout<<"\n";
}       


int main()
{
	cout<<"Enter the number of elements...\n";
	int n;
	cin>>n;
	cout<<"Enter the elements....\n";
	vector<int> arr(n);
	for(auto i = 0;i < n;i++)        cin>>arr[i];
	bubbleSort(arr);
	return 0;
}

