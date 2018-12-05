#ifndef __BS_TREE_H__
#define __BS_TREE_H__

struct bs_tree_node 
{
  int key;
 // int counter;
  bs_tree_node*	left;
  bs_tree_node*	right;
  bs_tree_node*	p;
};

class bs_tree
{ 
	int counter_duplicate,counter,k;
  protected:
    bs_tree_node*	T_nil;
    bs_tree_node*	T_root;

  public:
    bs_tree();
    ~bs_tree();
	void display_counters();
    void insert(int*, int);
    void insert(int);

	int INORDER_TREE_WALK()
      { INORDER_TREE_WALK(T_root,1); }
    void inorder_output()
      { inorder_output(T_root, 1); }
    void output()
      { output(T_root, 1); }

  protected:
    void insert(bs_tree_node*);
    void remove_all(bs_tree_node*);

    void inorder_output(bs_tree_node*, int);
	int INORDER_TREE_WALK(bs_tree_node*, int);
    void output(bs_tree_node*, int);
};


#endif
