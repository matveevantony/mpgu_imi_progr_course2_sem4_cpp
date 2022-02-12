#include <iostream>
using namespace std;

int maxTwoArrElDif(int*, int*, int);

int main() {
    int n;
    cin >> n;
    int arrayA[n];
    int arrayB[n];
    for (int i = 0; i < n; i++) {
        cin >> arrayA[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arrayB[i];
    }
    cout << maxTwoArrElDif(arrayA, arrayB, n) << endl;
}

int maxTwoArrElDif(int *arrA, int *arrB, int n) {
    int maxDif = arrA[0] - arrB[0];
    for (int i = 1; i < n; i++) {
        if (arrA[i] - arrB[i] > maxDif) {
            maxDif = arrA[i] - arrB[i];
        }
    }
    return maxDif;
}