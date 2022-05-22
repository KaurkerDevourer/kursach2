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
	if (abs(x1) > 100 || abs(y1) > 100 || abs(x2) > 100 || abs(y2) > 100){
		return 1;
	}
	if (x1 == x2 && y1 == y2){
		cout << 0;
		return 0;
	}
	if (is_white(x2, y2)){
		cout << -1;
		return 0;
	}
	if (is_white(x1, y1)) {
		if (abs(x1 - x2) + abs(y1 - y2) == 3 && x1 != x2 && y1 != y2) {
			cout << 1 << endl;
			cout << x2 << ' ' << y2 << endl;
			return 0;
		}
	} else {
		if (abs(x1 - x2) == abs(y1 - y2)) {
			cout << 1 << endl;
			cout << x2 << ' ' << y2 << endl;
			return 0;
		}
	}
	if (is_white(x1, y1)) {
		for (int i = 0; i < 8; i++){
			if (abs(x2 - (x1 + dx[i])) == abs(y2 - (y1 + dy[i]))) {
				cout << 2 << endl;
				cout << x1 + dx[i] << ' ' << y1 + dy[i] << endl;
				cout << x2 << ' ' << y2 << endl;
				return 0;
			}
		}
	} else {
		cout << 2 << endl;
		int newx = ((x1 - y1) + (x2 + y2)) >> 1;
		cout << newx << ' ' << newx - (x1 - y1) << endl;
		cout << x2 << ' ' << y2 << endl;
		return 0;
	}
	cout << 3 << endl;
	x1 += dx[0];
	y1 += dy[0];
	cout << x1 << ' ' << y1 << endl;
	int newx = ((x1 - y1) + (x2 + y2)) >> 1;
	cout << newx << ' ' << newx - (x1 - y1) << endl;
	cout << x2 << ' ' << y2 << endl;
}