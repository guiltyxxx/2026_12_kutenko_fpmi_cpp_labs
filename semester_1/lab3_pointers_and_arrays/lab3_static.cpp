#include <iostream>
#include <random>
#include <iomanip>
#include <cmath>

int inputSize() {
int n;
std::cout << "Введи количество оценок\n";
if(!(std::cin >> n) || n < 3 || n > 100) {
     std::cout << "error\n";
     return -1;
}
return n; 
}

bool inputScore(double score[], int n) {
std::cout << "Введи оценки\n";
for(int i = 0; i < n; i++) {
    if(!(std::cin >> score[i]) || score[i] < 0|| score[i] > 6.0) {
        std::cout << "error\n";
        return false;
    }
}
return true;
}

bool inputRandom(double score[], int n, std::mt19937& gen) {
double a,b;
std::cout << "Введи границы интервала\n";
if(!(std::cin >> a >> b) || a < 0 || b > 6.0 || a > b) {
    std::cout << "error\n";
    return false;
}
std::uniform_real_distribution<double> dist(a, b);

for(int i = 0; i < n; i++) {
    score[i] = std::round(dist(gen)*10)/10;
}
return true; 
}

double calculateScore(const double score[], int n) { 
 double min = score[0];
    double max = score[0];
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += score[i];
        if (score[i] < min) { min = score[i]; }
        if (score[i] > max) { max = score[i]; }
    }

    sum = sum - min - max;
    return sum / (n - 2);
}

 void printScore(const double score[], int n, double final_score) {
    std::cout << "Оценки: ";
    for (int i = 0; i < n; i++) {
        std::cout << score[i] << " ";
    }
    std::cout << std::endl;

     std::cout << "Итоговая оценка в зачёт: " << std::fixed << std::setprecision(2) << final_score << std::endl;
 }
int main() {
setlocale(LC_ALL, "Russian");

int n = inputSize();
if (n == -1) {
     std::cout << "error\n";
    return 1;
}

double score[100];
int choice;
std::cout << "Способ ввода: \n 1 - клавитура \n 2 - рандом\n";

if(!(std::cin >> choice) || (choice != 1 && choice != 2)) {
    std::cout << "error\n";
    return 1;
}

std::mt19937 gen(45218965);

if (choice ==1) {

    if (!inputScore(score, n)) {
        return 1;
    }
} else {
    if (!inputRandom(score, n, gen)) {
        return 1;
    }
}

double final_score = calculateScore(score, n);
printScore(score, n, final_score);
return 0;
}