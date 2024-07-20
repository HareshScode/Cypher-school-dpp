#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

node *start=NULL;
node *last=NULL;

void insert_end(){
    node *nd=new node;
    cin>>nd->data;
    if(start==NULL){
        start=nd;
        last=nd;
        nd->next=NULL;
        nd->prev=NULL;
    }else{
        last->next=nd;
        nd->next=NULL;
        nd->prev=last;
        last=nd;
    }
}

void display(){
    node *ptr=last;
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr=ptr->prev;
    }
}

void delete_sec_last(int n){
    int count=0;
    node *ptr=start;
    node *temp=NULL;
    node *sec_max=NULL;
    while(ptr!=NULL){
        if(ptr->data==n){
            sec_max=temp;
            temp=ptr;
            count++;
        }
        ptr=ptr->next;
    }
    if(count>1){
        sec_max->prev->next=sec_max->next;
        sec_max->next->prev=sec_max->prev;
        display();
    }else{
        cout<<"Deletion not possible";
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    if(n>2 && n<=20){
        while(n--){
            insert_end();
        }
        int m;
        cin>>m;
        delete_sec_last(m);
    }else{
        cout<<"Invalid list size";
    }
    return 0;
}
