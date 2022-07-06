#include <iostream>
#include <queue>

using namespace std;

int N, M;
int box[1000][1000];
queue<pair<int, int>> q;
int a, b, c, d;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1};



void bfs() {

	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			c = a + dx[i];
			d = b + dy[i];

			if (c < 0 || d < 0 || c >= N || d >= M) {
				continue;
			}

			if (box[c][d] == 0) {
				q.push(make_pair(c, d));
				box[c][d] = box[a][b] + 1;
			}
		}
	}
}

int main(void) {
	
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];

			if (box[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	bool f = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				f = true;
			}
		}
	}

	if (f == false) {
		cout << 0;

		return 0;
	}
	else {
		bfs();
		
		int max = 0;
		bool flag = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				if (max < box[i][j]) {
					max = box[i][j];
				}

				if (box[i][j] == 0) {
					cout << -1;

					return 0;
				}
			}
		}

		cout << max - 1;

	}

	return 0;
}