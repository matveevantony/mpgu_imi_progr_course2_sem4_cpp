#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <set> // подключение библиотеки, содержащей класс множеств
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n, k;
    cin >> n >> k;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    set<int> sets[k];
    for (int i = 0; i < n; i++) {
        sets[i % k].insert(array[i]);
    }
    for (int j = 0; j < k; j++) {
        for (set<int> :: iterator i = sets[j].begin(); i != sets[j].end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
}