#include<bits/stdc++.h>
using namespace std;

int n, e;
vector<tuple<int, int, int>> g;
vector<int> vis, dist,  par;

void bellmanford(int s) {
	dist[s] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (auto it : g) {
			int a , b, w;
			tie(a, b, w) = it;
			dist[b] = min(dist[b], dist[a] + w);
		}
	}
}

int main() {
	cin >> n >> e;
	vis.resize(n + 1); par.resize(n + 1); dist.resize(n + 1, 1e9);

	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		g.push_back({a, b, w});
	}
	bellmanford(1);

	for (int i = 2; i <= n; i++)
		cout << dist[i] << " ";
	cout << endl;

	return 0;
}