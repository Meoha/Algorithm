#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; //사다리의 수
int M; //뱀의 수
vector<pair<int, int>> mov; //사다리와 뱀의 위치
queue<pair<int, int>> q; //말의 위치 및 차례
bool visited[101];
int ans;

//사다리나 뱀의 위치 확인
int check_mov(int a) {

	for (int i = 0; i < mov.size(); i++) {

		if (mov[i].first == a) {

			return mov[i].second;

		}

	}

	return a;
}

void sol() {

	//1부터 시작
	for (int i = 2; i <= 7; i++) {

		int m = check_mov(i);
		q.push({ m, 1 });
		visited[m] = true;

	}

	while (!q.empty()) {

		int x = q.front().first;
		int turn = q.front().second;

		q.pop();

		if (x >= 100) {

			ans = turn;

			return;
		}

		for (int i = 1; i <= 6; i++) {

			int nx = check_mov(x + i);

			if (!visited[nx]) {

				q.push({ nx, turn + 1 });
				visited[nx] = true;

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {

		int a, b = 0;

		cin >> a >> b;

		mov.push_back(make_pair(a, b));

	}

	//sol
	sol();

	cout << ans << '\n';

	return 0;
}