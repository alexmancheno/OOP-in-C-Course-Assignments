//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 19 - Shortest Path (non-recursively)
#include <iostream>

using namespace std;
const int rows = 5;
const int cols = 6;

int minimum(int q[][cols], int r, int c) {
    //to return the minumum of the three adjacent boxes:
    
    int down = r + 1, left = r, up = r - 1;
    
    if (down == rows) down = 0;
    if (up < 0) up = rows - 1;
    
    int minimum = q[up][c - 1];
    if (minimum > q[left][c - 1]) minimum = q[left][c - 1];
    if (minimum > q[down][c - 1]) minimum = q[down][c - 1];
    
    return minimum;
}

int shortestRoute(int q[][cols], int r, int c) {
    int down = r + 1, left = r, up = r - 1;
    
    //to prevent from going out of bounds:
    if (down == rows) down = 0;
    if (up < 0) up = rows - 1;    
    
    int index = up;
    int minimum = q[up][c];
    
    if (minimum > q[left][c]) {
        index = left;
        minimum = q[left][c];
    }
    
    if (minimum > q[down][c]) {
        index = down;
        minimum = q[down][c];
    }
    return index;
}

void print(int a[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] < 10) cout << a[i][j] << "  ";
            else              cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int weight[rows][cols] = {
        {3, 4, 1, 2, 8, 6},
        {6, 1, 8, 2, 7, 4},
        {5, 9, 3, 9, 9, 5},
        {8, 4, 1, 3, 2, 6},
        {3, 7, 2, 8, 6, 4}
    };
    
    int memo_cost[rows][cols] = {0};

    //to initialize first column of memo_cost matrix:
    for (int i = 0; i < rows; i++)
        memo_cost[i][0] = weight[i][0];

    //to finish filling in memo_cost matrix:
    for (int i = 1; i < cols; i++)   
        for (int j = 0; j < rows; j++) 
            memo_cost[j][i] = minimum(memo_cost, j, i) + weight[j][i];
    
    cout << "cost matrix: " << endl;
    print(memo_cost);

    int finalStep = memo_cost[0][cols - 1], index = 0, c = cols - 1;
    
    //to find index and path with the minimum cost:
    for (int i = 1; i < rows; i++) {
        if (finalStep > memo_cost[i][c]) {
            finalStep = memo_cost[i][c];
            index = i;
        }
    } 
    
   
    int route[cols - 1]; 
    route[c] = index;
    
    //to fill in array with shortest path:
    for (c--; c >= 0; c--) 
        route[c] = shortestRoute(memo_cost, route[c + 1], c);
    
    //print route:
    cout << endl <<"shortest path route: ";
    for (int i = 0; i < cols; i++) 
        cout << route[i] << " ";
    
    cout << endl << "minimum cost of shortest route: " << finalStep << endl;
    return 0;
}