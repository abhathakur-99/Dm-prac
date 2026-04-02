#include<iostream>
using namespace std;

int digits[10];
int n;

// Without repetition using backtracking
int chosen[10];
bool used[10];

void permuteWithout(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++)
            cout << chosen[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            chosen[pos] = digits[i];
            permuteWithout(pos + 1);
            used[i] = false;
        }
    }
}

// With repetition
void permuteWith(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++)
            cout << chosen[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        chosen[pos] = digits[i];
        permuteWith(pos + 1);
    }
}

int main() {
    int choice;

    cout << "Enter number of digits: ";
    cin >> n;
    cout << "Enter the digits: ";
    for (int i = 0; i < n; i++)
        cin >> digits[i];

    cout << "\n1. Permutations WITHOUT repetition" << endl;
    cout << "2. Permutations WITH repetition" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nAll permutations without repetition:" << endl;
        for (int i = 0; i < n; i++) used[i] = false;
        permuteWithout(0);
    } else {
        cout << "\nAll permutations with repetition:" << endl;
        permuteWith(0);
    }

    return 0;
}
