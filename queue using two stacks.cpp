#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Queue
{
    stack <int> s1;
    stack <int> s2;
    
    public:
    void enqueue(int n)
    {
        s1.push(n);
    }
    
    void dequeue()
    {
        if (s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
        else
        {
            s2.pop();
        }
    }
    
    void show_top()
    {
        if (s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            cout << s2.top() << "\n";
        }
        else
        {
            cout << s2.top() << "\n";
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Queue o;
    int n{};
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int op{};
        cin >> op;
        
        if (op == 1)
        {
            int value{};
            cin >> value;
            o.enqueue(value);
        }
        else if(op == 2)
        {
            o.dequeue();
        }
        else
        {
            o.show_top();
        }
    }
    return 0;
}
