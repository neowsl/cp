#include <bits/stdc++.h>

using namespace std;

void solve() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cout << i * i << " ";
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		solve();
	}
}
