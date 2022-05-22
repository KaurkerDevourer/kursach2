#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    int a, n;
    cin >> a >> n;
    long long now = 1;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        now *= a;
        ans += (now / (a + 1));
        ans %= mod;
        now %= mod;
    }
    cout << ans << endl;
}