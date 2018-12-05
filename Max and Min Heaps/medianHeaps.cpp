#include <iostream>
#include <climits>
#include "medianHeaps.h"
#include "minHeap.h"
#include "maxHeap.h"

using namespace std; 

medianHeaps::medianHeaps(int cap):
maxH(cap),minH(cap)
{ 
	capacity= cap;
	median=0;
	counter=0;
	count_max=0; //count of max heap
	count_min=0; //count of min heap
	first=0; //store first element
	
} 

medianHeaps::~medianHeaps()
{
	

}
 
void medianHeaps::addNewNumber(int x) 
{ 	

	counter++; //maintain current size
	if(counter>capacity){
		cout<<"exceeds capacity"<<endl;
	}
	if(counter==1){ 

		first=x;
	}
	else if(counter==2){
		
		if(x<first){ //compare first two elements
			
			maxH.insertKey(x); //maintain max heap with lower values
			minH.insertKey(first);
			count_max++;
			count_min++;
		}
		else if(x>first){
			minH.insertKey(x);//maintain min heap with higher values
			maxH.insertKey(first);
			count_max++;
			count_min++;
		}
	}
	else if(counter>2)
	{	
		if(x>maxH.getMax()){ //compare with root of max heap
			
			minH.insertKey(x); //maintain min heap with higher values
			minH.minHeapify(count_min);
			count_min++;
		}
		else { 
			
			maxH.insertKey(x); //maintain max heap with lower values
			maxH.maxHeapify(count_max);
			count_max++;
		}
	}

	if(minH.size()-maxH.size()>1) //balance the sizes of heaps to not be greater than 1
	{
	
		int emax=minH.extractMin(); //extract root of min heap
		maxH.insertKey(emax);  //insert in max heap
		count_min--;
		count_max++;
	}
	else if(maxH.size()-minH.size()>1){
		
		int emin=maxH.extractMax();//extract root of max heap
		
		minH.insertKey(emin); //insert in min heap
		
		count_max--;
		count_min++;
	}
	
} 

 
int medianHeaps::getMedian() 
{	
	if(counter==0){
			median = 0;
		}
		else if(counter==1){
			median = first;
		}
		else if(counter%2==0){  //check if even
		
		
		int sum=maxH.getMax()+minH.getMin();
		
		median=sum/2; //return average of two roots
		
		}
		else{
		if(count_min>count_max){
			
			median= minH.getMin(); // return root of minHeap
		}
		else{
			
		median= maxH.getMax(); // return root of maxHeap
		}
		}
	
	return median;
   
} 
