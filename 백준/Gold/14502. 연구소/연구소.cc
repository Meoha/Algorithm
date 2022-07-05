#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point {

	int x, y;

}; //위치

int N, M; //지도의 세로, 가로 크기
int board[8][8];
int temp[8][8];
vector<point> virus; //바이러스 위치
vector<point> blank; //빈 칸 위치
queue<point> q;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; //방향 벡터
int ans;

//초기화
void init() {

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {

			temp[m][n] = board[m][n];

		}
	}

	while (!q.empty()) {

		q.pop();

	}

	return;
}

//바이러스 퍼진 후 안전 구역 계산
int sol() {

	int safe = blank.size() - 3;

	for (int v = 0; v < virus.size(); v++) {

		q.push(virus[v]);

	}

	while (!q.empty()) {

		point cur = q.front();
		q.pop();

		//4방향 바이러스가 퍼짐
		for (int i = 0; i < 4; i++) {

			int nx = cur.x + dir[i][0];
			int ny = cur.y + dir[i][1];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && temp[nx][ny] == 0) {

				q.push({ nx, ny });
				temp[nx][ny] = 2;
				safe--;

			}

		}

	}

	return safe;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	//연구소의 지도 정보 입력
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {

			cin >> board[m][n];

			//빈 칸, 바이러스 위치 벡터에 추가
			if (board[m][n] == 0) {

				blank.push_back({ m ,n });

			}
			else if (board[m][n] == 2) {

				virus.push_back({ m, n });

			}

		}
	}

	//벽 3개 세운 뒤 바이러스 퍼짐
	for (int a = 0; a < blank.size() - 2; a++) {
		for (int b = a + 1; b < blank.size() - 1; b++) {
			for (int c = b + 1; c < blank.size(); c++) {

				init();
				temp[blank[a].x][blank[a].y] = 1;
				temp[blank[b].x][blank[b].y] = 1;
				temp[blank[c].x][blank[c].y] = 1;

				int ret = sol();

				if (ans < ret) {

					ans = ret;

				}

			
			}
		}
	}

	//출력
	cout << ans << '\n';

	return 0;
}