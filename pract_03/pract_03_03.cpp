#include <iostream> // подключение стандартной библиотеки ввода-вывода
using namespace std; // настройка стандартного пространства имён

class ResidueClass31 { // класс классов вычетов по модулю 31
    private:
        int x; // поле класса
    public:
        static const int n = 31; // ститическое поле класса
        ResidueClass31() { // конструктор по умолчанию
            x = 0;
        }
        ResidueClass31(const ResidueClass31& a) { // конструктор копирования
            x = a.x % n;
        }
        ResidueClass31(int a) { // конструктор из целого числа
            if (a >= 0) {
                x = a % n;
            }
            else {
                x = n + (a % n);
            }
        }
        friend istream& operator>> (istream&, ResidueClass31&); // прототип дружественной функции перегрузки оператора ввода
        friend ostream& operator<< (ostream&, const ResidueClass31&); // прототип дружественной функции перегрузки оператора вывода
        ResidueClass31 operator+ (const ResidueClass31& a) { // перегрузка оператора сложения
            ResidueClass31 res;
            res = x + a.x;
            return res;
        }
        ResidueClass31& operator+= (const ResidueClass31 a) { // перегрузка оператора сложения с присвоением
            *this = *this + a;
            return *this;
        }
        ResidueClass31 operator- (const ResidueClass31& a) { // перегрузка оператора вычитания
            ResidueClass31 res;
            res = x - a.x;
            return res;
        }
        ResidueClass31& operator-= (const ResidueClass31& a) { // перегрузка оператора вычитания с присвоением
            *this = *this - a;
            return *this;
        }
        ResidueClass31 operator* (const ResidueClass31& a) { // перегрузка оператора умножения
            ResidueClass31 res;
            res = x * a.x;
            return res;
        }
        ResidueClass31& operator*= (const ResidueClass31& a) { // перегрузка оператора умножения с присвоением
            *this = *this * a;
            return *this;
        }
        ResidueClass31 inverse() { // метод нахождения обратного элемента по умножению
            ResidueClass31 res;
            for (int i = 1; i < n; i++) {
                if ((x * i) % n == 1) {
                    res = i;
                    return res;
                }
            }
            return res;
        }
        ResidueClass31 operator^ (const int m) { // перегрузка оператора возведения в целую степень
            ResidueClass31 res;
            res = 1;
            if (m > 0) {
                for (int i = 0; i < m; i++) {
                    res *= *this;
                }
            }
            if (m < 0) {
                for (int i = 0; i < (-m); i++) {
                    res *= this->inverse();
                }
            }
            return res;
        }
        ResidueClass31 operator/ (const ResidueClass31& a) { // перегрузка оператора деления
            ResidueClass31 firstMult;
            firstMult = *this;
            ResidueClass31 inv;
            inv = a;
            inv = inv.inverse();
            return (firstMult * inv);
        }
        ResidueClass31& operator/= (const ResidueClass31& a) { // перегрузка оператора деления с присвоением
            *this = *this / a;
            return *this;
        }
};

istream& operator>> (istream& is, ResidueClass31& a) { // дружественная функция перегрузки оператора ввода
    int input;
    is >> input;
    if (input >= 0) {
        a.x = input % ResidueClass31::n;
    }
    else {
        a.x = ResidueClass31::n + (input % ResidueClass31::n);
    }
    return is;
}

ostream& operator<< (ostream& os, const ResidueClass31& a) { // дружественная функция перегрузки оператора вывода
    os << a.x;
    return os;
}

int main() { // главная функция
    ResidueClass31 a, b;
    int c;
    cin >> a >> b >> c;
    cout << (a + b) << " " << (a - b) << " " << (a * b) << " " << (a ^ c) << " " << a.inverse() << " " << (a / b) << endl;
}