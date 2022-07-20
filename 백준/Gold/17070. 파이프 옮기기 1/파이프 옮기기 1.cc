#include <iostream>
#include <vector>

using namespace std;

int N; //집의 크기
int board[16][16]; //집의 상태
int ans; //방법의 수
bool visited[16][16][3];

bool check_board(int x, int y, int dir) {

	if (dir == 0) {

		if (!board[y][x]) {

			return true;

		}

	}
	else if (dir == 1) {

		if (!board[y][x]) {

			return true;

		}

	}
	else if (dir == 2) {

		if (!board[y][x] && !board[y - 1][x] && !board[y][x - 1]) {

			return true;
		}
	}

	return false;
}

void sol(int x, int y, int dir) {

	if (x == y && x == N - 1) {

		ans++;

		return;
	}
	else {

		if (dir == 0) {

			int v[2][3] = { {1, 0, 0}, {1, 1, 2} };

			for (int i = 0; i < 2; i++) {

				int nx = x + v[i][0];
				int ny = y + v[i][1];
				dir = v[i][2];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N && check_board(nx, ny, dir) && !visited[ny][nx][dir]) {

					visited[ny][nx][dir] = true;
					sol(nx, ny, dir);
					visited[ny][nx][dir] = false;

				}

			}
		}
		else if (dir == 1) {

			int v[2][3] = { {0, 1, 1}, {1, 1, 2} };

			for (int i = 0; i < 2; i++) {

				int nx = x + v[i][0];
				int ny = y + v[i][1];
				dir = v[i][2];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N && check_board(nx, ny, dir) && !visited[ny][nx][dir]) {

					visited[ny][nx][dir] = true;
					sol(nx, ny, dir);
					visited[ny][nx][dir] = false;

				}

			}

		}
		else if (dir == 2) {

			int v[3][3] = { {1, 0, 0}, {1, 1, 2}, {0, 1, 1} };

			for (int i = 0; i < 3; i++) {

				int nx = x + v[i][0];
				int ny = y + v[i][1];
				dir = v[i][2];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N && check_board(nx, ny, dir) && !visited[ny][nx][dir]) {

					visited[ny][nx][dir] = true;
					sol(nx, ny, dir);
					visited[ny][nx][dir] = false;

				}

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	//빈 칸은 0, 벽은 1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> board[i][j];

		}
	}

	//sol

	visited[0][1][0] = true;
	sol(1, 0, 0);

	//출력
	cout << ans << '\n';

	return 0;
}