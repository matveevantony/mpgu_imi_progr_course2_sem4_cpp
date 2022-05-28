#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <set> // подключение библиотеки, содержащей класс множеств
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n, m;
    cin >> n >> m;
    int arrayA[n];
    int arrayB[m];
    for (int i = 0 ; i < n; i++) {
        cin >> arrayA[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arrayB[i];
    }
    set<int> setA;
    set<int> setB;
    for (int i = 0; i < n; i++) {
        setA.insert(arrayA[i]);
    }
    for (int i = 0; i < m; i++) {
        setB.insert(arrayB[i]);
    }
    if (setA.size() < setB.size()) {
        cout << "<" << endl;
    }
    else {
        if (setA.size() == setB.size()) {
            cout << "=" << endl;
        }
        else {
            cout << ">" << endl;
        }
    }
}