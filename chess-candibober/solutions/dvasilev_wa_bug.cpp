#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> SolveForBishop(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return {};
    }
    int dx = x2 - x1, dy = y2 - y1;
    if (abs(dx) == abs(dy)) {
        return {{x2, y2}};
    }

    vector<pair<int, int>> res;

    assert(abs(dy - dx) % 2 == 0);
    if (abs(dx) < abs(dy)) {
        // on each turn abs(dx)++, abs(dy)--
        int n = abs(abs(dy) - abs(dx)) / 2;

        int dir_x = dx < 0 ? -1 : 1;
        int dir_y = dy < 0 ? -1 : 1;
        res.emplace_back(x1 + n * dir_x, y1 + n * dir_y);
    } else {
        // on each turn abs(dx)--, abs(dy)++
        int n = abs(abs(dy) - abs(dx)) / 2;

        int dir_x = dx < 0 ? -1 : 1;
        int dir_y = dy < 0 ? 1 : -1;
        res.emplace_back(x1 + n * dir_x, y1 + n * dir_y);
    }

    res.emplace_back(x2, y2);
    return res;
}

void run() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int c1 = (x1 + y1) % 2, c2 = (x2 + y2) % 2;
    c1 = (c1 + 2) % 2;
    c2 = (c2 + 2) % 2;

    if (x1 == x2 && y1 == y2) {
        cout << 0 << endl;
        return;
    }

    vector<pair<int, int>> ans(10);
    if ((c1 == 0 && c2 == 0)  || (c1 == 1 && c2 == 0)) {
        cout << -1;
        return;
    } else if (c1 == 0 && c2 == 1) {
        vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
        vector<int> dy = {-1, 1, -2, 2, -2, 2, -1, 1};
        for (int i = 0; i < 8; ++i) {
            vector<pair<int, int>> sol = SolveForBishop(x1 + dx[i], y1 + dy[i], x2, y2);
            sol.insert(sol.begin(), {x1 + dx[i], y1 + dy[i]});
            if (ans.size() > sol.size()) {
                ans = sol;
            }
        }
    } else if (c1 == 1 && c2 == 1) {
        ans = SolveForBishop(x1, y1, x2, y2);
    }
    cout << ans.size() << endl;
    for (auto& [x, y]: ans) {
        cout << x << " " << y << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout << fixed << setprecision(13);

    int t = 1;
    //cin >> t;
    for (int test = 1; test <= t; ++test) {
        run();
    }

    return 0;
}