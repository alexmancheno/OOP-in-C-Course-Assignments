 //Mancheno, Alex
//CS 211 - Section 52B
//Hw # 15 - Towers of Hanoi, non-recursively

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int> t[3];
    int n;
    cout << "Enter the number of rings to move: ";
    cin >> n;
    cout << endl;
    
    int close = 1, far = 1;
   
    //close/far is determined depending on whether no. of rings is odd/even:
    if (n % 2 == 1)
        far = 2;
    else
        close = 2;
    
    int from = 0, to = close, candidate = 1, move = 0;
    
    //to put all the rings on the first tower:
    for (int i = n + 1; i >= 1; i--)
        t[0].push_back(i);
    
    //to make sure we can move rings onto 'empty' towers:
    t[1].push_back(n + 1);
    t[2].push_back(n + 1);
        
    //while the middle ring does not contain all the required rings:
    while (t[1].size() < n + 1) {
        cout << "Move #" << ++move << ": Transfer ring " << candidate
             << " from tower " << char(from + 'A') << " to tower " << char(to + 'A')
             << "\n";
        //move ring from current 'from' tower to current 'to' tower:
        t[to].push_back(t[from].back());
        t[from].pop_back();
        
        //the next 'from' tower can only be either one or two towers forward:
        if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back())
            from = (to + 1) % 3;
        else
            from = (to + 2) % 3;
        
        candidate = t[from].back();
        
        //the next 'to' tower can only be either one or two towers forward:
        if (t[(from)].back() < t[(from + close) % 3].back())
            to = (from + close) % 3;
        else
            to = (from + far) % 3;
    }
    return 0;
}