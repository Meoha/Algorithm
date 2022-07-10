#include <iostream>
#include <queue>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N; //카드의 개수
	int M; //카드 합체 횟수
	long long ans = 0;

	cin >> N >> M;

	priority_queue<long long, vector<long long>, greater<long long>> pq; //카드의 상태 정보 우선 순위 큐
	
	for (int n = 0; n < N; n++) {

		long long temp;

		cin >> temp;

		pq.push(temp);

	}

	//카드 합체	
	for (int m = 0; m < M; m++) {

		long long num = pq.top();
		pq.pop();
		num += pq.top();
		pq.pop();
		pq.push(num);
		pq.push(num);

	}

	while (!pq.empty()) {

		ans += pq.top();
		pq.pop();

	}

	cout << ans << '\n';

	return 0;
}