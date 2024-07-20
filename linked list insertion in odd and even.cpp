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
    friend class Linked_list;

public:
    Node(int value) : data{value}, next{NULL}
    {
    }
};

class Linked_list
{
    Node *head;
    int size;

public:
    Linked_list()
    {
        head = NULL;
        size = 0;
    }

    void insert(int value)
    {
        Node *nd = new Node(value);
        Node *p = head;
        if (head == NULL)
        {
            nd->next = head;
            head = nd;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }

            p->next = nd;
        }
    }
    
    void display()
    {
        Node *p = head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    
    bool solve(int value)
    {
        Node *nd = new Node(value);
        Node *p = head;
        if (value % 2 == 0)
        {
            if (head->data == value)
            {
                cout << "Duplicates are not allowed";
                return false;
            }
            else if (head->data % 2 == 0 && head->data < value)
            {
                nd->next = head;
                head = nd;
            }
            else if (p->next == NULL)
            {
                nd->next = NULL;
                p->next = nd;
            }
            else
            {
                while (p->next != NULL && p->next->data % 2 != 0)
                {
                    p = p->next;
                }
                while (p->next != NULL && p->next->data > value)
                {
                    p = p->next;
                }
                if (p->next != NULL && p->next->data == value)
                {
                    cout << "Duplicates are not allowed";
                    return false;
                }
                else
                {
                    nd->next = p->next;
                    p->next = nd;
                }
            }
        }
        else
        {
            if (head->data == value)
            {
                cout << "Duplicates are not allowed";
                return false;
            }
            else if (head->data % 2 == 0 || head->data > value)
            {
                nd->next = head;
                head = nd;
            }
            else
            {
                while(p->next != NULL && (p->next->data % 2 != 0 && p->next->data < value))
                {
                    p = p->next;
                }
                nd->next = p->next;
                p->next = nd;
            }
        }
        return true;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n{};
    cin >> n;
    Linked_list o;
    for (int i = 0; i < n; i++)
    {
        int value{};
        cin >> value;
        o.insert(value);
    }
    
    int in{};
    cin >> in;
    if (o.solve(in))
    {
       o.display();
    }
    return 0;
}
