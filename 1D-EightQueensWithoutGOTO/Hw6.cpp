//Mancheno, Alex
//CS 211 - Lab section 52B
//Hw # 6
#include <iostream>
#include <cmath>
using namespace std;

//checks if the queen can be placed on current row/column:
bool valid(int q[], int c) {
    //this for-loop contains the row, upper-diagonal, and lower-diagonal test:
    for (int i = 0; i < c; i++)
        if (q[c] == q[i] || c - i == abs(q[c] - q[i])) return false;
    return true;
}

//prints array:
void print(int q[], int &s) {
    s++;
    cout << "Solution " << s << ":" << endl;
    for (int i = 0; i < 8; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

//recursive function to find all the solutions for 8-queens:
void eightQueens(int q[], int c, int s) {
    //increment row:
    q[c]++;
    //to stop program once all solutions have been found:
    if (c == -1) {
        cout << "All solutions have been found.";
        return;
    }
    //backtrack if queen cannot be placed on current column:
    if (q[c] == 8) return eightQueens(q, --c, s);
    //go to next row if queen cannot be placed on current row/column:
    if (!valid(q, c)) return eightQueens(q, c, s);
    c++;
    //if 8 queens are placed, we print:
    if (c == 8) {
        print(q, s);
        return eightQueens(q, --c, s);
    }
    //we reset row before we begin backtracking in the next recursive call:
    q[c] = -1;
    return eightQueens(q, c, s);
}

int main() {
    int q[8] = {-1}, c = 0, numberOfSolutions = 0;
    eightQueens(q, c, numberOfSolutions);
    return 0;
} 