#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int idx = 0;
    string temp = "";
    vector<string> eng = {"ze", "on", "tw", "th", "fo", "fi", "si", "se", "ei", "ni"};
    
    while(idx < s.length()){
        
        if(s[idx] >= '0' && s[idx] <= '9'){
            
            answer = answer * 10 + (s[idx] - '0');
            idx++;
            continue;
            
        }
        
        if(temp.length() == 2){
            
            for(int i = 0; i < eng.size(); i++){
            
                if(temp == eng[i]){
                    
                    answer = answer * 10 + i;
                    
                    if(i == 1 || i == 2 || i == 6){
                        
                        idx += 1;
                        
                    }
                    else if(i == 0 || i == 4 || i == 5 || i == 9){
                        
                        idx += 2;
                        
                    }
                    else if(i == 3 || i == 7 || i == 8){
                        
                        idx += 3;
                        
                    }
                    
                    break;
                    
                }
                
                
            }
            
            temp = "";
            
            continue;
            
        }
        else{
            
            temp += s[idx];
            idx++;
            
        }
        
    }
    
    return answer;
}