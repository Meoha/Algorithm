#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct horse {

	int x; //행의 번호
	int y; //열의 번호
	int dir; //이동 방향

};

int N; //체스판의 크기
int board[14][14]; //체스판 정보
int K; //말의 개수
struct horse h[10]; //말 정보
string board_info[14][14]; //체스판 위의 말 정보
int turn = 1; //턴의 번호

//말의 다음 좌표
vector<pair<int, int>> next_point(int h_num) {

	int nx = h[h_num].x;
	int ny = h[h_num].y;

	//우로 이동
	if (h[h_num].dir == 1) {

		ny = ny + 1;

	}
	//좌로 이동
	else if (h[h_num].dir == 2) {

		ny = ny - 1;

	}
	//상으로 이동
	else if (h[h_num].dir == 3) {

		nx = nx - 1;

	}
	//하로 이동
	else if (h[h_num].dir == 4) {

		nx = nx + 1;

	}

	vector<pair<int, int>> np;

	np.push_back(make_pair(nx, ny));

	return np;
}

//쌓여있는 말
string stack_h(int h_num) {

	string info = board_info[h[h_num].x][h[h_num].y];
	string temp1;
	string temp2;
	bool flag = false;

	for (int i = 0; i < info.length(); i++) {

		if (info[i] == h_num + '0') {

			flag = true;

		}

		if (flag) {

			temp2 = temp2 + info[i];

		}
		else {

			temp1 = temp1 + info[i];

		}

	}

	board_info[h[h_num].x][h[h_num].y] = temp1;

	return temp2;
}

//이동하려는 칸 확인
void check_point(vector<pair<int, int>> np, int h_num, string sh) {

	int nx = np[0].first;
	int ny = np[0].second;


	//흰색인 경우
	if (board[nx][ny] == 0) {

		for (int i = 0; i < sh.length(); i++) {

			h[sh[i] - '0'].x = nx;
			h[sh[i] - '0'].y = ny;
			board_info[nx][ny] = board_info[nx][ny] + sh[i];

		}

	}
	//빨간색인 경우
	else if (board[nx][ny] == 1) {

		for (int i = sh.length() - 1; i >= 0; i--) {

			h[sh[i] - '0'].x = nx;
			h[sh[i] - '0'].y = ny;
			board_info[nx][ny] = board_info[nx][ny] + sh[i];

		}

	}
	//파란색인 경우
	else if (board[nx][ny] == 2) {

		//방향 전환
		if (h[h_num].dir == 1) {

			h[h_num].dir = 2;

		}
		else if (h[h_num].dir == 2) {

			h[h_num].dir = 1;

		}
		else if (h[h_num].dir == 3) {

			h[h_num].dir = 4;

		}
		else if (h[h_num].dir == 4) {

			h[h_num].dir = 3;

		}

		vector<pair<int, int>> nnp = next_point(h_num);

		int nnx = nnp[0].first;
		int nny = nnp[0].second;


		//흰색인 경우
		if (board[nnx][nny] == 0) {

			for (int i = 0; i < sh.length(); i++) {

				h[sh[i] - '0'].x = nnx;
				h[sh[i] - '0'].y = nny;
				board_info[nnx][nny] = board_info[nnx][nny] + sh[i];

			}

		}
		//빨간색인 경우
		else if (board[nnx][nny] == 1) {

			for (int i = sh.length() - 1; i >= 0; i--) {

				h[sh[i] - '0'].x = nnx;
				h[sh[i] - '0'].y = nny;
				board_info[nnx][nny] = board_info[nnx][nny] + sh[i];

			}

		}
		//파란색인 경우
		else if (board[nnx][nny] == 2) {

			board_info[h[h_num].x][h[h_num].y] = board_info[h[h_num].x][h[h_num].y] + sh;

		}

	}

	return;
}

//종료 조건 확인
bool check_game() {

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {

			if (board_info[i][j].length() >= 4) {

				return true;
			}

		}

	}

	return false;
}

void sol() {

	while (turn <= 1000) {

		//1번 말부터 K번 말까지
		for (int k = 0; k < K; k++) {

			vector<pair<int, int>> np = next_point(k);
			string sh = stack_h(k);
			check_point(np, k, sh);

			if (check_game()) {

				return;

			}
		}

		turn++;

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	//체스판 정보 입력
	for (int i = 0; i <= N + 1; i++) {

		for (int j = 0; j <= N + 1; j++) {

			if (i == 0 || i == N + 1 || j == 0 || j == N + 1) {

				board[i][j] = 2;

			}
			else {

				cin >> board[i][j];

			}

		}

	}

	//말 정보 입력
	for (int i = 0; i < K; i++) {

		cin >> h[i].x >> h[i].y >> h[i].dir;

		board_info[h[i].x][h[i].y] = board_info[h[i].x][h[i].y] + to_string(i);

	}

	//sol
	sol();

	//출력
	if (turn > 1000) {

		cout << -1 << '\n';

	}
	else {

		cout << turn << '\n';

	}

	return 0;
}