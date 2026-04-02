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
    cout << "\nAdjacency Matrix:" << endl;
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
        cout << "\nThis is a COMPLETE GRAPH (K" << n << ")." << endl;
    else
        cout << "\nThis is NOT a complete graph." << endl;

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
