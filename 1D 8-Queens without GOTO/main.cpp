//Mancheno, Alex
//CS 211 - Lab section 52B
//Hw # 6
#include <iostream>
#include <cmath>
using namespace std;

bool valid(int q[], int c) {
    //this for-loop contains the row, upper-diagonal, and lower-diagonal test:
    for (int i = 0; i < c; i++) {
        if (q[c] == q[i] || c - i == abs(q[c] - q[i])) return false;
    }
    return true;
}

void print(int q[]) {
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

void eightQueens(int q[], int c) {
    print(q);
    q[c]++;
    if (c == 8) print(q);
    if (c == -1) //terminate program
    if (q[c] == 8) eightQueens(q, c - 1);
    if (valid(q, c)) {
        
        eightQueens(q, c + 1);
    }
}

int main() {
    int q[8], c = 1, i, numberOfSolutions = 0;
    q[0] = 0;    
    eightQueens(q, c);

}