#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cout << array[0] << " " << array[3] << " " << array [n-1] << endl;
}