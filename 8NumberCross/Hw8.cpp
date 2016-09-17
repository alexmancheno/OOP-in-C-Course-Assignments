#include <iostream>
#include <cmath>
using namespace std;

bool valid(int q[], int c) {
    for (int col = 0; col < c; col++) {
        if (q[col] == q[c]) {
            return false;
        }
    }
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
    return true;
}

void print(int q[], int &s) {
    s++;
    cout << "Solution " << s << ": " << endl; 
    cout << "   " << q[1] << " " << q[6] << endl;
    cout << " " << q[0] << " " << q[2] << " " << q[5] << " " << q[7] << endl;
    cout << "   " << q[3] << " " << q[4] << endl; 
}

int main() {
    int q[8] = {100, 100, 100, 100, 100, 100, 100, 100}, c = 0, numberOfSolutions = 0;
    q[0] = 0;

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