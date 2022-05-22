#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int MAX_N = 100 * 1000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, MAX_N, "n");
    inf.readEoln();
    
    int sz = 3 * n;
    set<pair<int, int>> edges;
    for (int i = 0; i < sz; i++){
        int a= inf.readInt(1, sz, "a[" + vtos(i + 1) + "]");
        inf.readSpace();
        int b = inf.readInt(1, sz, "b[" + vtos(i + 1) + "]");

        ensuref(a != b, "a[%d] = b[%d] = %d, but self loops not allowed", i + 1, i + 1, a);
        ensuref(edges.insert({min(a, b), max(a, b)}).second, "edge %d - %d occur at least twice, but multiedges are forbidden", a, b);
        
        inf.readEoln();
    }
    
	inf.readEof();

}