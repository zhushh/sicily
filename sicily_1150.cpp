// http://soj.sysu.edu.cn/1150

#include <iostream>
#include <string>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::string;

typedef struct {
    char up[4];
    char down[4];
    string seq;
} Node;

bool finish(Node &a, Node &b) {
    for (int i = 0; i < 4; i++) 
        if (a.up[i] != b.up[i] || a.down[i] != b.down[i]) {
            return false;
        }
    return true;
}

Node do_opA(const Node &t) {
    Node c = t;
    for (int i = 0; i < 4; i++) {
        c.up[i] = t.down[i];
        c.down[i] = t.up[i];
    }
    c.seq.push_back('A');
    return c;
}

Node do_opB(const Node &t) {
    Node c = t;
    for (int i = 3; i > 0; i--) {
        c.up[i] = c.up[i-1];
        c.down[i] = c.down[i-1];
    }
    c.up[0] = t.up[3];
    c.down[0] = t.down[3];
    c.seq.push_back('B');
    return c;
}

Node do_opC(const Node &t) {
    Node c = t;
    c.up[1] = c.down[1];
    c.down[1] = c.down[2];
    c.down[2] = c.up[2];
    c.up[2] = t.up[1];
    c.seq.push_back('C');
    return c;
}

void print(Node t) {
    cout << "\nNode step: " << t.seq.size() << "\tNode seq: " << t.seq << endl;
    for (int i = 0; i < 4; i++) {
        cout << t.up[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << t.down[i] << " ";
    }
    cout << endl << endl;
}

int main() {
    int n, num;
    while (cin >> n) {
        if (n == -1) break;
        Node target;
        Node temp;
        temp.seq = "";

        // initial
        for (int i = 0; i < 4; i++) {
            cin >> num;
            target.up[i] = '0' + num;
            temp.up[i] = '1' + i;
        }
        for (int i = 0; i < 4; i++) {
            cin >> num;
            target.down[i] = '0' + num;
            temp.down[i] = '0' + (8-i);
        }

        // search
        queue<Node> q;
        q.push(temp);
        while (!q.empty()) {
            temp = q.front();
            q.pop();

            //print(temp);
            if (finish(temp, target)) break;
            if (temp.seq.size() >= n)  continue;

            int seqSize = temp.seq.size();
            // operator A
            if (seqSize == 0 || temp.seq[seqSize - 1] != 'A')
                q.push(do_opA(temp));
            // operator B
            // operator C
            if (seqSize >= 3) {
                int c = 3;
                while (c > 0 && temp.seq[seqSize-c] == 'B') c--;
                if (c > 0) {
                    q.push(do_opB(temp));
                }

                c = 3;
                while (c > 0 && temp.seq[seqSize-c] == 'C') c--;
                if (c > 0) {
                    q.push(do_opC(temp));
                }
            } else {
                q.push(do_opB(temp));
                q.push(do_opC(temp));
            }
        }

        if (finish(temp, target))
            cout << temp.seq.size() << " " << temp.seq << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
