#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <set> // подключение библиотеки, содержащей класс множеств
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    set<int> noRepeats, repeated;
    for (int i = 0; i < n; i++) {
        if (repeated.find(array[i]) == repeated.end()) {
            if (noRepeats.find(array[i]) == noRepeats.end()) {
                noRepeats.insert(array[i]);
            }
            else {
                noRepeats.erase(array[i]);
                repeated.insert(array[i]);
            }
        }
    }
    cout << noRepeats.size() << endl;
}