#include "matrix.h"
#include <iomanip>
#include <iostream>

Matrix::Matrix(int *arr, int n) {
  matrix = arr;
  size = n;
}

void Matrix::print() {
  for (int i = 0; i < size; i++) {
    std::cout << "[";
    for (int k = 0; k < size; k++) {
      std::cout << std::setw(3) << Matrix::get_item(i, k) << " ";
    }
    std::cout << ']' << std::endl;
  }
  std::cout << '\n';
}


//Instead of actual [][] matrix I just use a array 
//because its easier for me personally to visualize the pointers
//The basic formula for the conversion is (Row size * row) + col
int Matrix::get_item(int row, int col) { return matrix[(size * row) + col]; }

void Matrix::set_item(int row, int col, int item) {
  matrix[(size * row) + col] = item;
}

int Matrix::get_size() { return size; }


//The main reason I wanted to use OOP here is because
//I thought it would be fun to use the overload operator feature
//This allows operators like *, +, -, etc to be used on this Matrix class and not just numbers
Matrix Matrix::operator+(Matrix other) {
  int newSize = other.get_size();
  int* newArr = new int[newSize * newSize];
  
  Matrix newMat(newArr, newSize);

  for (int i = 0; i < newSize; i++) {
    for (int j = 0; j < newSize; j++) {
      int sum = get_item(i, j) + other.get_item(i, j);
      newMat.set_item(i,j,sum);
    }
  }
  
  return newMat;
}

Matrix Matrix::operator*(Matrix other) {
  int newSize = other.get_size();
  int* newArr = new int[newSize * newSize];
  Matrix newMat(newArr,newSize);
  for (int i = 0; i < newSize; i++) {
    for (int j = 0; j < newSize; j++) {
      int dot = dot_product(other, i, j);
      newMat.set_item(i,j,dot);
    }
  }
  
  return newMat;
}

Matrix Matrix::operator*(int num) {
  int newSize = get_size();
  int* newArr = new int[newSize * newSize];
  Matrix newMat(newArr,newSize);
  for (int i = 0; i < newSize; i++) {
    for (int j = 0; j < newSize; j++) {
      int item = get_item(i,j);
      item = item * num;
      newMat.set_item(i,j,item);
    }
  }

  return newMat;
}

Matrix Matrix::operator-(Matrix other) {
  return *this + (other * -1); //A - B = A + -(B) essentially
  
}

//When a matrix does multiplication
//Whats happening is a bunch of dot products which is a sum of products (a1 * a2) + (b1 * b2) + ...
//This makes the operator* method for loop looka lot better than a triple for loop
int Matrix::dot_product(Matrix other, int row, int col) {
  int sum = 0;
  for (int i = 0; i < other.get_size(); i++) {
    sum += get_item(row, i) * other.get_item(i, col);
  }
  return sum;
}

//I don't think I used this one, but If I built a more elaborate test case, this would be useful
bool Matrix::operator==(Matrix other) {
  if (get_size() != other.get_size()) {
    return false;
  }
  else {
    for (int i = 0; i < get_size(); i++) {
      for (int j = 0; j < get_size(); i++) {
        if (get_item(i,j) != other.get_item(i,j)) {
          return false;
        }
      }
    }
  }
  return true;
}
void Matrix::T() {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      int temp = get_item(i, j);
      set_item(i, j, get_item(j, i));
      set_item(j, i, temp);
    }
  }
}

int Matrix::get_max() {
  int max = get_item(0,0);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (get_item(i, j) > max) {
        max = get_item(i, j);
      }
    }
  }
  return max;
}