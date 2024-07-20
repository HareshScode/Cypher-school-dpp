#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;
    friend class Dlinked_list;

public:
    Node(int n)
    {
        data = n;
        next = NULL;
        prev = NULL;
    }
};

class Dlinked_list
{
    Node *head;
    Node *tail;

public:
    Dlinked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int value)
    {
        Node *nd = new Node(value);
        if (head == NULL)
        {
            head = nd;
            tail = nd;
        }
        else
        {
            nd->prev = tail;
            tail->next = nd;
            tail = nd;
        }
    }
    
    void traverse()
    {
        Node *p = head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Dlinked_list o;
    for (int i = 0; i < 10; i++)
    {
        int value{};
        cin >> value;
        o.insert(value);
    }
    o.traverse();
    return 0;
}
