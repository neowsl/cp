#include <bits/stdc++.h>

using namespace std;

int solve() {
	int N;
	cin >> N;

	vector<int> A = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());
	int ans = 0;
	int length = 1;
	for (int i = 1; i < N; i++) {
		if (A[i] > A[i - 1] + 1) {
			ans = max(ans, length);
			length = 1;
		}
		if (A[i] == A[i - 1] + 1) length++;
	}
	ans = max(ans, length);

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		cout << solve() << endl;
	}
}
