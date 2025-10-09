#include <algorithm>
#include <iostream>
#include <vector>

int solve() {
	int N;
	std::cin >> N;

	std::vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
	}

	std::vector<std::vector<int>> dp(N, std::vector<int>(4, 1e9));

	dp[0][0] = A[0];

	for (int i = 1; i < N; ++i) {
		int hard = A[i];
		dp[i][0] = std::min(dp[i - 1][2], dp[i - 1][3]) + hard;
		dp[i][1] = dp[i - 1][0] + hard;
		dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]);
		dp[i][3] = dp[i - 1][2];
	}

	auto last = dp[N - 1];
	return *std::min_element(last.begin(), last.end());
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
