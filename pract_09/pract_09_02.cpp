#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <vector> // подключение библиотеки, содержащей класс векторов
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n;
    cin >> n;
    vector<int> deviders;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            deviders.push_back(i);
        }
    }
    deviders.push_back(n);
    int size = deviders.size();
    double average;
    for (int i = 0; i < size; i++) {
        average += deviders[i];
    }
    average /= size;
    for (int i = 0; i < size; i++) {
        if (deviders[i] > average) {
            cout << deviders[i] << " ";
            break;
        }
    }
    if (size - 3 < 0) {
        cout << "-1" << endl;
    }
    else {
        cout << deviders[size - 3] << endl;
    }
}