#include<bits/stdc++.h>
using namespace std;

vector<int> heap{0};

void shiftUp(int idx) {
	while (idx > 1 and heap[idx] > heap[idx / 2]) {
		swap(heap[idx], heap[idx / 2]);
		idx /= 2;
	}
}

void shiftDown(int idx) {
	while (idx * 2 < heap.size()) {
		int child = idx * 2;
		if (child + 1 < heap.size() and heap[child + 1] > heap[child]) {
			child++;
		}

		if (heap[child] > heap[idx]) {
			swap(heap[child], heap[idx]);
			idx = child;
		}
		else break;
	}
}

void Insert(int val) {
	heap.push_back(val);
	shiftUp(heap.size() - 1);
}

void Pop() {
	swap(heap[1], heap.back());
	heap.pop_back();

	shiftDown(1);
}

int Peek() {
	return heap[1];
}

int main() {
	int n;
	cin >> n;


	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		Insert(a);
		if (heap.size() < 4) cout << "-1\n";
		else {
			int b = Peek(); Pop(); int c = Peek(); Pop(); int d = Peek(); Pop();
			cout << b << " " << c << " " << d << endl;
			Insert(b); Insert(c); Insert(d);
		}
	}


	return 0;
}