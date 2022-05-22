#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
    int n;
    n = atoi(argv[1]);
    cout << n << '\n';
    cout << 1 << ' ' << 3*n << '\n';
    for (int i = 1; i < 3*n - 1; i++){
        int a = rnd.next(1, i);
        cout << a << ' ' << i + 1 << '\n';
    }
    cout << 3*n << ' ' << rnd.next(2, 3*n - 1) << '\n';

}