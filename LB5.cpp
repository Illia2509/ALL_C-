#include <iostream>

// Функція для виведення матриці
void outputMatr(int** matr, int n, int m) {
    for (int i = 0; i < n; ++i, std::cout << std::endl) { // Перебір рядків
        for (int j = 0; j < m; ++j) { // Перебір стовпців
            std::cout << matr[i][j] << "\t"; // Виведення кожного елемента
        }
    }
    std::cout << std::endl; // Додатковий відступ після виведення матриці
}

// Функція для заповнення матриці статичними значеннями
void fillStaticMatr(int** matr, int n, int m) {
    int staticValues[3][3] = { // Статичний масив значень для заповнення
        {10, -2, 3},
        {2, -10, 9},
        {3, -4, -3}
    };

    for (int i = 0; i < n; ++i) { // Перебір рядків
        for (int j = 0; j < m; ++j) { // Перебір стовпців
            matr[i][j] = staticValues[i][j]; // Копіювання значень у матрицю
        }
    }
}

// Функція для знаходження максимуму серед мінімумів кожного рядка
int findMaxOfRowMins(int** matr, int n, int m) {
    int rowMins[n]; // Масив для збереження мінімальних значень рядків

    for (int i = 0; i < n; ++i) { // Перебір рядків
        int minVal = matr[i][0]; // Ініціалізація мінімального значення першим елементом рядка
        for (int j = 1; j < m; ++j) { // Перебір стовпців у рядку
            if (matr[i][j] < minVal) { // Перевірка, чи знайдено новий мінімум
                minVal = matr[i][j];
            }
        }
        rowMins[i] = minVal; // Збереження мінімального значення рядка
    }

    int maxOfMins = rowMins[0]; // Ініціалізація максимуму першим елементом
    for (int i = 1; i < n; ++i) { // Перебір всіх мінімумів рядків
        if (rowMins[i] > maxOfMins) { // Пошук нового максимуму
            maxOfMins = rowMins[i];
        }
    }

    return maxOfMins; // Повернення максимуму з мінімумів
}

int main() {
    const int n = 3, m = 3; // Розмір матриці

    // Виділення динамічної пам'яті для 2D-матриці
    int** mas2d = new int*[n];
    for (int i = 0; i < n; ++i) { // Виділення пам'яті для кожного рядка
        mas2d[i] = new int[m];
    }

    fillStaticMatr(mas2d, n, m); // Заповнення матриці статичними значеннями
    
    outputMatr(mas2d, n, m); // Виведення матриці на екран

    int maxOfMins = findMaxOfRowMins(mas2d, n, m); // Знаходження максимуму серед мінімумів рядків
    std::cout << "максимум з мінімумів = " << maxOfMins << std::endl; // Виведення результату

    return 0; // Завершення програми
}
