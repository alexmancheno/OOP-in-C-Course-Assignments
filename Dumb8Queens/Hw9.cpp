//Mancheno, Alex
//CS 211 - Section 52B
//Hw # 9 - Dumb 8-Queens

//brute forcing 8queens problem; testing every possible configuration:
#include<iostream>
using namespace std;

bool ok(int q[][8]) {
    //we iterate through the whole board to find the placed-queens:
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            //once we find a placed-queen, we run the tests:
            if (q[row][col] == 1) {
                int i;
                //row test:
                for (i = 0; i < col; i++)
                    if (q[row][i] == 1) return false;                
                //upper-diagonal test:
                for (i = 1; (row - i) >= 0 && (col - i) >= 0; i++)
                    if (q[row - i][col - i] == 1) return false;
                //lower-diagonal test:
                for (i = 1; (row + i) < 8 && (col - i) >= 0; i++) 
                    if (q[row + i][col - i]) return false;
            }
        }
    }
    return true; //we return true if none of the tests fail.
}

void print(int q[][8], int solution) {
    //prints solution number and board:
    cout << "Solution " << solution << ":" << endl;
    cout << "---------------------------------" << endl;
    for (int r = 0; r < 8; r++) {
        cout << "|";
        for (int c = 0; c < 8; c++)
            if (q[r][c]) cout << " Q |";
            else         cout << "   |";                
        cout << endl <<"---------------------------------" << endl;        
    }
    cout << endl;
}

int main() {
    int board[8][8] = {0};
    int count = 0;
    /*these nested for-loops change the configuration of the board in a 
     speedometer-like manner; the right-most queen changes the most times
     and the left-most queen changes the least amount of times. Every time we 
     move a queen, we call the 'valid' function and run our tests:*/
    for (int i0 = 0; i0 < 8; i0++) {
        board[i0][0] = 1;
        for (int i1 = 0; i1 < 8; i1++) {
            board[i1][1] = 1;
            for (int i2 = 0; i2 < 8; i2++) {
                board[i2][2] = 1;
                for (int i3 = 0; i3 < 8; i3++) {
                    board[i3][3] = 1;
                    for (int i4 = 0; i4 < 8; i4++) {
                        board[i4][4] = 1;
                        for (int i5 = 0; i5 < 8; i5++) {
                            board[i5][5] = 1;
                            for (int i6 = 0; i6 < 8; i6++) {
                                board[i6][6] = 1;
                                for (int i7 = 0; i7 < 8; i7++) {
                                    board[i7][7] = 1;
                                    if (ok(board)) print(board, ++count);
                                    board[i7][7] = 0;
                                }
                                board[i6][6] = 0;
                            }
                            board[i5][5] = 0;
                        }
                        board[i4][4] = 0;
                    }
                    board[i3][3] = 0;
                }
                board[i2][2] = 0;
            }
            board[i1][1] = 0;
        }
        board[i0][0] = 0;
    }
    cout << "All solutions have been found." << endl;
    return 0;
}