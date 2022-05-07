#include <iostream> // подключение стандартной библиотеки ввода-вывода
using namespace std; // настройка стандартного пространства имён

template <typename T> // шаблонный класс прямоугольных матриц
class Matrix {
    private:
        T** matr; // указатель на двумерный массив
        int n, m; // переменные для хранения размеров матрицы
    public:
        Matrix(int _n, int _m, T value) { // конструктор по количеству строк, количеству столбцов и значению элементов
            n = _n;
            m = _m;
            matr = new T*[n];
            for (int i = 0; i < n; i++) {
                matr[i] = new T[m];
                for (int j = 0; j < m; j++) {
                    matr[i][j] = value;
                }
            }
        }
        ~Matrix() { // деструктор
            delete matr;
        }
        void setValue(int i, int j, T value) { // метод задания значения i-го j-го элемента матрицы
            matr[i][j] = value;
        }
        T getValue(int i, int j) { // метод получения значения i-го j-го элемента матрицы
            return matr[i][j];
        }
        template <typename I> friend istream& operator>> (istream&, Matrix<I>&); // дружественная функция перегрузки оператора ввода
        template <typename O> friend ostream& operator<< (ostream&, const Matrix<O>&); // дружественная функция перегрузки оператора вывода
        int countElements(T x) { // метод нахождения количества элементов, равных переданному в качестве параметра
            int res = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matr[i][j] == x) {
                        res++;
                    }
                }
            }
            return res;
        }
        bool searchSet(T* givenSet, int l) { // метод, определяющий, встречается ли в матрице хотя бы один из элементов массива, переданного в качестве параметра
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < l; k++) {
                        if (matr[i][j] == givenSet[k]) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        T findMax() { // метод, определяющий максимальный элемент матрицы
            T max = matr[0][0];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matr[i][j] > max) {
                        max = matr[i][j];
                    }
                }
            }
            return max;
        }
        void printRow(int row, ostream& os) { // метод вывода строки матрицы в поток вывода
            for (int i = 0; i < m; i++) {
                os << matr[row][i]<< " ";
            }
        }
        template <typename C> friend int countUnique(const Matrix<C>&); // дружественная функция нахождения количества различных элементов матрицы
};

template <typename T> // функция перегрузки оператора ввода
istream& operator>> (istream& is, Matrix<T>& x) {
    for (int i = 0 ; i < x.n; i++) {
        for (int j = 0; j < x.m; j++) {
            is >> x.matr[i][j];
        }
    }
    return is;
}

template <typename T> // функция перегрузки оператора вывода
ostream& operator<< (ostream& os, const Matrix<T>& x) {
    for (int i = 0; i < x.n; i++) {
        for (int j = 0; j < x.m; j++) {
            os << x.matr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

template <typename T> // шаблонная функция нахождения количества различных элементов матрицы
int countUnique(const Matrix<T>& matr) {
    int l = matr.n * matr.m;
    T array[l];
    for (int i = 0; i < matr.n; i++) {
        for (int j = 0; j < matr.m; j++) {
            array[i * matr.m + j] = matr.matr[i][j];
        }
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l - 1; j++) {
            if (array[j] > array[j + 1]) {
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    int res = 1;
    for (int i = 1; i < l; i++) {
        if (array[i - 1] != array[i]) {
            res++;
        }
    }
    return res;
}

#include "extrachecker.h" // подключение заголовочного файла тестирующей системы

int main() { // главная функция
    ExtraChecker::run();
    int i, j;
    cin >> i >> j;
    Matrix<int> matr(i, j, 0);
    cin >> matr;
    int row;
    cin >> row;
    matr.printRow(row, cout);
    cout << endl << countUnique(matr) << endl;
}