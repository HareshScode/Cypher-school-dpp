#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
    char data;
    Node *next;
    friend class Linked_list;

public:
    Node(char value) : data{value}, next{NULL}
    {
    }
};

class Linked_list
{
    Node *head;
    Node *tail;
public:
    Linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_at_end(char value)
    {
        Node *nd = new Node(value);
        if (head == NULL)
        {
            nd->next = NULL;
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
    
    void display()
    {
        Node *p = head;
        while (p != NULL)
        {
            if (p->next != NULL)
            {
               cout << p->data << "-->";
            }
            else
            {
                cout << p->data;
            }
            p = p->next;
        }
    }
    
    bool is_vowel(char value)
    {
        if (value == 'a' || value == 'e' || value == 'i' || value == 'o' || value == 'u')
        {
            return true;
        }
        return false;
    }
    
    bool del_vowels()
    {
        bool present = false;
        Node *p = head;
        if (is_vowel(head->data))
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            while (p->next != NULL)
            {
                if (is_vowel(p->next->data))
                {
                    Node *temp = p->next;
                    p->next = temp->next;
                    delete temp;
                    present = true;
                }
                else
                {
                    p = p->next;
                }
            }
        }
        return present;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Linked_list o;
    while (true)
    {
        char value{};
        cin >> value;
        if (value == '\0')
        {
            break;
        }
        o.insert_at_end(value);
    }
    if (o.del_vowels())
    {
        o.display();
    }
    else
    {
        cout << "No vowel in linked list";
    }
    return 0;
}
