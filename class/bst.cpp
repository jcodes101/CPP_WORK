#include <iostream>
#include <queue>
using namespace std;

class node {
public:
  int key;
  node *left, *right;

  node() {
    key = 0;
    left = right = NULL;
  }
  node(int key) {
    this->key = key;
    left = right = NULL;
  }
  node(int key, node *left, node *right) {
    this->key = key;
    this->left = left;
    this->right = right;
  }
};

void levelorder(node *r) {
  queue<node*> Q;
  Q.push(r);
  while (!Q.empty()) {
    node *temp = Q.front();
    Q.pop();
    cout << temp->key << " ";
    if (temp->left) Q.push(temp->left);
    if (temp->right) Q.push(temp->right);
  }
  cout << endl;
}

// preorders the values in tree starting from r
void preorder(node *r) {
  if (!r) return;
  cout << r->key << endl; // preorder the root first
  preorder(r->left); // preorder left sub tree
  preorder(r->right); // whole right sub tree is preordered
}

void inorder(node *r) {
  if (!r) return;
  inorder(r->left); // inorder left sub tree
  cout << r->key << " "; // inorder the root first
  inorder(r->right); // whole right sub tree is 
}
void postorder(node *r) {
  if (!r) return;
  postorder(r->left); // inorder left sub tree
  postorder(r->right); // whole right sub tree is 
  cout << r->key << endl; // inorder the root first
}

// returns the number of nodes in tree r
int count(node *r) {
  if (!r) return 0;
  return count(r->left) + count(r->right) + 1;
}
// reutnrs the hiehgt of the tree r. single node tree height = 0
int height(node *r) {
  if (!r) return -1;
  return max(height(r->left),height(r->right))+1;
}

// insert k into bst at root r, and return the root of the tree after the insertion
// worst case: O(h), if tree is balanced or close to balanced O(logn)
node* insert(int k, node* r) {
  // base
  if (!r) return new node(k);
  if (r->key < k) r->right =insert(k,r->right);
  else if (r->key > k) r->left = insert(k,r->left);
  return r;
}

int maximum(node *r) {
  while (r->right) r = r->right;
  return r->key;
}

// O(h). If quite balanced O(logn)
node* erase(int k, node* r) {
  if (!r) return NULL;
  if (r->key < k) r->right = erase(k,r->right);
  else if (r->key > k) r->left = erase(k,r->left);
  else {
    if (!r->left && !r->right) { delete r; return NULL; }
    else if (!r->left) { node *p = r->right; delete r; return p; }
    else if (!r->right) { node *p = r->left; delete r; return p; }
    else { // r has 2 children
      int v = maximum(r->left);
      r->key = v;
      r->left = erase(v,r->left);
    }
  }
  return r;
}

int main() {
  node* root = NULL;
  root = insert(10,root);
  root = insert(6,root); 
  root = insert(20,root); 
  root = insert(16,root); 
  root = insert(24,root); 
  root = insert(23,root); 
  root = insert(8,root); 
  root = insert(7,root); 
  root = insert(3,root); 
  root = insert(5,root); 
  inorder(root); cout << endl;
  root = erase(10, root);
  inorder(root); cout << endl;
  return 0;
}