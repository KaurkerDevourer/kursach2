#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
    int n;
    n = atoi(argv[1]);
    int x1 = rnd.next(-n, n);
    int y1 = rnd.next(-n, n);
    int x2 = rnd.next(-n, n);
    int y2 = rnd.next(-n, n);
    if ((x2 + y2)%2 == 0) {
        x2++;
    }
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
}