#include <bits/stdc++.h>

using namespace std;

int solve() {
	int N;
	cin >> N;

	int best = 0;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		best = max(best, A);
	}

	return N * best;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		cout << solve() << endl;
	}
}
