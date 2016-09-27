//Mancheno, Alex
//CS 211 - Section 52B
//Hw 7B - Understanding arrays as pointers
#include <iostream>
using namespace std;

int main() {
    int b[3][2];
    int i = 12312;
    /*the following gets the size of the whole array in terms of bytes,
     which is row * col = 3 * (4 * 2) = 24:*/
    cout << sizeof (b) << endl;
    /*the following gets the size of the pointer to the first element
     the array, which is always 8 for an integer on my machine:*/
    cout << sizeof (b + 0) << endl;
    /*the following gets the size of the *element* to first element
     of the array, which here is (int size) * (# of ints in this element) =
     4 * 2 = 8 */
    cout << sizeof (*(b + 0)) << endl;
    //the address of the pointer to the first element:
    cout << "The address of b is: " << b<< endl;
    //address of the second element to b, which is 8 bytes ahead of b:
    cout << "The address of b+1 is: " << b[0][0] + 5 << endl;
    //since an array is a pointer to the first element, this also gets the address 
    //of the pointer to the first element:
    cout << "The address of &b is: " << &b << endl;
    //gets the address that is ahead of the entire array, which is 24 bytes ahead
    //of b, which in hexadecimal is represented as 18 and hence the memory difference
    //between &b and &b + 1:
    cout << "The address of &b+1 is: " << &b + 1 << endl << endl;
    return 0;
}

