#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
    vector<int> a;
    int n, m;
    n = atoi(argv[1]);
    cout << n << '\n';
    cout << 1 << ' ' << 2 << '\n';
    cout << 2 << ' ' << 3 << '\n';
    cout << 1 << ' ' << 3 << '\n';
    for (int i = 3; i < 3*n; i++){
        cout << rnd.next(1, 3) << ' ' << i + 1 << '\n';
    }
}