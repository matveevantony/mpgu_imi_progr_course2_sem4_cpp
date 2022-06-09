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

class IntArray : public IntCollection { // класс "массив целых чисел"
    private:
        int n;
        int* array;
    public:
        IntArray(int* _array, int _n) { // конструктор по указателю на массив и размеру массива
            n = _n;
            array = new int[n];
            for (int i = 0; i < n; i++) {
                array[i] = _array[i];
            }
        }
        ~IntArray() { // деструктор
            delete array;
        }
        int getSum() { // метод вычисления суммы
            int res = 0;
            for (int i = 0; i < n; i++) {
                res += array[i];
            }
            return res;
        }
        int getMax() { // метод нахождения максимального элемента
            int res = array[0];
            for (int i = 0; i < n; i++) {
                if (array[i] > res) {
                    res = array[i];
                }
            }
            return res;
        }
        void reset() { // метод обнуления всех элементов
            for (int i = 0; i < n; i++) {
                array[i] = 0;
            }
        }
        int getMinIndex() { // метод поиска индекса минимального элемента
            int minel = array[0];
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (array[i] <= minel) {
                    minel = array[i];
                    res = i;
                }
            }
            return res;
        }
};

#include "extrachecker.h" // подключение заголовочного файлы тестирующей системы
int main () { // главная функция
    ExtraChecker::run();
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    IntArray arr(array, n);
    cout << arr.getSum() << " " << arr.getMax() << " " << arr.getMinIndex() << endl;
}