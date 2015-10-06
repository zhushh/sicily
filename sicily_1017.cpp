// http://soj.sysu.edu.cn/1017

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    int month;
    double money;
} Node;

double solve(vector<Node> &data, Node &target) {
    double deta = 0.000000001;    // for precision
    double rate;
    double first = 0.0, second = 1.0;
    while (true) {
        rate = (first + second) / 2.0;
        double sum = 0.0;     // the sum of calculate
        for (int i = 0; i < data.size(); i++) {
            sum += (data[i].money * (pow(1.0+rate, target.month - data[i].month + 1)));
        }
        if (abs(sum - target.money) < deta)
            break;
        if (sum - target.money > deta)
            second = rate;
        else
            first = rate;
    }
    return rate;
}

int main() {
    int n;
    int count = 1;
    double ans;
    cin >> n;
    while (n != -1) {
        Node target;
        vector<Node> data(n);
        for (int i = 0; i < n; i++) {
            cin >> data[i].month >> data[i].money;
        }
        cin >> target.month >> target.money;

        ans = solve(data, target);
        cout << "Case " << count++ << ": ";
        cout << std::fixed << std::setprecision(5) << ans << endl;
        cin >> n;
        if (n != -1) cout << endl;
    }
    return 0;
}
