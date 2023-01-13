#include<bits/stdc++.h>
using namespace std;

vector<int> ar;
int n;

int partition(int st, int en) {
	int i = st + 1, pivot = ar[st];

	for (int j = st + 1; j <= en; j++) {
		if (ar[j] < pivot) {
			swap(ar[j], ar[i]);
			i++;
		}
	}

	swap(ar[i - 1], ar[st]);
	return i - 1;
}

void quicksort(int i, int j) {
	if (i < j) {
		int pivot = partition(i, j);
		quicksort(i, pivot - 1);
		quicksort(pivot + 1, j);
	}
}

int main() {
	cin >> n;
	ar.resize(n);

	for (int i = 0; i < n; i++)
		cin >> ar[i];

	quicksort(0, n - 1);
	for (int d : ar) cout << d << " " ;
	cout << endl;

	return 0;
}