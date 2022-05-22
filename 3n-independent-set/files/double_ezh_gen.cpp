#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
    vector<int> a;
    int n, m;
    n = atoi(argv[1]);
    cout << n << '\n';
    cout << 1 << ' ' << 2 << '\n';
    for (int i = 2; i < 3*n; i++){
        cout << rnd.next(1, 2) << ' ' << i + 1 << '\n';
    }
    int ab = rnd.next(1, 3*n);
    int b = rnd.next(1, 3*n);
    while(ab == b || ab == 1 || ab == 2 || b == 1 || b == 2){
        b = rnd.next(1, 3*n);
    }
    cout << ab << ' ' << b << '\n';
}