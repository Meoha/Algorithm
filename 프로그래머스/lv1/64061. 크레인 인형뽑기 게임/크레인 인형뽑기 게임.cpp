#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> box;
    
    for(int i = 0; i < moves.size(); i++){
        
        for(int j = 0; j < board.size(); j++){
            
            if(board[j][moves[i] - 1] != 0){
                
                if(box.size() != 0){
                    
                    if(box[box.size() - 1] == board[j][moves[i] - 1]){
                        
                        answer += 2;
                        box.pop_back();
                        board[j][moves[i] - 1] = 0;
                        
                    }
                    else{

                        box.push_back(board[j][moves[i] - 1]);
                        board[j][moves[i] - 1] = 0;
                        
                    }
                    
                }
                else{
                    
                    box.push_back(board[j][moves[i] - 1]);
                    board[j][moves[i] - 1] = 0;      
                    
                }
                
                break;
                  
            }
            
        }
        
    }
    
    return answer;
}