// Контрольная работа № 3 (03 июня 2022 года)
// Вариант 6

// Задача № 2

#include <iostream> // подключение стандартной библиотеки ввода-вывода
using namespace std; // настройка стандартного пространства имён

template <typename T> // шаблонная функция нахождения максимального из трёх элементов произвольного типа
T maxOfThree(const T& a, const T& b, const T& c) {
    T max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

int main() { // главная функция
    int a1, a2, a3;
    cout << "Введите 3 целых числа: ";
    cin >> a1 >> a2 >> a3;
    cout << "Максимум: " << maxOfThree(a1, a2, a3) << endl;
    double b1, b2, b3;
    cout << "Введите 3 действительных числа: ";
    cin >> b1 >> b2 >> b3;
    cout << "Максимум: " << maxOfThree(b1, b2, b3) << endl;
    char c1, c2, c3;
    cout << "Введите 3 символа: ";
    cin >> c1 >> c2 >> c3;
    cout << "Максимум: " << maxOfThree(c1, c2, c3) << endl;
}