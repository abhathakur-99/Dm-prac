#include<iostream>
using namespace std;

int main() {
    int degree;

    cout << "Polynomial Evaluator" << endl;
    cout << "Enter degree of polynomial: ";
    cin >> degree;

    // Store coefficients in array
    // coefficients[i] is coefficient of n^i
    double coefficients[20];

    cout << "Enter coefficients from highest degree to lowest (constant last):" << endl;
    for (int i = degree; i >= 0; i--) {
        cout << "Coefficient of n^" << i << ": ";
        cin >> coefficients[i];
    }

    // Display the polynomial
    cout << "\nYour polynomial: f(n) = ";
    bool first = true;
    for (int i = degree; i >= 0; i--) {
        if (coefficients[i] != 0) {
            if (!first && coefficients[i] > 0) cout << " + ";
            else if (coefficients[i] < 0) cout << " - ";
            if (i == 0) cout << (coefficients[i] < 0 ? -coefficients[i] : coefficients[i]);
            else if (i == 1) cout << (coefficients[i] < 0 ? -coefficients[i] : coefficients[i]) << "n";
            else cout << (coefficients[i] < 0 ? -coefficients[i] : coefficients[i]) << "n^" << i;
            first = false;
        }
    }
    cout << endl;

    // Evaluate for a given value of n
    double n;
    cout << "\nEnter value of n: ";
    cin >> n;

    double result = 0;
    double power = 1;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * power;
        power *= n;
    }

    cout << "f(" << n << ") = " << result << endl;

    return 0;
}
