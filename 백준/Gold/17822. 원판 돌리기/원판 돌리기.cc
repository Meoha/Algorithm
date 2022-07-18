#include <iostream>

using namespace std;

struct Turn {

	int x; //회전시킬 원판이 x의 배수
	int d; //회전 방향
	int k; //회전시킬 칸의 수

};

int N; //반지름의 크기
int M; //원판당 정수의 개수
int T; //회전 수
int circle[51][51]; //원판 정보
int temp_circle[51][51];
struct Turn turn[50]; //회전 정보
int ans;

void init() {

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {

			temp_circle[n][m] = 0;

		}
	}

	return;
}

void check_circle() {

	bool flag = false;
	float sum = 0;
	float s = 0;

	//내부 인접
	for (int n = 1; n <= N; n++) {

		if (circle[n][1] != 0) {

			if (circle[n][1] == circle[n][M] || circle[n][1] == circle[n][2]) {

				flag = true;
				temp_circle[n][1] = 0;

			}
			else {

				temp_circle[n][1] = circle[n][1];

			}

		}

		if (circle[n][M] != 0) {

			if (circle[n][M] == circle[n][M - 1] || circle[n][M] == circle[n][1]) {

				flag = true;
				temp_circle[n][M] = 0;

			}
			else {

				temp_circle[n][M] = circle[n][M];

			}

		}

		for (int m = 2; m <= M - 1; m++) {

			if (circle[n][m] != 0) {

				if (circle[n][m] == circle[n][m - 1] || circle[n][m] == circle[n][m + 1]) {

					flag = true;
					temp_circle[n][m] = 0;

				}
				else {

					temp_circle[n][m] = circle[n][m];

				}

			}

		}
	}

	//외부 인접
	for (int m = 1; m <= M; m++) {

		if (temp_circle[1][m] != 0) {

			if (circle[1][m] == circle[2][m]) {

				flag = true;
				temp_circle[1][m] = 0;

			}
			else {

				temp_circle[1][m] = circle[1][m];

			}

		}

		if (temp_circle[N][m] != 0) {

			if (circle[N][m] == circle[N - 1][m]) {

				flag = true;
				temp_circle[N][m] = 0;

			}
			else {

				temp_circle[N][m] = circle[N][m];

			}

		}


		for (int n = 2; n <= N - 1; n++) {

			if (temp_circle[n][m] != 0) {

				if (circle[n][m] == circle[n - 1][m] || circle[n][m] == circle[n + 1][m]) {

					flag = true;
					temp_circle[n][m] = 0;

				}
				else {

					temp_circle[n][m] = circle[n][m];

				}

			}

		}
	}

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {

			circle[n][m] = temp_circle[n][m];

			if(!flag && circle[n][m] != 0){

				sum = sum + (float) circle[n][m];
				s++;

			}

		}
	}

	float avg = sum / s;

	if (!flag) {
		for (int n = 1; n <= N; n++) {
			for (int m = 1; m <= M; m++) {

				if (circle[n][m] != 0 && circle[n][m] > avg) {

					circle[n][m]--;

				}
				else if (circle[n][m] != 0 && circle[n][m] < avg) {

					circle[n][m]++;

				}
			}
		}
	}

	return;
}


void sol() {

	//회전당 동작
	for (int t = 0; t < T; t++) {

		//회전 방법
		int xi = turn[t].x;
		int di = turn[t].d;
		int ki = turn[t].k;
		int i = 1;

		//회전
		while (xi * i <= N) {

			//시계 방향 회전
			if (di == 0) {

				for (int b = 1; b <= ki; b++) {
					
					
					int temp1 = circle[xi * i][1];
					circle[xi * i][1] = circle[xi * i][M];

					for (int a = 1; a < M; a++) {


						int temp2 = circle[xi * i][a + 1];
						circle[xi * i][a + 1] = temp1;
						temp1 = temp2;

					}

				}
			

			}
			//반시계 방향 회전
			else if (di == 1) {

				for (int b = 1; b <= ki; b++) {
					
					int temp1 = circle[xi * i][M];
					circle[xi * i][M] = circle[xi * i][1];

					for (int a = M; a >= 2; a--) {

						int temp2 = circle[xi * i][a - 1];
						circle[xi * i][a - 1] = temp1;
						temp1 = temp2;

					}

				}

			}

			i++;
		}

		//회전 후
		check_circle();
		init();

	}

}

void calc_sum() {

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {

			ans = ans + circle[n][m];

		}
	}
	
	return;
}

int main() {

	cin >> N >> M >> T;

	//원판 정보 입력
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {

			cin >> circle[n][m];

		}
	}

	//회전 정보 입력
	for (int t = 0; t < T; t++) {

		cin >> turn[t].x >> turn[t].d >> turn[t].k;

	}

	//sol
	sol();

	calc_sum();

	cout << ans << '\n';

	return 0;
}