#include <iostream>   // Стандартная библиотека для ввода/вывода
#include <cstdlib>    // Для функций rand() и srand()
#include <ctime>      // Для функции time() (используется как seed для генератора случайных чисел)
using namespace std;

int main() {
    // --- Определяем размеры матрицы ---
    const int ROWS = 5;  // Количество строк
    const int COLS = 5;  // Количество столбцов

    // --- Динамическое выделение памяти для двумерного массива ---
    // Выделяем память для массива указателей на строки
    int** matrix = new int*[ROWS];
    // Для каждой строки выделяем память для массива столбцов
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = new int[COLS];
    }

    // --- Инициализация генератора случайных чисел ---
    srand(time(NULL));

    // --- Заполнение матрицы случайными числами (от 0 до 99) ---
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // --- Вывод сгенерированной матрицы ---
    cout << "Generated matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // --- Вывод элементов главной диагонали ---
    cout << "\nElements of MAIN diagonal:" << endl;
    // Главная диагональ: элементы, у которых индекс строки равен индексу столбца
    for (int i = 0; i < ROWS && i < COLS; i++) {
        cout << matrix[i][i] << " ";
    }
    cout << "\n\n";

    // --- Вывод элементов побочной (другой) диагонали ---
    cout << "Elements of OTHER diagonal:" << endl;
    // Побочная диагональ: элемент в строке i имеет индекс столбца (COLS - 1 - i)
    for (int i = 0; i < ROWS && i < COLS; i++) {
        cout << matrix[i][COLS - 1 - i] << " ";
    }
    cout << "\n\n";

    // --- Подсчёт количества чётных и нечётных чисел ---
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] % 2 == 0)
                evenCount++;
            else
                oddCount++;
        }
    }
    cout << "Amount of even nums: " << evenCount << endl;
    cout << "Amount of odd nums: " << oddCount << endl;

    // --- Освобождение динамически выделенной памяти ---
    for (int i = 0; i < ROWS; i++) {
        delete[] matrix[i]; // Освобождаем память для каждой строки
    }
    delete[] matrix; // Освобождаем память для массива указателей

    return 0;
}
