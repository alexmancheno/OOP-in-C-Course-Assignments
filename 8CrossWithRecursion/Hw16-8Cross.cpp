//Mancheno, Alex
//CS 211 - Section 52B
//Hw # 16 - 8Cross with recursion

#include <cstdlib>
#include <cmath>
#include <iostream>
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
    
    return true; //return true if no test fails.
}

void print(int q[], int s) {
    //to print our board:
    cout << "Solution " << s << ": " << endl;
    cout << "   " << q[1] << " " << q[6] << endl;
    cout << " " << q[0] << " " << q[2] << " " << q[5] << " " << q[7] << endl;
    cout << "   " << q[3] << " " << q[4] << endl;
}

void recursiveEightCross(int q[], int c, int &solutionNumber) {

    if (c == -1) {
        cout << "All solutions have been found." << endl;
        return;
    }
    q[c]++;
    
    if (q[c] == 9) {
        q[c] = 100;
        return recursiveEightCross(q, --c, solutionNumber);
    }
    
    if (!valid(q, c))
        return recursiveEightCross(q, c, solutionNumber);
    c++;
    
    if (c == 8) {
        solutionNumber++;
        print(q, solutionNumber);
        //q[c] = 100;
        return recursiveEightCross(q, --c, solutionNumber);
    }
    
    q[c] = 0;
    return recursiveEightCross(q, c, solutionNumber);
}

int main() {
    int q[8] = {100, 100, 100, 100, 100, 100, 100, 100},
    c = 0, numberOfSolutions = 0;
    q[0] = 0;
    recursiveEightCross(q, c, numberOfSolutions);
}
