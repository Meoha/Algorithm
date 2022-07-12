#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coin {

	int ax;
	int ay;
	int bx;
	int by;
	int turn;

};

int N; //세로 크기
int M; //가로 크기
char board[22][22]; //보드 정보
bool visited[22][22][22][22];
vector<pair<int, int>> c;
int ans = -1;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
queue<coin> q;

void sol() {

	int xy[4] = {};

	for (int i = 0; i < 2; i++) {

		xy[2 * i] = c[i].first;
		xy[2 * i + 1] = c[i].second;

	}

	q.push({ xy[0], xy[1], xy[2], xy[3], 0 });
	visited[xy[0]][xy[1]][xy[2]][xy[3]] = true;

	while (!q.empty()) {

		int x1 = q.front().ax;
		int y1 = q.front().ay;
		int x2 = q.front().bx;
		int y2 = q.front().by;
		int t = q.front().turn;

		q.pop();

		if (t > 10) {

			return;
		}

		if (board[x1][y1] != board[x2][y2]) {

			if (board[x1][y1] == 'D' || board[x2][y2] == 'D') {

				ans = t;
				
				return;
			}

		}

		for (int i = 0; i < 4; i++) {

			int nx1 = x1 + dir[i][0];
			int ny1 = y1 + dir[i][1];
			int nx2 = x2 + dir[i][0];
			int ny2 = y2 + dir[i][1];

			if (board[nx1][ny1] == '#') {

				nx1 = x1;
				ny1 = y1;

			}

			if (board[nx2][ny2] == '#') {

				nx2 = x2;
				ny2 = y2;

			}

			if (board[nx1][ny1] == 'D' && board[nx2][ny2] == 'D') {

				continue;

			}
			else {

				if (!visited[nx1][ny1][nx2][ny2]) {

					q.push({ nx1, ny1, nx2, ny2, t + 1 });
					visited[nx1][ny1][nx2][ny2] = true;

				}

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {

			cin >> board[m][n];

			if (board[m][n] == 'o') {

				c.push_back(make_pair(m, n));

			}

		}
	}

	for (int i = 0; i <= N + 1; i++) {

		board[0][i] = 'D';
		board[M + 1][i] = 'D';

	}

	for (int i = 0; i <= M + 1; i++) {

		board[i][0] = 'D';
		board[i][N + 1] = 'D';

	}

	//sol
	sol();

	cout << ans << '\n';

	return 0;
}