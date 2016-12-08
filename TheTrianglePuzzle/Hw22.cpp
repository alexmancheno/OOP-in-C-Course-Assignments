//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 22 - The Triangle Puzzle
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int row = 4, col = 5;
int inputArray[row][col], cost[row][col] = {0};

void readFromFile() {
    ifstream file;
    file.open("triangle.txt");
    string line;
    int r = 0, c = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        int n;
        while (iss >> n) {
            inputArray[r][c] = n;
            c++;
        }
        c = 0;
        r++;
    }    
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int calculateCost(int r, int c) {
    if (r < 0 || c < 0) return 0;
    
    if (cost[r][c] != 0) return cost[r][c];
    
    int rightSide = calculateCost(r - 1, c) + inputArray[r][c];
    int leftSide = calculateCost(r - 1, c - 1) + inputArray[r][c];
    
    cost[r][c] = max(rightSide, leftSide);
    return max(rightSide, leftSide);
}

void print(int a[][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; a[i][j] != -1; j++) {
            if (a[i][j] < 10) cout << a[i][j] << "  ";
            else              cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int r, c;
    
    //to fill out 'input' array with an arbitrary number, -1:
    for (r = 0; r < row; r++)
        for (c = 0; c < col; c++)
            inputArray[r][c] = -1;      

    //read numbers from file into 'input' array:
    readFromFile();
    
    print(inputArray);
    
    cout << calculateCost(row - 1, col - 1);
    return 0;
}

