#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	vector<ll> energy(N + 1);
	vector<ll> time(N + 1, -1);
	vector<vector<pair<int, ll>>> adj(N + 1);
	priority_queue<pair<ll, vector<pair<int, ll>>>> refreshers;
	queue<int> frontier;

	for (int i = 1; i <= N; ++i) {
		cin >> energy[i];
		if (energy[i] == 0) {
			frontier.push(i);
		}
	}

	for (int i = 0; i < K; ++i) {
		ll T, S;
		cin >> T >> S;

		vector<pair<int, ll>> ids(S);
		for (int i = 0; i < S; ++i) {
			int id;
			cin >> id;
			ids[i] = make_pair(id, 1e5);
		}

		refreshers.push(make_pair(-T, ids));
	}

	for (int i = 0; i < M; ++i) {
		int U, V, W;
		cin >> U >> V >> W;

		adj[U].push_back(make_pair(V, W));
	}

	ll currTime = 0;
	while (true) {
		while (!frontier.empty()) {
			int i = frontier.front();
			frontier.pop();

			if (time[i] == -1) {
				time[i] = currTime;
				for (auto a : adj[i]) {
					int neighbour = a.first;
					ll transferTime = a.second;

					refreshers.push(make_pair(
					    -(currTime + transferTime),
					    vector(1,
						   make_pair(neighbour, 1ll))));
				}
			}
		}

		if (refreshers.empty()) {
			break;
		}

		auto top = refreshers.top();
		refreshers.pop();

		currTime = -top.first;
		for (auto thing : top.second) {
			energy[thing.first] -= thing.second;
			if (energy[thing.first] <= 0) {
				frontier.push(thing.first);
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << time[i] << " ";
	}
	cout << endl;

	return 0;
}
