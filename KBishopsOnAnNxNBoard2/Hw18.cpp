//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 18 - K bishops on an N * N board
#include <cmath>
#include <iostream>

using namespace std;

bool valid(int *q, int n, int c) {
    
    int row = q[c] / n, col = q[c] % n;
    
    //upper-diagonal test:
    for (int i = 0; i < c; i++)             
        if (row - col == (q[i] / n) - (q[i] % n))
            return false;
    
    //lower-diagonal test:
    for (int i = 0; i < c; i++)
        if (row + col == (q[i] / n) + (q[i] % n))
            return false;
    
    return true;
}

int numberOfSolutions(int n, int k) {
    int *q = new int [k];
    int totalSolutions = 0, c = 0;
    q[0] = -1;
    
    //same algorithm as previous backtracking programs:
    while (q[0] != n * n) {
        
        q[c]++;
        if (c == k) {
            totalSolutions++;
            c--;
        } else if (q[c] == n * n) {
            c--;
        } else if (valid(q, n, c)) {
            c++;
            q[c] = q[c - 1];
        }
    }
    
    delete[]q;
    return totalSolutions;    
}

int main() {
            
    int k, n;
    cout << "Enter a board size (enter -1 to end): ";
    cin >> n;
    cout << "Enter a number of bishops less than the board size: ";
    cin >> k;
    
    //program ends when user enters -1:
    while (n != -1) {
        if (k > n) {
            cout << "Number of bishops is larger than board size. Try again: ";            
        } else {
            cout << "Board of size " << n << " with " << k << " bishops has " 
                 << numberOfSolutions(n, k) << " solutions." << endl;
        }
        
        cout << "Enter numbers again: ";
        cin >> n;
        cin >> k;
    }      
    return 0;
}