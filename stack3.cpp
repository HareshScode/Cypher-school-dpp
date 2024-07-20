#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Stack
{
    queue <int> q1;
    queue <int> q2;
    int size;
    
    public:
    Stack()
    {
        size = 0;
    }
    void in(int n)
    {
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(n);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        size++;
    }
    
    void out()
    {
        q1.pop();
        size--;
    }
    
    int show_top()
    {
        return q1.front();
    }
    
    bool is_empty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Stack o;
    stack <int> s;
    while (true)
    {
        int n{};
        cin >> n;
        if (n == 3)
        {
            if (o.is_empty())
            {
                cout << -1;
                break;
            }
            while(!o.is_empty())
            {
                s.push(o.show_top());
                o.out();
            }
            while(!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
            break;
        }
        else if (n == 1)
        {
            int value{};
            cin >> value;
            o.in(value);
        }
        else
        {
            o.out();
        }
    }
    return 0;
}
