// Контрольная работа № 2 (06 мая 2022 года)
// Вариант 5

// Задача № 3

#include <iostream> // подключение стандартной библиотеки ввода-вывода
using namespace std; // настройка стандартного пространства имён

template <typename T>
class Array11 { // шаблонный класс массивов длины 11
    private:
        const static int n = 11;
        T a[n];
    public:
        Array11() { // конструктор по умолчанию
        }
        Array11(T x) { // конструктор, заполняющий массив одинаковыми значениями
            for (int i = 0; i < n; i++) {
                a[i] = x;
            }
        }
        Array11(T x1, T x2, T x3, T x4, T x5, T x6, T x7, T x8, T x9, T x10, T x11) { // конструктор по значения элементов
            a[0] = x1;      a[1] = x2;      a[2] = x3;
            a[3] = x4;      a[4] = x5;      a[5] = x6;
            a[6] = x7;      a[7] = x8;      a[8] = x9;
            a[9] = x10;     a[10] = x11;
        }
        int countGreater(T x) { // метод нахождения числа элементов, превосходящих переданное в качестве параметра значение
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > x) {
                    res++;
                }
            }
            return res;
        }
        T kSmallest(int k) { // метод нахождения k-го по величине элемента
            T c[n];
            for (int i = 0; i < n; i++) {
                c[i] = a[i];
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (c[j] > c[j + 1]) {
                        T temp = c[j];
                        c[j] = c[j + 1];
                        c[j + 1] = temp;
                    }
                }
            }
            return c[k - 1];
        }
        template <typename I>
        friend istream& operator>> (istream&, Array11<I>&); // объявление дружественной функции перегрузки оператора ввода
};

template <typename I>
istream& operator>> (istream& is, Array11<I>& arr) { // перегрузка оператора ввода
    for (int i = 0; i < Array11<I>::n; i++) {
        is >> arr.a[i];
    }
    return is;
}

int main() { // главная функция
    Array11<int> intArray;
    cout << "Введите 11 целых чисел:" << endl;
    cin >> intArray;
    int x;
    cout << "Введите целое число: ";
    cin >> x;
    cout << "Количество превосходящих его элементов массива - " << intArray.countGreater(x) << endl;
    int n;
    cout << "Введите желаемый номер элемента по возрастанию: ";
    cin >> n;
    cout << "Элемент, имеющий этот номер по возрастанию равен " << intArray.kSmallest(n) << endl;
    Array11<double> doubleArray;
    cout << "Введите 11 вещественных чисел:" << endl;
    cin >> doubleArray;
    double y;
    cout << "Введите вещественное число: ";
    cin >> y;
    cout << "Количество превосходящих его элементов массива - " << doubleArray.countGreater(y) << endl;
    cout << "Введите желаемый номер элемента по возрастанию: ";
    cin >> n;
    cout << "Элемент, имеющий этот номер по возрастанию равен " << doubleArray.kSmallest(n) << endl;
    Array11<char> charArray;
    cout << "Введите 11 символов:" << endl;
    cin >> charArray;
    char z;
    cout << "Введите символ: ";
    cin >> z;
    cout << "Количество превосходящих его элементов массива - " << charArray.countGreater(z) << endl;
    cout << "Введите желаемый номер элемента по возрастанию: ";
    cin >> n;
    cout << "Элемент, имеющий этот номер по возрастанию равен " << charArray.kSmallest(n) << endl;
}