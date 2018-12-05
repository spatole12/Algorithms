#ifndef __medianHeaps_h__
#define __medianHeaps_h__

#include "minHeap.h"
#include "maxHeap.h"

// A class for Min Heap 
class medianHeaps
{ 
  int capacity;  // member variables
  int median;
  int counter;
  int count_min;
  int count_max;
  int first;
  maxHeap maxH;
  minHeap minH;

public: 
 

    // Constructor 
    medianHeaps(int capacity); 
	 
    // Destructor
    ~medianHeaps();
  
    // Adds a new number and stores it in the two heaps to maintain the median value
    void addNewNumber(int x);
    
    // Returns median value from randomly generated values
    int getMedian();
};

#endif // __medianHeaps_h__