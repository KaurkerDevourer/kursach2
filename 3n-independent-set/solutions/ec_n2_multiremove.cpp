#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 300 * 1000 + 228;

int n;
int sz;
vector<int> g[MAX_N];
int cnt[MAX_N];
int ans[MAX_N];
set<pair<int, int>> by_cnt;

void dec_cnt(int v) {
    if (auto it = by_cnt.find({cnt[v], v}); it != by_cnt.end()) {
        by_cnt.erase(it);
        --cnt[v];
        by_cnt.insert({cnt[v], v});
    }
}

void remove(int v) {
    by_cnt.erase({cnt[v], v});
    for (int u : g[v]) {
        dec_cnt(u);
    }
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%d", &n);
    sz = 3 * n;
    for (int i = 0; i < sz; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
        ++cnt[a];
        ++cnt[b];
    }

    for (int i = 0; i < sz; ++i) {
        by_cnt.insert({cnt[i], i});
    }

    for (int i = 0; i < n; ++i) {
        assert(!by_cnt.empty());
        ans[i] = by_cnt.begin()->second;
        remove(ans[i]);
        for (int v : g[ans[i]]) {
            remove(v);
        }
    }

    printf("Yes\n");
    for (int i = 0; i < n; ++i) {
        printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
    }

    return 0;
}

