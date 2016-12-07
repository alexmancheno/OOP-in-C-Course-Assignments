//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 21 - Continued Fraction

//compiled on venus server using: g++ -std=c++0 Hw21.cpp -o Hw21
//to_string() does not work with regular compiler!

#include <iostream>
#include <cmath>
using namespace std;

double continued_frac_1(int a[], int i) {
    if (a[i] == -1)
        return a[i];
    return (a[i] + 1 / continued_frac_1(a, i + 1));
}

int* continued_frac_2(int a[], int i) {
    static int v[2] = {0, 0}; //memoized array

    int temp = v[0];

    if (i == 2) {//base case
        v[1] = 1;
        v[0] = a[2];
        return v;
    }
    continued_frac_2(a, i + 1); //recursive call
    temp = v[0];
    v[0] = a[i] * temp + v[1];
    v[1] = temp;
    return v;
}

//rat class for the 3rd function:
class Rat {
private:
    int n;
    int d;
public:

    Rat() {
        n = 0;
        d = 1;
    }

    Rat(int i) {
        n = i;
        d = 1;
    }

    Rat(int i, int j) {
        n = i;
        d = j;   
    }

    int gcd(int n, int d) {
        if (d == 0) return n;
        return gcd(d, n % d);
    }

    //to reduce fraction to lowest terms:
    void reduce() {
        int x = gcd(n, d);
        n /= x;
        d /= x;
    } 
    //to grant the following functions access to Rat private variables:
    friend ostream& operator<<(ostream& os, Rat r);    
};

ostream& operator<<(ostream& os, Rat r) {
    r.reduce(); //reduce fraction to lowest terms before turning it into an appropriate string
    
    int wholeNumber = r.n / r.d;
    int numerator = abs(r.n) % r.d; 
    
    //to give appropriate mixed number to 'mixedFraction' string for os object:
    string mixedFraction = "";
    if (wholeNumber != 0) {
        mixedFraction += to_string(wholeNumber);
        if (numerator != 0) 
            mixedFraction += " " + to_string(numerator) + "/" + to_string(r.d);
    } else if (numerator != 0) {
        if (r.n != 0) {
            if (r.n < 0) 
                numerator *= -1;
            mixedFraction += to_string(numerator) + "/" + to_string(r.d);
        }
    } else {
        mixedFraction += "0";
    }
    
    os << mixedFraction;
    return os;
}

Rat continued_frac_3(int a[], int i) {
    int *continuedFraction = continued_frac_2(a, i);
    Rat rat(continuedFraction[0], continuedFraction[1]);
    return rat;
}

int main() {
    int array[] = {3, 7, 16, -1};
    cout << "Continued fractions function 1: " <<
    continued_frac_1(array, 0) << endl;
    
    int *a = continued_frac_2(array,0);
    cout << "Continued fractions function 2: " <<
    a[0] << '/' << a[1] << endl;
    // delete []a;
    
    cout << "Continued fractions function 3: " <<
    continued_frac_3(array, 0) << endl;
    
    return 0;
}