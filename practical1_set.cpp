#include<iostream>
#include<vector>
using namespace std;

class SET {
public:
    vector<int> elements;

    // Add elements to set
    void addElement(int x) {
        elements.push_back(x);
    }

    // a. Check if element is member
    bool isMember(int x) {
        for (int i = 0; i < elements.size(); i++) {
            if (elements[i] == x)
                return true;
        }
        return false;
    }

    // b. Print power set
    void powerset() {
        int n = elements.size();
        int total = 1;
        for (int i = 0; i < n; i++) total *= 2; // 2^n subsets

        cout << "Power Set:" << endl;
        for (int i = 0; i < total; i++) {
            cout << "{ ";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))
                    cout << elements[j] << " ";
            }
            cout << "}" << endl;
        }
    }

    // c. Check if this set is subset of another
    bool isSubset(SET other) {
        for (int i = 0; i < elements.size(); i++) {
            if (!other.isMember(elements[i]))
                return false;
        }
        return true;
    }

    // d. Union of two sets
    SET unionSet(SET other) {
        SET result;
        for (int i = 0; i < elements.size(); i++)
            result.addElement(elements[i]);
        for (int i = 0; i < other.elements.size(); i++) {
            if (!result.isMember(other.elements[i]))
                result.addElement(other.elements[i]);
        }
        return result;
    }

    // d. Intersection of two sets
    SET intersection(SET other) {
        SET result;
        for (int i = 0; i < elements.size(); i++) {
            if (other.isMember(elements[i]))
                result.addElement(elements[i]);
        }
        return result;
    }

    // e. Complement (universal set given by user)
    SET complement(SET universal) {
        SET result;
        for (int i = 0; i < universal.elements.size(); i++) {
            if (!isMember(universal.elements[i]))
                result.addElement(universal.elements[i]);
        }
        return result;
    }

    // f. Set difference (A - B)
    SET setDifference(SET other) {
        SET result;
        for (int i = 0; i < elements.size(); i++) {
            if (!other.isMember(elements[i]))
                result.addElement(elements[i]);
        }
        return result;
    }

    // f. Symmetric difference
    SET symmetricDifference(SET other) {
        SET aMinusB = setDifference(other);
        SET bMinusA = other.setDifference(*this);
        return aMinusB.unionSet(bMinusA);
    }

    // g. Cartesian product
    void cartesianProduct(SET other) {
        cout << "Cartesian Product:" << endl;
        for (int i = 0; i < elements.size(); i++) {
            for (int j = 0; j < other.elements.size(); j++) {
                cout << "(" << elements[i] << ", " << other.elements[j] << ")" << endl;
            }
        }
    }

    // Print set
    void display() {
        cout << "{ ";
        for (int i = 0; i < elements.size(); i++)
            cout << elements[i] << " ";
        cout << "}" << endl;
    }
};

int main() {
    SET A, B, U;
    int choice, n, x;

    cout << "Enter number of elements in Set A: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> x; A.addElement(x); }

    cout << "Enter number of elements in Set B: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> x; B.addElement(x); }

    cout << "Enter number of elements in Universal Set U: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> x; U.addElement(x); }

    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Is Member" << endl;
        cout << "2. Power Set of A" << endl;
        cout << "3. Is A subset of B?" << endl;
        cout << "4. Union of A and B" << endl;
        cout << "5. Intersection of A and B" << endl;
        cout << "6. Complement of A" << endl;
        cout << "7. Set Difference (A - B)" << endl;
        cout << "8. Symmetric Difference" << endl;
        cout << "9. Cartesian Product (A x B)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        else if (choice == 1) {
            cout << "Enter element to check: ";
            cin >> x;
            if (A.isMember(x)) cout << x << " is in Set A" << endl;
            else cout << x << " is NOT in Set A" << endl;
        }
        else if (choice == 2) {
            A.powerset();
        }
        else if (choice == 3) {
            if (A.isSubset(B)) cout << "A is a subset of B" << endl;
            else cout << "A is NOT a subset of B" << endl;
        }
        else if (choice == 4) {
            SET result = A.unionSet(B);
            cout << "A union B = "; result.display();
        }
        else if (choice == 5) {
            SET result = A.intersection(B);
            cout << "A intersection B = "; result.display();
        }
        else if (choice == 6) {
            SET result = A.complement(U);
            cout << "Complement of A = "; result.display();
        }
        else if (choice == 7) {
            SET result = A.setDifference(B);
            cout << "A - B = "; result.display();
        }
        else if (choice == 8) {
            SET result = A.symmetricDifference(B);
            cout << "Symmetric Difference = "; result.display();
        }
        else if (choice == 9) {
            A.cartesianProduct(B);
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
