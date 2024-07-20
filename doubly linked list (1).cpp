#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *start=NULL;

void insert(){
    Node *nd=new Node;
    cin>>nd->data;
    if(start==NULL){
        nd->next=NULL;
        start=nd;
    }
    else{
        Node *ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        nd->next=NULL;
        ptr->next=nd;
    }
}
void display(){
    Node *point=start;
    while(point!=NULL){
        cout<<point->data<<" ";
        point=point->next;
    }
}
int main() {
    int n,pos;
    cin>>n;
    if(n>=0 &&n<=1000){
       for(int i=0;i<n;i++){
           insert();
       }
       cin>>pos;
       if(pos<0 &&pos>1000){
           cout<<"Invalid Position";
       }
       else{
           Node *ptr1=start;
           Node *prev=NULL;
           if(pos==0){
               start=ptr1->next;
               cout<<"SLL is empty";
           }
           else{
               for(int i=0;i<pos;i++){
                   prev=ptr1;
                   ptr1=ptr1->next;
               }
               prev->next=ptr1->next;
           }
           
           
       }
     display();
    } 
    return 0;
}

