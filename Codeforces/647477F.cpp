#include <bits/stdc++.h>
using namespace std;

int solve() {
	int N, A, B;
	cin >> N >> A >> B;

	int S;
	cin >> S;

	vector<int> ac(N, -1);
	vector<int> penalty(N, 0);
	vector<int> unknown(N, -1);

	for (int i = 0; i < S; ++i) {
		int T;
		char P;
		string V;
		cin >> T >> P >> V;

		P -= 'A';

		if (V == "ac") {
			if (ac[P] == -1) {
				ac[P] = T + penalty[P];
			}
		} else if (V == "rj") {
			penalty[P] += 20;
		} else {
			if (unknown[P] == -1 && ac[P] == -1) {
				unknown[P] = T + penalty[P];
			}
		}
	}

	int time = 0;
	int baseSolved = 0;
	for (int s : ac) {
		if (s != -1) {
			time += s;
			baseSolved++;
		}
	}

	if (baseSolved > A || (baseSolved == A && time < B)) {
		return 0;
	}

	sort(unknown.begin(), unknown.end());

	int pdSolved = 0;
	for (int i = 0; i < unknown.size(); i++) {
		if (unknown[i] == -1) {
			continue;
		}

		time += unknown[i];
		pdSolved++;

		if (baseSolved + pdSolved > A ||
		    (baseSolved + pdSolved == A && time < B)) {
			return pdSolved;
		}
	}

	return -1;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		cout << solve() << endl;
	}

	return 0;
}
