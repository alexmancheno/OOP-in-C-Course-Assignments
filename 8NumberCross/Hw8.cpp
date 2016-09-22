//Mancheno, Alex
//CS 211 - Section 52B
//Hw # 8
#include <iostream>
#include <cmath>
using namespace std;

bool valid(int q[], int c) {
    //this for-loop checks if the number already is on the board:
    for (int col = 0; col < c; col++) 
        if (q[col] == q[c]) return false;
    /*following block of if/elif statements contains the tests for each
    individual column to check whether the difference between our current column
    and any adjacent column is less than 2:
    */
    if (c == 1) {
        if (abs(q[c] - q[0]) < 2) return false;      
    } else if (c == 2) {
        if (abs(q[c] - q[0]) < 2) return false; 
        else if (abs(q[c] - q[1]) < 2) return false; 
    } else if (c == 3) {
        if (abs(q[c] - q[0]) < 2) return false; 
        else if (abs(q[c] - q[2]) < 2) return false; 
    } else if (c == 4) {
        if (abs(q[c] - q[3]) < 2) return false; 
        else if (abs(q[c] - q[2]) < 2) return false; 
    } else if (c == 5) {
        if (abs(q[c] - q[1]) < 2) return false; 
        else if (abs(q[c] - q[2]) < 2) return false; 
        else if (abs(q[c] - q[3]) < 2) return false; 
        else if (abs(q[c] - q[4]) < 2) return false; 
    } else if (c == 6) {
        if (abs(q[c] - q[1]) < 2) return false; 
        else if (abs(q[c] - q[2]) < 2) return false; 
        else if (abs(q[c] - q[5]) < 2) return false; 
    } else if (c == 7) {
        if (abs(q[c] - q[4]) < 2) return false; 
        else if (abs(q[c] - q[5]) < 2) return false; 
        else if (abs(q[c] - q[6]) < 2) return false;         
    }
    return true; //method returns true if none of our tests fail.
}

void print(int q[], int &s) {
    s++;
    //to print our board:
    cout << "Solution " << s << ": " << endl; 
    cout << "   " << q[1] << " " << q[6] << endl;
    cout << " " << q[0] << " " << q[2] << " " << q[5] << " " << q[7] << endl;
    cout << "   " << q[3] << " " << q[4] << endl; 
}

int main() {
    //we set every column to our board 'q' an arbitrary number that does not
    //interfere with the tests from our 'valid' method above:
    int q[8] = {100, 100, 100, 100, 100, 100, 100, 100},
    c = 0, numberOfSolutions = 0;
    //we set first column to 0 so the following while loop begins at 1 correctly:
    q[0] = 0;
    /*this while-loop contains a similar algorithm to the 8queen problems; we 
     increment row if we cannot place the number there, increment column when we 
     can, backtrack if we cannot increment column, print when we find a solution,
     and end the program when all solutions are found:*/
    while (true) {
        q[c]++;
        if (c == -1) {
            cout << "All solutions have been found.";
            return 0;
        } else if (q[c] == 9) {
            q[c] = 100;
            c--;
            continue;
        } else if (!valid(q, c)) {

            continue;
        }
        c++;
        if (c == 8) {
            print(q, numberOfSolutions);
            q[c] = 100;
            c--;
            continue;
        }
        q[c] = 0;
    }
    return 0;
}