//
// Created by ahmed on 3/2/2019.
//
#include <bits/stdc++.h>
using namespace std;
#ifndef ASSIGNMENT_1_MATRIX_H
#define ASSIGNMENT_1_MATRIX_H
template  <typename T>
class Matrix {
private :
    T ** ptrMatrix; /// double pointer to the matrix
    int row ,  column ;
    bool flag ;
    string type ;           /// redunant for now

public:
    Matrix();
    Matrix(int r , int c);          /// done
    
    Matrix(const Matrix  &obj);
    
    Matrix operator+(Matrix<T>& obj);
    Matrix& operator-(Matrix<T>& obj);
    Matrix  operator * (Matrix obj); ///todo
    
    
    friend istream& operator >> (istream & in , Matrix<T> obj  ){    ///  done
        for(int i = 0 ; i<obj.row ; ++i){
            for(int j =0 ; j< obj.column ; ++j){
                cout<<"Enter the cell "<<i<<" "<<j<<"in The Matrix : ";
                in>>obj.ptrMatrix[i][j];
            }
        }
        return in ;
    }
    
    friend ostream &operator <<(ostream &  out , Matrix <T> obj){     /// done
        for(int i = 0 ; i<obj.row ; ++i){
            for(int j =0 ; j< obj.column ; ++j){
                out<<obj.ptrMatrix[i][j]<<" ";
            }
            out<<"\n";
        }
        return out ;
    }
    ~Matrix() {
       for(int i = 0  ; i <this->row ; ++i)
           delete ptrMatrix[i];
        delete []ptrMatrix ;
    };
    
    
    
};


#endif //ASSIGNMENT_1_MATRIX_H
