//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 10 - 1D 8Queen: Fancy Print

#include<iostream>
using namespace std;

//declaring 'box' here so the functions can use this datatype without problems:
typedef char box[5][7];

bool valid(int q[], int c) {
    //this for-loop contains the row, upper-diagonal, and lower-diagonal test:
    for (int i = 0; i < c; i++)
        if (q[c] == q[i] || c - i == abs(q[c] - q[i])) return false;
    return true;
}

void print(box *q[][8], int s) {
    cout << "Solution " << s << ":" << endl;
    //print the board via the pointers in array board
    //first print upper border
    for (int i = 0; i < 7 * 8; i++)
        cout << '_';
    cout << endl;
    //now print the board
    for (int i = 0; i < 8; i++)
        for (int k = 0; k < 5; k++) {
            cout << " " << char(219); //print left border
            for (int j = 0; j < 8; j++)
                for (int l = 0; l < 7; l++)
                    cout << (*q[i][j])[k][l];
            cout << char(219) << endl;
        }
    //before exiting print lower border
    cout << " ";
    for (int i = 0; i < 7 * 8; i++)
        cout << char(196);
    cout << endl << endl;
}

void makeTileSet(box bb, box wb, box &bq, box &wq) {
    //to make empty black and white boxes:
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 7; c++) {
            wb[r][c] = char(32);
            bb[r][c] = char(219);
        }
        cout << endl;
    }

    //to shape the queen:
    int queen[5][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    //to create boxes with queens:
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 7; c++) {
            if (queen[r][c] == 1) bq[r][c] = char(32);
            else                  bq[r][c] = char(219);
            if (queen[r][c] == 1) wq[r][c] = char(219);
            else                  wq[r][c] = char(32);
        }
    }
}

void fillArray(int q[], box *board[][8], box &bb, box &wb, box &bq, box &wq) {
    //to fill board with black/white boxes:
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) 
            if ((r + c) % 2 == 0)
                board[r][c] = &wb;
            else 
                board[r][c] = &bb;
    }
    //to place queens on board depending on the current solution found:
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++)
            if ((q[c] == r) && board[r][c] == &wb)
                board[r][c] = &wq;
            else if ((q[c] == r) && board[r][c] == &bb)
                board[r][c] = &bq;
    }
     
}

int main() {
    int q[8] = {0}, c = 0, numberOfSolutions = 0;
    q[0] = -1;
    typedef char box[5][7];
    box bb, wb, bq, wq, *board[8][8];
    makeTileSet(bb, wb, bq, wq);
    //same algorithm as previous 1D eight-queen programs, but now
    //the 'fillArray' function gets called when we find a solution
    //and the 'print' function prints the array of pointers instead
    //of the array with the solution:
    while (true) {
        q[c]++;
        if (c == -1) {
            cout << "All solutions have been found." << endl;
            return 0;
        } else if (c == 8) {
            fillArray(q, board, bb, wb, bq, wq);
            numberOfSolutions++;
            print(board, numberOfSolutions);
            q[c] = -1;
            c--;
        } else if (q[c] == 8) {
            q[c] = -1;
            c--;
        } else if (valid(q, c)) {
            c++;
            q[c] = -1;
        }
    }
    return 0;
}