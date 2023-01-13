#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> mark, dist;

void bfs(int s) {
	queue<int> q;
	q.push(s);
	dist[s] = 1;

	while (!q.empty()) {
		int u = q.front();
		mark[u] = 1;
		q.pop();

		for (int v : g[u]) {
			if (mark[v]) continue;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}

}

int main() {
	int n;
	cin >> n;

	mark.resize(n + 1); dist.resize(n + 1);
	g.resize(n + 1, vector<int>());

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int x;
	cin >> x;
	bfs(1);

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (dist[i] == x) ans++;
	}
	cout << ans << endl;

	return 0;
}