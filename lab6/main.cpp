#include "matrix.h"
#include <fstream>
#include <iostream>

void userInput(int*& arr1, int*& arr2, int& n);

int main() {
  //User Input and Init
  int n = 0;
  int* arr1 = nullptr;
  int* arr2 = nullptr;
  userInput(arr1, arr2, n);
  Matrix mat1(arr1, n);
  Matrix mat2(arr2, n);

  
  std::cout << "Matrix 1: " << std::endl;
  mat1.print();
  
  std::cout << "Matrix 2: " << std::endl;
  mat2.print();

  std::cout << "Matrix 1 + Matrix 2 = Matrix 3" << std::endl;
  Matrix mat3 = mat1 + mat2;
  mat3.print();

  std::cout << "Matrix 1 - Matrix 2 = Matrix 4" << std::endl;
  Matrix mat4 = mat1 - mat2;
  mat4.print();

  std::cout << "Matrix 1 * Matrix 2 = Matrix 5" << std::endl;
  Matrix mat5 = mat1 * mat2;
  mat5.print();
  std::cout << "Matrix 1[0,0] = 9, Matrix 1[1,1] = 9, Matrix 1[2,2] = 9" << std::endl;
  mat1.set_item(0,0,9);
  mat1.set_item(1,1,9);
  mat1.set_item(2,2,9);
  mat1.print();

  std::cout << "Matrix 1 Maximum: " << mat1.get_max() << std::endl << std::endl;

  std::cout << "Matrix 1 Transpose:" << std:: endl;
  mat1.T();
  mat1.print();

  
  delete[] arr1;
  delete[] arr2;
  return 0;
}

void userInput(int*& arr1, int*& arr2, int& n) {
  std::ifstream myfile;
  myfile.open("matrix_input.txt.");
  myfile >> n;

  arr1 = new int[n * n];
  arr2 = new int[n * n];

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      myfile >> arr1[(n * i) + k];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      myfile >> arr2[(n * i) + k];
    }
  }

  myfile.close();
}