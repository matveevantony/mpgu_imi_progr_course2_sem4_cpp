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

class IntMatrix : public IntCollection { // класс "двумерный массив целых чисел"
    private:
        int n, m;
        int** array;
    public:
        IntMatrix(int** _array, int _n, int _m) { // конструктор по указателю на массив, длине и ширине двумерного массива
            n = _n;
            m = _m;
            array = new int*[n];
            for (int i = 0; i < n; i++) {
                array[i] = new int[m];
                for (int j = 0; j < m; j++) {
                    array[i][j] = _array[i][j];
                }
            }
        }
        ~IntMatrix() { // деструктор
            for (int i = 0; i < n; i++) {
                delete array[i];
            }
            delete array;
        }
        int getSum() { // метод вычисления суммы
            int res = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res += array[i][j];
                }
            }
            return res;
        }
        int getMax() { // метод нахождения максимального элемента
            int res = array[0][0];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (array[i][j] > res) {
                        res = array[i][j];
                    }
                }
            }
            return res;
        }
        void reset() { // метод обнуления всех элементов
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    array[i][j] = 0;
                }
            }
        }
        int getColumnSum(int k) { // метод нахождения суммы k-го столбца
            int res = 0;
            for (int i = 0; i < n; i++) {
                res += array[i][k];
            }
            return res;
        }
};

int absDiff(IntCollection& a, IntCollection& b) { // функция нахождения модуля разности между суммами двух наборов целых чисел
    return abs(a.getSum() - b.getSum());
}

int maxOfCollections(IntCollection& a, IntCollection& b, IntCollection& c) { // функция нахождения максимального элемента из элементов трёх наборов целых чисел
    int maxa = a.getMax();
    int maxb = b.getMax();
    int maxc = c.getMax();
    if (maxa >= maxb) {
        if (maxa >= maxc) {
            return maxa;
        }
        return maxc;
    }
    if (maxb >= maxc) {
        return maxb;
    }
    return maxc;
}

#include "extrachecker.h" // подключение заголовочного файлы тестирующей системы
int main () { // главная функция
    ExtraChecker::run();
    int a, b;
    cin >> a >> b;
    IntPair couple(a, b);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    IntArray array(arr, n);
    int m;
    cin >> n >> m;
    int** matr = new int*[n];
    for (int i = 0; i < n; i++) {
        matr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> matr[i][j];
        }
    }
    IntMatrix matrix(matr, n , m);
    cout << absDiff(couple, array) << " " << absDiff(couple, matrix) << " " << absDiff(array, matrix) << " " << maxOfCollections(couple, array, matrix) << endl;
}