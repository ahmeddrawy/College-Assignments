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
    Matrix(){
        ptrMatrix = nullptr;
        flag = 0;
    }
    Matrix(int r , int c){          /// done
        row = r , column = c;
        flag = 1;
        ptrMatrix = new T*[r];
        for(int i = 0 ; i < r ;++i )
            ptrMatrix[i] = new T[c];
    }
    Matrix(Matrix<T>  &obj){    /// todo
        this->row    = obj.row;
        this->column = obj.column;
        this->flag = obj.flag;
        if(this->ptrMatrix != NULL)
            delete [] this->ptrMatrix;
        ptrMatrix = new T*[row];
        for(int i = 0 ; i < row ;++i )
            ptrMatrix[i] = new T[column];
        for(int i = 0 ; i < row ; ++i) {
            for (int j = 0; j < column; ++j) {
                this->ptrMatrix = obj.ptrMatrix[i][j];
            }
        }
        
    }
    
    Matrix operator+(Matrix<T>& obj){         /// done with the matrices with the same data type
        if(this->row != obj.row || this->column !=  obj.column   ) {
            cout << "Can't add two matrices with different sizes\n";
            return *this;
        }
        if(!this->flag || !obj.flag){
            cout<<"Uninitialised matrices\n";
            return *this;
        }
        for(int i = 0 ; i< this->row     ; ++i){
            for(int j = 0 ; j< this-> column     ; ++j) {
                this->ptrMatrix[i][j] +=obj.ptrMatrix[i][j];
            }
        }
        return *this;
        
    }
    Matrix& operator-(Matrix<T>& obj){         /// done with the matrices with the same data type
        if(this->row != obj.row || this->column !=  obj.column   ) {
            cout << "Can't subtract two matrices with different sizes\n";
            return *this;
        }
        if(!this->flag || !obj.flag){
            cout<<"Uninitialised matrices\n";
            return *this;
        }
        for(int i = 0 ; i< this->row     ; ++i){
            for(int j = 0 ; j< this-> column     ; ++j) {
                this->ptrMatrix[i][j] -=obj.ptrMatrix[i][j];
            }
        }
        return *this;
        
    }
    Matrix operator * (Matrix obj){ ///todo
        if(this->column !=obj.row){
            cout<<"Can't Multiply two matrices the column of the first not equal the row of the second\n";
            return  *this;
        }
        Matrix ret(this->row , obj.column);
        for (int i = 0; i < this->row; ++i) {       /// looping over each row in the this matrix
            for (int j = 0; j < obj.column; ++j) {  /// looping over each column in obj matrix for every row in this matrix
                ret.ptrMatrix[i][j]= 0 ;
                for (int k = 0; k < this->column; ++k) {    /// looping over the size of column of this , mat(r,c)*mat(c,y) = mat(r,y) , we loop here for c
                        ret.ptrMatrix[i][j] +=  this->ptrMatrix[i][k] * obj.ptrMatrix[k][j];
                }
            }
        }
        return ret;
        
        
    }
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
        delete []ptrMatrix ;
    };
    
    
    
};


#endif //ASSIGNMENT_1_MATRIX_H
