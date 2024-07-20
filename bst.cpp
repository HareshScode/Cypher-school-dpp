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
    friend class BST;
    
    public:
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
    public:
    Node *root;
    
    BST()
    {
        root = NULL;
    }
    
    Node *insert(Node *p, int value)
    {
        if (p == NULL)
        {
            Node *nd = new Node(value);
            return nd;
        }
        if (value < p->data)
        {
            p->left = insert(p->left, value);
        }
        else if(value > p->data)
        {
            p->right = insert(p->right, value);
        }
        return p;
    }
    
    int height(Node *p, int value)
    {
        if (value == p->data)
        {
            return 0;
        }
        if (value < p->data)
        {
            return 1 + height(p->left, value);
        }
        else
        {
            return 1 + height(p->right, value);
        }
    }
    
    int solve(Node *p, int a, int b)
    {
        if (p == NULL)
        {
            return 0;
        }
        if (p->data > a && p->data > b)
        {
            return solve(root->left, a, b);
        }
        else if(p->data < b && p->data < a)
        {
            return solve(p->right, a, b);
        }
        else if ((p->data >= a && p->data <= b) || (p->data <= a && p->data >= b))
        {
            return height(p, a) + height(p, b);
        }
        return 0;
    }
    
    int get_data()
    {
        return root->data;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n{};
    cin >> n;
    BST o;
    for (int i = 0; i < n; i++)
    {
        int value{};
        cin >> value;
        
        o.root = o.insert(o.root, value);
    }
    int a{}, b{};
    cin >> a >> b;
    cout << o.solve(o.root, a, b);
    return 0;
}
