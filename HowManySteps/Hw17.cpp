//Mancheno, Alex
//CS 211 - Section 52B
//Hw # 17 - How many steps taken?

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {

    ifstream myFile;
    myFile.open("class.txt");
    
    int numOfClasses, studentsHeight, stepsTaken = 0;
    vector<int> students;

    if (myFile != 0) {
        cout << "File opened successfully!" << endl;
        string line;
        getline(myFile, line);
        istringstream iss(line);
        iss >> numOfClasses;
        cout << numOfClasses << endl;

        int i, j;
        
        //to get heights from current class:
        for (i = 0; i < numOfClasses; i++) {
            getline(myFile, line, ' ');
            cout << line;
            for (j = 0; j < 19; j++) {
                getline(myFile, line, ' ');
                istringstream iss(line);
                iss >> studentsHeight;
                students.push_back(studentsHeight);
            }
            
            //to get last height number from current class:
            getline(myFile, line, '\n');
            istringstream iss(line);
            iss >> studentsHeight;
            students.push_back(studentsHeight);

            //to sort and get number of steps taken:
            for (int r = 0; r < 20; r++) {
                int newPosition = 0, OldPosition = 0;
                for (int t = 0; t < r; t++) {
                   if (students[r] < students[t]) {
                       int temp = students[r];
                       students.erase(students.begin() + r);
                       students.insert(students.begin() + t, temp);
                       newPosition = t;
                       OldPosition = r;
                   }
                }
                stepsTaken += OldPosition - newPosition;
            }

            cout << " "  << stepsTaken << endl;
            cout << endl;
            students.clear();
            stepsTaken = 0;
        }

        myFile.close();
        return 0;
    }
}