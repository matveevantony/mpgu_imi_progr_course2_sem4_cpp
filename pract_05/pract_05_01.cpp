#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <cmath> // подключение математической библиотеки
using namespace std; // настройка стандартного пространства имён

class ConvexPolygon { // класс четырёхугольников
    public:
        static const int n = 4;
    protected:
        double x[n];
        double y[n];
    public:
        ConvexPolygon() { // конструктор по умолчанию
            for (int i = 0; i < n; i++) {
                x[i] = 0;
                y[i] = 0;
            }
        }
        ConvexPolygon(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4) { // конструктор по координатам вершин
            x[0] = _x1;
            y[0] = _y1;
            x[1] = _x2;
            y[1] = _y2;
            x[2] = _x3;
            y[2] = _y3;
            x[3] = _x4;
            y[3] = _y4;
        }
        double getPerimeter() { // метод вычисления периметра
            double res = 0;
            for (int i = 0; i < n; i++) {
                double side = sqrt((x[i] - x[(i + 1) % n]) * (x[i] - x[(i + 1) % n]) + (y[i] - y[(i + 1) % n]) * (y[i] - y[(i + 1) % n]));
                res += side;
            }
            return res;
        }
        double getArea() { // метод вычисления площади
            double res = 0;
            for (int i = 0; i < n; i++) {
                int j = (i + 1) % n;
                int k = (i - 1) % n;
                if (k < 0) {
                    k += n;
                }
                res += x[i] * (y[j] - y[k]);
            }
            res = abs(res);
            res /= 2;
            return res;
        }
};

#include "extrachecker.h" // подключение заголовочного файлы тестирующей системы
int main() { // главная функция
    ExtraChecker::run();
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    ConvexPolygon quad(x1, y1, x2, y2, x3, y3, x4, y4);
    cout << quad.getPerimeter() << " " << quad.getArea() << endl;
}