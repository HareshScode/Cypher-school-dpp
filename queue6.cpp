#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    if(k==1){
        cout<<"1";
    }
    else{
        queue<int> q;
        for(int i=0;i<n;i++){
            int e;
            cin>>e;
            q.push(e);
        }
        int max=0,min=100000000;
        while(!q.empty()){
            if(max<q.front()){
                max=q.front();
            }
            if(min>q.front()){
                min=q.front();
            }
        q.pop();
        }
        int f=max-min+1;
        cout<<f;
    }
    return 0;
}
