#include <iostream>

using namespace std;

char chess[50][50];
char temp_chess[8][8];

void paste(int a, int b) {

	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {

			temp_chess[i - a][j - b] = chess[i][j];

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {

			cin >> chess[n][m];

		}
	}

	int ans = 2500;

	for (int a = 0; a <= N - 8; a++) {
		for (int b = 0; b <= M - 8; b++) {

			paste(a, b);

			char a[2] = {};

			for (int i = 0; i < 2; i++) {

				if (i == 0) {

					a[0] = 'W';
					a[1] = 'B';

				}
				else {

					a[0] = 'B';
					a[1] = 'W';

				}

				int sum = 0;

				for (int n = 0; n < 8; n++) {
					for (int m = 0; m < 8; m++) {

						if (n % 2 == 0 && m % 2 == 0) {

							if (temp_chess[n][m] != a[0]) {

								sum++;

							}

						}

						if (n % 2 == 0 && m % 2 == 1) {

							if (temp_chess[n][m] != a[1]) {

								sum++;

							}

						}

						if (n % 2 == 1 && m % 2 == 0) {

							if (temp_chess[n][m] != a[1]) {

								sum++;

							}

						}

						if (n % 2 == 1 && m % 2 == 1) {

							if (temp_chess[n][m] != a[0]) {

								sum++;

							}

						}

					}
				}
				
				if (ans > sum) {

					ans = sum;

				}

			}

		}
	}

	cout << ans << '\n';

	return 0;
}