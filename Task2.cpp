#include<bits/stdc++.h>
using namespace std;

enum etype{laborer,secretary,manager,accountant,executive,researcher};

int main(){
    etype first;
    cout<<"Enter first letter of your employee type:"<<endl;
    char ch;
    cin>> ch;
    switch (ch)
    {
    case 'l':
        first=laborer;
        break;
    case 's':
        first=secretary;
        break;
    case 'm':
        first=manager;
        break;
    case 'a':
        first=accountant;
        break;
    case 'e':
        first=executive;
        break;
    case 'r':
        first=researcher;
        break;        
    default: cout<<"Invalid employee type"<<endl;
        break;
    }

    switch (first)
    {
    case laborer:
        cout<<"Employee type is laborer"<<endl;
        break;
    case secretary:
        cout<<"Employee type is secretary"<<endl;
        break;
    case manager:
        cout<<"Employee type is manager"<<endl;
        break;

    case accountant:
        cout<<"Employee type is accountant"<<endl;
        break; 
        
    case executive:
        cout<<"Employee type is executive"<<endl;
        break; 

    case researcher:
        cout<<"Employee type is researcher"<<endl; 
    }

}