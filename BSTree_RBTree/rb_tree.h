#ifndef __RB_TREE_H__
#define __RB_TREE_H__

enum rb_tree_color 
{
  RB_RED,
  RB_BLACK
};

struct rb_tree_node 
{
  int		key;
  int		color;
  rb_tree_node*	left;
  rb_tree_node*	right;
  rb_tree_node*	p;
};

class rb_tree
{ 
	int counter_left,counter_right,counter_case1,counter_case2,counter_case3,counter_duplicate,counter_bh,counter,k;

  protected:
    rb_tree_node*	T_nil;
    rb_tree_node*	T_root;
	
  public:
    rb_tree();
    ~rb_tree();

    void insert(int*, int);
    void insert(int);
	void display_counters();
	int INORDER_TREE_WALK()
      { INORDER_TREE_WALK(T_root, 1); }
    void inorder_output()
      { inorder_output(T_root, 1); }
    void output()
      { output(T_root, 1); }
	
  protected:
	int calculate_bh(rb_tree_node*);
    void insert(rb_tree_node*);
    void insert_fixup(rb_tree_node*&);

    void remove_all(rb_tree_node*);

    void left_rotate(rb_tree_node*);
    void right_rotate(rb_tree_node*);
	int INORDER_TREE_WALK(rb_tree_node*, int);
    void inorder_output(rb_tree_node*, int);
    void output(rb_tree_node*, int);
};


#endif
