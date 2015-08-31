#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Period {
    int start;
    int end;
    double ave_spot_plan;
    Period(int s, int e, double d) {
        start = s;
        end = e;
        ave_spot_plan = d;
    }
};

bool cmp(Period a, Period b) {
    if (a.ave_spot_plan > b.ave_spot_plan) return true;
    else if (a.ave_spot_plan < b.ave_spot_plan) return false;

    if (a.end - a.start > b.end - b.start) return true;
    else if (a.end - a.start < b.end - b.start) return false;

    if (a.end < b.end) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Result for run " << i << ":" << endl;
        int num, num_quarters, num_best_period, min_spot_plan;
        cin >> num_quarters >> num_best_period >> min_spot_plan;

        vector<int> tm_pot;
        for (int j = 0; j < num_quarters; j++) {
            cin >> num;
            tm_pot.push_back(num);
        }

        vector<Period> p;
        for (int j = 0; j <= num_quarters - min_spot_plan; j++) {
            double total = 0;
            for (int k = j; k < num_quarters; k++) {
                total += tm_pot[k];
                if (k - j + 1 >= min_spot_plan) {
                    p.push_back(Period(j+1, k+1, total/(k-j+1)));
                }
            }
        }

        sort(p.begin(), p.end(), cmp);

        for (int j = 0; j < p.size(); j++) {
            if (j == num_best_period) break;
            cout << p[j].start << "-" << p[j].end << endl;
        }
    }
    return 0;
}
