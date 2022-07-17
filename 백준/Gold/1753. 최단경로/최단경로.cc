#include <iostream>
#include <vector>
#include <queue>

#define MAX 20001
#define INF 987654321

using namespace std;

vector<pair<int, int>> graph[MAX]; //정점의 간선 정보
int dist[MAX]; //최소 비용 배열

void dijkstra(int start) {

	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {

		int cur = pq.top().second;
		int distance = -pq.top().first; 
		pq.pop();

		if (dist[cur] < distance) {

			continue;
		}

		for (int i = 0; i < graph[cur].size(); ++i) {

			int next = graph[cur][i].second;
			int next_dist = distance + graph[cur][i].first;

			//시작~next 까지 새롭게 계산한 거리가 dist[next] 보다 짧을 경우 
			if (dist[next] > next_dist) {

				dist[next] = next_dist;
				pq.push({ -next_dist, next });

			}

		}

	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int V; //정점의 개수
	int E; //간선의 개수
	int K; //시작 정점의 번호

	cin >> V >> E;

	for (int i = 1; i <= V; ++i) {

		dist[i] = INF;

	}

	cin >> K;

	for (int e = 0; e < E; ++e) {

		int u, v, w;

		cin >> u >> v >> w;

		graph[u].push_back({ w, v });
	}

	dijkstra(K);

	for (int i = 1; i <= V; ++i) {

		if (dist[i] == INF) {

			cout << "INF" << '\n';

		}
		else {

			cout << dist[i] << '\n';

		}

	}

	return 0;
}