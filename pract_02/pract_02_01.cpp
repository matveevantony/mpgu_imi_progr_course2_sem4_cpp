#include <iostream>
using namespace std;

class SqMatrix3 {
    public:
        static const int n = 3;
    private:
        int matrix[n][n];
    public:
        SqMatrix3() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> matrix[i][j];
                }
            }
        }
        SqMatrix3(const int dArray[n][n]) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = dArray[i][j];
                }
            }
        }
        void print() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    const int n = 3;
    int unitDArray[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                unitDArray[i][j] = 1;
            }
            else {
                unitDArray[i][j] = 0;
            }
        }
    }
    SqMatrix3 unitMatrix(unitDArray);
    SqMatrix3 inputMatrix;
    unitMatrix.print();
    cout << endl;
    inputMatrix.print();
}