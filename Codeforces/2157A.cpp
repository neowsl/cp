#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
	int N;
	cin >> N;

	vector<int> freq(N + 1);
	for (int i = 0; i < N; ++i) {
		int A;
		cin >> A;
		++freq[A];
	}

	int ans = 0;
	for (int i = 0; i <= N; ++i) {
		if (freq[i] == 0) continue;

		if (freq[i] < i) {
			ans += freq[i];
			continue;
		}

		ans += freq[i] - i;
	}

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
		cout << solve() << endl;

	return 0;
}
