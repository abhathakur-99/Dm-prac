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
    cout << "\nAdjacency Matrix:" << endl;
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

    cout << "\nVertex | In-Degree | Out-Degree" << endl;
    cout << "-------|-----------|----------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  V" << i+1 << "   |     " << inDegree[i] << "     |     " << outDegree[i] << endl;
    }

    return 0;
}
