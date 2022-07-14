#include <iostream>
#include <queue>

using namespace std;

int N;
int near[401][4];
int table[21][21];
queue<int> q;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int calc() {

	int ret = 0;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {

			int want = 0;

			for (int d = 0; d < 4; d++) {

				int nx = x + dir[d][0];
				int ny = y + dir[d][1];

				if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {

					if (table[nx][ny] != 0) {

						for (int idx = 0; idx < 4; idx++) {

							if (near[table[x][y]][idx] == table[nx][ny]) {

								want++;

							}

						}

					}

				}

			}

			if (want == 1) {

				ret += 1;

			}
			else if (want == 2) {

				ret += 10;

			}
			else if (want == 3) {

				ret += 100;

			}
			else if (want == 4) {

				ret += 1000;

			}
		}
	}

	return ret;
}

void sit_down() {

	while (!q.empty()) {

		int stu = q.front();
		q.pop();

		int temp_x = 21;
		int temp_y = 21;
		int MAX_want = 0;
		int MAX_blank = 0;

		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {

				int want = 0;
				int blank = 0;

				if (table[x][y] == 0) {

					for (int d = 0; d < 4; d++) {

						int nx = x + dir[d][0];
						int ny = y + dir[d][1];

						if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {

							for (int idx = 0; idx < 4; idx++) {

								if (near[stu][idx] == table[nx][ny]) {

									want += 1;
									break;

								}

							}

							if (table[nx][ny] == 0) {

								blank += 1;

							}

						}

					}

					if (want != 0) {
						if (MAX_want < want) {

							temp_x = x;
							temp_y = y;
							MAX_want = want;
							MAX_blank = blank;

						}
						else if (MAX_want == want) {

							if (MAX_blank < blank) {

								temp_x = x;
								temp_y = y;
								MAX_blank = blank;

							}
							else if (MAX_blank == blank) {

								if (temp_y > y) {

									temp_y = y;
									temp_x = x;

								}
								else if (temp_y == y) {

									if (temp_x > x) {

										temp_x = x;
										temp_y = y;

									}

								}

							}

						}
					}
					else if (want == 0 && MAX_want == 0) {

						if (MAX_blank < blank) {

							temp_x = x;
							temp_y = y;
							MAX_blank = blank;

						}
						else if (MAX_blank == blank) {

							if (temp_y > y) {

								temp_y = y;
								temp_x = x;

							}
							else if (temp_y == y) {

								if (temp_x > x) {

									temp_x = x;
									temp_y = y;

								}
							}

						}

					}

				}

			}
		}

		table[temp_x][temp_y] = stu;

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int n = 1; n <= N * N; n++) {

		int a, b, c, d, e;

		cin >> a >> b >> c >> d >> e;

		near[a][0] = b;
		near[a][1] = c;
		near[a][2] = d;
		near[a][3] = e;

		q.push(a);

	}

	//sit_down
	sit_down();
	int ans = calc();

	cout << ans << '\n';

	return 0;
}