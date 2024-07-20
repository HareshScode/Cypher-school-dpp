#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int data;
    node *link;
};
node *start=NULL;

void insert(){
    node *nd=new node;
    cin>>nd->data;
    if(start==NULL){
        nd->link=NULL;
        start=nd;
    }
    else{
        node *ptr=start;
        while(ptr->link!=NULL){
            ptr=ptr->link;
            
        }
        nd->link=NULL;
        ptr->link=nd;
    }
}

void display(){
    node *point=start;
    while(point!=NULL){
        cout<<point->data<<" ";
        point=point->link;
    }
}

void insert1(){
    int n;
    cin>>n;
    node *nd=new node;
    cin>>nd->data;
    node *p=start;
    node *ptr=start;
    p=p->link;
    for(int i=1;i<n-1;i++){
        p=p->link;
        ptr=ptr->link;       
    }
    nd->link=p;
    ptr->link=nd;
}

int main() {
    for(int i=0;i<5;i++){
    insert();
    }
    insert1();
    display();
    
    return 0;
}
