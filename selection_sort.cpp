#include<bits/stdc++.h>


using namespace std;

void selectionSort(vector<int>&arr)
{
	int n = arr.size();

	//Here just Iterate from rangel 0 to n-1
	//and in that range just find the minimum element and swap it with the first one
	for(int i=0;i<n;i++)
	{
		int mini = INT_MAX;
		int tar = i;
                for(int j=i;j<n;j++)
		{
			//find the minimum
		        if(mini>arr[j])
			{
				tar = j;
				mini = arr[j];
			}
		}

	//swap now 	
        swap(arr[tar],arr[i]);
	}
	//printing
	for(auto it : arr)    cout<<it<<" ";
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
	selectionSort(arr);
	return 0;
}

