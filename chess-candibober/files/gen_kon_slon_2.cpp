#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;


int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(int argc, char* argv[]) {
    int n;
    n = atoi(argv[1]);
    int x1 = rnd.next(-n, n);
    int y1 = rnd.next(-n, n);
    if (((x1 + y1)%2 + 2)%2 == 1){
        x1++;
    }
    int i = rnd.next(0, 7);
    int delta = rnd.next(-n, n);
    int nap = -2 * rnd.next(0, 1) + 1;
    cout << x1 << ' ' << y1 << ' ' << x1 + dx[i] + delta << ' ' << y1 + dy[i] + nap*delta << '\n';
}