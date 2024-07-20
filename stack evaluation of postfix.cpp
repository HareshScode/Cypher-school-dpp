#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <stack>
#include <string>
using namespace std;

bool isnumber(string s)
{
    for (auto ch: s)
    {
        if (!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string c{};
    stack <string> s;
    while(cin >> c)
    {
        if (isnumber(c))
        {
            s.push(c);
        }
        else if(c == "+")
        {
            if (s.empty())
            {
                cout << "Invalid Input";
                return 0;
            }
            int a = stoi(s.top());
            s.pop();
            if (s.empty())
            {
                cout << "Invalid Input";
                return 0;
            }
            int b = stoi(s.top());
            s.pop();
            s.push(to_string(a + b));
        }
        else if(c == "-")
        {
            if (s.empty())
            {
                cout << "Invalid Input";
                return 0;
            }
            int a = stoi(s.top());
            s.pop();
            if (s.empty())
            {
                cout << "Invalid Input";
                return 0;
            }
            int b = stoi(s.top());
            s.pop();
            s.push(to_string(b - a));
        }
        else if(c == "*")
        {
            if (s.empty())
            {
                cout << "Invalid Input";
                return 0;
            }
            int a = stoi(s.top());
            s.pop();
            if (s.empty())
            {
                cout << "Invalid Input";
                return 0;
            }
            int b = stoi(s.top());
            s.pop();
            s.push(to_string(a * b));
        }
        else if(c == "/")
        {
            if (s.empty())
            {
                cout << "Invalid Input";
                return 0;
            }
            float a = stof(s.top());
            s.pop();
            if (s.empty())
            {
                cout << "Invalid Input";
                return 0;
            }
            float b = stof(s.top());
            s.pop();
            s.push(to_string(b / a));
        }
    }
    cout << s.top();
    s.pop();
    return 0;
}
