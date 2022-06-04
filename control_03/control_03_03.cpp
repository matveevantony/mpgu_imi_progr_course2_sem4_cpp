// Контрольная работа № 3 (03 июня 2022 года)
// Вариант 6

// Задача № 3

#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <vector> //подключение библиотеки класса векторов
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n;
    cout << "Введите количество чисел в наборе: ";
    cin >> n;
    cout << "Введите целые числа - элементы набора:" << endl;
    vector<int> positive, negative;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input < 0) {
            negative.push_back(input);
        }
        else {
            positive.push_back(input);
        }
    }
    cout << "Отрицательные числа в наборе:" << endl;
    for (int i = 0; i < negative.size(); i++) {
        cout << negative[i] << " ";
    }
    cout << endl;
    cout << "Остальные числа набора:" << endl;
    for (int i = 0; i < positive.size(); i++) {
        cout << positive[i] << " ";
    }
    cout << endl;
}