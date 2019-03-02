/*  Author : Ahmed Mohamed Hanafy
 *  ID: 20170357
 *  problem 3 for Assignment 1
 *  Generic  Class Matrix
 *  class Matrix calculator
 *  Date : 01/03/19
 *  version log : v1.0 , 01/03/19 By Hanafy
 *
 *
 */
 /*     TODO
  *     1- COPY CONSTRUCTOR FOR THE GENERIC CLASS
  *
  *
  *
  *
  */


#include <iostream>
#include <bits/stdc++.h>
 using namespace std;

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
    Matrix(Matrix <T> &obj){    /// todo
    
    }
    Matrix& operator+(Matrix& obj){         /// done with the matrices with the same data type
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
    friend istream& operator >> (istream & in , Matrix & obj  ){    ///  done
        for(int i = 0 ; i<obj.row ; ++i){
            for(int j =0 ; j< obj.column ; ++j){
                    cout<<"Enter the cell "<<i<<" "<<j<<"in The Matrix : ";
                    in>>obj.ptrMatrix[i][j];
            }
        }
        return in ;
    }
    void setCell(int _row, int _col , int val){
        this->ptrMatrix[_row][_col] = val;
    }
    friend ostream &operator <<(ostream &  out , Matrix  &obj){     /// done
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

int main() {
    Matrix<double > m(1 , 5) ;
    Matrix<double> n(1 , 5) ;
    cin>>m >> n;
    cout<<m+n;
    return 0;
}