//
// Created by ahmed on 3/4/2019.
//
#include <bits/stdc++.h>
using namespace std;

#ifndef ASSIGNMENT_1_CALCUALATER_H
#define ASSIGNMENT_1_CALCUALATER_H

class Calualater{
private:
    int option;
public:
    void print(){
        cout<<"Please choose an option \n";
        cout<<"1 - print Matrix \n";
        cout<<"2 - input Matrix \n";
        cout<<"3 - multiply 2 matrices\n";
        cout<<"4 - Add 2 matrices\n";
        cout<<"5 - Subtract 2 matrices\n";
        
        
    }
    void menu() {
        if (option == -1 ) {
            
            do{
                print();
                cin >> option;
            }
            while(option<0 ||option >5);
            
            cout << "please enter an option\n";
    
        }
        
        
        
    }
    
    
    
    
};



#endif //ASSIGNMENT_1_CALCUALATER_H
