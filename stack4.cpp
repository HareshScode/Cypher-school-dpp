#include<iostream>
#include<stack>
using namespace std;

//top to bottom
void PrintStack(stack<string> s)
{
    if(s.empty())
    {
        return;
    }
    string x = s.top();
    s.pop();
    cout <<x<<" ";
    PrintStack(s);
    s.push(x);
}

int main()
{
    stack <string> s;
    string x;
    int c1,c2;
    while(c1!=2)
    {
        cin>>c1;
        if(c1==1)
        {
            cin>>c2;
            for(int i=0;i<c2;i++)
            {
                cin>>x;
                s.push(x);
            }
        }
    }
    cout<<s.top()<<endl;
    s.pop();
    PrintStack(s);
    return 0;
}
