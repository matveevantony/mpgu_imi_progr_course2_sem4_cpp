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
};

#include "extrachecker.h" // подключение заголовочного файла тестирующей системы

int main() { // главная функция
    ExtraChecker::run();
    int i, j;
    char symb;
    cin >> i >> j >> symb;
    Matrix<char> matr(i, j, symb);
    char replacesymb;
    cin >> i >> j >> replacesymb;
    matr.setValue(i, j, replacesymb);
    cin >> i >> j;
    cout << matr.getValue(i, j) << endl;
}