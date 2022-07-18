#include <iostream>
#include <algorithm>

using namespace std;

int N; //재현시의 크기
int board[21][21]; //재현시 정보
int part[21][21]; //선거구 정보
int people[6]; //인구 정보
int ans = 40000;

void init() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			part[i][j] = 0;

		}
	}

	for (int i = 1; i <= 5; i++) {

		people[i] = 0;

	}

	return;
}

//최솟값 계산
void calc_people() {

	//선거구 인구 계산
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (part[i][j] == 1) {

				people[1] = people[1] + board[i][j];

			}
			else if (part[i][j] == 2) {

				people[2] = people[2] + board[i][j];

			}
			else if (part[i][j] == 3) {

				people[3] = people[3] + board[i][j];

			}
			else if (part[i][j] == 4) {

				people[4] = people[4] + board[i][j];

			}
			else if (part[i][j] == 5 || part[i][j] == 0) {

				people[5] = people[5] + board[i][j];

			}

		}
	}

	sort(people + 1, people + 6);

	if (ans > people[5] - people[1]) {

		ans = people[5] - people[1];
	}

	return;
}

//선거구 나누기
void divide(int x, int y, int d1, int d2) {

	//제 1 경계선
	for (int i = 0; i <= d1; i++) {

		part[x + i][y - i] = 5;

	}

	//제 2 경계선
	for (int i = 0; i <= d2; i++) {

		part[x + i][y + i] = 5;

	}

	//제 3 경계선
	for (int i = 0; i <= d2; i++) {

		part[x + d1 + i][y - d1 + i] = 5;

	}

	//제 4 경계선
	for (int i = 0; i <= d1; i++) {

		part[x + d2 + i][y + d2 - i] = 5;

	}

	//1번 선거구
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {


			if (part[i][j] == 0) {

				part[i][j] = 1;

			}
			else {

				break;

			}

		}
	}

	//2번 선거구
	for (int i = 1; i <= x + d2; i++) {
		for (int j = N; j >= y + 1; j--) {

			if (part[i][j] == 0) {

				part[i][j] = 2;

			}
			else {

				break;

			}

		}
	}

	//3번 선거구
	for (int i = x + d1; i <= N; i++) {
		for (int j = 1; j < y - d1 + d2; j++) {

			if (part[i][j] == 0) {

				part[i][j] = 3;

			}
			else {
				
				break;

			}

		}
	}

	//4번 선거구
	for (int i = N; i >= x + d2 + 1; i--) {
		for (int j = N; j >= y - d1 + d2; j--) {

			if (part[i][j] == 0) {

				part[i][j] = 4;

			}
			else {

				break;

			}

		}
	}



}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			cin >> board[i][j];

		}
	}

	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int d1 = 1; d1 <= j - 1; d1++) {
				for (int d2 = 1; d2 <= N - j; d2++) {

					if (i + d1 + d2 <= N) {

						init();
						divide(i, j, d1, d2);
						calc_people();

					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}