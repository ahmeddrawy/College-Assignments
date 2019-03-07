#include "Matrix.h"
#include <bits/stdc++.h>
using namespace std;
template  <class  T>
Matrix<T> ::Matrix() {
    row = 0 , column = 0;
    ptrMatrix = NULL;
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
Matrix<T>  Matrix<T>:: operator=(const Matrix<T> &obj ){
    this->row = obj.row ;

    this->column = obj.column ;
    if(this->ptrMatrix !=NULL) {
        for (int (i) = 0; (i) < this->row; ++(i)) {
            delete[] this->ptrMatrix[i];
        }

        delete[] this->ptrMatrix;
        this->ptrMatrix = 0;
    }
    this->ptrMatrix = 0 ;
    this->ptrMatrix = new T*[this->row];
    for(int i = 0 ; i < this->row ;++i )
        this->ptrMatrix[i] = new T[this->column];
    for(int i = 0 ; i < this->row ; ++i) {
        for (int j = 0; j < this->column; ++j) {
            this->ptrMatrix[i][j] = obj.ptrMatrix[i][j];
        }
    }
    return  *this;
}
template  <class  T>
Matrix<T>  ::Matrix(const Matrix<T> &obj){    /// todo
    this->row    = obj.row;
    this->column = obj.column;
    this->ptrMatrix = new T*[row];
    for(int i = 0 ; i < row ;++i )
        this->ptrMatrix[i] = new T[column];
    for(int i = 0 ; i < row ; ++i) {
        for (int j = 0; j < column; ++j) {
            this->ptrMatrix[i][j] = obj.ptrMatrix[i][j];
        }
    }

}
template  <class  T>
Matrix<T>  Matrix<T>:: operator+(Matrix<T> obj){         /// done with the matrices with the same data type
    assert(this->row == obj.row || this->column ==  obj.column   ) ;
    for(int i = 0 ; i< this->row     ; ++i){
        for(int j = 0 ; j< this-> column     ; ++j) {
            this->ptrMatrix[i][j] +=obj.ptrMatrix[i][j];
        }
    }
    return *this;
    
}
template  <class  T>
Matrix<T>  Matrix<T> :: operator-(Matrix<T> obj){         /// done with the matrices with the same data type
    assert(this->row == obj.row || this->column ==  obj.column   ) ;
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
Matrix <T>  Matrix<T> :: operator * (Matrix<T> &obj){ ///todo
    assert(this->column ==obj.row);
    /*{
        cout<<"Can't Multiply two matrices the column of the first not equal the row of the second\n";
        return  *this;
    }*/
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
    T ** temp =this-> ptrMatrix;
    ptrMatrix = Nptr;
    this->row = Nr;
    this->column = Nc;
    Matrix <T> mat = *this;

    this->ptrMatrix =temp  ;
    this->row = Nc;
    this->column = Nr;
    return mat;
}
template class Matrix<int>;
template class Matrix<double>;
template class Matrix<float>;
template class Matrix<long>;
template class Matrix<long long>;
template class Matrix<short>;

