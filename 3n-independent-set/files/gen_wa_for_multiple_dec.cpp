#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
    int n, k, t;
    k = atoi(argv[1]); // n = 3k^2 + 1 => k = sqrt((n - 1)/3) => k <= 182
    t = (3 * k - 1);
    n = ((t + 1) * (t + 1) + 3) / 3;
    cout << n << '\n';
    set<pair<int,int> > ss;
    for (int i = 0; i < t + 3; i++){
        cout << i + 1 << ' ' << t + 4 << '\n';
        ss.insert({i + 1, t + 4});
    }
    for (int i = t + 4; i < t + t + 4; i++){
        cout << t + 4 << ' ' << i + 1 << '\n';
        ss.insert({t + 4, i + 1});
    }
    for (int i = t + t + 5; i <= 3*n; i++){
        cout << (i - (t + t + 5))/t + t + 5 << ' ' << i << '\n';
    }
    int a = rnd.next(t + t + 6, 3*n);
    int b = rnd.next(t + t + 6, 3*n);
    while(a == b || !ss.insert({min(a, b), max(a,b)}).second){
        b = rnd.next(t + t + 6, 3*n);
        a = rnd.next(t + t + 6, 3*n);
    }
    cout << a << ' ' << b << '\n';
}