//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 19 - Shortest Path (recursively)

#include <iostream>
using namespace std;

const int rows = 5, cols = 6;
int memo_cost[rows][cols];

int calculateCost( int r, int c) {
    
    //to prevent from going out of bounds:
    if (r < 0) r = rows - 1;
    if (r == rows) r = 0;
    
    static int weight[rows][cols] = {
        {3, 4, 1, 2, 8, 6},
        {6, 1, 8, 2, 7, 4},
        {5, 9, 3, 9, 9, 5},
        {8, 4, 1, 3, 2, 6},
        {3, 7, 2, 8, 6, 4}};
    
    //return the cost if it has been calculated already.
    if (memo_cost[r][c] != 0) return memo_cost[r][c];
    
    //check for the base case.
    if (c == 0) {
        memo_cost[r][c] = weight[r][c];
        return weight[r][0];
    }

    // Calculate the costs of the 3 adjacent squares by calling the function recursively.
    int up = calculateCost(r - 1, c - 1) + weight[r][c];
    int left = calculateCost(r, c - 1) + weight[r][c];
    int down = calculateCost(r + 1, c - 1) + weight[r][c];
    
    // Find the minimum of the 3 costs.
    int min = left;
    if (min > up) min = up;
    if (min > down) min = down;    
    
    //assign minimum to memo_cost matrix and return minimum to caller:
    memo_cost[r][c] = min;
    return min;
}

void findShortestPath(int q[], int r, int c) {
    
    //stop recursion once 'shortest route' array is filled:
    if (c < 0) return; 
    
    //to prevent from going out of bounds:
    int down = r + 1, left = r, up = r - 1;
    if (down == rows) down = 0;
    if (up < 0) up = rows - 1;
    
    //to keep track of index of the lowest adjacent box:
    int index = up;
    int minimum = memo_cost[up][c];
    
    if (minimum > memo_cost[left][c]) {
        index = left;
        minimum = memo_cost[left][c];
    }
    
    if (minimum > memo_cost[down][c]) {
        index = down;
        minimum = memo_cost[down][c];
    }
    
    //once index is found, store it in the array passed in as an argument:
    q[c] = index;
    
    //do another recursive call to fill in previous column:
    findShortestPath(q, index, --c);
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
    int minRow = 0;
    int ex[rows], shortestPath[cols];
    
    //to initialize memo_cost matrix and save last column into 'ex' matrix:
    for (int i = 0; i < rows; i++) {
        ex[i] = calculateCost(i, cols - 1);
    }
    
    //to find index of the minimum cost of last column:
    int temp = ex[0];
    for (int i = 1; i < rows; i++) {
        if (ex[i] > temp) {
            temp = ex[i];
            minRow = i;
        }
    }
    
    cout << "cost matrix: " << endl;
    print(memo_cost);
    
    shortestPath[cols - 1] = minRow;
    findShortestPath(shortestPath, minRow, cols - 1);
    
    cout << "shortest route: ";
    for (int i = 0; i < cols; i++) {
        cout << shortestPath[i] << " ";
    }
    
    cout << endl <<"cost of shortest path: " << memo_cost[shortestPath[cols - 1]][cols - 1]; 
    return 0;
}