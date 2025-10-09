#include <iostream>
#include <vector>

bool solve() {
	int N, K;
	std::cin >> N >> K;

	std::vector<bool> map(2e9);

	for (int i = 0; i < N; ++i) {
		int S;
		std::cin >> S;

		map[S] = true;
		map[S + K] = true;
		map[std::abs(S - K)] = true;
	}

	for (int i = 0; i < N; ++i) {
		int T;
		std::cin >> T;

		if (!map[T]) {
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
