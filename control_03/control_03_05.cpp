// Контрольная работа № 3 (03 июня 2022 года)
// Вариант 6

// Задача № 5

#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <map> //подключение библиотеки класса словарей
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n;
    cout << "Введите количество книг в наборе: ";
    cin >> n;
    map<string, int> books;
    string inputString;
    int inputInt;
    cout << "Введите названия книг и количество страниц в них:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> inputString >> inputInt;
        books[inputString] = inputInt;
    }
    cout << "Введите названия двух книг из выше перечисленных:" << endl;
    string firstBook, secondBook;
    cin >> firstBook >> secondBook;
    cout << "Из этих двух книг меньше страниц в книге с названием: ";
    if (books[firstBook] < books[secondBook]) {
        cout << firstBook << endl;
    }
    else {
        cout << secondBook << endl;
    }
}