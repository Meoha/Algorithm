#include <vector>
#include <iostream>
using namespace std;

vector<int> num;
int ans;

void dfs(int sum, int idx, int cnt){
    
    if(cnt == 3){
        
        for(int i = 2; i * i <= sum; i++){
            
            if(sum % i == 0){
                
                return;
            }
            
        }
        
        ans++;
        
        return;
        
    }
    else{
        
        for(int j = idx; j < num.size(); j++){
        
            dfs(sum + num[j], j + 1, cnt + 1);
            
        }
    
    }
    
}

int solution(vector<int> nums) {
    int answer = 0;
    
    num = nums;

    dfs(0, 0, 0);
    
    answer = ans;
    
    return answer;
}