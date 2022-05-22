#include <iostream>


using namespace std;

const int mod = 1e9 + 7;

long long binpow(long long a, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return (a * binpow(a, n - 1))%mod;
    } else {
        long long p = binpow(a, n/2);
        return (p * p) %mod;
    }
}

int main() {
    int a, n;
    cin >> a >> n;
    if (a == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (n % 2 == 1) {
        long long ans = (((((binpow(a, n + 1) - 1) * binpow(a + 1, mod - 2)) % mod * binpow(a - 1, mod - 2)) % mod) - (n + 1) / 2 + mod)%mod;
        cout << ans << endl;
    } else {
        long long ans = ((((a * (binpow(a, n) - 1) % mod * binpow(a + 1, mod - 2)) % mod * binpow(a - 1, mod - 2)) % mod) - n/2 + mod)%mod;
        cout << ans << endl;
    }
}