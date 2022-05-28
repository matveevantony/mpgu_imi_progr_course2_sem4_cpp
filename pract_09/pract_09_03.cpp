#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <vector> // подключение библиотеки, содержащей класс векторов
#include <algorithm> // подключение библиотеки, содержащей стандартный алгоритмы
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    vector<vector<int>> lastDigitGroup(10);
    vector<vector<int>> sortLastDigitGroup(10);
    for (int i = 0; i < n; i++) {
        lastDigitGroup[array[i] % 10].push_back(array[i]);
        sortLastDigitGroup[array[i] % 10].push_back(array[i]);
    }
    for (int i = 0; i < 10; i++) {
        sort(sortLastDigitGroup[i].begin(), sortLastDigitGroup[i].end());
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < lastDigitGroup[i].size(); j++) {
            cout << lastDigitGroup[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < sortLastDigitGroup[i].size(); j++) {
            cout << sortLastDigitGroup[i][j] << " ";
        }
        cout << endl;
    }
}