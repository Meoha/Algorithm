#include <iostream>
#include <string>

using namespace std;

int N; //수식의 길이
string s;
int ans = -987654321;

int calc(int a, int b, char oper) {

	if (oper == '+') {

		return a + b;

	}
	else if (oper == '-') {

		return a - b;

	}
	else if (oper == '*') {

		return a * b;

	}
	else if (oper == '/') {

		return a / b;

	}

}

void sol(int idx, int result) {


	if (idx > N - 1) {

		if (ans < result) {

			ans = result;

		}

		return;
	}

	char op;

	if (idx == 0) {

		op = '+';
	}
	else {

		op = s[idx - 1];

	}

	//괄호로 묶을 경우
	if (idx + 2 < N) {
		
		sol(idx + 4, calc(result, calc(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]), op));

	}

	//괄효로 안묶을 경우
	sol(idx + 2, calc(result, s[idx] - '0', op));

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	cin >> N >> s;

	sol(0, 0);

	cout << ans << '\n';

	return 0;
}