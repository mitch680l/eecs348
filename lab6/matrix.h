#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:

  //I made everthing public because why not
  
  Matrix(int *arr, int n); //constructor
  void print(); //prints matrix
  void set_item(int row, int col, int item); //sets element like A[i][j]
  Matrix operator+(Matrix other); //addition
  Matrix operator*(Matrix other);//multiplication
  Matrix operator*(int num); //scalar multiplaction
  Matrix operator-(Matrix other); //subtraction
  bool operator==(Matrix other); //comparison
  void T(); //transpose
  int dot_product(Matrix other, int row, int col); //dot product
  int get_item(int row, int col); //retreive value A[i][j]
  int get_size(); //retreive size of matrix
  int *matrix; //array address for matrix
  int size; //size storage
  int get_max(); //get the max
};

#endif