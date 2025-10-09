#include <iostream>

int solve() {
	int N, M, X, Y;
	std::cin >> N >> M >> X >> Y;

	int i;
	for (i = 0; i < N + M; ++i) {
		int v;
		std::cin >> v;
	}

	return i;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	while (T--) {
		std::cout << solve() << std::endl;
	}

	return 0;
}
