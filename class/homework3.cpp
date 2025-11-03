#include <iostream>
using namespace std;

class tree_node
{
public:
    int data;
    tree_node *left, *right;
    tree_node(int d, tree_node *l = NULL, tree_node *r = NULL)
    {
        data = d;
        left = l;
        right = r;
    }
};

/*
    the purpose of this function is to return the sum of all leaf nodes'
    (val or data) values. a leaf is a node with no children (both L and R are NULL)
*/
int sumleaves(tree_node *r)
{
    if (r == NULL)
        return 0;

    if (r->left == NULL && r->right == NULL)
    {
        return r->data;
    }
    else
    {
        return sumleaves(r->left) + sumleaves(r->right);
    }
}

/*
    this function returns the depth of a tree node with value -1 in a tree with root r.
    this tree contains exactly one -1. Your goal is to figure out the depth of the tree node that contains -1.
*/
int depthnegative1(tree_node *r)
{
    if (r == NULL)
        return -1;

    if (r->data == -1)
        return 0;

    int left_depth = depthnegative1(r->left);
    int right_depth = depthnegative1(r->right);

    if (left_depth != -1)
        return left_depth + 1;

    if (right_depth != -1)
        return right_depth + 1;

    // if (right_depth == -1 && left_depth == -1)
    return -1;
}

// int main()
// {
//     // Example tree:
//     //       5
//     //      / \
//     //     7  -1

//     tree_node *root = new tree_node(5, new tree_node(7), new tree_node(-1));

//     // expected 6 (7 + -1)
//     cout << "sum of all leaves: " << sumleaves(root) << endl;

//     // expected 1
//     cout << "depth of -1: " << depthnegative1(root) << endl;

//     return 0;
// }