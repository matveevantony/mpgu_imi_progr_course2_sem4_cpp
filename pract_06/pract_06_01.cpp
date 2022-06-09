#include <iostream> // подключение стандартной библиотеки ввода-вывода
using namespace std; // настройка стандартного пространства имён

class IntCollection { // класс "набор целых чисел"
    public:
        virtual int getSum() { // виртуальный метод вычисления суммы
            return -1;
        }
        virtual int getMax() = 0; // виртуальный метод нахождения максимального элемента
        virtual void reset() = 0; // виртуальный метод обнуления всех элементов
};

class IntPair : public IntCollection { // класс "пара целых чисел"
    private:
        int a, b;
    public:
        IntPair(int _a, int _b) { // конструктор по двум числам
            a = _a;
            b = _b;
        }
        int getSum() { // метод вычисления суммы
            return a + b;
        }
        int getMax() { // метод нахождения максимального элемента
            if (a >= b) {
                return a;
            }
            return b;
        }
        void reset() { // метод обнуления всех элементов
            a = 0;
            b = 0;
        }
};

#include "extrachecker.h" // подключение заголовочного файлы тестирующей системы
int main () { // главная функция
    ExtraChecker::run();
    int a, b;
    cin >> a >> b;
    IntPair couple(a, b);
    cout << couple.getSum() << " " << couple.getMax() << endl;
}