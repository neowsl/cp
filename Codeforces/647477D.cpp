#include <iostream>
using namespace std;
#define ll long long

ll solve() {
	ll r;
	cin >> r;

	ll ans = 0;
	int i = 0;
	while (r > 0) {
		int ones = r % 10;
		ans += ones * (1 << i);
		r /= 10;
		i++;
	}

	return ans;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	while (T--) {
		cout << solve() << endl;
	}

	return 0;
}
