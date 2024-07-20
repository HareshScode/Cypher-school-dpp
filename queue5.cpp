#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int x;
    int data;
    queue<int>q;
    while(n)
    {
        cin>>x;
        if(x==1)
        {   
            cin>>data;
            q.push(data);
            n--;

        }
        else
        {   
            cout<<q.front()<<" ";
            q.pop();
            n--;
        }
    }
}
