#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "sort.h"
#include "bs_tree.h"
#include "rb_tree.h"
#include "timer.h"
#include "random_generator.h"
using namespace std;
int main(int argc, char* argv[])
{	
	random_generator rg;
	timer t;
	//cout<<"inside"<<endl;
	
  int n, d, a;
  
  if (argc > 1)
    { 
        n = atoi(argv[1]);
      n = (n < 0) ? 0 : n;
    }
  else
    {
		n = 0;
      cout << "hw4: [n] [direction]" << endl; 
      cout << "[n]              size integer array" << endl;
      cout << "[direction]      0: random" << endl;
      cout << "                 1: sorted" << endl;
      cout << "                 -1: reverse sorted" << endl;
      cout << endl;
      return 0;
    }

  if (argc > 2)
    {
     d = atoi(argv[2]);
    }
  else
    d = 0;



  int* input_array;
/*
 * create input array sorted/reverse sorted/random 
 * depending on program argument
 * -> input_array is allocated!
 */
 
  if (d == 0)
    input_array = create_random(n);
  else
    {
      if (d < 0)
	input_array = create_reverse_sorted(n);
      else
	input_array = create_sorted(n);
    }
 

 

/*
 * output the first 20 elements for debugging purposes
 */
   // cout << "[";
      // for (int j = 0; j < 20; j++)
	// cout << input_array[j] << " ";
      // cout << "]" << endl;
    
  //cout << endl;
  cout<<"===================RBT======================"<<endl;
	t.start();
	rb_tree rb;
	rb.insert(input_array,n);
	rb.inorder_output();
	int arr_cap1 = rb.INORDER_TREE_WALK();
	cout<<"RBT:elemets copied into array after inorder_tree_walk   :"<<arr_cap1<<endl;
	rb.output();	
	rb.display_counters();
	t.stop();
	cout << "Timer (generate): " << t << endl;
	
	cout<<"==============BST==========================="<<endl;
	
	
	t.start();
	bs_tree bs;
	bs.insert(input_array,n);
	bs.inorder_output();
	
	int arr_cap2 = bs.INORDER_TREE_WALK();
	cout<<"BST:elemets copied into array after inorder_tree_walk   :"<<arr_cap2<<endl;
	bs.output();
	bs.display_counters();
	t.stop();
	cout << "Timer (generate): " << t << endl; 
	return 0;
}
  
