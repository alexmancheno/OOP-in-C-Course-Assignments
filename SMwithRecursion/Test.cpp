#include <iostream>
#include <stdlib.h>
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
        }//if the current man prefers the new woman to his partner and
            //if the new woman prefers the current man to her partner:
        else if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) {
            return false;
        }//if the new man prefers the current woman to his partner and
            //if the current woman prefers the new man to her partner:
        else if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) {
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

void recursiveSM(int q[], int c, int solutionNumber) {
    q[c]++;
    if (c == -1) {
        cout << "All solutions have been found." << endl;
        return;
    }
    
    if (c == 3) {
        solutionNumber++;
        print(q, solutionNumber);
        q[c] = -1;
        return recursiveSM(q, --c, solutionNumber);
    }
    
    if (q[c] == 3) {
        q[c] = -1;
        return recursiveSM(q, --c, solutionNumber);
    }
    
    if (valid(q, c)) {
        c++;
        q[c] = -1;
    }
    
    return recursiveSM(q, c, solutionNumber);
}

int main() {
    int q[3] = {0}, numberOfSolutions = 0, c = 0;
    q[0] = -1;
    recursiveSM(q, c, numberOfSolutions);
    return 0;
}