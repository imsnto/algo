#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> ar;
int c = 0;

void merge(int l, int m, int r) {
	int ls = m - l + 1, rs = r - m;
	vector<int> ll, rr;
	for (int i = l; i <= m; i++) ll.push_back(ar[i]);
	for (int i = m + 1; i <= r; i++) rr.push_back(ar[i]);

	int k = 0, i = 0, j = 0;

	while (i < ls and j < rs) {
		if (i < ls and ll[i] <= rr[j]) ar[l + k++] = ll[i++];
		else if (j < rs) {ar[l + k++] = rr[j++]; c += ls - i; }
	}

	while (i < ls) ar[l + k++] = ll[i++];
	while (j < rs) ar[l + k++] = rr[j++];
}

void mergesort(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergesort(l, m);
		mergesort(m + 1, r);
		merge(l, m, r);
	}
}

int32_t main() {
	int n;
	cin >> n;
	ar.resize(n);

	for (int i = 0; i < n; i++)
		cin >> ar[i];

	mergesort(0, n - 1);
	cout << c << endl;


	return 0;
}