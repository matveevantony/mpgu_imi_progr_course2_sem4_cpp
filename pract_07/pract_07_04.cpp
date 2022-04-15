#include <iostream> // подключение стандартной библиотеки ввода-вывода
using namespace std; // настройка стандартного пространства имён

template <typename T> // шаблонная функция нахождения индекса медианы массива
int findMedian(T* array, int n) {
    T copyArray[n];
    int idArray[n];
    for (int i = 0; i < n; i++) {
        copyArray[i] = array[i];
        idArray[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (copyArray[j] > copyArray[j + 1]) {
                T temp = copyArray[j];
                copyArray[j] = copyArray[j + 1];
                copyArray[j + 1] = temp;
                int tempId = idArray[j];
                idArray[j] = idArray[j + 1];
                idArray[j + 1] = tempId;
            }
        }
    }
    return idArray[n / 2];
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
    double dblArray[n2];
    for (int i = 0; i < n2; i++) {
        cin >> dblArray[i];
    }
    cout << findMedian(intArray, n1) << " " << findMedian(dblArray, n2) << endl;
}