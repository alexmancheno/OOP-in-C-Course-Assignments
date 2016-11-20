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

void backtrack(int *q, int& c, int n) {
    q[c] = 0;
    
    //to look for the previously placed bishop:
    for (c -= n; q[c] == 0; c -= n) 
        if (c < 0) {
            c += (n * n - 1);
        
    }
}

int numberOfSolutions(int n, int k) {
    int *q = new int[n * n];
    int totalSolutions = 0, c = 0, bishopsPlaced = 1;
    //q[0] = 1;    
    c -= n;
    
    while (c < n * n && bishopsPlaced != 0) {
        c += n;
        
        if (c > n * n) {
            c -= n * n + 1;
            cout << "1" << endl;
        }
        
        if (valid(q, c, n) && k - bishopsPlaced > 0) {
            cout << "2" << endl;
            q[c] == 1;
            bishopsPlaced++;
        }
        
        if (bishopsPlaced == k) {
            cout << "3" << endl;
            totalSolutions++;
            backtrack(q, c, n);
            bishopsPlaced--;
        }
    }
    return totalSolutions;
}

int main() {
            
    int k, n;
    cout << "Enter a board size: ";
    cin >> n;
    cout << "Enter a number of bishops less than the board size: ";
    cin >> k;
    
    while (n != -1) {
        if (k > n) {
            cout << "Number of bishops is larger than board size. Try again: ";            
        } else {
            cout << "Board of size " << n << " with " << k << " bishops has " << numberOfSolutions(n, k) << " solutions." << endl;
        }
            cout << "Enter numbers again: ";
    cin >> n;
    cin >> k;
    }      
    return 0;
}