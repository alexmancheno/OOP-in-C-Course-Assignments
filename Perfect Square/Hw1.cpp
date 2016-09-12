//Mancheno, Alex
//CS 211 - Lab section 52B
#include <iostream>
using namespace std;

//Assignment 1:

int perfectSquare() {
    /*This function attempts to return the first perfect square whose last 
    two digits are both odd.*/
    int x = 0, perfectSquare;
    while (true) {
        perfectSquare = x * x; //creating perfect square to then test last two digits.
        if ((perfectSquare % 2 == 1) && ((perfectSquare) / 10) % 2 == 1) {
            break;
        }
        x++;
    }
    return perfectSquare;
}

int main() {
    cout << perfectSquare() << endl;
    /* The answer printed is obviously not the right answer. What seems to be
     * happening is that the variables inside the function increment past the capacity 
     * of the 'perfectSquare' int variable. My conclusion is that once it passes 
     * the capacity, 'perfectSquare' loses some of its digits (which after searching 
     * around the Internet a bit, I think this is called an 'overflow') but still
     * meets the 'break' condition inside the loop and thus returning the "answer",
     * which in this case is 131073.*/
    return 0;
}


