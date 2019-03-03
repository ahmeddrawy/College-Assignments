#include "Matrix.h"
#include <bits/stdc++.h>
using namespace std;
template  <class  T>
Matrix<T> ::Matrix() {
    ptrMatrix = nullptr;
    flag = 0;
}
template  <class  T>
Matrix<T> ::Matrix(int r , int c){          /// done
    row = r , column = c;
    flag = 1;
    ptrMatrix = new T*[r];
    for(int i = 0 ; i < r ;++i )
        ptrMatrix[i] = new T[c];
}
template  <class  T>
Matrix<T>  ::Matrix(const Matrix &obj){    /// todo
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
            this->ptrMatrix[i][j] = obj.ptrMatrix[i][j];
        }
    }
    
}
template  <class  T>
Matrix<T>  Matrix<T>:: operator+(Matrix<T> obj){         /// done with the matrices with the same data type
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
template  <class  T>
Matrix<T>  Matrix<T> :: operator-(Matrix<T> obj){         /// done with the matrices with the same data type
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
template  <class  T>
Matrix <T>  Matrix<T> :: operator * (Matrix<T> obj){ ///todo
    if(this->column !=obj.row){
        cout<<"Can't Multiply two matrices the column of the first not equal the row of the second\n";
        return  *this;
    }
    Matrix<T> ret(this->row , obj.column);
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
template<class T>
Matrix <T> Matrix <T> ::transpose() {
    int Nr = this->column ;
    int Nc = this->row ;
    T ** Nptr = new T*[Nr];
    for(int i = 0 ; i < Nr ; ++i )
        Nptr[i] = new T[Nc];
    for(int i = 0 ; i <row ; ++i){
        for (int j = 0; j < column; ++j) {
            Nptr[j][i] = ptrMatrix[i][j];
        }
    }
    delete []ptrMatrix ;
    ptrMatrix = Nptr;
    this->row = Nr;
    this->column = Nc;
    return *this;
}
template class Matrix<int>;
template class Matrix<double>;
template class Matrix<float>;
template class Matrix<long>;
template class Matrix<long long>;
template class Matrix<short>;

