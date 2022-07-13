#include <iostream>
#include <vector>

using namespace std;

int N; //에너지 구슬의 개수
int W[10]; //에너지 구슬의 무게
int ans;

void sol(int sum, vector<int> v) {

	if (v.size() == 2) {

		if (ans < sum) {

			ans = sum;

		}

		return;
	}

	for (int i = 1; i < v.size() - 1; i++) {

		vector<int> temp_v = v;
		temp_v.erase(temp_v.begin() + i);
        sol(sum + v[i - 1] * v[i + 1], temp_v);

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	vector<int> v;

	for (int n = 0; n < N; n++) {

		cin >> W[n];
		v.push_back(W[n]);

	}

	//sol
	sol(0, v);

	cout << ans << '\n';

	return 0;
}