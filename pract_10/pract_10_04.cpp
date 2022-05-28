#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <set> // подключение библиотеки, содержащей класс множеств
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n;
    cin >> n;
    string visitorsList[n];
    for (int i = 0; i < n; i++) {
        cin >> visitorsList[i];
    }
    set<string> insideBuilding;
    for (int i = 0; i < n; i++) {
        if (insideBuilding.find(visitorsList[i]) == insideBuilding.end()) {
            insideBuilding.insert(visitorsList[i]);
        }
        else {
            insideBuilding.erase(visitorsList[i]);
        }
        cout << insideBuilding.size() << " ";
    }
    cout << endl;
    for (set<string> :: iterator i = insideBuilding.begin(); i != insideBuilding.end(); i++) {
        string visitorInside = *i;
        if (visitorInside.length() >= 5) {
            cout << visitorInside << " ";
        }
    }
    cout << endl;
}