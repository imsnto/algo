#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> mark;

void dfs(int s) {
	if (mark[s]) return;
	mark[s] = 1;
	for (int d : g[s]) {
		dfs(d);
	}
}

int main() {
	cin >> n >> m;
	g.resize(n + 1, vector<int>());
	mark.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int x;
	cin >> x;
	dfs(x);
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}