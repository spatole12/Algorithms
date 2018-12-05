
#include "bs_tree.h"
#include <iostream>
#include <list>
using namespace std;
int *asc_array1;

bs_tree::bs_tree()
{	
   // bt = new bs_tree_node;
	//bt->p = NULL;
	//bt->left = NULL;
	//bt->right = NULL;
	//counter_duplicate=0;
	T_root = NULL;
    counter_duplicate = 0;
	counter =0;
    k = 0;
}


bs_tree::~bs_tree()
{ 
  remove_all(T_root);
 // delete bt;
 delete[] asc_array1;
} 

void bs_tree::insert(int* key_array, int n)
{ /*<<<*/
 // asc_array1[n];
  for (int i = 0; i < n; i++)
    insert(key_array[i]);
} /*>>>*/

void bs_tree::insert(int key)
{ /*<<<*/
/*
 * wrapper around insert
 * -> creates  node with key
 * -> inserts node
 */
// cout<<"In insert 1"<<endl;
  bs_tree_node* z;

  z = new bs_tree_node;
  z->key = key;
  insert(z);
} /*>>>*/

void bs_tree::insert(bs_tree_node* z)
{ 
  counter++;
  //cout<<"In insert 2"<<endl;
  bs_tree_node* x;
  bs_tree_node* y;
  
  y = NULL;
  x = T_root;
  while (x != NULL)
    {	
	//  cout<<"In while "<<endl;
      y = x;
	
      if (z->key < x->key)
	  {
		x = x->left;
		//counter++;
	  }
      else if(z->key > x->key){
		x = x->right;
		//counter++;
	  }
	  else if (z->key == x->key){
		counter_duplicate++;
		return;
	}
    }
	

  z->p = y;
  if (y == NULL)
    T_root = z;
  else
    {
      if (z->key < y->key)
	y->left = z;
      else
	y->right = z;
    }
	
	z->left = NULL;
    z->right = NULL;
}
void bs_tree::display_counters()
{ /*<<<*/
/*
 * display counters
 */
 
 cout<<"counter_duplicate BST:"<<counter_duplicate<<endl;
 
} /*>>>*/
void bs_tree::inorder_output(bs_tree_node* x, int level)
{ 
	
    if (x != NULL)
	{
	  inorder_output(x->left, level+1);
		cout << "(" << x->key << "," << level << ")" << endl;

	  inorder_output(x->right, level+1); 
	  
	}
	
	asc_array1 = new int[counter-counter_duplicate];
		  
} 

int bs_tree::INORDER_TREE_WALK(bs_tree_node* x ,int level)
{ /*<<<*/
/*
 * display ascending array
 */
 if (x != NULL)
	{
	  INORDER_TREE_WALK(x->left, level+1);
	  asc_array1[k] = x->key;
	  k++;
	  INORDER_TREE_WALK(x->right, level+1); 
	  
	}
	 
	return k;
} 

void bs_tree::output(bs_tree_node* x, int r_level)
{ /*<<<*/
/*
 * some structured output
 */
  list< pair<bs_tree_node*,int> > l_nodes;
  pair<bs_tree_node*,int> c_node;
  int c_level;

  c_level = r_level;
  l_nodes.insert(l_nodes.end(), pair<bs_tree_node*,int>(x, r_level));

  while (!l_nodes.empty())
    {
      c_node = *(l_nodes.begin());

      if (c_level < c_node.second)
	{
	  cout << endl;
	  c_level = c_node.second;
	}

      cout << "(" << c_node.first->key;

      if (c_node.first->p == NULL)
	cout << ",ROOT) ";
      else
        cout << ",P:" << c_node.first->p->key << ") ";

      if (c_node.first->left != NULL)
	l_nodes.insert(l_nodes.end(), pair<bs_tree_node*,int>(c_node.first->left, 
							      c_node.second+1));
      if (c_node.first->right != NULL)
	l_nodes.insert(l_nodes.end(), pair<bs_tree_node*,int>(c_node.first->right, 
							      c_node.second+1));
      l_nodes.erase(l_nodes.begin());
    }

  cout << endl;
} /*>>>*/

void bs_tree::remove_all(bs_tree_node* x)
{ /*<<<*/
/*
 * recursively remove all tree elements
 */
  if (x != NULL)
    {
      remove_all(x->left);
      remove_all(x->right);

      delete x;
    }
} /*>>>*/



