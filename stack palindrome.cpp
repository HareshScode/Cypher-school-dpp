#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    string str;
    stack <char> s1,s2;
    cin>>str;
    int a=str.length();
    for(int i=0;i<a;i++){
        s1.push(str[i]);
    }
    for(int j=0;j<a;j++){
        char c=s1.top();
        s1.pop();
        if(c!=str[j]){
            cout<<"Not Palindrome";
            exit(0);
        }
    }
    cout<<"Palindrome";
    return 0;
}
