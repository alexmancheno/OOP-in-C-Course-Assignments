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

        int i, j, k;
        
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
            
            //to get last height number from current class without problems:
            getline(myFile, line, '\n');
            istringstream iss(line);
            iss >> studentsHeight;
            students.push_back(studentsHeight);
            
            cout << " (before sort): ";
            for (j = 0; j < 20; j++)
                cout << students[j] << " ";
            cout << endl;

            //sort:
            for (j = 0; j < 20; j++) {
                if (students[j] < students[0]) {
                    int temp = students[j];
                    students.erase(students.begin() + j);
                    students.insert(students.begin(), temp);
                    stepsTaken += j;
                }
            }
                     
            cout << i + 1 << " (after sort):  ";
            for (j = 0; j < 20; j++)
                cout << students[j] << " ";
            cout << endl;

            cout << "number of steps taken: " << stepsTaken << endl;
            cout << endl;
            students.clear();
            stepsTaken = 0;
        }

        myFile.close();
        return 0;
    }
}