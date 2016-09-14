//Mancheno, Alex
//CS 211 - Lab section 52B
//Hw # 6
#include <iostream>
#include <cmath>
using namespace std;

bool valid(int q[], int c) {
    //this for-loop contains the row, upper-diagonal, and lower-diagonal test:
    for (int i = 0; i < c; i++)
        if (q[c] == q[i] || c - i == abs(q[c] - q[i])) return false;
    return true;
}

void print(int q[], int &s) {
    s++;
    cout << "Solution " << s << ":" << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (q[i] == j) {
                cout << " Q |";
            } else {
                cout << "   |";
            }
        }
        cout << endl;
        cout << "--------------------------------" << endl;
    }
    cout << endl;
    return;
}

void eightQueens(int q[], int c, int s) {
    q[c]++;
    if (c == -1) {
        cout << "All solutions have been found.";
        return;
    }
    if (q[c] == 8) return eightQueens(q, --c, s);
    if (valid(q, c) == false) return eightQueens(q, c, s);
    c++;
    if (c == 8) print(q, s);
    q[c] = -1;
    return eightQueens(q, c, s);
}

int main() {
    int q[8] = {-1}, c = 0, numberOfSolutions = 0;
    eightQueens(q, c, numberOfSolutions);
    return 0;
} 