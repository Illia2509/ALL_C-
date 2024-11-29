#include <iostream>  // Підключаємо бібліотеку для вводу/виводу
#include <cmath>     // Підключаємо бібліотеку для математичних функцій

int main() {
    double x = 1.0;        // Початкове значення змінної x
    double x_step = 0.5;   // Крок зміни x
    double x_finish = 4.0; // Граничне значення x

    // Цикл, який виконується, поки x менше або дорівнює x_finish
    while (x <= x_finish) {
        // Обчислюємо значення z за формулою |x| + x^3
        double z = std::abs(x) + std::pow(x, 3);

        // Обчислюємо значення y за формулою z * sin^2(x + 2) / 2 + x
        double y = z * std::pow(std::sin(x + 2), 2) / 2 + x;

        // Виводимо значення x і y
        std::cout << "when x: " << x << ", then y: " << y << std::endl;

        // Збільшуємо x на заданий крок
        x += x_step;
    };

    return 0; // Завершення програми
}
