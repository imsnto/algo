#include<bits/stdc++.h>
using namespace std;

vector<int> ar;

void countingsort() {
	int mx = *max_element(ar.begin(), ar.end());
	vector<int> cnt(mx + 1);
	for (int i = 0; i < ar.size(); i++)
		cnt[ar[i]]++;

	for (int i = 1; i < cnt.size(); i++)
		cnt[i] += cnt[i - 1];

	vector<int> sortedlist(ar.size());

	for (int i = 0; i < ar.size(); i++) {
		sortedlist[cnt[ar[i]] - 1] = ar[i];
		cnt[ar[i]]--;
	}


	ar = sortedlist;
}

int main() {
	int n;
	cin >> n;
	ar.resize(n);

	for (int i = 0; i < n; i++)
		cin >> ar[i];

	countingsort();
	for (int x : ar) cout << x << " " ;
	cout << endl;

	return 0;
}