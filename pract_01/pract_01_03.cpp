#include <iostream>
using namespace std;

int arraySum(int*,int);

int main() {
    int n; 
    cin >> n; 
    int a[n]; 
    for (int i=0; i<n; i++) {
        cin >> a[i]; 
    }
    cout << arraySum(a, n) << endl;
}

int arraySum(int *array, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;
}