#include <iostream>


using namespace std;

long long binpow(long long a, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return a * binpow(a, n - 1);
    } else {
        long long p = binpow(a, n/2);
        return p * p;
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
        long long ans = (binpow(a, n + 1) - 1) / ((a + 1) * (a - 1)) - (n + 1) / 2;
        cout << ans << endl;
    } else {
        long long ans = (a * (binpow(a, n) - 1)) / ((a + 1) * (a - 1)) - n/2;
        cout << ans << endl;
    }
}