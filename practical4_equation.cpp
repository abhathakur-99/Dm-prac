#include<iostream>
using namespace std;

int n, C;
int x[15]; // stores values of x1, x2, ... xn
int count = 0;

// Brute force: try all combinations using recursion
void solve(int pos, int remaining) {
    if (pos == n) {
        if (remaining == 0) {
            count++;
            cout << "Solution " << count << ": ";
            for (int i = 0; i < n; i++)
                cout << "x" << i+1 << "=" << x[i] << " ";
            cout << endl;
        }
        return;
    }
    // Try all values from 0 to remaining for current variable
    for (int val = 0; val <= remaining; val++) {
        x[pos] = val;
        solve(pos + 1, remaining - val);
    }
}

int main() {
    cout << "Enter number of variables (n): ";
    cin >> n;
    cout << "Enter constant C (C <= 10): ";
    cin >> C;

    if (C > 10) {
        cout << "C must be <= 10" << endl;
        return 0;
    }

    cout << "\nAll solutions of x1 + x2 + ... + x" << n << " = " << C << ":" << endl;
    solve(0, C);
    cout << "\nTotal solutions: " << count << endl;

    return 0;
}
