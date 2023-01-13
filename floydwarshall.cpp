#include<bits/stdc++.h>
using namespace std;

int n, e;
vector<vector<int>> g, dist;

int main() {
	cin >> n >> e;
	g.resize(n + 1, vector<int>(n + 1));
	dist.resize(n + 1, vector<int>(n + 1));

	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a][b] = w;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) g[i][j] = 0;
			else if (g[i][j]) dist[i][j] = g[i][j];
			else dist[i][j] = 1e9;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}

	for (int i = 2; i <= n; i++) cout << dist[1][i] << " " ;
	cout << endl;

	return 0;
}