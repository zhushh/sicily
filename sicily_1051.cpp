// http://soj.sysu.edu.cn/1051
#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.1415927;

int main() {
    double diameter;
    int revolution;
    double costTime;
    int count = 1;
    while (cin >> diameter >> revolution >> costTime) {
        if (revolution == 0) break;
        double s = (PI * diameter * revolution) / (12 * 5280);
        double mph = s / (costTime / 3600);
        cout << "Trip #" << count << ": ";
        cout << std::fixed;
        cout << std::setprecision(2) << s;
        cout << " ";
        cout << std::setprecision(2) << mph << endl;
        count++;
    }
    return 0;
}