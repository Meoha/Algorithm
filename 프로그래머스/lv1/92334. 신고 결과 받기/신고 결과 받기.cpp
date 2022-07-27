#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    //동일 유저 신고 중복 제거
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    //key : 유저 ID, value : 유저가 신고한 ID 집합
    map<string, vector<string>> report_list;
    
    //누적 신고 횟수
    vector<int> cnt(id_list.size(), 0);
    
    for(int i = 0; i < report.size(); i++){
        
        string user = "";
        string r_user = "";
        bool flag = false;
        
        for(int j = 0; j < report[i].length(); j++){
            
            //공백 다음 유저가 신고한 ID 기록
            if(report[i][j] == ' '){
                
                flag = true;
                continue;
                
            }
            
            //공백 이전 유저 ID 기록
            if(!flag){
                
                user += report[i][j];
                
            }
            else{
                
                r_user += report[i][j];
                
            }
            
        }
        
        report_list[user].push_back(r_user);
        
        //누적 신고 횟수 기록
        for(int c = 0; c < cnt.size(); c++){    
            
            if(id_list[c] == r_user){
            
                cnt[c]++;
                
            }
            
        }
        
    }
    
    //k번 이상 신고당한 유저 목록 구하기
    vector<string> ban;
    
    for(int i = 0; i < id_list.size(); i++){
        
        if(cnt[i] >= k){
            
            ban.push_back(id_list[i]);
            
        }
        
    }
    
    //처리 결과 메일 받은 횟수 구하기
    for(int i = 0; i < id_list.size(); i++){
        
        int n = 0;
        
        for(int c = 0; c < report_list[id_list[i]].size(); c++){
        
            for(int j = 0; j < ban.size(); j++){
                
                if(report_list[id_list[i]][c] == ban[j]){
                    
                    n++;
                    break;
                }
                
            }
            
        }
        
        answer.push_back(n);
        
    }
    
    return answer;
}