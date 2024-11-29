#include <iostream>   // Підключаємо бібліотеку для вводу/виводу
#include <string>     // Підключаємо бібліотеку для роботи з рядками

const int number = 20;   // Кількість записів у масиві
const int curYear = 2024; // Поточний рік

// Структура для збереження ПІБ
struct PIB {
    std::string SurName;   // Прізвище
    std::string FirstName; // Ім'я
    std::string SecondName; // По-батькові
};

// Структура для інформації про власника автомобіля
struct nameOfGarageOwner {
    PIB name;              // Поле для збереження ПІБ
    std::string carBrand;  // Бренд автомобіля
    std::string carPlate;  // Номерний знак автомобіля
    int year;              // Рік випуску автомобіля
};

// Ініціалізація масиву із 20 записів
nameOfGarageOwner list[number] = {
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2017},
    {{"Yurchenko", "Andriy", "Pavlovyth"}, "nissan", "BC1111IT", 2014}
};

int main() {
    // Виведення даних до сортування
    std::cout << "Before sorting:\n";
    for (int i = 0; i < number; i++) {
        std::cout << list[i].name.SurName << "\t" 
                  << list[i].name.FirstName << "\t" 
                  << list[i].name.SecondName << "\t" 
                  << list[i].carBrand << "\t" 
                  << list[i].carPlate << "\t" 
                  << list[i].year << std::endl; // Виводимо дані про кожного власника автомобіля
    }

    // Сортування масиву записів за роком випуску автомобіля
    for (int i = 0; i < number - 1; i++) {       // Зовнішній цикл (проходить по всьому масиву)
        for (int j = 0; j < number - i - 1; j++) { // Внутрішній цикл (порівнює сусідні елементи)
            if (list[j].year > list[j + 1].year) { // Якщо рік випуску поточного запису більше, ніж наступного
                // Обмін записів місцями
                nameOfGarageOwner temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    // Виведення автомобілів, які старші за 10 років
    std::cout << "\nCars older than 10 years:\n";
    for (int i = 0; i < number; i++) { // Проходимо по всіх записах
        if(curYear - list[i].year >= 10) { // Перевіряємо, чи вік автомобіля >= 10 років
            std::cout << list[i].name.SurName << "\t" 
                      << list[i].name.FirstName << "\t" 
                      << list[i].name.SecondName << "\t" 
                      << list[i].carBrand << "\t" 
                      << list[i].carPlate << "\t" 
                      << list[i].year << std::endl; // Виводимо дані про старі автомобілі
        }
    }

    return 0; // Завершення програми
}
