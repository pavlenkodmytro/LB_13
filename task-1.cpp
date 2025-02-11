#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE = 5;

void fillArray(int (*arr)[SIZE]) {
    srand(time(0));
    for (int *ptr = &arr[0][0]; ptr <= &arr[SIZE - 1][SIZE - 1]; ptr++) {
        *ptr = rand() % 100;  // Заповнення випадковими числами від 0 до 99
    }
}

void printArray(int (*arr)[SIZE]) {
    for (int *ptr = &arr[0][0]; ptr <= &arr[SIZE - 1][SIZE - 1]; ptr++) {
        std::cout << *ptr << "\t";
        if ((ptr - &arr[0][0] + 1) % SIZE == 0)
            std::cout << std::endl;
    }
}

void printDiagonals(int (*arr)[SIZE]) {
    std::cout << "Головна діагональ: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << *(*(arr + i) + i) << " ";
    }
    std::cout << "\nПобічна діагональ: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << *(*(arr + i) + (SIZE - 1 - i)) << " ";
    }
    std::cout << std::endl;
}

void countEvenOdd(int (*arr)[SIZE], int &evenCount, int &oddCount) {
    evenCount = oddCount = 0;
    for (int *ptr = &arr[0][0]; ptr <= &arr[SIZE - 1][SIZE - 1]; ptr++) {
        (*ptr % 2 == 0) ? evenCount++ : oddCount++;
    }
}

int main() {
    int arr[SIZE][SIZE];

    fillArray(arr);
    std::cout << "Масив:\n";
    printArray(arr);

    printDiagonals(arr);

    int evenCount, oddCount;
    countEvenOdd(arr, evenCount, oddCount);
    
    std::cout << "Кількість парних елементів: " << evenCount << std::endl;
    std::cout << "Кількість непарних елементів: " << oddCount << std::endl;

    return 0;
}
