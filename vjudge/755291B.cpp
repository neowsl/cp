#include <iostream>
#include <map>

int norm(int x, int K) {
	x %= K;
	return std::min(x, K - x);
}

bool solve() {
	int N, K;
	std::cin >> N >> K;

	std::map<int, int> freq;

	for (int i = 0; i < N; ++i) {
		int S;
		std::cin >> S;
		freq[norm(S, K)]++;
	}
	for (int i = 0; i < N; ++i) {
		int T;
		std::cin >> T;
		freq[norm(T, K)]--;
	}

	for (const auto &pair : freq) {
		if (pair.second != 0) {
			return false;
		}
	}

	return true;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	while (T--) {
		std::cout << (solve() ? "YES" : "NO") << std::endl;
	}

	return 0;
}
