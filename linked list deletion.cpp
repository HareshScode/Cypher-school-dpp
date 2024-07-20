#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int data;
    node *next;
};

node *start=NULL;

void insert_end(){
    node *nd=new node;
    cin>>nd->data;
    nd->next=NULL;
    if(start==NULL){
        start=nd;
    }else{
        node *ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=nd;
    }
}

int find_max(){
    node *ptr=start;
    int max=-1;
    while(ptr!=NULL){
        if(ptr->data > max){
            max=ptr->data;
        }
        ptr=ptr->next;
    }
    return max;
}

void delete_max(){
    int max=find_max();
    node *ptr=start;
    node *pre=NULL;
    if(start->data==max){
        start=start->next;
    }else{
        while(ptr!=NULL && ptr->data!=max){
            pre=ptr;
            ptr=ptr->next;
        }
        pre->next=ptr->next;
    }
}

void display(){
    node *ptr=start;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    while(n--){
        insert_end();
    }
    delete_max();
    display();
    return 0;
}
