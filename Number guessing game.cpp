#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
int main() {
    

    cout<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Number__Guessing__Game-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;

    
    srand(time(0));
    int a;
    int p;
    cout<<"Enter 1 For Easy Mode, Enter 2 For Normal Mode and 3 For Hard Mode And Any Other Key To Quit"<<endl;
    cin>>p;
    while(p==1 || p==2 || p==3){
        if(p==1){
            a=rand()%20+1;
            cout<<"You Are Playing Easy Mode, Numbers Range From 1 to 20"<<endl;
        }
        else if(p==2){
            a=rand()%100+1;
            cout<<"You Are Playing Easy Mode, Numbers Range From 1 to 100"<<endl;
        }
        else{
            a=rand()%1000+1;
            cout<<"You Are Playing Easy Mode, Numbers Range From 1 to 1000"<<endl;
        }
        
        int n;
        cout<<"Choose a Number: ";cin>>n;
    
        while(n!=a){
            if(n<a){
                cout<<"Your Guess Is Low:"<<endl;
            }
            else{
                cout<<"Your Guess Is High:"<<endl;
            }
            cout<<"Choose Again:";
            cin>>n;
        }
        cout<<"You Got It, Number Is : "<<a<<endl;
        
        cout<<"Enter 1 For Easy Mode,2 For Normal Mode and 3 For Hard Mode And Any Other Key To Quit"<<endl;
        cin>>p;
    }
    
    return 0;
}