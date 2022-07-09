#include <iostream>
#include <vector>

using namespace std;

int N, M;

void sol(vector<int> v) {

	if (v.size() == M) {

		for (int i = 0; i < M; i++) {

			cout << v[i] << ' ';

		}

		cout << '\n';

		return;
	}
	else {

		for (int i = 1; i <= N; i++) {

			bool flag = true;

			
			v.push_back(i);

			sol(v);

			v.pop_back();

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	vector<int> v;

	sol(v);

	return 0;
}