#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    stack <string> s;
    int n{};
    cin >> n;
    
    if (n > 6)
    {
        cout << "Full Box";
        return 0;
    }
    if (n == 0)
    {
        cout << "Empty Box";
        return 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        string st{};
        cin >> st;
        s.push(st);
    }
    
    int count = 0;
    while (!s.empty())
    {
        count++;
        if (count == n)
        {
            cout << s.top();
        }
        else
        {
            cout << s.top() << "->";
        }
        s.pop();
    }
    return 0;
}
