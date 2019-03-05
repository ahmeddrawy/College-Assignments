//
// Created by ahmed on 3/4/2019.
//
#include <bits/stdc++.h>
#include "Matrix.h"
using namespace std;

#ifndef ASSIGNMENT_1_CALCUALATER_H
#define ASSIGNMENT_1_CALCUALATER_H

class Calcualater{
private:
    int option;
public:
    Calcualater(int _option = -1){
        option = _option;
        this->menu();
    }
    void print(){
        cout<<"Please choose an option \n";
        cout<<"1 - mulftiply 2 matrices\n";
        cout<<"2 - Add 2 matrices\n";
        cout<<"3 - Subtract 2 matrices\n";
        
    }
    void menu() {
        if (option == -1 ) {
            
            do{
                print();
                cin >> option;
            }
            while(option<0 ||option >5);
            
           
        }
        this->process();
        
    }
    
     void  process (){
         cout << "please input  the 2 matrices that you want to process \n";
         cout << "Please enter the Row and column of the first Matrix  : ";
         int r, c;
         cin >> r >> c;
         Matrix<int> mat1(r, c);
         cin>>mat1;
         cout << "Please enter the Row and column of the Second Matrix  : ";
         cin >> r >> c;
         Matrix<int> mat2(r, c);
         cin>>mat2;
        switch (option) {
            case 1:
                cout << mat1 * mat2;
                break;
            case 2:
                
                cout << mat1 + mat2;
                break;
            case 3:
                cout<<mat1-mat2;
                break;
            default:
                break;
        }
    }
    
    
    
    
};



#endif //ASSIGNMENT_1_CALCUALATER_H
