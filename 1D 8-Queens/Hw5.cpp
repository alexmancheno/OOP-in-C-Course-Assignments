//Mancheno, Alex
//CS 211 - Lab section 52B
//Hw # 5
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int q[8], c = 0, i, numberOfSolutions = 0;
    q[0] = 0;
NC:
    c++;
    if (c == 8) goto print; //we cease testing and print results once 8 queens have been placed.
    q[c] = -1;
NR:
    q[c]++;
    //if no queen can be placed on current column, we backtrack:
    if (q[c] == 8) goto backtrack;
    //this for-loop contains the row, upper-diagonal, and lower-diagonal test:
    for (i = 0; i < c; i++) {
        if (q[c] == q[i] || c - i == abs(q[c] - q[i])) goto NR;
    }
    //we go to next column if no test fails:
    goto NC;
backtrack:
    c--;
    if (c == -1) {
        cout << "All solutions have been found." << endl;
        return 0;
    }
    goto NR;
print:
    numberOfSolutions++; //to keep track of the number of solutions found.
    cout << "Solution # " << numberOfSolutions << ": " << endl;
    //this nested for-loop prints the solution's results:
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

    cout << endl;
    goto backtrack;
}