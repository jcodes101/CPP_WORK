#include <iostream>
using namespace std;

// == node class
class node {
public:
  int data;
  node *left, *right;

  // default constructor
  node() {
    data = 0;
    left = right = NULL;
  }

  // single-param constructor
  node(int data) {
    this->data = data;
    left = right = NULL;
  }

  node(int data, node *left, node *right) {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};

// == functions

// in order function
void in_order(node *r){
  if (r == NULL) return; // if the root is empty, return nothing


  in_order(r->left); // traverse the left
  cout << r->data << " "; // go to the root 
  in_order(r->right); // traverse the right
}

// pre order function
void pre_order(node *r);

// post order function
void post_order(node *r);




// == main function
int main() {

  // PRACTICE TREE CONSTRUCTION 1
  /* this makes...

       10
      /  \
     5   20

  */
  node *tree_1 = new node(10, // root
    new node(5), new node(20)); // (root, (left), (right))
    
  cout << "Tree 1" << endl;
  cout << "Tree 1, Root: " << tree_1->data << endl;
  cout << "Tree 1, Left Node: " << tree_1->left->data << endl;
  cout << "Tree 1, Right Node: " << tree_1->right->data << endl;

  cout << "\n";

  // PRACTICE TREE CONSTRUCTION 2
  /* this makes...

        9
      /  \
     2    1
    / \   / \
  10  8  4   7

  */
  node *tree_2 = new node(9, // root
    new node(2, new node(10), new node (8)), // left, left - right
    new node(1, new node(4), new node(7))); // left, left -  right

  cout << "Tree 2" << endl;
  cout << "Tree 2, Root: " << tree_2->data << endl;

  cout << "Tree 2, Left Node: " << tree_2->left->data << endl;
  cout << "Left Node, Left Subs: " << tree_2->left->left->data << endl;
  cout << "Left Node, Right Subs: " << tree_2->left->right->data << endl;

  cout << endl;

  cout << "Tree 2, Right Node: " << tree_2->right->data << endl;
  cout << "Left Node, Left Subs: " << tree_2->right->left->data << endl;
  cout << "Left Node, Right Subs: " << tree_2->right->right->data << endl;

  cout << "\n";

  // IN ORDER FUNCTION PRACTICE 1
  in_order(tree_1);


  return 0;
}