//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 10 - 1D 8Queen: Fancy Print

/*Hi Changlin, 
    I was just with you at your office (Thursday between 4:30-6:15pm) and 
    you said to leave a comment about the way this code prints on the Venus
    server is acceptable, though it compiles/prints perfectly on Netbeans 
    (my compiler). And if you happen to find why exactly it prints the way
    it does as of now on the Venus server, please let me know! I'm definitely
    curious why it prints this way.
 
    So the way it prints is that the white boxes print fine, but the black
    boxes/queens mess up when they print. This doesn't occur on Netbeans, 
    and prints perfectly on there.*/

#include<iostream>
#include<cstdlib>
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
    cout << "Solution " << s << ":" << endl << " ";
    //print the board via the pointers in array board
    //first print upper border
    for (int i = 0; i < 7 * 8 + 2; i++)
        cout << char(196);
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
    for (int i = 0; i < 7 * 8 + 2; i++)
        cout << char(219);
    cout << endl << endl;

    //now we reset the board after we are finished printing:
}

void makeTileSet(box bb, box wb, box &bq, box &wq) {
    //to make empty black and white boxes:
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 7; c++) {
            wb[r][c] = ' ';
            bb[r][c] = char(219);
        }
        // cout << endl;
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
            if (queen[r][c] == 1) bq[r][c] = ' ';
            else bq[r][c] = char(219);
            if (queen[r][c] == 1) wq[r][c] = char(219);
            else wq[r][c] = ' ';
        }
    }
}

void fillArray(int board[8], box *boardPrint[][8], box *bB, box *wB, box *bQ, box *wQ) {
    //to fill board with black/white boxes:
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if((i+j)%2==0)
            {
                if(board[i]== j) boardPrint[i][j]=wQ;
                else boardPrint[i][j]=wB;
            }else {
                if(board[i]== j) boardPrint[i][j]=bQ;
                else boardPrint[i][j]=bB;
            }
        }
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
            fillArray(q, board, &bb, &wb, &bq, &wq);
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
        //fillArray(q, board, bb, wb, bq, wq);
        //print(board, numberOfSolutions);
    }
    return 0;
}