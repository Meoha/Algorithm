#include <iostream>

using namespace std;

int w; //지도의 너비
int h; //지도의 높이
int dir[8][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} }; //방향 벡터
int board[50][50]; //지도의 정보
bool visited[50][50]; //방문 배열
int ans; //섬의 개수

//초기화 함수
void init() {

	w = 0;
	h = 0;
	ans = 0;

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {

			board[i][j] = 0;
			visited[i][j] = false;

		}
	}

	return;
}

//dfs
void dfs(int x, int y) {

	for (int d = 0; d < 8; d++) {

		int nx = x + dir[d][0];
		int ny = y + dir[d][1];

		//지정된 지도의 좌표에 존재하고 방문하지 않은 곳 중에 땅인 곳
		if (nx >= 0 && nx < w && ny >= 0 && ny < h && !visited[ny][nx] && board[ny][nx] == 1) {

			visited[ny][nx] = true;
			dfs(nx, ny);

		}

	}

}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {

		init();

		cin >> w >> h;

		//입력 마지막일 땐 종료
		if (w == 0 && h == 0) {

			return 0;
		}


		//지도의 정보
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {

				cin >> board[i][j];

			}
		}

		//sol
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {

				//섬이 될 수 있는 경우
				if (board[i][j] == 1 && !visited[i][j]) {

                    visited[i][j] = true;
					dfs(j, i);
					ans++;

				}

			}
		}

		cout << ans << '\n';
	}

	return 0;
}