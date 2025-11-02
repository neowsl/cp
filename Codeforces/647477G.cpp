#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	ll N, Q;
	cin >> N >> Q;

	for (int i = 0; i < N; ++i) {
		int _;
		cin >> _;
	}

	for (int i = 0; i < Q; ++i) {
		ll M;
		cin >> M;

		cout << floor(pow(N, M) / M) << " ";
	}

	return 0;
}
