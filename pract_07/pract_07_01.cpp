#include <iostream> // подключение стандартной библиотеки ввода-вывода
using namespace std; // настройка стандартного пространства имён

template <typename T> // шаблонная функция сложения
T sum(T x, T y) {
    return (x + y);
}

#include "extrachecker.h" // подключение заголовочного файлы тестирующей системы
int main() { // главная функция
    ExtraChecker::run();
    int a, b;
    double c, d;
    cin >> a >> b >> c >> d;
    cout << sum<int>(a, b) << " " << sum<double>(c, d) << endl;
}