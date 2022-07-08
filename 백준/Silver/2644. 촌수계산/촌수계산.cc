#include <iostream>
#include <vector>

using namespace std;

int N; //전체 사람의 수
int check[2]; //촌수를 계산해야 하는 사람
int M; //부모 자식간의 관계의 개수
vector<int> arr[101]; //촌수 정보
bool visited[101]; //방문 배열
int ans = -1;

void dfs(int p, int c, int cnt) {

	if (c == p) {

		ans = cnt;

		return;
	}

	for (int i = 0; i < arr[p].size(); i++) {

		if (!visited[arr[p][i]]) {

			visited[p] = true;
			dfs(arr[p][i], c, cnt + 1);

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	cin >> check[0] >> check[1];

	cin >> M;

	for (int m = 0; m < M; m++) {

		int t1;
		int t2;

		cin >> t1 >> t2;

		arr[t1].push_back(t2);
		arr[t2].push_back(t1);

	}

	dfs(check[0], check[1], 0);

	cout << ans << '\n';

	return 0;
}