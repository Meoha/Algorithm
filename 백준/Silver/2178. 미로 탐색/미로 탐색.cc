#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

struct INFO {

	int x, y, cnt;

};

INFO start = { 1, 1, 1 }; //시작정보
int N; //세로
int M; //가로
int board[101][101]; //보드 정보, 0은 이동할 수 없는 칸, 1은 이동할 수 있는 칸
bool visited[101][101]; //방문 배열
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; //방향 벡터
queue<INFO> q;

int bfs() {

	int ans = 0;

	visited[start.y][start.x] = true;
	q.push(start);

	while (!q.empty()) {

		INFO cur = q.front();
		q.pop();

		if (cur.x == M && cur.y == N) {

			ans = cur.cnt;

			break;

		}

		for (int d = 0; d < 4; d++) {

			int nx = cur.x + dir[d][0];
			int ny = cur.y + dir[d][1];

			if (nx >= 1 && nx <= M && ny >= 1 && ny <= N) {

				if (!visited[ny][nx] && board[ny][nx] == 1) {

					visited[ny][nx] = true;
					q.push({ nx, ny, cur.cnt + 1 });

				}

			}

		}

	}

	return ans;
}
int main() {

	cin >> N >> M;

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {

			scanf("%1d", &board[n][m]);

		}
	}

	//bfs
	cout << bfs() << '\n';

	return 0;
}