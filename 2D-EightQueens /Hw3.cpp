//Mancheno, Alex
//CS 211 - Lab section 52B
//Hw # 3
#include <iostream>
using namespace std;

int main() {
    int b[8][8] = {0};
    int row = 0, col = 0, i, numberOfSolutions = 0;
    b[0][0] = 1;
nextColumn:
    row = (-1);
    col++;
    if (col == 8) { //if every queen has been placed for this solution, then array prints.
        cout << "Solution #" << numberOfSolutions + 1 << ":" << endl;
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                cout << b[r][c] << ' ';
            }
            cout << endl;
        }
        numberOfSolutions++; //to keep track of the number of solutions found
        cout << endl;
    }
    
nextRow:
    row++;
    if (row == 8) goto backtrack;
    //row-test:
    for (i = 0; i < col; i++) {
        if (b[row][i] == 1) goto nextRow;
    }
    //upper-diagonal test:
    for (i = 1; (row - i) >= 0 && (col - i) >= 0; i++) {
        if (b[row - i][col - i] == 1) goto nextRow;
    }
    //lower-diagonal test:
    for (i = 1; (row + i) < 8 && (col - i) >= 0; i++) {
        if (b[row + i][col - i]) goto nextRow;
    }
    b[row][col] = 1;
    goto nextColumn;
    
    //this will happen if 'r' increments to 8:
backtrack:
    col--; //go back to previous column to put queen on higher-indexed row.
    if (col == -1) {
        cout << "Every possible solution has been found.";
        return 0; //program ends if every possible solution has been found.
    }
    //to keep track of what row to start after during backtrack:
    for (int i = 0; i < 8; i++) {
        if (b[i][col] == 1) {
            b[i][col] = 0;
            row = i;
            goto nextRow;
        }
    }
}
