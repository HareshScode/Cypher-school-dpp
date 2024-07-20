#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *root=NULL;

void insert_bst(node *nd){
    if(root==NULL){
        root=nd;
    }else{
        node *ptr=root;
        node *pre=NULL;
        while(ptr!=NULL){
            pre=ptr;
            if(nd->data > ptr->data){
                ptr=ptr->right;
            }else{
                ptr=ptr->left;
            }
        }
        if(nd->data > pre->data){
            pre->right=nd;
        }else{
            pre->left=nd;
        }
    }
}

void print_leaf(node *temp){
    if(temp==NULL){
        return;
    }
    if (temp->left==NULL && temp->right==NULL) {
        cout << temp->data << " ";
        return;
    }
    if (temp->right){
        print_leaf(temp->right);
    }
    if (temp->left){
        print_leaf(temp->left);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    while(n--){
        node *nd=new node;
        cin>>nd->data;
        nd->right=NULL;
        nd->left=NULL;
        insert_bst(nd);
    }
    print_leaf(root);
    return 0;
}
