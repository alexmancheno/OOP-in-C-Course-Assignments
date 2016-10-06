//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 11 - Stable Marriage

#include <cstdlib>
#include <iostream>
using namespace std;

//preference-for-women and preference-for-men arrays:
int mp[3][3] = {
    {0, 2, 1},
    {0, 2, 1},
    {1, 2, 0}
};
int wp[3][3] = {
    {2, 1, 0},
    {0, 1, 2},
    {2, 0, 1}
};

bool valid(int q[], int c) {
    for (int i = 0; i < c; i++) {
        //if new woman is already assigned to a man:
        if (q[c] == q[i]) {
            return false;
        } //if the current man prefers the new woman to his partner and
          //if the new woman prefers the current man to her partner:
        else if (mp[i][q[i]] < mp[i][q[c]] && wp[q[c]][c] < wp[q[c]][i]) {
            return false;
        } //if the new man prefers the current woman to his partner and
          //if the current woman prefers the new man to her partner:
        else if (mp[c][q[i]] < mp[c][q[c]] && wp[q[c]][c] > wp[q[c]][i]) {
            return false;
        }
    }
    return true; //return true if none of the tests fail.
}

void print(int q[], int numberOfSolutions) {
    cout << "Solution " << numberOfSolutions << ":" << endl;
    cout << "Man   Woman" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << "     " << q[i] << endl;
    }
    cout << endl;
}

int main() {
    int q[3] = {0}, numberOfSolutions = 0, c = 0;
    q[0] = -1;
    /*similar algorithm to previous 1D array eight-queen programs, but
     * with different array sizes; we increment column with every iteration
     * of the while-loop, end program once every solution is found, print 
     * and backtrack when a solution is found, backtrack when we cannot
     * match current man to any woman, and go to a new man once current 
     * man is matched:  */
    while (true) {
        q[c]++;
        if (c == -1) {
            cout << "All solutions found." << endl;
            return 0;
        } else if (c == 3) {
            numberOfSolutions++;
            print(q, numberOfSolutions);
            q[c] = -1;
            c--;
        } else if (q[c] == 3) {
            q[c] = -1;
            c--;
        } else if (valid(q, c)) {
            c++;
            q[c] = -1;
        }
    }
    return 0;
}