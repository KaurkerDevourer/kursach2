#include "testlib.h"
#include <iostream>

using namespace std;
#define ll long long

ll FAIL = -1361313;
ll x1, y1, x2, y2;


bool is_white(int x, int y) {
    return (x + y)%2 == 0 ? 1 : 0;
}

void read_data() {
    x1 = inf.readInt();
    y1 = inf.readInt();
    x2 = inf.readInt();
    y2 = inf.readInt();
}

ll read_answer(InStream& in) {
    ll k = in.readInt();
    if(k == -1) {
        return -1;
    }
    ll nowx = x1;
    ll nowy = y1;
    ll x, y;
    for (int i = 0; i < k; i++){
        x = in.readInt();
        y = in.readInt();
        if (is_white(nowx, nowy)) {
            if (x == nowx || y == nowy) {
                return FAIL;
            }
            if (abs(x - nowx) + abs(y - nowy) == 3){
                nowx = x;
                nowy = y;
            } else {
                return FAIL;
            }
        } else {
            ll delx = abs(nowx - x);
            ll dely = abs(nowy - y);
            if (delx == dely) {
                nowx = x;
                nowy = y;
            } else {
                return FAIL;
            }
        }
    }
    if (nowx == x2 && nowy == y2) {
        return k;
    } else {
        return FAIL;
    }
}


int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    read_data();

    ll jans = read_answer(ans);
    ll pans = read_answer(ouf);

    if (jans == FAIL) {
	    quitf(_fail, "The jury hasn't found an answer.");
	}else if (pans == FAIL) {
	    quitf(_wa, "The jury has a correct answer, but the participant hasn't");
	}else if (pans < jans && pans != -1) {
 	    quitf(_fail, "Jury's answer is not optimal");
	} else if (jans != pans) {
	    quitf(_wa, "Participant answer is not optimal");
	} else if (jans == pans) {
	    quitf(_ok, "The jury and the participant had found the correct answer");
	}
}