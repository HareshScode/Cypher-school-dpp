#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n1,n2=0;
    cin>>n1;
    int arr1[n1];
    if(n1<=20 && n1>0){
        for(int i=0;i<n1;i++){
            if(i==0){
                cin>>arr1[0];
                continue;
               }
            cin>>arr1[i];
            if(arr1[i]>arr1[i-1]){
                    cout<<"Incorrect Array Elements";
                    break;
               }
            }       
         }
    else{
        cout<<"Invalid Array";
      }
    
    cin>>n2;
    int arr2[n2];
    if(n1!=n2){
           if(n2<=20 && n2>0){
                for(int i=0;i<n2;i++){
                    if(i==0){
                        cin>>arr2[0];
                        continue;
                    }
                    cin>>arr2[i];
                    if(arr2[i]>arr2[i-1]){
                          cout<<"Incorrect Array Elements";
                          break;
                        }
                   }     
        
               }
    else{
        cout<<"Invalid Array";
      }
     }
    else{
        cout<<"Invalid Array";
    }
    
int merge[n1+n2];
    for(int i=0;i<n1;i++){
        merge[i]=arr1[i];
    }
    for(int i=n1;i<(n1+n2);i++){
        merge[i]=arr2[i];
    }
    for(int i=0;i<n1+n2;i++){
        cout<<merge[i];
    }
    
    return 0;
}
