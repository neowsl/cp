#include <iostream>
#include <vector>

std::vector<std::vector<int>> adj;

int dfs(int node) {
	int max = 0;
	for (int x : adj[node]) {
		max = std::max(max, dfs(x));
	}

	return max + 1;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	adj.resize(N);

	for (int i = 0; i < N; ++i) {
		int parent;
		std::cin >> parent;
		if (parent == -1) {
			continue;
		}

		adj[parent - 1].push_back(i);
	}

	int max = 0;
	for (int i = 0; i < N; ++i) {
		max = std::max(max, dfs(i));
	}

	std::cout << max << std::endl;

	return 0;
}
