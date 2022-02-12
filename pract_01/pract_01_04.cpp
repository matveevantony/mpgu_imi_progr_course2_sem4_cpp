#include <iostream>
using namespace std;

double maxElThree(double,double,double);

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    cout << maxElThree(a, b, c) << endl;
}

double maxElThree(double a, double b, double c) {
    if (a > b) {
        if (a > c) {
            return a;
        }
        return c;
    }
    if (b > c) {
        return b;
    }
    return c;
}