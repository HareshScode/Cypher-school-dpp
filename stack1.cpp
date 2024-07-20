#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
bool check(string &s)
{
    string str = s;
    stack<char> temp;
    for (auto &i : s)
    {
        temp.push(i);
    }
    string flag;
    while (!temp.empty())
    {
        flag += temp.top();
        temp.pop();
    }
    if (flag == str)
        return true;
    return false;
}
int main()
{
    int t = 0;
    cin >> t;
    if (t <= 0)
    {
        cout << "Invalid Input";
        return 0;
    }
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        if (check(s))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
