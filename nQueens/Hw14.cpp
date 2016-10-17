//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 14 - nQueen

#include <cstdlib>
#include <iostream>
using namespace std;

bool valid(int q[], int c) {
    //this for-loop contains the row, upper-diagonal, and lower-diagonal test:
    for (int i = 0; i < c; i++)
        if (q[c] == q[i] || c - i == abs(q[c] - q[i])) return false;
    return true;
}

int numberOfSolutions(int n) {
    int *q = new int[n]; //dynamic array declared on the heap!
    int numOfSolutions = 0, c = 0;
    q[0] = -1;
    //same algorithm as previous programs, but now made sure that I'm not
    //accessing memory that is not legal since dynamic memory is being used:
        while (c != -1) {
         if (c == n) {
            numOfSolutions++;
            c--;
        }
         q[c]++;
         if (q[c] == n) {
            c--;
        } else if (valid(q, c)) {
            c++;
            if (c != n) q[c] = -1;
        }
    }
    delete[]q; //to reset before we call this fxn again from the main.
    return numOfSolutions;   
}

int main() {
    int n;
    cout << "Enter a number to test: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "There are " << numberOfSolutions(i) << " solutions to the " << i 
             << " queens problem." << endl;
    }    
    return 0;
}