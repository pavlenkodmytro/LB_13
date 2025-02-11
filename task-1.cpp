// ============================================================================
// Підключення бібліотек:
// ----------------------------------------------------------------------------
// '#'            - символ препроцесора, що вказує на директиву препроцесора.
// include       - директива для включення файлу.
// <iostream>    - стандартна бібліотека вводу/виводу (надає доступ до cout, cin тощо).
#include <iostream>

// ----------------------------------------------------------------------------
// <cstdlib>     - бібліотека стандартних функцій С++, включаючи rand() і srand().
// '#' та include - аналогічно попередньому коментарю.
#include <cstdlib>

// ----------------------------------------------------------------------------
// <ctime>       - бібліотека для роботи з часом, потрібна для функції time().
#include <ctime>

// ============================================================================
// Простір імен:
// ----------------------------------------------------------------------------
// using         - ключове слово, яке дозволяє використовувати імена з певного простору.
// namespace     - слово, що вказує на простір імен.
// std           - стандартний простір імен, в якому знаходяться стандартні функції та класи.
// ';'           - роздільник, що завершує команду.
using namespace std;

// ============================================================================
// Оголошення констант:
// ----------------------------------------------------------------------------
// const         - ключове слово, що задає константне (не змінне) значення.
// int           - тип даних "ціле число".
// SIZE          - ім'я константи, що представляє розмір масиву.
// '='           - оператор присвоєння.
// 5             - числове значення, яке присвоюється константі SIZE.
// ';'           - завершення виразу.
const int SIZE = 5; // Розмір квадратного масиву (матриці 5x5).

