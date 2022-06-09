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

class Rectangle : public ConvexPolygon { // класс прямоугольников со сторонами, параллельными осям координат, - наследник класса четырёхугольников
    public:
        Rectangle(double _x, double _y, double _a, double _b) : ConvexPolygon(_x, _y, _x, _y+_b, _x+_a, _y+_b, _x+_a, _y) {} // конструктор по левой нижней вершине и двум сторонам
        double getDiagonal() { // метод вычисления длины диагонали
            return sqrt((x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]));
        }
};

class Square : public Rectangle { // класс квадратов со сторонами, параллельными осям координат, - наследник класса прямоугольников со сторонами, параллельными осям координат
    public:
        Square(double _x, double _y, double _a) : Rectangle(_x, _y, _a, _a) {} // конструктор по левой нижней вершине и стороне
        double getInscribedCircleRadius() { // метод вычисления радиуса вписанной окружности
            return (abs(x[0] - x[2]) / 2);
        }
        double getCircumscribedCircleRadius() { // метод вычисления радиуса описанной окружности
            return ((this->getDiagonal()) / 2);
        }
};

class IsoscelesTrapezoid : public ConvexPolygon { // класс равнобедренных трапеций с основаниями, параллельными оси Ox - наследник класса четырёхугольников
    public:
        IsoscelesTrapezoid(double _x, double _y, double _a, double _b, double _h) : ConvexPolygon(_x, _y, _x + (_b - _a) / 2, _y + _h, _x + (_a + _b) / 2, _y + _h, _x + _b, _y) {} // конструктор по левой нижней вершине, основаниям и высоте
        double getMiddleLine() { // метод вычисления средней линии
            return (((x[3] - x[0]) + (x[2] - x[1]))) / 2;
        }
        double getSin() { // метод вычисления синуса угла
            return (y[1] - y[0]) / sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]));
        }
};

#include "extrachecker.h" // подключение заголовочного файлы тестирующей системы
int main() { // главная функция
    ExtraChecker::run();
    double x, y, a, b, h;
    cin >> x >> y >> a >> b >> h;
    IsoscelesTrapezoid trapez(x, y, a, b, h);
    cout << trapez.getPerimeter() << " " << trapez.getArea() << " " << trapez.getMiddleLine() << " " << trapez.getSin() << endl;
}