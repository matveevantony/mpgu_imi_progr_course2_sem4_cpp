// Контрольная работа № 3 (03 июня 2022 года)
// Вариант 6

// Задача № 4

#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <set> //подключение библиотеки класса множеств
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n, m;
    cout << "Введите количество чисел в 1-м наборе: ";
    cin >> n;
    cout << "Введите количество чисел в 2-м наборе: ";
    cin >> m;
    set<int> firstSet, secondSet;
    int input;
    cout << "Введите целые числа - элементы 1-го набора:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> input;
        firstSet.insert(input);
    }
    cout << "Введите целые числа - элементы 2-го набора:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> input;
        secondSet.insert(input);
    }
    int count = 0;
    for (set<int> :: iterator i = secondSet.begin(); i != secondSet.end(); i++) {
        if (firstSet.find(*i) != firstSet.end()) {
            count++;
        }
    }
    cout << "Количество целых чисел, принадлежащих обоим наборам: " << count << endl;
}