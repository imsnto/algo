#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> vis, dist,  par;
int node, edge;

void dijksta(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});
	dist[s] = 0;

	while (!q.empty()) {
		int u = q.top().second;
		q.pop();

		if (vis[u]) continue;
		vis[u] = 1;

		for (auto to : g[u]) {
			int w = to.second;
			int v = to.first;

			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				q.push({dist[v], v});
				par[v] = u;
			}
		}
	}
}

int main() {
	cin >> node >> edge;
	g.resize(node + 1, vector<pair<int, int>>());
	vis.resize(node + 1); par.resize(node + 1); dist.resize(node + 1, 1e9);

	for (int i = 0; i < edge; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].push_back({b, w});
	}

	dijksta(1);

	for (int i = 2; i <= node; i++)
		cout << dist[i] << " "; cout << endl;

	return 0;
}