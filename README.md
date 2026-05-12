# 1. Create a class SET. Create member functions to perform the following SET operations:

* is member
* powerset
* subset
* union and intersection
* complement
* set difference and symmetric difference
* cartesian product

```cpp
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
```

# 2. Create a class RELATION, use Matrix notation to represent a relation. Include member functions to check if the relation is Reflexive, Symmetric, Anti-symmetric, Transitive.

```cpp
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
```

# 3. Write a Program that generates all the permutations of a given set of digits, with or without repetition.

```cpp
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

    cout << "
1. Permutations WITHOUT repetition" << endl;
    cout << "2. Permutations WITH repetition" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "
All permutations without repetition:" << endl;
        for (int i = 0; i < n; i++) used[i] = false;
        permuteWithout(0);
    } else {
        cout << "
All permutations with repetition:" << endl;
        permuteWith(0);
    }

    return 0;
}
```

# 4. For any number n, write a program to list all the solutions of the equation x1 + x2 + x3 + ...+ xn = C, where C is a constant (C<=10) and x1, x2, x3,...,xn are nonnegative integers, using brute force strategy.

```cpp
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

    cout << "
All solutions of x1 + x2 + ... + x" << n << " = " << C << ":" << endl;
    solve(0, C);
    cout << "
Total solutions: " << count << endl;

    return 0;
}
```

# 5. Write a Program to evaluate a polynomial function.

```cpp
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

    cout << "
All solutions of x1 + x2 + ... + x" << n << " = " << C << ":" << endl;
    solve(0, C);
    cout << "
Total solutions: " << count << endl;

    return 0;
}
```

# 6. Write a Program to check if a given graph is a complete graph. Represent the graph using the Adjacency Matrix representation.

```cpp
#include<iostream>
using namespace std;

int main() {
    int n; // number of vertices
    int matrix[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (0 or 1, diagonal should be 0):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "matrix[" << i+1 << "][" << j+1 << "] = ";
            cin >> matrix[i][j];
        }

    // Display the matrix
    cout << "
Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Check if complete graph
    // In a complete graph: every pair of vertices is connected
    // i.e., matrix[i][j] = 1 for all i != j
    bool isComplete = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && matrix[i][j] != 1) {
                isComplete = false;
                break;
            }
        }
        if (!isComplete) break;
    }

    if (isComplete)
        cout << "
This is a COMPLETE GRAPH (K" << n << ")." << endl;
    else
        cout << "
This is NOT a complete graph." << endl;

    // Also show total edges
    int edges = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (matrix[i][j] == 1)
                edges++;

    cout << "Total edges: " << edges << endl;
    cout << "Edges needed for complete graph: " << n*(n-1)/2 << endl;

    return 0;
}
```

# 7. Write a Program to accept a directed graph G and compute the in-degree and outdegree of each vertex.

```cpp
#include<iostream>
using namespace std;

int main() {
    int n; // number of vertices
    int matrix[10][10];

    cout << "Enter number of vertices in directed graph: ";
    cin >> n;

    cout << "Enter adjacency matrix (matrix[i][j]=1 means edge from i to j):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "matrix[" << i+1 << "][" << j+1 << "] = ";
            cin >> matrix[i][j];
        }

    // Display the matrix
    cout << "
Adjacency Matrix:" << endl;
    cout << "     ";
    for (int i = 0; i < n; i++) cout << "V" << i+1 << " ";
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "V" << i+1 << " -> ";
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << "  ";
        cout << endl;
    }

    // Compute in-degree and out-degree
    // Out-degree of vertex i = sum of row i
    // In-degree of vertex i = sum of column i
    int inDegree[10] = {0};
    int outDegree[10] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outDegree[i] += matrix[i][j]; // row sum
            inDegree[i] += matrix[j][i];  // column sum
        }
    }

    cout << "
Vertex | In-Degree | Out-Degree" << endl;
    cout << "-------|-----------|----------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  V" << i+1 << "   |     " << inDegree[i] << "     |     " << outDegree[i] << endl;
    }

    return 0;
}
```
