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
    for (int i = 0; i < 3*n; i++){
        cout << a[i] << ' ' << a[(i + 1)%(3*n)] << '\n';
    }
}