#include<iostream>
using namespace std;

class RELATION {
public:
    int matrix[10][10];
    int n; // number of elements

    void input() {
        cout << "Enter number of elements in set: ";
        cin >> n;
        cout << "Enter the relation matrix (0 or 1):" << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cout << "matrix[" << i+1 << "][" << j+1 << "] = ";
                cin >> matrix[i][j];
            }
    }

    void display() {
        cout << "\nRelation Matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    // Reflexive: matrix[i][i] = 1 for all i
    bool isReflexive() {
        for (int i = 0; i < n; i++)
            if (matrix[i][i] != 1)
                return false;
        return true;
    }

    // Symmetric: if matrix[i][j]=1 then matrix[j][i]=1
    bool isSymmetric() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] != matrix[j][i])
                    return false;
        return true;
    }

    // Anti-symmetric: if matrix[i][j]=1 and matrix[j][i]=1 then i==j
    bool isAntiSymmetric() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1)
                    return false;
        return true;
    }

    // Transitive: if matrix[i][j]=1 and matrix[j][k]=1 then matrix[i][k]=1
    bool isTransitive() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[i][k] != 1)
                        return false;
        return true;
    }

    void checkType() {
        bool ref = isReflexive();
        bool sym = isSymmetric();
        bool antisym = isAntiSymmetric();
        bool trans = isTransitive();

        cout << "\nReflexive: " << (ref ? "Yes" : "No") << endl;
        cout << "Symmetric: " << (sym ? "Yes" : "No") << endl;
        cout << "Anti-Symmetric: " << (antisym ? "Yes" : "No") << endl;
        cout << "Transitive: " << (trans ? "Yes" : "No") << endl;

        if (ref && sym && trans)
            cout << "\nThis is an EQUIVALENCE RELATION." << endl;
        else if (ref && antisym && trans)
            cout << "\nThis is a PARTIAL ORDER RELATION." << endl;
        else
            cout << "\nThis is NONE of the above." << endl;
    }
};

int main() {
    RELATION r;
    r.input();
    r.display();
    r.checkType();
    return 0;
}
