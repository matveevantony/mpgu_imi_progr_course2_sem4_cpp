#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <map> // подключение библиотеки, содержащей класс словарей
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n;
    cin >> n;
    string array[n];
    map<string, int> repeatsOfStrings;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < n; i++) {
        repeatsOfStrings[array[i]]++;
    }
    string mostRepeats = repeatsOfStrings.begin()->first;
    for (map<string, int> :: iterator i = repeatsOfStrings.begin(); i != repeatsOfStrings.end(); i++) {
        if (repeatsOfStrings[mostRepeats] < i->second) {
            mostRepeats = i->first;
        }
    }
    cout << mostRepeats << endl;
    for (map<string, int> :: iterator i = repeatsOfStrings.begin(); i != repeatsOfStrings.end(); i++) {
        if (i->second % 2 == 0) {
            cout << i->first << " ";
        }
    }
    cout << endl;
}