#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isBalanced(string s) {
    unordered_map <char, char> hash;
    hash['['] = '.';
    hash['('] = '.';
    hash['{'] = '.';
    hash[']'] = '[';
    hash[')'] = '(';
    hash['}'] = '{';
    int l = s.length();
    if (l % 2 != 0)
    {
        return "NO";
    }
    stack <char> st;
    st.push('0');
    for (int i = 0; i < l; i++)
    {
        if (st.top() == hash[s[i]])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    st.pop();
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() 
{
    string a{};
    cin >> a;
    if (isBalanced(a))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }
    return 0;
}
