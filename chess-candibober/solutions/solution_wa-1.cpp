#include <iostream>

using namespace std;

#define int long long

bool is_white(int x, int y) {
    return (x + y)%2 == 0;
}

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

signed main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if (is_white(x2, y2)){
		cout << -1;
		return 0;
	}
}