// ============================================================================
// Головна функція програми:
// ----------------------------------------------------------------------------
// int           - тип значення, яке повертає функція (тут ціле число).
// main          - ім'я головної функції, з якої починається виконання програми.
// ()            - список аргументів функції (порожній, тобто без аргументів).
// {             - відкриває тіло функції.
int main() {
    
    // ініціалізація генератора випадкових чисел:
    // ----------------------------------------------------------------------------
    // srand         - функція для встановлення початкового значення генератора випадкових чисел.
    // time(0)       - функція, що повертає поточний час; аргумент 0 означає використання поточного часу.
    // ( )           - огортає аргументи функції.
    // ';'           - завершення виразу.
    srand(time(0)); // Ініціалізація генератора випадкових чисел (початкове значення залежить від поточного часу).

    // Оголошення змінної для початкового індексу:
    // ----------------------------------------------------------------------------
    // int           - оголошення змінної типу ціле число.
    // temporaryInt  - ім'я змінної.
    // '='           - оператор присвоєння.
    // 0             - значення, яке присвоюється.
    // ';'           - завершення виразу.
    int temporaryInt = 0;

    // Оголошення статичного двовимірного масиву:
    // ----------------------------------------------------------------------------
    // int           - елементи масиву будуть типу ціле число.
    // arr           - ім'я масиву.
    // [SIZE][SIZE]  - задає розміри масиву: кількість рядків та кількість стовпців рівні значенню константи SIZE.
    // ';'           - завершення виразу.
    int arr[SIZE][SIZE]; // Статичний двовимірний масив розміром 5x5.

    // Оголошення вказівника на перший елемент масиву:
    // ----------------------------------------------------------------------------
    // int*          - оголошення вказівника на int (тип вказівника).
    // ptr           - ім'я вказівника.
    // '='           - оператор присвоєння.
    // '&'           - оператор взяття адреси.
    // arr[...]      - доступ до елемента масиву за індексами.
    // [temporaryInt] - використовується як індекс для першого виміру (тут 0).
    // [temporaryInt] - використовується як індекс для другого виміру (теж 0).
    // ';'           - завершення виразу.
    int* ptr = &arr[temporaryInt][temporaryInt]; // Вказівник на перший елемент масиву (адреса елемента arr[0][0]).

    // ========================================================================
    // Заповнення масиву випадковими числами (без використання індексів напряму):
    // ========================================================================

    // for - цикл, що повторює блок коду задану кількість разів.
    // (int i = 0; i < SIZE * SIZE; i++) - оголошення змінної циклу і умова продовження:
    //   - int i = 0     : оголошення змінної i та її ініціалізація нулем.
    //   - i < SIZE * SIZE : умова, що перевіряється перед кожною ітерацією; SIZE * SIZE обчислюється як 25.
    //   - i++           : інкремент (збільшення значення i на 1 після кожної ітерації).
    // { ... } - блок коду, який виконується кожного разу, коли умова циклу істинна.
    for (int i = 0; i < SIZE * SIZE; i++) {
        // *(ptr + i)
        //   - ptr       : початкова адреса (вказівник на перший елемент масиву).
        //   - + i       : арифметика вказівників для доступу до i-го елемента (масив зберігається послідовно в пам'яті).
        //   - *         : оператор розіменування, що дозволяє отримати значення за даною адресою.
        //
        // rand()         : функція, що генерує випадкове ціле число.
        // % 99           : оператор взяття остачі від ділення, обмежує результат значеннями від 0 до 98.
        // + 1            : зміщує діапазон значень до 1-99.
        // =              : оператор присвоєння значення елементу масиву.
        // ';'            : завершення виразу.
        *(ptr + i) = rand() % 100; // Присвоєння кожному елементу масиву випадкового числа від 1 до 99.
    } // Кінець циклу for.

    // ========================================================================
    // Виведення матриці на екран:
    // ========================================================================

    // cout         : стандартний об'єкт для виведення інформації.
    // <<           : оператор виведення, направляє дані в потік cout.
    // "Матриця:\n": рядок символів для виведення; \n означає перехід на новий рядок.
    // ';'          : завершення виразу.
    cout << "Матриця:\n";

    // Виведення матриці рядок за рядком:
    // Зовнішній цикл for відповідає за рядки, внутрішній - за стовпці.
    for (int i = 0; i < SIZE; i++) {           // Проходимо по кожному рядку (i від 0 до 4).
        for (int j = 0; j < SIZE; j++) {       // Проходимо по кожному стовпцю в рядку (j від 0 до 4).
            // *(ptr + i * SIZE + j)
            //   - i * SIZE   : обчислює зсув для початку i-го рядка.
            //   - + j        : додає зміщення для конкретного стовпця в цьому рядку.
            //   - ptr        : вказівник на початок масиву.
            //   - *          : розіменування для отримання значення елемента.
            //
            // << "\t"      : виведення символу табуляції для вирівнювання стовпців.
            cout << *(ptr + i * SIZE + j) << "\t";
        }
        // endl         : маніпулятор, що переводить курсор на наступний рядок.
        // ';'          : завершення виразу.
        cout << endl; // Перехід на новий рядок після завершення виведення одного рядка матриці.
    }

    // ========================================================================
    // Виведення елементів головної діагоналі:
    // ========================================================================
    
    // Вивід тексту з початком нового рядка:
    cout << "\nГоловна діагональ: ";

      // 2. Цикл for для виведення елементів головної діагоналі:
    // -------------------------------------------------------------
    for (int i = 0; i < SIZE; i++) {  
        // Кожна ітерація циклу відповідає за виведення одного елемента головної діагоналі.
        // Зауважимо, що в квадратній матриці з розміром SIZE x SIZE
        // головна діагональ містить елементи, де номер рядка дорівнює номеру стовпця.
        //
        // Детальний розбір всередині циклу:
        //
        // a) Обчислення позиції елемента головної діагоналі:
        //
        //    - Вираз: i * (SIZE + 1)
        //
        //      * i: поточний індекс ітерації, який одночасно є індексом рядка і стовпця.
        //
        //      * (SIZE + 1): число, що дорівнює (розмір матриці + 1).
        //          Оскільки матриця зберігається в пам'яті послідовно (рядок за рядком),
        //          перехід від одного елемента головної діагоналі до наступного відповідає
        //          пересуванню на (SIZE + 1) позицій.
        //
        //      Таким чином:
        //          Для i = 0: зміщення 0 * (SIZE + 1) = 0  → перший елемент (arr[0][0]).
        //          Для i = 1: зміщення 1 * (SIZE + 1) = SIZE + 1 → arr[1][1].
        //          Для i = 2: зміщення 2 * (SIZE + 1) = 2*(SIZE + 1) → arr[2][2].
        //          ... і так далі.
        //
        // b) Доступ до елемента за допомогою арифметики вказівників:
        //
        //    - *(ptr + i * (SIZE + 1))
        //
        //      * ptr: вказівник на початок масиву (адреса першого елемента arr[0][0]).
        //      * + i * (SIZE + 1): арифметика вказівників для переходу на потрібне місце
        //                          у пам'яті, де зберігається потрібний елемент головної діагоналі.
        //      * * (розіменування): дає змогу отримати значення елемента за обчисленою адресою.
        //
        // c) Вивід отриманого значення:
        //
        //    - cout << *(ptr + i * (SIZE + 1)) << " ";
        //
        //      Оператор << спочатку виводить значення елемента, а потім рядок, що містить
        //      один пробіл (" "), для розділення чисел при виводі.
        //
        // Результат виконання циклу:
        //   Буде виведено послідовно елементи головної діагоналі матриці, розділені пробілами.
        //   Наприклад, для матриці 5x5 елементи з позицій: arr[0][0], arr[1][1], arr[2][2],
        //   arr[3][3], arr[4][4].
        cout << *(ptr + i * (SIZE + 1)) << " ";
    } // Закінчення циклу for для головної діагоналі.

    // 3. Вивід заголовка для побічної діагоналі:
    // -------------------------------------------------------------
    // cout << "\nПобічна діагональ: ";
    //
    // - "\n": символ переводу рядка, який забезпечує початок виводу з нового рядка.
    // - "Побічна діагональ: ": текст, який попереджає, що далі будуть виведені елементи
    //   побічної діагоналі (елементи, розташовані по іншій, протилежній до головної, діагоналі).
    //
    // Результат виконання цього рядка:
    //   У консолі з'явиться новий рядок, після якого текст "Побічна діагональ: ".
    cout << "\nПобічна діагональ: ";

    // 4. Цикл for для виведення елементів побічної діагоналі:
    // -------------------------------------------------------------
    for (int i = 0; i < SIZE; i++) {  
        // Кожна ітерація циклу відповідає за виведення одного елемента побічної діагоналі.
        // Для квадратної матриці побічна діагональ містить елементи, які розташовані так, що
        // перший елемент знаходиться в правому верхньому куті, а останній — в лівому нижньому.
        //
        // Детальний розбір всередині циклу:
        //
        // a) Обчислення позиції елемента побічної діагоналі:
        //
        //    - Вираз: (i + 1) * (SIZE - 1)
        //
        //      * (SIZE - 1): число, що визначає відстань між елементами побічної діагоналі.
        //          Для матриці розміром SIZE x SIZE (наприклад, 5x5) це число дорівнює 4.
        //      * (i + 1): враховує, що перший елемент побічної діагоналі не починається
        //          з нульового зміщення. Обчислення (i + 1) гарантує, що при i = 0 ми отримаємо
        //          1 * (SIZE - 1), тобто перший елемент, який знаходиться у верхньому правому куті.
        //
        //      Таким чином:
        //          Для i = 0: зміщення (0+1)*(SIZE-1) = 1*(SIZE-1) = 4 → arr[0][4].
        //          Для i = 1: зміщення (1+1)*(SIZE-1) = 2*(SIZE-1) = 8 → arr[1][3].
        //          Для i = 2: зміщення (2+1)*(SIZE-1) = 3*(SIZE-1) = 12 → arr[2][2].
        //          Для i = 3: зміщення (3+1)*(SIZE-1) = 4*(SIZE-1) = 16 → arr[3][1].
        //          Для i = 4: зміщення (4+1)*(SIZE-1) = 5*(SIZE-1) = 20 → arr[4][0].
        //
        // b) Доступ до елемента за допомогою арифметики вказівників:
        //
        //    - *(ptr + (i + 1) * (SIZE - 1))
        //
        //      * ptr: вказівник на початок масиву (адреса arr[0][0]).
        //      * (i + 1) * (SIZE - 1): обчислює кількість елементів, яку необхідно пропустити,
        //          щоб дістатись до потрібного елемента побічної діагоналі.
        //      * Оператор * (розіменування) отримує значення елемента, що знаходиться за
        //          обчисленою адресою.
        //
        // c) Вивід отриманого значення:
        //
        //    - cout << *(ptr + (i + 1) * (SIZE - 1)) << " ";
        //
        //      Спочатку виводиться значення елемента побічної діагоналі,
        //      а потім символ пробілу (" ") для розділення елементів при виводі.
        //
        // Результат виконання циклу:
        //   Буде виведено послідовно елементи побічної діагоналі матриці, розділені пробілами.
        //   Для матриці 5x5 це будуть елементи: arr[0][4], arr[1][3], arr[2][2],
        //   arr[3][1], arr[4][0].
        cout << *(ptr + (i + 1) * (SIZE - 1)) << " ";
    } // Закінчення циклу for для побічної діагоналі.

    // ========================================================================
    // Підрахунок кількості парних та непарних чисел:
    // ========================================================================
    
    // Оголошення двох змінних для підрахунку:
    // evenCount   : лічильник парних чисел.
    // oddCount    : лічильник непарних чисел.
    // 0           : початкове значення (обидва ініціалізовані нулем).
    int evenCount = 0, oddCount = 0;

    // Цикл for для обходу всіх елементів масиву:
    for (int i = 0; i < SIZE * SIZE; i++) {
        // *(ptr + i) : отримання значення i-го елемента масиву за допомогою арифметики вказівників.
        // % 2         : обчислення залишку від ділення на 2.
        // == 0       : перевірка, чи є число парним (залишок дорівнює 0).
        // if         : умовна конструкція, що виконує блок коду, якщо умова істинна.
        if (*(ptr + i) % 2 == 0)
            evenCount++;  // Збільшення лічильника парних чисел на 1.
        else
            oddCount++;   // Якщо число непарне, збільшення лічильника непарних чисел на 1.
    }

    // ========================================================================
    // Виведення результатів підрахунку:
    // ----------------------------------------------------------------------------
    // Вивід тексту та значення evenCount:
    cout << "\nКількість парних чисел: " << evenCount;
    // Вивід тексту та значення oddCount, завершення рядка:
    cout << "\nКількість непарних чисел: " << oddCount << endl;

    // Повернення значення 0 з функції main:
    // ----------------------------------------------------------------------------
    // return 0; - повідомляє операційній системі, що програма завершилась успішно.
    // ';'        - завершення виразу.
    return 0;
} // '}' - закриває тіло функції main.
