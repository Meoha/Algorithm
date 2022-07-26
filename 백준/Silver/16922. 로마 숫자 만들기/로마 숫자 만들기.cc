#include <iostream>

using namespace std;

int N;
bool visited[1001];
int roma[4] = { 1, 5, 10, 50 };
int ans;

void sol(int cnt, int idx, int sum) {

	if (cnt == N) {

		if (!visited[sum]) {

			visited[sum] = true;
			ans++;

		}

		return;
	}

	for(int i = idx; i < 4; i++)
		sol(cnt + 1, i, sum + roma[i]);

}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	sol(0, 0, 0);

	cout << ans << '\n';

	return 0;
}