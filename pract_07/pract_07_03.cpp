#include <iostream> // подключение стандартной библиотеки ввода-вывода
using namespace std; // настройка стандартного пространства имён

template <typename T> // шаблонная функция сортировки массива в порядке неубывания
void sortArray(T* array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (array[j] > array[j + 1]) {
                T temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

#include "extrachecker.h" // подключение заголовочного файлы тестирующей системы
int main() { // главная функция
    ExtraChecker::run();
    int n1, n2;
    cin >> n1;
    int intArray[n1];
    for (int i = 0; i < n1; i++) {
        cin >> intArray[i];
    }
    cin >> n2;
    char chArray[n2];
    for (int i = 0; i < n2; i++) {
        cin >> chArray[i];
    }
    sortArray<int>(intArray, n1);
    sortArray<char>(chArray, n2);
    for (int i = 0; i < n1; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n2; i++) {
        cout << chArray[i] << " ";
    }
    cout << endl;
}