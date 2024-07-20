#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int data;
    node *prev;
    node *next;
};
node *start=NULL;
node *last=NULL;

void insert(){
    node *nd=new node;
    cin>>nd->data;
    if(start==NULL || last==NULL){
        nd->next=NULL;
        nd->prev=NULL;
        start=nd;
        last=nd;
    }
    else{
        last->next=nd;
        
        nd->next=NULL;
        nd->prev=last;
        last=nd;
    }
}
void display(){
    node *point=last;
    while(point!=start){
        cout<<point->data<<" ";
        point=point->prev;
    }
    cout<<point->data;
}
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n=0;
        cin>>n;
        for(int j=0;j<n;j++){
            insert();
        }
    }
    display();  
    return 0;
}

