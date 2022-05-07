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

#include "extrachecker.h" // подключение заголовочного файла тестирующей системы

int main() { // главная функция
    ExtraChecker::run();
    int i, j;
    cin >> i >> j;
    Matrix<double> matr(i, j, 0);
    cin >> matr;
    double x;
    cin >> i >> j >> x;
    matr.setValue(i, j, x);
    cout << matr;
}