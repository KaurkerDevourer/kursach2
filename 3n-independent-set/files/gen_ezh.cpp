#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
    vector<int> a;
    int n, m;
    n = atoi(argv[1]);
    cout << n << '\n';
    a.resize(3 * n);
    for (int i = 0; i < 3 * n; i++) 
        a[i] = i + 1;
    shuffle(a.begin(), a.end());
    for (int i = 1; i < 3*n; i++){
        cout << a[0] << ' ' << a[i] << '\n';
    }
    int ab = rnd.next(1, 3*n);
    int b = rnd.next(1, 3*n);
    while(ab == b || ab == a[0] || b == a[0]){
        b = rnd.next(1, 3*n);
        ab = rnd.next(1, 3*n);
    }
    cout << ab << ' ' << b << '\n';
}