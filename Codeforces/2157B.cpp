#include <bits/stdc++.h>
#define int long long
using namespace std;

string solve() {
	int N, X, Y;
	cin >> N >> X >> Y;
	X = abs(X);
	Y = abs(Y);

	for (int i = 0; i < N; ++i) {
		char C;
		cin >> C;

		if (C == '4') {
			if (X > Y)
				X--;
			else
				Y--;
		} else {
			X--;
			Y--;
		}
	}

	return X <= 0 && Y <= 0 ? "YES" : "NO";
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
