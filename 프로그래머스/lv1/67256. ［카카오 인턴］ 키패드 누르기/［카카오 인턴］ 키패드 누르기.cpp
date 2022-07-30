#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int left = 10;
    int right = 12;
    
    for(int i = 0; i < numbers.size(); i++){
        
        if(numbers[i] == 0){
            
            numbers[i] = 11;
            
        }
        
        if(numbers[i] % 3 == 1){
            
            answer = answer + "L";
            left = numbers[i];
            
        }
        else if(numbers[i] % 3 == 0){
            
            answer = answer + "R";
            right = numbers[i];
            
        }
        else{
            
            int left_d = abs(numbers[i] - left);
            
            if(left_d == 2 || left_d == 4){
                
                left_d = 2;
                
            }
            else if(left_d == 5 || left_d == 7){
                
                left_d = 3;
                
            }
            else if(left_d == 8 || left_d == 10){
                
                left_d = 4;
                
            }
            else if(left_d % 3 == 0){
                
                left_d = left_d / 3;
                
            }
            
            int right_d = abs(numbers[i] - right);
            
            if(right_d == 2 || right_d == 4){
                
                right_d = 2;
                
            }
            else if(right_d == 5 || right_d == 7){
                
                right_d = 3;
                
            }
            else if(right_d == 8 || right_d == 10){
                
                right_d = 4;
                
            }
            else if(right_d % 3 == 0){
                
                right_d = right_d / 3;
                
            }
            
            if(left_d < right_d){
                
                answer = answer + "L";
                left = numbers[i];
                
            }
            else if(left_d > right_d){
                
                answer = answer + "R";
                right = numbers[i];
                
            }
            else{
                
                if(hand == "left"){

                    answer = answer + "L";
                    left = numbers[i];
                    
                }
                else{
                    
                    answer = answer + "R";
                    right = numbers[i];
                    
                }
                
            }
            
        }
        
    }
    
    return answer;
}