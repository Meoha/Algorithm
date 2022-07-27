#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int zero_cnt = 0;
    int MIN = 0;
    int idx = 0;
    
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    for(int i = 0 ; i < lottos.size(); i++){
        
        if(lottos[i] == 0){

            zero_cnt++;
            continue;

        }
        
        for(int j = idx; j < win_nums.size(); j++){

            if(lottos[i] == win_nums[j]){
                
                MIN++;
                
            }
            else if(lottos[i] < win_nums[j]){
                
                idx = j;
                break;
                
            }
            
        }
        
    }
    
    if(MIN + zero_cnt > 1){
        
        answer.push_back(7 - MIN - zero_cnt);
        
    }
    else{
        
        answer.push_back(6);
        
    }
    
    if(MIN > 1){
        
        answer.push_back(7 - MIN);
        
    }
    else{
        
        answer.push_back(6);
        
    }
    
    return answer;
}