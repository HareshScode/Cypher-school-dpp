#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    node *right = NULL;
    node *left = NULL;
    int data;
};

node *root = NULL;

void print(node *root){
    if(root == NULL){
        return;
    }
    print(root->left);
    if(!(root->right == NULL && root->left == NULL)){
        cout << root->data << " ";
    }
    print(root->right);
}

void insert(int item)
{
    struct node *ptr, *par, *n;
    ptr = new node;
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        ptr->data = item;
        ptr->left = NULL;
        ptr->right = NULL;
        if (root == NULL)
        {
            root = ptr;
            root->left = NULL;
            root->right = NULL;
        }
        else
        {
            par = NULL;
            n = root;
            while (n != NULL)
            {
                par = n;
                if (item < n->data)
                {
                    n = n->left;
                }
                else if (item > n->data)
                {
                    n = n->right;
                }
                else
                {
                    return;
                }
            }
            if (item < par->data)
            {
                par->left = ptr;
            }
            else
            {
                par->right = ptr;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    // if(n <= 0){
    //     return 0;
    // }
    
    for(int i = 0; i < n;i++){
        int x;
        cin >> x;
        insert(x);
    }
    print(root);
    return 0;
}
