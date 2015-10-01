#include <cstdio>
#include <climits>
#include <cstring>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct
{
    string rank;
    int dist;
} RankInfo;

int distanceOfTwoRank(const string &a, const string &b) {
    int d = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                break;
            } else {
                for (int k = i+1; k < a.size(); k++) {
                    if (b[j] == a[k]) {
                        d++;
                        break;
                    }
                }
            }
        }
    }
    return d;
}

bool cmp(RankInfo a, RankInfo b) {
    return a.dist < b.dist;
}

RankInfo solve(vector<string> &givenRank) {
    RankInfo minimal;
    minimal.rank = "ABCDE";
    minimal.dist = INT_MAX;
    string cur = "ABCDE";
    do {
        RankInfo info;
        info.rank = cur;
        info.dist = 0;
        for (int i = 0; i < givenRank.size(); i++) {
            info.dist += distanceOfTwoRank(info.rank, givenRank[i]);
        }

        if (info.dist < minimal.dist) {
            minimal.rank = info.rank;
            minimal.dist = info.dist;
        }
    } while (next_permutation(cur.begin(), cur.end()));

    return minimal;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        string temp;
        vector<string> givenRank;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            givenRank.push_back(temp);
        }
        RankInfo ans = solve(givenRank);

        cout << ans.rank << " is the median ranking with value " << ans.dist << "." << endl;
    }
    return 0;
}
