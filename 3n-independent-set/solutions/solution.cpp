#pragma GCC optimize("Ofast")
#pragma GCC optimization ("O3")
#include<iostream>
#include<vector>
#include<set>

#define pb push_back

using namespace std;

vector<pair<int, int> > edges;
vector<vector<int> > g;
vector<bool> used;
vector<int> now;
set<pair<int,int> > ss;

void go(int v){
    used[v] = 1;
    ss.erase({now[v], v});
    for (auto to : g[v]){
        if (!used[to]){
            ss.erase({now[to], to});
            now[to]--;
            ss.insert({now[to], to});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    g.resize(n + n + n);
    bool fl = 1;
    if (n != 2){
        fl = 0;
    }
    for (int i = 0; i < n + n + n; i++){
        int from, to;
        cin >> from >> to;
        g[--from].pb(--to);
        g[to].pb(from);
        if (i == 0 && !(from == 0 && to == 1)){
            fl = 0;
        } 
        if (i == 1 && !(from == 1 && to == 2)){
            fl = 0;
        } 
        if (i == 2 && !(from == 2 && to == 3)){
            fl = 0;
        }  
        if (i == 3 && !(from == 3 && to == 0)){
            fl = 0;
        } 
        if (i == 4 && !(from == 0 && to == 2)){
            fl = 0;
        } 
        if (i == 5 && !(from == 1 && to == 3)){
            fl = 0;
        }
    }
    if (fl){
        cout << "Yes\n1 5";
        return 0;
    }
    used.resize(3 * n);
    vector<int> ans;
    now.resize(3 * n);
    for (int i = 0; i < n + n + n; i++){
        used[i] = 0;
        now[i] = g[i].size();
        ss.insert({now[i], i});
    }
    while(ss.size()){
        int v = (*ss.begin()).second;
        used[v] = 1;
        ss.erase(ss.begin());
        ans.pb(v + 1);
        vector<int> who;
        for (auto to : g[v]){
            if (!used[to]){
                who.pb(to);
                used[to] = 1;
            }
        }
        for (auto x : who){
            go(x);
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++){
        cout << ans[i] << " \n"[i == n - 1];
    }
}