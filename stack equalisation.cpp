#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int m(int a, int b, int c)
{
    if (a > b && a > c)
    {
        return a;
    }
    else if(b > c)
    {
        return b;
    }
    else
    {
        return c;
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a{}, b{}, c{};
    cin >> a >> b >> c;
    
    queue <int> q1;
    queue <int> q2;
    queue <int> q3;
    int s1{}, s2{}, s3{};
    
    int value{};
    for (int i = 0; i < a; i++)
    {
        cin >> value;
        s1 += value;
        q1.push(value);
    }
    
    for (int i = 0; i < b; i++)
    {
        cin >> value;
        s2 += value;
        q2.push(value);
    }
    
    for (int i = 0; i < c; i++)
    {
        cin >> value;
        s3 += value;
        q3.push(value);
    }
    
    while (!(s1 == s2 && s2 == s3))
    {
        int max = m(s1, s2, s3);
        if (s1 == max)
        {
            s1 -= q1.front();
            q1.pop();
        }
        else if(s2 == max)
        {
            s2 -= q2.front();
            q2.pop();
        }
        else
        {
            s3 -= q3.front();
            q3.pop();
        }
    }
    cout << s1;
    return 0;
}
