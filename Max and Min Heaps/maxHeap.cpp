#include <iostream>
#include <climits>
#include "maxHeap.h"

using namespace std; 



maxHeap::maxHeap(int cap) 
{ 
heapArray = new int[cap];
heapSize = 0;
capacity = cap ;


} 

maxHeap::~maxHeap() 
{ 
delete []heapArray;
} 

void maxHeap::insertKey(int k) 
{ 
if(heapSize == capacity)
{
	cout<<"Overflow:Exceeding Capacity"<<endl;
	return;
}
heapSize++;
int new_ele_indx = heapSize-1;
heapArray[new_ele_indx]=k;

while(new_ele_indx !=0 && heapArray[new_ele_indx] > heapArray[parent(new_ele_indx)])
{
int temp = heapArray[parent(new_ele_indx)];
heapArray[parent(new_ele_indx)] = heapArray[new_ele_indx];
heapArray[new_ele_indx] = temp;	
new_ele_indx = parent(new_ele_indx);
}	
} 

void maxHeap::increaseKey(int i, int new_val) 
{ 
	if(heapArray[i] < new_val)
	{
	heapArray[i] = new_val;
	}
	
	while(i!=0 && heapArray[i] > heapArray[parent(i)])
	{
	int temp = heapArray[parent(i)];
	heapArray[parent(i)] = heapArray[i];
	heapArray[i] = temp;	
	i = parent(i);
	}
} 

int maxHeap::extractMax() 
{ 
	if(heapSize<=0)
	{
		return INT_MAX;
	}
	else if(heapSize==1)
	{
		heapSize--;
		return heapArray[0];
	}
	else{
	int max_val = heapArray[0];
	heapArray[0] = heapArray[heapSize-1];
	heapSize--;
	maxHeapify(0);
	return max_val;
	}
	
} 
 
void maxHeap::deleteKey(int i) 
{ 
	if(heapArray[i]>INT_MAX)
	{
	heapArray[i] = INT_MAX;
	}
	while(i!=0 && heapArray[i] > heapArray[parent(i)])
	{
	int temp = heapArray[parent(i)];
	heapArray[parent(i)] = heapArray[i];
	heapArray[i] = temp;	
	i = parent(i);
	}
	extractMax();
} 

void maxHeap::maxHeapify(int i) 
{ 
int l = left(i);
int r = right(i);
int largest;
if(l <= heapSize && heapArray[l] > heapArray[i])
{
	largest = l;
}
else{
	largest = i;
}
if(r <= heapSize && heapArray[r] > heapArray[largest])
{
	largest = r;
}
if(largest != i)
{
int temp = heapArray[i];
heapArray[i] = heapArray[largest];
heapArray[largest] = temp;
maxHeapify(largest);
}
} 