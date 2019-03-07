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
    vector<Matrix<int> > mMat;
    int sz ;
public:
    Calcualater(){
        cout << "enter the number of matrices you want to perform operations on : ";
        int _sz;
        cin >> _sz;
        this->sz = _sz;
        for (int i = 0; i < sz; ++i) {
            Matrix<int> m;
            cin >> m;
            this->mMat.push_back(m);

        }
        PROCESS();
    }
    void printMATRICES (){
        for (int i = 0; i <sz ; ++i) {
            cout<<"Matrix number :  "<<i+1<<"\n"<<mMat[i]<<endl;
        }
    }
    int printMenu(){
        cout<<"Please choose an option \n";
        cout<<"1 - multiply 2 matrices\n";
        cout<<"2 - Add 2 matrices\n";
        cout<<"3 - Subtract 2 matrices\n";
        cout<<"4 - transpose a matrix\n";
        cout<<"5 - perform another operation \n";
        cout<<"6 - insert new matrix\n";
        cout<<"7 - print the Matrices in the Memory \n";
        cout<<"0 - Exit\n";
        int option;
        do {
            cin >> option;
        } while (option < 0 || option > 7);
        return option;

    }
    void insertMat(){
        Matrix <int > m ;
        cin>>m;
        this->mMat.push_back(m);
        this->sz++;
    }
    void PROCESS() {
        int option = 10 ;

        while (option != 0 ){
            option = printMenu();
            if(option == 0)break;

            int fst= 0  , scd= 0  ;

            do {
                printMATRICES();
                if(option == 7 || option == 6){
                    continue;
                }
                cout << "Please choose the  matrix or matrices  you want to perform operations on \n";
                cout << "Note that the result will be saved by default and you can use later\n";


                cin >> fst;

                if (option != 4) {
                    if (this->sz > 1)
                        cin >> scd;
                    else {
                        cout<<"Can't perform operations on 2 matrices and the available is 1 matrix only press Y to insert another matrix\n";
                        char c ;cin>>c;
                        if(c== 'y'||c == 'Y'){
                            this->insertMat();
                        }
                    }
                }
            }while(fst<0 ||fst > this->sz || scd <0 ||scd>this->sz);

            --fst , --scd;
            Matrix <int>ret ;
            switch (option) {
                case 1:
                    ret = this->mMat[fst] * this->mMat[scd];
                    cout<<ret<<endl;
                    this->mMat.push_back(ret);
                    this->sz++;
//                    option = printMenu();
                    break;
                case 2:
                    ret = this->mMat[fst] + this->mMat[scd];
                    cout<<ret<<endl;
                    this->mMat.push_back(ret);
                    this->sz++;
//                    option = printMenu();
                    break;
                case 3:
                    ret = this->mMat[fst] - this->mMat[scd];
                    cout<<ret<<endl;
                    this->mMat.push_back(ret);
                    this->sz++;
                    break;
                case 4:
                    ret = this->mMat[fst].transpose();
                    cout<<ret;
                    this->mMat.push_back(ret);
                    this->sz++;
                    break;
                case 5:
                    option = printMenu();
                    break;
                case 6:
                    this->insertMat();
                    break;

                default:
                    break;
            }
        }
        
        
    }
    
    
    
    
};



#endif //ASSIGNMENT_1_CALCUALATER_H
