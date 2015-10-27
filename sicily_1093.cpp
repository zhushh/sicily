// http://soj.sysu.edu.cn/1093

#include <iostream>
using namespace std;

int main() {
    int count;
    int sum_money, sum_weight, add_weight;
    int w[4], perWeight[4];

    count = 1;
    while (cin >> w[0] >> perWeight[0]) {
        for (int i = 1; i < 3; i++) {
            cin >> w[i] >> perWeight[i];
        }
        cin >> perWeight[3];

        cout << "Set number " << count++ << ":" << endl;
        while (cin >> sum_weight) {
            if (sum_weight == 0) break;
            sum_money = 0;
            add_weight = 0;

            for (int i = 0; i < 3; i++) {
                if (w[i] >= sum_weight) {
                    sum_money = sum_weight * perWeight[i];
                    break;
                }
            }
            if (sum_money == 0) 
                sum_money = sum_weight * perWeight[3];
            for (int i = 0; i < 3; i++) {
                if ((w[i]+1) > sum_weight && (w[i]+1)*perWeight[i+1] < sum_money) {
                    sum_money = (w[i] + 1) * perWeight[i+1];
                    add_weight = (w[i] + 1) - sum_weight;
                }
            }
            cout << "Weight (" << sum_weight << ") has best price $" << sum_money;
            cout << " (add " << add_weight << " pounds)" << endl;
        }
        cout << endl;
    }
    return 0;
}