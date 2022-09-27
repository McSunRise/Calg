#include "Vector.h"
#include "Complex.h"
#include "Matrix.h"
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    Vector a(2, 3, 6), b(4, 4, 7);
    cout << a * b << "\n";
    Complex c(3, 4), d(8, -5);
    cout << c + d << "\n";
    Matrix e(3, 3), f(3, 3);
    cin >> e >> f;
    cout << e * 4;
}