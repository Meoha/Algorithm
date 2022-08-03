#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    for(int i = 0; i < signs.size(); i++){
        
        //실제 정수가 음수인 경우
        if(!signs[i]){
            
            answer -= absolutes[i];
            
        }
        //실제 정수가 양수인 경우
        else{
            
            answer += absolutes[i];
            
        }
        
    }
    
    return answer;
}