// Контрольная работа № 1 (08 апреля 2022 года)
// Вариант 6

// Задача № 2

#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <cmath> // подключение математической библиотеки
using namespace std; // настройка стандартного пространства имён

class Sqrt11 { // класс чисел вида a + b * sqrt(11), где a и b - целые числа
    private:
        int a, b; // поля класса
    public:
        Sqrt11() { // конструктор по умолчанию
            a = 0;
            b = 0;
        }
        Sqrt11(int _a) { // конструктор по одному целому числу
            a = _a;
            b = 0;
        }
        Sqrt11(int _a, int _b) { // конструктор по двум целым числам
            a = _a;
            b = _b;
        }
        Sqrt11 mult(Sqrt11 x) { // метод вычисления произведения
            Sqrt11 res;
            res.a = a * x.a + b * x.b * 11;
            res.b = a * x.b + b * x.a;
            return res;
        }
        friend Sqrt11 dif(Sqrt11, Sqrt11); // дружественная функция вычисления разности
        Sqrt11 operator+ (Sqrt11 x) { // оператор сложения
            Sqrt11 res;
            res.a = a + x.a;
            res.b = b + x.b;
            return res;
        }
        friend istream& operator>> (istream&, Sqrt11&); // дружественная функция оператора ввода
        friend ostream& operator<< (ostream&, const Sqrt11&); // дружественная функция оператора вывода
        double toR() { // метод вычисления вещественного приближения
            return a + b * sqrt(11);
        }
        bool operator== (Sqrt11 x) { // оператор равенства
            return ((a == x.a) && (b == x.b));
        }
        bool operator!= (Sqrt11 x) { // оператор неравенства
            return !(*this == x);
        }
        bool operator> (Sqrt11 x) { // оператор больше
            return (toR() > x.toR());
        }
        bool operator< (Sqrt11 x) { // оператор меньше
            return (toR() < x.toR());
        }
        bool operator>= (Sqrt11 x) { // оператор больше или равно
            return ((*this > x) || (*this == x));
        }
        bool operator<= (Sqrt11 x) { // оператор меньше или равно
            return ((*this < x) || (*this == x));
        }
};

Sqrt11 dif (Sqrt11 x, Sqrt11 y) { // дружественная функция вычисления разности
    Sqrt11 res;
    res.a = x.a - y.a;
    res.b = x.b - y.b;
    return res;
}

istream& operator>> (istream& is, Sqrt11& x) { // оператор ввода
    is >> x.a >> x.b;
    return is;
}

ostream& operator<< (ostream& os, const Sqrt11& x) { // оператор вывода
    if (x.b == 0) {
        os << x.a;
        return os;
    }
    if (x.a != 0) {
        os << x.a;
    }
    if ((x.b > 0) && (x.a != 0)) {
        os << "+";
    }
    os << x.b << "*sqrt(11)";
    return os;
}

int main() { // главная функция
    const int n = 7;
    Sqrt11 array[n];
    cout << "Введите " << n << " пар целых коэффициентов чисел вида a+b*sqrt(11):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    Sqrt11 sum;
    for (int i = 0; i < n; i++) {
        sum = sum + array[i];
    }
    Sqrt11 res = sum.mult(sum.mult(sum));
    cout << "Куб суммы элементов массива: " << res << endl;
}