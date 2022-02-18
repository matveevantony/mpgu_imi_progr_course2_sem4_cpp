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
        void numMult(int x) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] *= x;
                }
            }
        }
        static SqMatrix3 sum(const SqMatrix3& A, const SqMatrix3& B) {
            int res[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = A.matrix[i][j] + B.matrix[i][j];
                }
            }
            SqMatrix3 resMatrix(res);
            return resMatrix;
        }
        static SqMatrix3 mult(const SqMatrix3& A, const SqMatrix3& B) {
            int res[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = 0;
                    for (int k = 0; k < n; k++) {
                        res[i][j] += A.matrix[i][k] * B.matrix[k][j];
                    }
                }
            }
            SqMatrix3 resMatrix(res);
            return resMatrix;
        }
        void pow(int x) {
            SqMatrix3 orig = *this;
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
            *this = unitMatrix;
            for (int i = 0; i < x; i++) {
                *this = mult(*this, orig);
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
    SqMatrix3 inputMatrixTwo;
    int P, S;
    cin >> P >> S;
    unitMatrix.print();
    cout << endl;
    inputMatrix.print();
    cout << endl;
    SqMatrix3 sumMatrix = SqMatrix3::sum(inputMatrix, inputMatrixTwo);
    sumMatrix.print();
    cout << endl;
    SqMatrix3 multInputMatrixTwo = inputMatrixTwo;
    multInputMatrixTwo.numMult(P);
    multInputMatrixTwo.print();
    cout << endl;
    SqMatrix3 multMatrix = SqMatrix3::mult(inputMatrix, inputMatrixTwo);
    multMatrix.print();
    cout << endl;
    SqMatrix3 powInputMatrixTwo = inputMatrixTwo;
    powInputMatrixTwo.pow(S);
    powInputMatrixTwo.print();
}