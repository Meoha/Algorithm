#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Score {

	int paper, interview;

};

int N;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; //테스트 케이스의 개수

	cin >> T;

	for (int t = 1; t <= T; t++) {

		cin >> N;

		vector<vector<int>> s(N, vector<int>(2, 0));
		int answer = 1;

		for (int n = 0; n < N; n++) {

			cin >> s[n][0] >> s[n][1];

		}

		sort(s.begin(), s.end());
		 
		int MAX = s[0][1];

		for (int i = 1; i < N; i++) {

			if (MAX > s[i][1]) {

				answer++;
				MAX = s[i][1];

			}
			
		}

		cout << answer << '\n';

	}

	return 0;
}