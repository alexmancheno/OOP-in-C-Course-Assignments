//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 22 - The Triangle Puzzle
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int row = 100, col = 101;
int inputArray[row][col], cost[row][col] = {0};

void readFromFile() {
    ifstream file;
    file.open("triangle.txt");
    string line;
    int r = 0, c = 0;
    while (getline(file, line)) { //read each line
        istringstream iss(line);
        int n;
        while (iss >> n) { //read each number from every line
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
    //stop this recursive ladder if we are out of bounds:
    if (r < 0 || c < 0) return 0;
    
    //stop this recursive ladder if cost has been calculated:
    if (cost[r][c] != 0) return cost[r][c];
    
    //start calculating cost-matrix starting from the bottom via recursion:
    int rightSide = calculateCost(r - 1, c) + inputArray[r][c];
    int leftSide = calculateCost(r - 1, c - 1) + inputArray[r][c];
    
    //fill cost-matrix once recursive calculations are finished:
    cost[r][c] = max(rightSide, leftSide);
    return cost[r][c];
}

void printMaxPath(int r, int c) {
    //recursive print of "maximum path":
    if (r == 0) {
        return; //return if we've run out of rows to print
    }
    if (cost[r - 1][c] > cost[r - 1][c - 1]) { 
        //print upper-left side of inputArray if cost to that side is higher:
        printMaxPath(r - 1, c);
        if (r % 10 == 0) cout << endl;
        cout << inputArray[r - 1][c] << " ";
    } else {
        //print upper-right side of inputArray if cost to that side is higher:
        printMaxPath(r - 1, c - 1);
        if (r % 10 == 0) cout << endl;
        cout << inputArray[r - 1][c - 1] << " ";
    }    
}

int main() {
    int r, c;
    
    //to fill out 'input' array with an arbitrary number, -1:
    for (r = 0; r < row; r++)
        for (c = 0; c < col; c++)
            inputArray[r][c] = -1;      

    //read numbers from file and store into 'inputArray':
    readFromFile();   
    
    int lastRow[col] = {0};
    
    //to calculate 'cost' matrix using 'inputArray':
    for (int i = 0; i < col; i++) 
        lastRow[i] = calculateCost(row - 1, i);
    
    //to find max cost and keep track of position on last row of cost matrix:
    int max = lastRow[0], indexOfMax;
    for (int i = 1; i < col; i++) {
        if (lastRow[i] > max) {
            max = lastRow[i];
            indexOfMax = i;
        }
    }
    
    //to print sequence:
    cout << "Sequence of \"maximum path\": " << endl << endl;    
    printMaxPath(row - 1, indexOfMax);
    cout << inputArray[row - 1][indexOfMax];
    
    cout << endl << endl << "The value of the maximum sum is: " << max << endl;
    return 0;
}

