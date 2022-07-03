#include <iostream>
#include <vector>

using namespace std;

//좌표 정보
struct INFO {

	int x, y;
	bool pick;

};

int N; //가로, 세로 길이
int M; //선택하는 치킨집의 최대 개수
int board[51][51]; //지도 정보
vector<INFO> home; //집의 위치 리스트
vector<INFO> chicken; //치킨집의 위치 리스트
int ans = 987654321;

//거리 구하기
void chicken_dist() {

	int total_dist = 0;

	for (int h = 0; h < home.size(); h++) {

		int dist = 2 * N;
		
		for (int c = 0; c < chicken.size(); c++) {

			if (chicken[c].pick) {

				int temp = abs(home[h].x - chicken[c].x) + abs(home[h].y - chicken[c].y);

				if (temp < dist) {

					dist = temp;

				}

			}

		}

		total_dist += dist;

	}

	if (ans > total_dist) {
		 
		ans = total_dist;

	}

	return;
}

//치킨집 M개 고르기
void pick_chicken(int idx, int cnt) {

	//최대 M개의 치킨집이지만 M개 일때가 가장 좋음
	if (chicken.size() - M - cnt == 0) {

		chicken_dist();

		return;
	}
	else {

		for (int i = idx; i < chicken.size(); i++) {

			//i번째 치킨 집을 폐업할 때
			chicken[i].pick = false;
			pick_chicken(i + 1, cnt + 1);

			//i번째 치킨 집을 폐업하지 않을 때
			chicken[i].pick = true;
			pick_chicken(i + 1, cnt);

		}

	}

}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	
	//지도 정보 및 집, 치킨집 위치 저장
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			cin >> board[i][j];

			if (board[i][j] == 1) {

				home.push_back({ j, i , true});

			}

			if (board[i][j] == 2) {

				chicken.push_back({ j, i , true});

			}

		}
	}

	//sol
	pick_chicken(0, 0);

	cout << ans << '\n';

	return 0;
}