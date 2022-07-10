#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T; //테스트 케이스의 개수
int M; //배추밭의 가로길이
int N; //배추밭의 세로길이
int K; //배추가 심어져 있는 위치의 개수
int map[51][51]; //배추밭
bool visited[51][51];
queue<pair<int, int>> q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans;
vector<int> result; //배추흰지렁이 마리 수

void sol() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}

	ans++;
}

int main() {

	cin >> T;

	for(int t = 1; t <= T; t++){
	
		cin >> M >> N >> K;

		for (int k = 0; k < K; k++) {

			int a, b;

			cin >> a >> b;

			map[a][b] = 1;

		}

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {

				if (map[m][n] == 1 && !visited[m][n]) {

					q.push(make_pair(m, n));
					visited[m][n] = true;

					sol();
				}

			}
		}

		result.push_back(ans);

		ans = 0;

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {

				map[m][n] = 0;
				visited[m][n] = false;
			}
		}

	}

	for (int v = 0; v < result.size(); v++) {
		
		cout << result[v] << endl;
	}

	return 0;
}