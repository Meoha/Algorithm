#include <iostream>

using namespace std;

int N;
int arr[16][2];
int ans;

void sol(int day, int cost) {

	if (day >= N + 1) {

		if (ans < cost) {

			ans = cost;

		}

		return;
	}
	else {

		//상담을 할 경우
		if (day + arr[day][0] <= N + 1 && day > 0) {

			sol(day + arr[day][0], cost + arr[day][1]);

		}

		//상담을 하지 않을 경우
		sol(day + 1, cost);

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int n = 1; n <= N; n++) {

		cin >> arr[n][0] >> arr[n][1];

	}

	//sol
	sol(0, 0);

	cout << ans << '\n';

	return 0;
}