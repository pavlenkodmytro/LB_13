#include <iostream>  // Ввід/вивід
#include <cstdlib>   // Генерація випадкових чисел
#include <ctime>     // Робота з часом

using namespace std;

const int SIZE = 5; // Розмір матриці

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int temporaryInt = 0; 
    int arr[SIZE][SIZE];  // Матриця 5x5
    int* ptr = &arr[temporaryInt][temporaryInt]; // Вказівник на перший елемент

    // Заповнення матриці випадковими числами (1-99)
    for (int i = 0; i < SIZE * SIZE; i++) 
        *(ptr + i) = rand() % 100;

    // Виведення матриці
    cout << "Матриця:\n";
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) 
            cout << *(ptr + i * SIZE + j) << "\t";
        cout << endl;
    }

    // Головна діагональ
    cout << "\nГоловна діагональ: ";
    for (int i = 0; i < SIZE; i++) 
        cout << *(ptr + i * (SIZE + 1)) << " ";

    // Побічна діагональ
    cout << "\nПобічна діагональ: ";
    for (int i = 0; i < SIZE; i++) 
        cout << *(ptr + (i + 1) * (SIZE - 1)) << " ";

    // Підрахунок парних та непарних чисел
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < SIZE * SIZE; i++) 
        (*(ptr + i) % 2 == 0) ? evenCount++ : oddCount++;

    cout << "\nПарні: " << evenCount << "\nНепарні: " << oddCount << endl;

    return 0;
}
