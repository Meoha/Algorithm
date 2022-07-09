#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, X;

	cin >> N >> X;

	int arr[10000] = { 0 };

	for (int n = 0; n < N; n++) {

		cin >> arr[n];

	}

	for (int n = 0; n < N; n++) {

		if (arr[n] < X) {
			cout << arr[n] << " ";
		}

	}

	cout << '\n';

	return 0;
}