#include <iostream>
#include <random>

void inputArray(int arr[], int size){
     std::cout << "Введите элементы массива";
     std::cout << std::endl;

     for (int i = 0; i < size; i++){
          std::cin >> arr[i];
     } 
}

void  randomArray(int arr[], std::mt19937& gen, int size){
     std::cout << "Введи границы интервалов";
     int a,b;
     std::cin >> a >> b;
     std::uniform_int_distribution<int> dist(a,b);
     for (int i = 0; i < size; i++){
          arr[i] = dist(gen);
}

}

void function(int arr[], int size) {
     int index = 1;
     for ( int i = 1; i < size; i++) {
          if(arr[i] != arr[i-1]) {
               arr[index] = arr[i];
          index++;
          }
     }
     for(int i = index; i<size; i++){
          arr[i] = 0;}
}

void printArray(int arr[], int size){
     for (int i = 0; i < size; i++) {
          std::cout << arr[i] << " ";
     }
     std::cout << std::endl;
}





int main(){
int size;
int arr[1000];
std::cout << "Введите количество элементов массива\n";
std::cin >> size;
std::cout << " Выбери способ ввода: 1 - с клавиатуры, 2 - рандом\n" ;
int n;

std::mt19937 gen(45218965);

if (!(std::cin >> n) || (n != 1 && n != 2)) {
     std::cout << "error";
     return 1;
}


if(n == 1){
     inputArray(arr, size);
    }
else{
     randomArray(arr, gen, size);
     std::cout << "Рандомный массив:";
     printArray(arr, size);}

function(arr, size);
printArray(arr, size);

return 0;
}
