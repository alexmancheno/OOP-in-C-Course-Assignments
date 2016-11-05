//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 18 - K bishops on an N * N board
#include <iostream>
#include <cmath>
using namespace std;

bool valid(int *q, int c, int n) {
    //upper-diagonal test:
    for (int i = c - (n + 1); i >= 0; i -= n + 1) 
        if (q[i] == 1) return false;
    
    //lower-diagonal test:
    for (int i = c + (n - 1); i < n * n; i += n - 1)
        if (q[i] == 1) return false;
   
    return true;
}

int numberOfSolutions(int n, int k) {
    int *q = new int[n * n];
    int totalSolutions = 0, c = 0, bishopsPlaced = 0, rowCounter = 0;
    
    c -= n;
    
    while (c <= (n * n * n - n) && bishopsPlaced != 0) {
        c += n;
        rowCounter++;
        
        if (rowCounter == n) {
            c -= n * n;
            c++;
            rowCounter -= n;
        }
        if (valid(q, c, n)) {
            q[c] == 1;
        }
    }
}

int main() {
            
    int k, n;
    cout << "Enter a board size: ";
    cin >> n;
    cout << "Enter a number of bishops less than the board size: ";
    cout >> k;
    while (n != -1) {
        if (k > n) {
            cout << "Number of bishops is larger than board size. Try again: ";
            cin >> n >> k;
        } else {
            cout << "Board of size " << n << " with " << k << " bishops has " << numberOfSolutions(n, k) << " solutions.";
        }
    }
       
    return 0;
}