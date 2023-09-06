#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int search_first(vector<int>& a, int n, int l, int r, int x) {
	int res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x) {
			res = m;
			r = m - 1;
		}
		else if (a[m] > x) r = m - 1;
		else l = m + 1;
	}
	return res;
}

int search_last(vector<int>& a, int n, int l, int r, int x) {
	int res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x) {
			res = m;
			l = m + 1;
		}
		else if (a[m] > x) r = m - 1;
		else l = m + 1;
	}
	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end()); // Sắp xếp vector a

	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		int x = k - a[i];
		int first = search_first(a, n, i + 1, n - 1, x);
		int last = search_last(a, n, i + 1, n - 1, x);
		while (first != -1) {
			first = search_first(a, n, i + 1, n - 1, x); // Cập nhật first
			last = search_last(a, n, i + 1, n - 1, x);  // Cập nhật last
			cnt += (last - first + 1);
		}
	}
	cout << cnt << endl;

	return 0;
}
