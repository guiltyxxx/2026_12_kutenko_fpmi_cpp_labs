#include <iostream>
#include <cmath>
#include <random>

void inputArray(int* &arr, int &size) {
     std::cout << "Введи размер массива: ";
     std::cin >> size;
     arr = new int[size];
     std::cout << "Ввод массива: ";
     for (int i = 0; i < size; i++){
          std::cin >> arr[i];
     }
}

void randomArray(int* &arr, int &size, std::mt19937& gen) {
     std::cout << "Введи размер массива: ";
     std::cin >> size;
     arr = new int[size];

     std::cout << "Введи границы интервалов (a и b через пробел): ";
     int a, b;
     std::cin >> a >> b;

     std::uniform_int_distribution<int> dist(a, b);
     for (int i = 0; i < size; i++) {
          arr[i] = dist(gen);
     }
}    

void printArray(const int* arr, const int &size){
     std::cout << "Массив: ";
     for (int i = 0; i < size; i++) {
          std::cout << arr[i] << " ";
     }
     std::cout << std::endl;
}

void function(int* &arr, int &size) {
     int m;
     std::cout << "Введи число M (модуль): ";
     std::cin >> m;

     int index = 0;
     for (int i = 0; i < size; i++) {
          if (std::abs(arr[i]) > m) {
               arr[index] = arr[i];
               index++;
          }
     }
     
     for (int i = index; i < size; i++) {
          arr[i] = 0;
     }
}

void deleteArray(int* &arr, int &size){
     delete[] arr;
     arr = nullptr;
     size = 0;
}

int main() {
    std::mt19937 gen(45218965);

    int* myarr = nullptr;
    int mysize = 0;

    std::cout << "Выбери способ ввода: 1 - с клавиатуры, 2 - рандом\n";
    int n;

    if (!(std::cin >> n) || (n != 1 && n != 2)) {
         std::cout << "error";
         return 1;
    }

    if (n == 1) {
         inputArray(myarr, mysize);
         printArray(myarr, mysize);
    } else {
         randomArray(myarr, mysize, gen);
         std::cout << "Рандомный массив: ";
         printArray(myarr, mysize);
    }

    function(myarr, mysize);
    
    std::cout << "Преобразованный массив:\n";
    printArray(myarr, mysize);

    deleteArray(myarr, mysize);

    return 0;
}
