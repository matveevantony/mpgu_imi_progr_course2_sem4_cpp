#include <iostream> // подключение стандартной библиотеки ввода-вывода
using namespace std; // настройка стандартного пространства имён

template <typename T> // шаблонная функция подсчёта количество максимумов из трёх элементов
int countOfMax(T a, T b, T c) {
    int res = 0;
    T max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    if (a == max) {
        res++;
    }
    if (b == max) {
        res++;
    }
    if (c == max) {
        res++;
    }
    return res;
}

#include "extrachecker.h" // подключение заголовочного файлы тестирующей системы
int main() { // главная функция
    ExtraChecker::run();
    int x, y, z;
    string a, b, c;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    cout << countOfMax(x, y, z) << " " << countOfMax (a, b, c) << endl;
}