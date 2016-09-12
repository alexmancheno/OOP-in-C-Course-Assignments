//Mancheno, Alex
//CS 211 - Lab section 52B
#include <iostream>
using namespace std;

//Assignment 2:

bool equivalent1(int a[], int b[], int n) {
    for (int shifts = 0; shifts < n; shifts++) {
        if (a[0] == b[shifts]) { /*Inner for-loop will not start unless outer
                                  for-loop finds an element from each array that 
                                  are equal.*/
            for (int i = 0; i < n; i++) {
                if (a[i] != b[(i + shifts) % n])
                    return false; //With shifts accounted for, this function returns
                //false if at least one pair is not equal.
            }
            return true; //function returns true if no pair of element is not equal.
        }
    }
    return false; //function returns false if there is no pair of elements that are equal.
}

int main() {
    //shift-equivalency tests:
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 5, 1, 1}; //arrays are not shift-equivalent.   
    if (equivalent1(a, b, 5)) cout << "Arrays are shift equivalent" << endl; // test for shift-equivalency. 
    else cout << "Arrays are not shift equivalent" << endl;

    int c[] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 8};
    int d[] = {6, 7, 7, 8, 8, 1, 2, 3, 4, 5}; //arrays are shift-equivalent.   
    if (equivalent1(c, d, 10)) cout << "Arrays are shift equivalent" << endl; // test for shift-equivalency. 
    else cout << "Arrays are not shift equivalent" << endl;
    return 0;
}
