#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <map> // подключение библиотеки, содержащей класс словарей
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n, m;
    cin >> n >> m;
    int arrayA[n], arrayB[m];
    for (int i = 0; i < n; i++) {
        cin >> arrayA[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arrayB[i];
    }
    map<int, int> inBothArrays;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arrayA[j] == arrayB[i]) {
                inBothArrays[arrayB[i]] = j;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (inBothArrays.find(arrayB[i]) != inBothArrays.end()) {
            cout << inBothArrays[arrayB[i]] << " ";
        }
        else {
            cout << "-1 ";
        }
    }
    cout << endl;
}