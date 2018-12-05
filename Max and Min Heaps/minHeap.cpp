#include <iostream>
#include <climits>
#include "minHeap.h"

using namespace std; 

minHeap::minHeap(int cap) 
{ 
heapArray = new int[cap];
heapSize = 0;
capacity = cap ;

} 

minHeap::~minHeap() 
{ 

delete []heapArray;
cout<<"min heap deleted";

} 

void minHeap::insertKey(int k) 
{ 
if(heapSize == capacity)
{
	cout<<"Overflow:Exceeding Capacity"<<endl;
	return;
}

heapSize++;
int new_ele_indx = heapSize-1;
heapArray[new_ele_indx]=k;
while(new_ele_indx !=0 && heapArray[new_ele_indx] < heapArray[parent(new_ele_indx)])
{
int temp = heapArray[parent(new_ele_indx)];
heapArray[parent(new_ele_indx)] = heapArray[new_ele_indx];
heapArray[new_ele_indx] = temp;	
new_ele_indx = parent(new_ele_indx);
}
} 

void minHeap::decreaseKey(int i, int new_val) 
{ 
	
	if(heapArray[i]>new_val)
	{
	heapArray[i] = new_val;
	}
	while(i!=0 && heapArray[i] < heapArray[parent(i)])
	{
	int temp = heapArray[parent(i)];
	heapArray[parent(i)] = heapArray[i];
	heapArray[i] = temp;	
	i = parent(i);
	}
} 

int minHeap::extractMin() 
{ 
	if(heapSize<=0)
	{
		return INT_MIN;
	}
	else if(heapSize==1)
	{
		heapSize--;
		return heapArray[0];
	}
	else{
	int min_val = heapArray[0];
	heapArray[0] = heapArray[heapSize-1];
	heapSize--;
	minHeapify(0);
	return min_val;
	}
	//return 1;
} 

void minHeap::deleteKey(int i) 
{ 
	if(heapArray[i]>INT_MIN)
	{
	heapArray[i] = INT_MIN;
	}
	while(i!=0 && heapArray[i] < heapArray[parent(i)])
	{
	int temp = heapArray[parent(i)];
	heapArray[parent(i)] = heapArray[i];
	heapArray[i] = temp;	
	i = parent(i);
	}
 extractMin();
 //remove from end of array
} 

void minHeap::minHeapify(int i) 
{
int l = left(i);
int r = right(i);
int smallest;
if(l <= heapSize && heapArray[l] < heapArray[i])
{
	smallest = l;
}
else{
	smallest = i;
}
if(r <= heapSize && heapArray[r] < heapArray[smallest])
{
	smallest = r;
}
if(smallest != i)
{
int temp = heapArray[i];
heapArray[i] = heapArray[smallest];
heapArray[smallest] = temp;
minHeapify(smallest);
}

}
 