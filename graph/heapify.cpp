#include<vector>
#include<algorithm>

void heapify(std::vector<int>&arr, int n, int ind)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left]>arr[largest])
    {
        largest = left;
    }

    if(right<n && arr[right]>arr[largest])
    {
        largest = right;
    }

    if(largest!=i)
    {
        std::swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}