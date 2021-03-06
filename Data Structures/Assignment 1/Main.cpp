/*  Author : Ahmed Mohamed Hanafy
 *  ID: 20170357
 *  problem 3 for Assignment 1
 *  Generic  Class Matrix
 *  class Matrix calculator
 *  Date : 01/03/19
 *  version log : v1.0 , 01/03/19 By Hanafy
 *                v2.0  , 04/03/19 - separate files and transpose and operators
 *
 *
 *
 */
 /*     TODO
  *
  *
  *
  *
  */
/*
    done (1) It is required to design and implement a generic class Matrix, in the form of a class template
    that accepts a type parameter. This way, when the class Matrix is instantiated, we decide if it
            should accept float, int or double, etc. [2 points]
    done (2) Matrix class holds a matrix of any size and allocates the required memory as needed. [2 points]
    done(3) Matrix class should have a destructor that frees used memory at the end of lifetime of each
            Matrix objects. [2 points]
    done (4) Matrix class specifications should be in a separate header “.h” file. [2 points]
    done (5) It should have a pointer to pointer attribute that points to the matrix content. It should have
            suitable constructors and methods for allocating the required memory space based on the
            dimensions decided by the user. [2 points]
     done (6) Overload standard operators and I/O operators to enable Matrix class with addition, subtraction
    and   multiplication and suitable input and output capabilities. Add a method for matrix transpose.
  done    (7) Then develop a MatrixCalculator class which offers the user a menu of operations to perform
    on int matrices as follows. Each of these options should be able to accept matrices of varying
    dimensions, which the user inputs. For multiplication, the calculator should check that two
            matrices are of dimensions n x m and m x p.
            
 */
 
#include <iostream>
#include <bits/stdc++.h>
#include "Matrix.h"
#include "Calcualater.h"
 using namespace std;

int main() {

    Calcualater c ;
    return 0;
}