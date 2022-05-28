#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <vector> // подключение библиотеки, содержащей класс векторов
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    vector<int> seq;
    int input;
    cin >> input;
    while (input != 0) {
        seq.push_back(input);
        cin >> input;
    }
    int id;
    cin >> id;
    cout << seq[id - 1] << endl;
}