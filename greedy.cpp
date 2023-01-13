#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int st, en;
		cin >> st >> en;
		g.push_back({st, en});
	}

	sort(g.begin(), g.end(), [](const vector<int> &a, const vector<int> &b)->bool{
		return a[1] < b[1];
	});

	int cnt = 0, prev = 0;
	for (int i = 0; i < n; i++) {
		if (prev < g[i][0]) {
			cnt++;
			prev = g[i][1];
		}
	}
	cout << cnt << endl;

	return 0;
}