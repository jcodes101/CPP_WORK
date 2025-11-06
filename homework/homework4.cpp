#include <cstddef>
#include <stack>
#include <string>
using namespace std;


class tree_node { 
public: 
    int data; 
    tree_node *left, *right; 
    tree_node(){
        data = 0; left = NULL; right = NULL;
    }
    tree_node(int d,tree_node *l=NULL, tree_node *r=NULL){
        data = d; left = l; right = r;
    } 
};

tree_node* two_ptr(int left, int right){
    if (left > right) 
        return NULL;
    
    // make root first
    int mid = (left + right) / 2;
    tree_node* root = new tree_node(mid);

    root->left = two_ptr(left, mid - 1);
    root->right = two_ptr(mid + 1 , right);

    return root;
}

tree_node* build_balanced(int n){
   tree_node* root = two_ptr(1, n);
   return root;
}


tree_node* remove_greater(int k,tree_node* r){
    if (!r) return NULL;

    r->right = remove_greater(k, r->right);

    r->left = remove_greater(k, r->left);

    if (r->data >= k){
        tree_node* temp = r->left;
        delete r;
        return temp;
    }

    return r;
}


int postfix(const string& s){
    stack<int> st;

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '+'){
            // get top 2 ints and do operation
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();

            st.push(first + second);
        }
        else if (s[i] == '*'){
            // get top 2 ints and do operation
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();

            st.push(first * second);
        }else{
            st.push(s[i] - '0'); // add int to stack
        }

    }
    return st.top();
}