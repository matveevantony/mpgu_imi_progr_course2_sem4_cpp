#include <iostream> // подключение стандартной библиотеки ввода-вывода
using namespace std; // настройка стандартного пространства имён

class VeryLongInt { // класс очень длинных целых чисел
    private:
        static const int n = 2002;
        short digits[n];
    public:
        VeryLongInt() { // конструктор по умолчанию
            for (int i = 0; i < n; i++) {
                digits[i] = 0;
            }
        }
        VeryLongInt(int x) { // конструктор из обычного целого числа
            int i = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (x != 0) {
                    digits[i] = x % 10;
                    x /= 10;
                }
                else {
                    digits[i] = 0;
                }
            }
        }
        friend istream& operator>> (istream&, VeryLongInt&); // прототип дружественной функции перегрузки оператора ввода
        friend ostream& operator<< (ostream&, const VeryLongInt&); // прототип дружественной функции перегрузки оператора вывода
        VeryLongInt operator+ (const VeryLongInt& a) { // перегрузка оператора сложения
            VeryLongInt res;
            for (int i = n - 1; i > 0; i--) {
                res.digits[i] += (digits[i] + a.digits[i]);
                if (res.digits[i] >= 10) {
                    res.digits[i] -= 10;
                    res.digits[i - 1] += 1;
                }
            }
            res.digits[0] += (digits[0] + a.digits[0]);
            if (res.digits[0] >= 10) {
                res.digits[0] -= 10;
            }
            return res;
        }
        bool operator== (const VeryLongInt& a) { // перегрузка оператора проверки на равенство
            for (int i = 0; i < n; i++) {
                if (digits[i] != a.digits[i]) {
                    return false;
                }
            }
            return true;
        }
        bool operator< (const VeryLongInt& a) { // перегрузка оператора сравнения "меньше"
            for (int i = 0; i < n; i++) {
                if (digits[i] < a.digits[i]) {
                    return true;
                }
                if (digits[i] > a.digits[i]) {
                    return false;
                }
            }
            return false;
        }
        bool operator> (const VeryLongInt& a) { // перегрузка оператора сравнения "больше"
            for (int i = 0; i < n; i++) {
                if (digits[i] < a.digits[i]) {
                    return false;
                }
                if (digits[i] > a.digits[i]) {
                    return true;
                }
            }
            return false;
        }
        VeryLongInt operator* (const VeryLongInt& a) { // перегрузка оператора умножения
            VeryLongInt res;
            for (int i = n - 1; i >= 0; i--) {
                if (a.digits[i] != 0) {
                    for (int j = i; j > 0; j--) {
                        if (digits[j + (n - i - 1)] != 0) {
                            res.digits[j] += (digits[j + (n - i - 1)] * a.digits[i]);
                        }
                        if (res.digits[j] >= 10) {
                            res.digits[j - 1] += (res.digits[j] / 10);
                            res.digits[j] %= 10;
                        }
                    }
                    if (digits[n - i - 1] != 0) {
                        res.digits[0] += (digits[n - i - 1] * a.digits[i]);
                    }
                    if (res.digits[0] >= 10) {
                        res.digits[0] %= 10;
                    }
                }
            }
            return res;
        }
        VeryLongInt operator- (const VeryLongInt& a) { // перегрузка оператора вычитания (усеченная разность)
            VeryLongInt res;
            if (*this > a) {
                for (int i = n - 1; i > 0; i--) {
                    res.digits[i] += (digits[i] - a.digits[i]);
                    if (res.digits[i] < 0) {
                        res.digits[i] += 10;
                        res.digits[i - 1] -= 1;
                    }
                }
                res.digits[0] += (digits[0] - a.digits[0]);
            }
            return res;
        }
};

istream& operator>> (istream& is, VeryLongInt& a) { // дружественная функция перегрузки оператора ввода
    char input[VeryLongInt::n];
    is >> input;
    int fin = 0;
    while (input[fin] != '\0') {
        fin++;
    }
    fin--;
    for (int i = VeryLongInt::n - 1; i >= 0; i--) {
        if (fin >= 0) {
            a.digits[i] = input[fin] - '0';
        }
        else {
            a.digits[i] = 0;
        }
        fin--;
    }
    return is;
}

ostream& operator<< (ostream& os, const VeryLongInt& a) { // дружественная функция перегрузки оператора вывода
    bool started = false;
    for (int i = 0; i < VeryLongInt::n - 1; i++) {
        if (!started) {
            if (a.digits[i] != 0) {
                started = true;
            }
        }
        if (started) {
            os << a.digits[i];
        }
    }
    os << a.digits[VeryLongInt::n - 1];
    return os;
}

int main() { // главная функция
    VeryLongInt a, b;
    cin >> a >> b;
    cout << (a + b) << " ";
    if (a < b) {
        cout << "<";
    }
    if (a == b) {
        cout << "=";
    }
    if (a > b) {
        cout << ">";
    }
    cout << " " << (a * b) << " " << (a - b) << endl;
}