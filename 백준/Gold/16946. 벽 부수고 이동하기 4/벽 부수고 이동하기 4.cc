#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M; //맵의 크기
int board[1001][1001]; //맵의 정보
int board_info[1001][1001]; //구역 정보
int section[1000000]; //구역별 이동할 수 있는 칸의 개수
bool visited[1000000]; //구역별 중복확인 제거
int ans[1001][1001];
queue<pair<int, int>> q;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

//0으로 이루어진 구역 나누기
void divide_board(int idx, int a, int b) {

	q.push(make_pair(a, b));
	board_info[a][b] = idx;
	int cnt = 1;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {

			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && board[nx][ny] == 0 && board_info[nx][ny] == 0) {

				board_info[nx][ny] = idx;
				q.push(make_pair(nx, ny));
				cnt++;

			}

		}

	}

	section[idx] = cnt;

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int n = 0; n < N; n++) {
		
		string s;

		cin >> s;

		for (int m = 0; m < M; m++) {

			board[m][n] = s[m] - '0';

		}
	}

	int id = 1;

	//0으로 이루어진 구역 나누기
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {

			if (board[m][n] == 0 && board_info[m][n] == 0) {

				divide_board(id, m, n);
				id++;

			}
			
		}
	}
	
	//벽이 이동할 수 있는 칸의 개수 
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {

			if (board[m][n] == 1) {

				int result = 1;

				for (int i = 0; i < 4; i++) {

					int nx = m + dir[i][0];
					int ny = n + dir[i][1];

					//이동할 수 있는 칸의 개수 계산 및 구역 중복확인 체크 
					if (nx >= 0 && nx < M && ny >= 0 && ny < N && board[nx][ny] == 0 && board_info[nx][ny] != 0 && !visited[board_info[nx][ny]]) {

						result = result + section[board_info[nx][ny]];
						visited[board_info[nx][ny]] = true;

					}

				}

				for (int i = 0; i < 4; i++) {

					int nx = m + dir[i][0];
					int ny = n + dir[i][1];

					if (nx >= 0 && nx < M && ny >= 0 && ny < N) {

						visited[board_info[nx][ny]] = false;

					}

				}
				
				ans[m][n] = result;

			}

		}

	}

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {

			cout << ans[m][n] % 10;

		}

		cout << '\n';

	}

	return 0;
}