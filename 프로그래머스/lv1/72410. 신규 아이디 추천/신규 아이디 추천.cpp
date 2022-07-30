#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //1단계 대문자를 소문자로 치환
    for(int i = 0; i < new_id.length(); i++){
        
        if(new_id[i] >= 'A' && new_id[i] <= 'Z'){
            
            new_id[i] += 32;
            
        }
        
    }
    
    //2단계 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표를 제외한 모든 문자 제거
    
    string temp = "";
    
    for(int i = 0; i < new_id.length(); i++){
        
        if((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            
            temp += new_id[i];
            
        }
        
    }
    
    new_id = temp;

    //3단계 마침표가 2번 이상 연속된 부분을 하나의 마침표로 치환
    temp = "";
    
    for(int i = 0; i < new_id.length(); i++){
        
        if(new_id[i] == '.' && new_id[i + 1] == '.'){
            
            continue;
            
        }
        
        temp += new_id[i];
        
    }
    
    new_id = temp;
  
    //4단계 마침표가 처음이나 끝에 위치하면 제거
    if(new_id[0] == '.'){
        
        new_id = new_id.substr(1);
        
    }
    
    if(new_id[new_id.length() - 1] == '.'){
        
        new_id = new_id.substr(0, new_id.length() - 1);
        
    }
    
    //5단계 빈 문자열이면, "a"를 대입
    if(new_id.length() == 0){
        
        new_id = "a";
        
    }
    
    //6단계 길이가 16자 이상이면, 첫 15개의 문자 제외 나머지 문자 제거
    //만약, 제거 후 마지막이 마침표이면 마침표도 제거
    new_id = new_id.substr(0, 15);
    
    if(new_id[new_id.length() - 1] == '.'){
        
        new_id = new_id.substr(0, new_id.length() - 1);
        
    }
    
    //7단계 길이가 2자 이하이면, 마지막 문자를 길이가 3이 될 때까지 반복
    
    while(new_id.length() <= 2){
        
        new_id += new_id[new_id.length() - 1];
        
    }
    
    answer = new_id;
    
    return answer;
}