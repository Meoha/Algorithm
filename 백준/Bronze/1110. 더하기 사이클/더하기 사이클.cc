#include <iostream>

using namespace std;

int N;
int ans;

void sol(int a) {

	int temp1 = 0; // 10의 자리
	int temp2 = 0; // 1의 자리
	int new_num = 0;

	new_num = a;

	while (1) {
		temp1 = new_num / 10;
		temp2 = new_num % 10;

		new_num = temp2 * 10 + ((temp1 + temp2) %10);
		ans++;

		if (a == new_num) {
			break;
		}
	}

}

int main() {

	cin >> N;

	sol(N);

	cout << ans << endl;


	return 0;
}