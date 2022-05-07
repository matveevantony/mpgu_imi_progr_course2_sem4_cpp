// Контрольная работа № 2 (06 мая 2022 года)
// Вариант 5

// Задача № 2

#include <iostream> // подключение стандартной библиотеки ввода-вывода
using namespace std; // настройка стандартного пространства имён

template <typename T>
int countNegative(T a, T b, T c, T d) { // шаблонная функция нахождения числа отрицательных элементов среди четырёх, переданных в качестве параметров
    int res = 0;
    if (a < 0) {
        res++;
    }
    if (b < 0) {
        res++;
    }
    if (c < 0) {
        res++;
    }
    if (d < 0) {
        res++;
    }
    return res;
}

int main() { // главная функция
    int intArray[4];
    cout << "Введите 4 целых числа:" << endl;
    for (int i = 0; i < 4; i++) {
        cin >> intArray[i];
    }
    cout << "Среди них отрицательных " << countNegative(intArray[0], intArray[1], intArray[2], intArray[3]) << endl;
    double intDouble[4];
    cout << "Введите 4 вещественных числа:" << endl;
    for (int i = 0; i < 4; i++) {
        cin >> intDouble[i];
    }
    cout << "Среди них отрицательных " << countNegative(intDouble[0], intDouble[1], intDouble[2], intDouble[3]) << endl;
}