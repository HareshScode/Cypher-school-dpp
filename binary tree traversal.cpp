#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;
    friend class Tree;
    
    public:
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
    public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    
    Node *construct(vector <int> in, vector <int> post)
    {
        int s = in.size();
        if (s == 0)
        {
            return NULL;
        }
        Node *nd = new Node(post[s - 1]);
        if (s == 1)
        {
            return nd;
        }
        int r_ind{};
        for (int i = 0; i < s; i++)
        {
            if (in[i] == nd->data)
            {
                r_ind = i;
                break;
            }
        }
        
        int right_sub = s - r_ind - 1;
        int left_sub = s - right_sub - 1;
        
        vector <int> in_left;
        vector <int> in_right;
        vector <int> post_left;
        vector <int> post_right;
        
        for (int i = 0; i < left_sub; i++)
        {
            in_left.push_back(in[i]);
            post_left.push_back(post[i]);
        }
        for (int i = r_ind + 1; i < r_ind + 1 + right_sub; i++)
        {
            in_right.push_back(in[i]);
        }
        for (int i = left_sub; i < left_sub + right_sub; i++)
        {
            post_right.push_back(post[i]);
        }
        
        nd->left = construct(in_left, post_left);
        nd->right = construct(in_right, post_right);
        return nd;
    }
    
    void preorder(Node *p)
    {
        if(p == NULL)
        {
            return;
        }
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n{};
    vector <int> v, v1, v2;
    while (cin >> n)
    {
        v.push_back(n);
    }
    int s = v.size();
    if (s / 2 < 3 || s / 2 >10)
    {
        cout << "Invalid input";
        return 0;
    }
    

    for (int i = 0; i < s; i++)
    {
        if (i < s / 2)
        {
            v1.push_back(v[i]);
        }
        else
        {
            v2.push_back(v[i]);
        }
    }
    
    Tree o;
    o.root = o.construct(v1, v2);
    o.preorder(o.root);
    return 0;
}
