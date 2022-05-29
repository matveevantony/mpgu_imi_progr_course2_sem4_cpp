#include <iostream> // подключение стандартной библиотеки ввода-вывода
#include <map> // подключение библиотеки, содержащей класс словарей
using namespace std; // настройка стандартного пространства имён

int main() { // главная функция
    int n;
    cin >> n;
    long int array[n];
    map<long int, int> valueFib;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        valueFib[array[i]] = -1;
    }
    long int fib = 1;
    long int prevFib = 0;
    long int numFib = 1;
    for (map<long int, int> :: iterator i = valueFib.begin(); i != valueFib.end(); i++) {
        while (fib != i->first) {
            long int temp = fib;
            fib += prevFib;
            prevFib = temp;
            numFib++;
        }
        valueFib[fib] = numFib;
    }
    for (int i = 0; i < n; i++) {
        cout << valueFib[array[i]] << " ";
    }
    cout << endl;
}