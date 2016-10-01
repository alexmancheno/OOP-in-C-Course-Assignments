#include <cstdlib>
#include <iostream>
using namespace std;

int mp [3][3] = {
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
        if (q[c] == q[i])
            return false;
        else if ((mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) ||
                 (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]))
            return false;
    }
    return true;
}

void print(int q[], int numberOfSolutions) {
    cout << "Solution " << numberOfSolutions << ":" << endl;
    cout << "Man   Woman" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << "     " << q[i] << endl;
    }
}

int main() {
    int q[3] = {0}, numberOfSolutions = 0, c = 0;
    q[0] = -1;
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