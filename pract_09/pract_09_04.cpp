#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <vector> // подключение библиотеки, содержащей класс векторов
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    string str;
    cin >> str;
    vector<char> vec;
    bool flag = 0;
    for (int i = 0; i < str.length(); i++) {
        if (((str[i] == '(') || (str[i] == '[')) || ((str[i] == '{') || (str[i] == '<'))) {
            vec.push_back(str[i]);
        }
        else {
            if (vec.size() > 0) {
                if ((str[i] == vec[vec.size() - 1] + 1) || (str[i] == vec[vec.size() - 1] + 2)) {
                    vec.pop_back();
                }
                else {
                    cout << "No" << endl;
                    flag = 1;
                    break;
                }
            }
            else {
                cout << "No" << endl;
                flag = 1;
                break;
            }
        }
    }
    if ((vec.size() == 0) && (flag == 0)) {
        cout << "Yes" << endl;
    }
    else {
        if (flag == 0) {
            cout << "No" << endl;
        }
    }
}