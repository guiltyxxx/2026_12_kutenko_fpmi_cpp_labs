#include <iostream>
#include <random>
#include <algorithm>




void deleteMatrix(int** &matrix, int &a, int &b) {
     for (int i = 0; i < a; i++) {
          delete[] matrix[i];
     }
     delete[] matrix;
     matrix = nullptr;
     a = 0;
     b = 0;
}

void inputMatrix(int** &matrix, int &a, int &b) {
     std::cout << "Введи количество строк: ";
     if(!(std::cin >> a) || a <= 0){
          std::cout << "error";
          return;
     }
     std::cout << std::endl << "Введи количество столбцов: ";
     if(!(std::cin >> b) || b <= 0){
          std::cout << "error";
          return;
     }
     std::cout << std::endl << "Введи матрицу: ";

     matrix = new int*[a];
     for (int i = 0; i < a; i++) {
         matrix[i] = new int[b];
     }

     for (int i = 0; i < a; i++) {
          for (int g = 0; g < b; g++) {
               if (!(std::cin >> matrix[i][g])) {
                    std::cout << "error";
                    deleteMatrix(matrix, a, b);
                    return;
               }
         }
     }
}

void randomMatrix(int** &matrix, int &a, int &b, std::mt19937& gen) {
     std::cout << "Введи количество строк: ";
     if(!(std::cin >> a) || a <= 0){
          std::cout << "error";
          return;
     }
     std::cout << std::endl << "Введи количество столбцов: ";
     if(!(std::cin >> b) || b <= 0){
          std::cout << "error";
          return;
     }

     matrix = new int*[a];
     for (int i = 0; i < a; i++) {
         matrix[i] = new int[b];
     }

     int min, max;
     std::cout << "Введи границы матрицы: ";
     if(!(std::cin >> min)){
          std::cout << "error";
          deleteMatrix(matrix, a, b);
          return;
     }
     if(!(std::cin >> max)){
          std::cout << "error";
          deleteMatrix(matrix, a, b);
          return;
     }
     if(min > max) {
     std::swap(min,max);     
     }

     std::uniform_int_distribution<int> dist(min, max);

      for (int i = 0; i < a; i++) {
          for (int g = 0; g < b; g++) {
               matrix[i][g] = dist(gen);
         }
     }
}

void printMatrix(int** matrix,int a, int b) {
     std::cout << "Матрица:\n";
     for (int i = 0; i < a; i++){
          for (int g = 0; g < b; g++) {
               std::cout << matrix[i][g] << " ";
          }
          std::cout << std::endl;
     }
}

void function(int** &matrix, int& a, int& b) {
     for(int i = 0; i < a; i++){
          int index = 0;
          for (int g = 0; g < b; g++){
               if(matrix[i][g] != 0) {
                    matrix[i][index] = matrix[i][g];
                    index++;
               }
          }
          for (int g = index; g < b; g++){
               matrix[i][g] = 0;
          }
     }
}



int main() {

std::cout << "Выбери способ ввода, 1 - с клавиатуры, 2 - рандом\n";
int n;
int** matrix = nullptr;
int a = 0, b = 0;
std::mt19937 gen(45218965);
if(!(std::cin >> n) || (n != 1 && n!= 2)) {
     std::cout << "error";
     return 1;
}

if(n == 1){
     inputMatrix(matrix, a, b);
}
else {
     randomMatrix(matrix, a, b, gen);
}
if (matrix == nullptr) {
    return 1;
}
std::cout << "Исходная матрица: ";
printMatrix(matrix, a ,b);
function(matrix, a, b);
std::cout << "Преобразованная матрица: ";
printMatrix(matrix, a ,b);
deleteMatrix(matrix, a, b);

return 0;
}