//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 18 - K bishops on an N * N board
#include <iostream>
using namespace std;

bool valid(int **q[], int r, int c) {
    //upper-diagonal test:
    for (int i = 1; (r - i) >= 0 && (c - i) >= 0; i++)
        if (*q[r - i][c - i] == 1) {
            cout << "upper-diagonal test fails" << endl;
            return false;
        }
    //lower-diagonal test:
    for (int i = 1; (r + i) < c && (c - i) >= 0; i++)
        if (*q[r + i][c + i] == 1) {
            cout << "lower-diagonal test fails" << endl;
            return false;
        }
    return true;
}

void backtrack(int **q, int n, int& r, int& c) {
    q[r][c] = 0;
    cout << "we're attempting to backtrack" << endl;
    for (; c >= 0; c--) {
        cout << "first loop is at: " << c << endl;
        for (; r >= 0; r--) {
            cout << "second loop is at: " << r << endl;
            if (q[r][c] == 1) {
                cout << "we're returning" << endl;
                q[r][c] = 0;
                return;
            }
        }
        r = n - 1;
    }
    //if (c == -1) c++;
    return;
}

int numberOfSolutions(int k, int n) {
    int ** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
    }
    cout << "board created" << endl;
    int numberOfSolutions = 0, r = -1, c = 0, bishopsPlaced = 0;
    
    while (c != -2) {
        if (c == n && bishopsPlaced == 0) break;
        r++;
        cout << "row is: " << r << endl;
        if (c == n) {
            cout << "backtrack attempted" << endl;
            backtrack(board, n, r, c);
        }
        if (r == n) {
            c++;
            cout << "column is: " << c << endl;
            r = -1;
        } else if (board[r][c] == 0 && valid(&board, r, c)) {
            board[r][c] = 1;
            bishopsPlaced++;
            cout << "bishops placed: " << bishopsPlaced << endl;                    
        } if (bishopsPlaced == k) {
            cout << "solution " << numberOfSolutions + 1<< " found and backtrack attempted" << endl;
            backtrack(board, n, r, c);
            numberOfSolutions++;
            bishopsPlaced--;
            cout << "backtrack succeeded" << endl;
        }        
    }
    
    delete[] board;
    return numberOfSolutions;
}

int main() {
    
    int k, n, answer;
    cout << "Enter a number of bishops and a board size: ";
    cin >> k >> n;
    while (k > n) {
        cout << "K is larger than N. Try again: ";
        cin >> k >> n;
    }
    answer = numberOfSolutions(k, n);
    cout << "Board of size " << n << " with " << k << " bishops has " << answer << " solutions.";
    return 0;
}