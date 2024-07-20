#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print_term(vector <int> in, vector <int> post)
{
    int s = in.size();
    if(s == 0)
    {
        return;
    }
    int data = post[s - 1];
    if (s == 1)
    {
        cout << in[0] << " ";
        return;
    }
    int r_ind{};
    for (int i = 0; i < s; i++)
    {
        if (in[i] == data)
        {
            r_ind = i;
            break;
        }
    }
    
    int right_sub = s - r_ind - 1;
    int left_sub = s - right_sub - 1;
    
    vector <int> in_left;
    vector <int> in_right;
    vector <int> post_left;
    vector <int> post_right;
    
    for (int i = 0; i < left_sub; i++)
    {
        in_left.push_back(in[i]);
        post_left.push_back(post[i]);
    }
    for (int i = r_ind + 1; i < r_ind + 1 + right_sub; i++)
    {
        in_right.push_back(in[i]);
    }
    for (int i = left_sub; i < left_sub + right_sub; i++)
    {
        post_right.push_back(post[i]);
    }
    
    print_term(in_left, post_left);
    print_term(in_right, post_right);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n{};
    cin >> n;
    
    vector <int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        int value{};
        cin >> value;
        v1.push_back(value);
    }
    
    v2 = v1;
    sort(v2.begin(), v2.end());
    print_term(v2, v1);
    return 0;
}
