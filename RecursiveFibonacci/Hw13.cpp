#include <cstdlib>
#include <iostream>
using namespace std;

int fib(int n) {
    if(n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int fib2(int n) {
    static int memo[100] = {0};
    for (int i = 1; i <= n; i++) {
        memo[i]
    }
}

int main() {
    
    cout << fib(50) << endl;
    return 0;
}

