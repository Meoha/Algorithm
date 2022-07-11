#include <iostream>

using namespace std;

int N; //지도의 크기
int L; //경사로의 길이
int board[100][100]; //지도의 정보
int ans; //지나갈 수 있는 길의 개수

void sol() {

	//가로 체크
	for (int i = 0; i < N; i++) {

		bool cango = true;
		int check = 1;

		for (int j = 0; j < N - 1; j++) {

			//높이가 같은 경우
			if (board[j][i] == board[j + 1][i]) {

				check++;

			}
			//오른쪽이 한칸 높은 경우
			else if (board[j][i] + 1 == board[j + 1][i]) {

				if (check >= L) {

					check = 1;

				}
				else {

					cango = false;
					break;

				}

			}
			//왼쪽이 한칸 높은 경우
			else if (board[j][i] == board[j + 1][i] + 1 && check >= 0) {

				if (j + L >= N) {

					cango = false;
					break;

				}
				else {

					check = - L + 1;

				}

			}
			//차이가 2 이상인 경우
			else {

				cango = false;
				break;

			}

		}

		if (cango) {

			//cout << "가로 : " << i + 1 << "번째" << '\n';

			ans++;

		}

	}

	//세로 체크
	for (int j = 0; j < N; j++) {

		bool cango = true;
		int check = 1;

		for (int i = 0; i < N - 1; i++) {

			//높이가 같은 경우
			if (board[j][i] == board[j][i + 1]) {

				check++;

			}
			//아래쪽이 한칸 높은 경우
			else if (board[j][i] + 1 == board[j][i + 1]) {

				if (check >= L) {

					check = 1;

				}
				else {

					cango = false;
					break;

				}

			}
			//위쪽이 한칸 높은 경우
			else if (board[j][i] == board[j][i + 1] + 1 && check >= 0) {

				if (i + L >= N) {

					cango = false;
					break;

				}
				else {

					check = - L + 1;

				}

			}
			//차이가 2 이상인 경우
			else {

				cango = false;
				break;

			}

		}

		if (cango) {

			//cout << "세로 : " << j + 1 << "번째" << '\n';

			ans++;

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> board[j][i];

		}
	}

	//sol
	sol();

	cout << ans << '\n';

	return 0;
}