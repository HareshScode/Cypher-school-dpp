#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct SLLNode
{
    int data;
    SLLNode* next;
};

SLLNode *head = NULL;
SLLNode *tail = NULL;
    

void insert()
{
    SLLNode *nd = new SLLNode;
    cin >> nd->data;
    if (head == NULL)
    {
        nd->next = head;
        head = nd;
        tail = nd;
    }
    else
    {
        nd->next = NULL;
        tail->next = nd;
        tail = nd;
    }
}

void traverse()
{
    if (head == NULL)
    {
        cout << "SLL is Empty";
        exit(0);
    }
    SLLNode *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void del_at_index(int in)
{
    if (head == NULL)
    {
        cout << "SLL is Empty";
        exit(0);
    }
    SLLNode *p = head;
    for (int i = 0; i < in - 1; i++)
    {
        p = p->next;
    }
    if (p == head)
    {
        head = head->next;
        delete p;
    }
    else
    {
        SLLNode *temp = p->next;
        p->next = temp->next;
        delete temp;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n{};
    cin >> n;
    if (n == 0)
    {
        cout << "SLL is Empty";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        insert();
    }
    
    int index{};
    cin >> index;
    if (index < 0 || index >= n)
    {
        cout << "Invalid Position";
        return 0;
    }
    
    del_at_index(index);
    traverse();
    return 0;
}
