#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using std::vector;
using std::priority_queue;

struct Contestant {
    Contestant() {}
    Contestant(char *nm, int num) {
        strncpy(name, nm, sizeof(name));
        solve_num = num;
    }
    char name[15];
    int solve_num;
};

class mincmp {
    public:
        bool operator() (const Contestant& a, const Contestant& b) const {
            return a.solve_num > b.solve_num;
        }
};

class maxcmp {
    public:
        bool operator() (const Contestant& a, const Contestant& b) const {
            return a.solve_num < b.solve_num;
        }
};

priority_queue<Contestant, vector<Contestant>, maxcmp > maxq;
priority_queue<Contestant, vector<Contestant>, mincmp > minq;

void insert(Contestant t)
{
    if (minq.empty()) {
        minq.push(t);
    } else if (minq.size() <= maxq.size()) {
        Contestant u = maxq.top();
        if (u.solve_num > t.solve_num) {
            maxq.pop();
            maxq.push(t);
            t = u;
        }
        minq.push(t);
    } else {
        Contestant u = minq.top();
        if (u.solve_num < t.solve_num) {
            minq.pop();
            minq.push(t);
            t = u;
        }
        maxq.push(t);
    }
}

int main()
{
    int m;
    char op[10];
    char nm[15];
    int num;
    int size = 0;

    scanf("%d", &m);
    while (m-- > 0) {
        size = 0;
        while (scanf("%s", op)) {
            if (strncmp(op, "Add", sizeof("Add")) == 0) {
                scanf("%s%d", nm, &num);
                insert(Contestant(nm, num));
                size++;
            } else if (strncmp(op, "Query", sizeof("Query")) == 0) {
                if ( (size & 1) == 0) {
                    printf("No one!\n");
                } else if (size > 0) {
                    printf("%s\n", minq.top().name);
                }
            } else if (strncmp(op, "End", sizeof("End")) == 0) {
                if ( (size & 1) == 0) {
                    printf("Happy BG meeting!!\n");
                } else if (size > 0) {
                    printf("%s is so poor.\n", minq.top().name);
                }
                break;
            }
        }
        while (!maxq.empty()) {
            maxq.pop();
        }
        while (!minq.empty()) {
            minq.pop();
        }
        if (m > 0) {
            printf("\n");
        }
    }
    return 0;
}
