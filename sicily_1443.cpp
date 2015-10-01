// http://soj.sysu.edu.cn/1443

/*

    1.The first job J in queue is taken from the queue.
    2.If there is some job in the queue with a higher priority than job J, 
        thenmove J to the end of the queue without printing it.
    3.Otherwise, print job J (and do not put it back in the queue).

    Your problem with the new policy is that it has become quite tricky to determine when 
your print job will actually be completed. You decide to write a program to figure this out. 
The program will be given the current queue (as a list of priorities) as well as the position 
of your job in the queue, and must then calculate how long it will take until your job is 
printed, assuming that no additional jobs will be added to the queue. To simplifymatters, 
we assume that printing a job always takes exactly one minute, and that adding and 
removing jobs from the queue is instantaneous.
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::queue;

typedef struct {
    int id;
    int priority;
} Job;

int count[10];  // count the number of each priority job

int main() {
    int t, n, m;
    cin >> t;
    while (t-- >0) {
        for (int i = 1; i < 10; i++) count[i] = 0;
        cin >> n >> m;
        queue<Job> jobs;
        int priority;
        for (int i = 0; i < n; i++) {
            cin >> priority;
            jobs.push(Job{i, priority});
            count[priority]++;
        }

        int ans = 0;    // current cost time
        while (!jobs.empty()) {
            Job f = jobs.front();
            jobs.pop();
            int i;
            for (i = 9; i > f.priority; i--) if (count[i] > 0) {
                jobs.push(f);
                break;
            }
            if (i == f.priority) {  // can finish job
                ans++;
                count[f.priority]--;
                if (m == f.id) {
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
