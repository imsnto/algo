#include<bits/stdc++.h>
using namespace std;

string s, t;
vector<vector<int>> dp;

int lcs(int i, int j) {
	if (i < 0 or j < 0) return 0;

	if (dp[i][j] != -1) return dp[i ][j];

	if (s[i] == t[j]) {
		return dp[i ][j ] = 1 + lcs(i - 1, j - 1);
	}
	else {
		return dp[i ][j ] = max(lcs(i - 1, j), lcs(i, j - 1));
	}
}

int main() {
	cin >> s >> t;

	dp.resize(s.size() + 1, vector<int>(t.size() + 1));

	for (int i = 1; i <= s.size(); i++) {
		for (int j = 1; j <= t.size(); j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[s.size()][t.size()] << endl;

	//int ans = lcs(s.size() - 1, t.size() - 1);
	//cout << ans << endl;

	string ans ;
	int i = s.size(), j = t.size();

	while (i > 0 and j > 0) {
		if (s[i - 1] == t[j - 1]) {
			ans += s[i - 1];
			i--; j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1] ) i--;
		else j--;

	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;

	return 0;
}