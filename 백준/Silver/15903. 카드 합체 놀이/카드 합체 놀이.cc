#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N; //카드의 개수
	int M; //카드 합체 횟수
	long long ans = 0;

	cin >> N >> M;

	long long* card = (long long*)malloc(sizeof(long long) * N); //카드의 상태 정보

	for (int n = 0; n < N; n++) {

		cin >> card[n];

	}

	for (int m = 0; m < M; m++) {

		//카드 정렬
		sort(card, card + N);

		//카드 합체
		card[0] = card[0] + card[1];
		card[1] = card[0];

	}

	for (int n = 0; n < N; n++) {

		ans += card[n];

	}

	cout << ans << '\n';

	return 0;
}