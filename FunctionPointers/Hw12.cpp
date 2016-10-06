//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 12 - Function Pointers
#include <iostream>
#include <cstdlib>
using namespace std;

//declaring a type: a pointer to a function that takes in a double and returns a double:
typedef double (*FUNC)(double);

//takes in a function with a defined prototype and 2 doubles, and returns the output
//(a double) of this function with the 2 other parameters (which are doubles):
double integrate(FUNC f, double a, double b) {
    double sum = 0;
    for (double x = a; x < b; x += .0001) 
        sum += f(x) * 0.0001; 
    return sum;
}

//for single-dimensional integration:
double line(double x) {
    return x;
}

//for double-dimensional integration:
double square(double x) {
    return x * x;
}

//for triple-dimensional integration:
double cube(double x) {
    return x * x * x;
}

int main () {
    cout << "The integral of f(x) = x between 1 and 5 is: " << integrate(line, 1, 5) << endl;
    cout << "The integral of f(x) = x between 1 and 5 is: " << integrate(square, 1, 5) << endl;
    cout << "The integral of f(x) = x between 1 and 5 is: " << integrate(cube, 1, 5) << endl;
    return 0;
}