#include <cstdlib>
#include <iostream>
using namespace std;

int fib(int n) {
    if(n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int fib2(int n) {
    int first = 0, second = 1, next;
    
    int* name = new int[second];
    for (int i = 0; i <= n; i++) {
        if (i <= 1) {
            next = i;
        }
        else {
            next = first + second;
            first = second;
            second = next;
        } 
    }
    delete[] name;
    return next;
}

int main() {
    
    cout << fib2(19) << endl;
    return 0;
}

