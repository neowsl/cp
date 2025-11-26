#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> solve() {
	int N, K, Q;
	cin >> N >> K >> Q;

	vector<bool> min = vector<bool>(N + 1);
	vector<bool> mex = vector<bool>(N + 1);
	for (int i = 0; i < Q; ++i) {
		int C, L, R;
		cin >> C >> L >> R;

		if (C == 1) {
			for (int j = L; j <= R; ++j)
				min[j] = true;
		} else {
			for (int j = L; j <= R; ++j)
				mex[j] = true;
		}
	}

	vector<int> ans = vector<int>(N + 1, -1);
	for (int i = 1; i <= N; ++i) {
		if (min[i] && !mex[i]) ans[i] = K;
		if (min[i] && mex[i]) ans[i] = K + 1;
	}

	int x = 0;
	for (int i = 1; i <= N; ++i) {
		if (ans[i] == -1) ans[i] = (x++) % K;
	}

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		vector<int> xs = solve();
		for (int i = 1; i < xs.size(); ++i)
			cout << xs[i] << " ";
		cout << endl;
	}

	return 0;
}
