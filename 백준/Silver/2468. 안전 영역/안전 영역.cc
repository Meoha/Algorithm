#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO {

	int x, y;

}; //좌표 구조체

int N; //행과 열의 개수
int board[100][100]; //보드 정보
vector<int> height_list; //높이 정보
queue<INFO> q;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int ans = 1; //안전한 영역의 개수, 최소 1개

int bfs(int h) {

	int result = 0;
	bool visited[100][100] = { false }; //방문 배열

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			//안전한 영역 중 방문하지 않은 영역 구하기
			if (board[i][j] > h && !visited[i][j]) {

				q.push({ j, i });
				visited[i][j] = true;

				while (!q.empty()) {

					INFO cur = q.front();
					q.pop();

					for (int d = 0; d < 4; d++) {

						int nx = cur.x + dir[d][0];
						int ny = cur.y + dir[d][1];

						//배열 내에 존재하고, 아직 방문하지 않은 곳 중에 안전한 영역인 경우
						if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx] && board[ny][nx] > h) {

							visited[ny][nx] = true;
							q.push({ nx, ny });

						}

					}

				}
				
				result++;

			}

		}
	}

	return result;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	int min_h = 100;
	int max_h = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> board[i][j];

			height_list.push_back(board[i][j]);

		}
	}
	
	//확인할 높이 리스트 만들기
	sort(height_list.begin(), height_list.end());
	height_list.erase(unique(height_list.begin(), height_list.end()), height_list.end());
	
	//sol
	for (int h = 0; h < height_list.size(); h++) {

		int result = bfs(height_list[h]);

		if (ans < result) {

			ans = result;

		}

	}

	cout << ans << '\n';

	return 0;
}