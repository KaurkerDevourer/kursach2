#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
int sz;
vector<pair<int, int>> edges;

void read_data() {
    n = inf.readInt();
    sz = 3 * n;
    edges.resize(sz);
    for (auto& [a, b] : edges) {
        a = inf.readInt();
        b = inf.readInt();
    }
}

bool read_answer(InStream& in) {
    string res = lowerCase(in.readToken());
    if (res != "no" && res != "yes") {
        in.quitf(_wa, "answer is not equal to \"yes\" or \"no\" (\"%s\")", compress(res).c_str());
    }
    if (res == "no") {
        return false;
    }
    
    set<int> ans;
    for (int i = 0; i < n; i++) {
        int x = in.readInt(1, sz, "p[" + vtos(i + 1) + "]");
        if (!ans.insert(x).second) {
            in.quitf(_wa, "%d occur at least twice in answer", x);
        }
    }

    for (const auto& [a, b] : edges) {
        if (ans.find(a) != ans.end() && ans.find(b) != ans.end()) {
            in.quitf(_wa, "both %d and %d are in answer, but edge %d - %d exists", a, b, a, b);
        }
    }
    
    return true;
}


int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    read_data();

    bool jans = read_answer(ans);
    bool pans = read_answer(ouf);

    if (pans && jans) {
        quitf(_ok, "The jury and the participant found the correct answer");
    } else if (!pans && !jans) {
        quitf(_ok, "Answer doesn't exist");
    } else if (!pans && jans) {
        quitf(_wa, "The jury has an answer, but the participant doesn't");
    } else { // pans && !jans
        quitf(_fail, "The participant has an answer, but the jury doesn't");
    }
}