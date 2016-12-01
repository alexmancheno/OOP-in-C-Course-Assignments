//Mancheno, Alex
//CSCI 211 - Section 52B
//Hw # 20 - Rat Class

//compiled on venus server using: g++ -std=c++0 Hw20.cpp -o Hw20
//to_string() does not work with regular compiler!


#include <iostream>
#include <cmath>
using namespace std;

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

    int getN() {
        return n;
    }

    int getD() {
        return d;
    }

    void setN(int i) {
        n = i;
    }

    void setD(int i) {
        d = i;
    }
    
    //override '+' operator:
    Rat operator+(Rat other) {
        Rat t;
        t.n = n * other.d + d * other.n;
        t.d = d * other.d;
        
        if (t.d < 0) {
            t.d = abs(t.d);
            t.n = t.n * -1;
        }
        
        return t;
    }

    //override '-' operator:
    Rat operator-(Rat other) {
        Rat t;
        t.n = n * other.d - d * other.n;
        t.d = d * other.d;
        
        if (t.d < 0) {
            t.d = abs(t.d);
            t.n = t.n * -1;
        }
        
        return t;
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

    //override '*' operator:
    Rat operator*(Rat other) {
        Rat t;
        t.n = n * other.n;
        t.d = d * other.d;
        
        if (t.d < 0) {
            t.d = abs(t.d);
            t.n = t.n * -1;
        }
        
        return t;
    }
    
    //override 'divide' operator:
    Rat operator/(Rat other) {
        Rat t;
        t.n = n * other.d;
        t.d = d * other.n;
        
        if (t.d < 0) {
            t.d = abs(t.d);
            t.n = t.n * -1;
        }
            
        return t;
    }

    //to grant the following functions access to Rat private variables:
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);

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

istream& operator>>(istream& is, Rat& r) {
    is >> r.n >> r.d;
    return is;
}

int main() {
   Rat r1(5, 2), r2(3, 2);
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2;
   r2 = r1 * r2;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2 + r1 * r2 / r1;
   r2 = r2 + r1 * r2 / r1;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   
   Rat x(1,2), y(2,3), z;
   z = x + y;
   cout << z << endl;

   x.setN(3);
   y.setD(2);
   z = x + y;
   cout << z << endl;
   cin >> x ;
   cout << x << endl;
   z = x + 5;
   cout << z << endl;

   return 0;
}