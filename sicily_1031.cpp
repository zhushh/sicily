#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define N 205
#define INF 1000000007

int n;				// the total number of node
int graph[N][N];	// record the graph info
int dist[N];		// record the distance from st to each node
bool visited[N];	// record whether the node is visited

int dijkstra(int st, int et) {
	// init state
	for (int i = 0; i < n; i++) {
		visited[i] = false;
		dist[i] = graph[st][i];
	}

	visited[st] = true;
	for (int i = 0; i < n; i++) {
		int smallest = INF;
		int index = -1;
		// find the smallest dist
		for (int j = 0; j < n; j++) if (!visited[j] && smallest >= dist[j]) {
			smallest = dist[j];
			index = j;
		}
		if (index >= 0) {	// get it
			visited[index] = true;
			for (int k = 0; k < n; k++) if (!visited[k]) {
				// update the dist
				dist[k] = min(dist[k], smallest + graph[index][k]);
			}
		} else {
			break;
		}
	}

	return dist[et];
}

int main() {
	int c, m;
	cin >> c;
	while (c-- > 0) {
		n = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				graph[i][j] = INF;
			}
			graph[i][i] = 0;
		}
		cin >> m;
		int value;
		string stp, edp;
		map<string, int> places;
		for (int i = 0; i < m; i++) {
			cin >> stp >> edp >> value;
			if (places.count(stp) <= 0) {
				places[stp] = n++;
			}
			if (places.count(edp) <= 0) {
				places[edp] = n++;
			}
			graph[places[stp]][places[edp]] = graph[places[edp]][places[stp]] = value;
		}
		cin >> stp >> edp;

		int ans;
		if (stp == edp) {
			cout << "0" << endl;
		} else if (places.count(stp) <= 0 || places.count(edp) <= 0) {
			cout << "-1" << endl;
		} else if ((ans = dijkstra(places[stp], places[edp])) >= INF) {
			cout << "-1" << endl;
		} else {
			cout << ans << endl;
		}

		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << graph[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		//cout << raw << " --> " << col << endl;
	}
	return 0;
}
