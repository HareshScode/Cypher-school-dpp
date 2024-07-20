#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    queue<char> q;
    int count=0;
    for(int i=0;i<10;i++){
        int x;
        char c;
        cin>>x;
        switch(x){
            case 1:
                if(count<=7){
                    cin>>c;
                    q.push(c);
                }else{
                    cout<<"OVERFLOW";
                    exit(0);
                }
                count++;
                break;
            case 2:
                q.pop();
                count--;
                break;
            default:
                cout<<q.front()<<endl;
                char temp='0';
                while(!q.empty()){
                    temp = q.front();
                    q.pop();
                }
                cout<<temp;
                exit(0);
        }
    }
    return 0;
}
