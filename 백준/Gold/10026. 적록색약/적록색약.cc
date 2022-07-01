#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int N;
int map[101][101];
bool visited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
int temp_result;
int ans[2];

//적록색약이 아닌 사람이 보는 그림
void normal(int a) {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] == a && !visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}

	temp_result++;
}

void abnormal(int a) {

	int flag = 0;

	if (a == 3) {
		flag = 1;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (flag == 0) {
					if ((map[nx][ny] == 1 || map[nx][ny] == 2) && !visited[nx][ny]) {
						q.push(make_pair(nx, ny));
						visited[nx][ny] = true;
					}
				}
				else if (flag == 1) {
					
					if (map[nx][ny] == 3 && !visited[nx][ny]) {
						q.push(make_pair(nx, ny));
						visited[nx][ny] = true;
					}
				}
			}
		}
	}

	temp_result++;

}

int main() {

	cin >> N;

	for (int n = 0; n < N; n++) {
		string temp = "";

		cin >> temp;

		for (int i = 0; i < temp.length(); i++) {
			
			if (temp[i] == 'R') {
				map[i][n] = 1;
			}
			else if (temp[i] == 'G') {
				map[i][n] = 2;
			}
			else if (temp[i] == 'B') {
				map[i][n] = 3;
			}
		}

	}

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
	

			if (!visited[i][j]) {

				q.push(make_pair(i, j));
				visited[i][j] = true;
				
				normal(map[i][j]);
			}
		}
	}

	ans[0] = temp_result;
	temp_result = 0;

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {

			visited[i][j] = false;
		}
	}

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {

			if (!visited[i][j]) {
				q.push(make_pair(i, j));
				visited[i][j] = true;

				abnormal(map[i][j]);
			}
		}
	}
	

	ans[1] = temp_result;

	cout << ans[0] << ' ' << ans[1] << endl;

	return 0;
}