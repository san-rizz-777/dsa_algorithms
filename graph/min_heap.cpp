#include<vector>
#include<utility>
#include<algorithm>

template<typename T>
void insert(std::vector<T>&heap, T&& val)
{
    //insert it at left most left node
     heap.push_back(std::move(val));
     
     //getting the index of parent node
     int index = heap.size()-1;
 
     while(index>0 && heap[(index-1)/2]>heap[index])
     {
        //if the parent is greater than left child
        //then swap them
        std::swap(heap[(index-1)/2], heap[index]);
        //change the index
        index = (index-1)/2;
     }

}      //for max_heap just the same with change of sign ">" to "<"

