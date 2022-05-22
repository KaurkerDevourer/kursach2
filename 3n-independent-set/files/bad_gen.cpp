#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
    int n;
    n = atoi(argv[1]);
    cout << n << '\n';
    set<pair<int,int> > ss;
    
    for (int i = 0; i < 3 * n; i++){
        int a = rnd.next(1, 3*n);
        int b = rnd.next(1, 3*n);
        while(a == b || !ss.insert({min(a,b), max(a,b)}).second){
            b = rnd.next(1, 3*n);
        }
        ss.insert({min(a,b), max(a,b)});
        cout << a << ' ' << b << '\n';
    }

}