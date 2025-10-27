#include <iostream>
// allows for use of anything that is waiting (first come, first serve)
#include <queue>
using namespace std;

/*
    ea. node box has a...n
    number in it (data)
    and a (left) arm and (right) arm
*/
class node
{
public:
    int data;
    node *left, *right;

    // makes an empty box
    node()
    {
        data = 0;
        left = right = NULL;
    }

    // makes a box with a number and no arms
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }

    // makes a box with a number and connects two samller boxes
    node(int data, node *left, node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

/*
    this function reads in a tree line by line
*/
void levelorder(node *r)
{
    queue<node *> Q;
    Q.push(r);
    while (!Q.empty())
    {
        node *temp = Q.front();
        Q.pop();
        cout << temp->data << " ";
        if (temp->left)
            Q.push(temp->left);
        if (temp->right)
            Q.push(temp->right);
    }
    cout << endl;
}

// preorders the values in tree starting from r
void preorder(node *r)
{
    if (!r)
        return;
    cout << r->data << endl; // preorder the root first
    preorder(r->left);       // preorder left sub tree
    preorder(r->right);      // whole right sub tree is preordered
}

void inorder(node *r)
{
    if (!r)
        return;
    inorder(r->left);        // inorder left sub tree
    cout << r->data << endl; // inorder the root first
    inorder(r->right);       // whole right sub tree is
}

void postorder(node *r)
{
    if (!r)
        return;
    postorder(r->left);      // inorder left sub tree
    postorder(r->right);     // whole right sub tree is
    cout << r->data << endl; // inorder the root first
}

// returns the number of nodes in tree r
int count(node *r)
{
    if (!r)
        return 0;
    return count(r->left) + count(r->right) + 1;
}

// return the sum of the whole tree r
int sum(node *r)
{
    if (!r)
        return 0;
    return sum(r->left) + sum(r->right) + r->data;
}

// reutnrs the maximum value in tree r
int maxv(node *r)
{
    if (!r)
        return INT_MIN;
    return max(max(maxv(r->left), maxv(r->right)), r->data);
}

// reutnrs the hiehgt of the tree r. single node tree height = 0
int height(node *r)
{
    if (!r)
        return -1;
    return max(height(r->left), height(r->right)) + 1;
}

/*
         5
       /   \
      6     3
     / \     \
   11  20     10
              /
             7

*/
int main()
{
    node *root = new node(5);
    root->left = new node(6, new node(11), new node(20));
    root->right = new node(3, NULL, new node(10, new node(7), NULL));
    postorder(root);

    // how many boxes total
    cout << "count=" << count(root) << endl;

    // add all the numbers together
    cout << "sum=" << sum(root) << endl;

    // biggest number in the tree
    cout << "max=" << maxv(root) << endl;

    // how many levels to the tree is there
    cout << "height=" << height(root) << endl;
    cout << "level order: ";
    levelorder(root);
    return 0;
}