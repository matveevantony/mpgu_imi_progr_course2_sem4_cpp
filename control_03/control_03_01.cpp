// Контрольная работа № 3 (03 июня 2022 года)
// Вариант 6

// Задача № 1

#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <cmath> // подключение стандартной математической библиотеки
using namespace std; // настройка стандартного пространства имён

class Circle { // класс окружностей на плоскости
    private:
        double x, y, r;
    public:
        Circle(double _x, double _y, double _d) { // конструктор по центру и диаметру
            x = _x;
            y = _y;
            r = _d / 2;
        }
        Circle(double _x, double _y, double _px, double _py) { // конструктор по центру и точке на окружности
            x = _x;
            y = _y;
            r = sqrt((_px - _x) * (_px - _x) + (_py - _y) * (_py - _y));
        }
        double getCenterX() { // геттер для координаты x центра окружности
            return x;
        }
        double getCenterY() { // геттер для координаты y центра окружности
            return y;
        }
        double getRadius() { // геттер для радиуса окружности
            return r;
        }
        double length() { // метод вычисления длины окружности
            return (2 * M_PI * r);
        }
        bool isOutside(double _px, double _py) { // метод проверки точки на попадание вовне окружности
            return (sqrt((_px - x) * (_px - x) + (_py - y) * (_py - y)) - r > 0);
        }
};

int intersectionPoints(Circle& a, Circle& b) { // функция определения числа точек пересесения двух окружностей
    double centersDistance = sqrt((a.getCenterX() - b.getCenterX()) * (a.getCenterX() - b.getCenterX()) + (a.getCenterY() - b.getCenterY()) * (a.getCenterY() - b.getCenterY()));
    double summOfRadiuses = a.getRadius() + b.getRadius();
    if (centersDistance > summOfRadiuses) {
        return 0;
    }
    if (centersDistance < summOfRadiuses) {
        return 2;
    }
    return 1;
}

int main() { // главная функция
    cout << "Введите координаты центра и диаметры 1-й окружности:" << endl;
    double x, y, d, px, py;
    cin >> x >> y >> d;
    Circle firstCircle(x, y, d);
    cout << "Введите координаты центра и точку на 2-й окружности:" << endl;
    cin >> x >> y >> px >> py;
    Circle secondCircle(x, y, px, py);
    cout << "Длины окружностей: " << firstCircle.length() << " " << secondCircle.length() << endl;
    cout << "Введите координаты точки: ";
    cin >> px >> py;
    if (firstCircle.isOutside(px , py)) {
        cout << "Точка лежит вовне 1-й окружности" << endl;
    }
    else {
        cout << "Точка не лежит вовне 1-й окружности" << endl;
    }
    if (secondCircle.isOutside(px , py)) {
        cout << "Точка лежит вовне 2-й окружности" << endl;
    }
    else {
        cout << "Точка не лежит вовне 2-й окружности" << endl;
    }
    cout << "Количество точек пересечения двух окружностей: " << intersectionPoints(firstCircle, secondCircle) << endl;
}