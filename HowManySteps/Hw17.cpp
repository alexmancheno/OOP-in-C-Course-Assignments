#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

//void swap(int q, )

int main() {

    ifstream myFile;
    myFile.open("class.txt");
    int numOfClasses, studentsHeight, numberOfStepsTaken = 0;
    vector<int> students;

    if (myFile != 0) {
        cout << "File opened successfully!" << endl;
        string line = "";
        getline(myFile, line);
        istringstream iss(line);
        iss >> numOfClasses;
        cout << numOfClasses << endl;

        int i, j, k;
        for (i = 0; i < numOfClasses; i++) {
            getline(myFile, line);
            
            for (i = 0; i < line.length(); i++) {
                
            }
            
            /* for (j = 0; j < ; j++) {
                getline(myFile, number, ' ');
                cout << number << " ";
                //istringstream iss(line);
                //iss >> studentsHeight;
                //cout << studentsHeight << " ";
                //students.push_back(studentsHeight);
            }*/

            /*for (int j = 0; j < 20; j++)
                cout << students[j] << " ";
            cout << endl;
            for (j = 0; j < 19; j++) {
                if (students[j] > students[j + 1]) {
                    for (k = j - 1; k >= 0; k--) {
                        if (students[j] < students[k]) {
                            students.insert(students.begin() + k, students[j]);
                            numberOfStepsTaken += j + 1;
                        }
                    }
                }
            }
             */
            //cout << numberOfStepsTaken << endl;
            cout << endl;
            //students.clear();
            //numberOfStepsTaken = 0;
        }

        myFile.close();
        return 0;
    }
}