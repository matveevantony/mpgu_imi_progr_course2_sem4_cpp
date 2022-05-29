#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <vector> // подключение библиотеки, содержащей класс векторов
#include <map> // подключение библиотеки, содержащей класс словарей
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n;
    cin >> n;
    map<string, vector<int>> marks;
    for (int i = 0; i < n; i++) {
        string name;
        string surname;
        cin >> name >> surname;
        string fullname = name + " " + surname;
        int mark;
        cin >> mark;
        marks[fullname].push_back(mark);
    }
    cout << marks.size() << endl;
    cout.setf(std::ios::fixed);
    cout.precision(2);
    for (map<string, vector<int>> :: iterator i = marks.begin(); i != marks.end(); i++) {
        double average = 0;
        cout << i->first << ": ";
        for (int j = 0; j < i->second.size(); j++) {
            cout << i->second[j] << " ";
            average += i->second[j];
        }
        average /= i->second.size();
        cout << "- " << average - 0.0049 << endl;
    }
}