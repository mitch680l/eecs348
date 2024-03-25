#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
  Matrix(int *arr, int n);
  void print();
  void set_item(int row, int col, int item);
  Matrix operator+(Matrix other);
  Matrix operator*(Matrix other);
  Matrix operator*(int num);
  Matrix operator-(Matrix other);
  bool operator==(Matrix other);
  void T();
  int dot_product(Matrix other, int row, int col);
  int get_item(int row, int col);
  int get_size();
  int *matrix;
  int size;
  int get_max();
};

#endif