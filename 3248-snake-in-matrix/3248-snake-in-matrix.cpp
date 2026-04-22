class Solution {
public:
    int finalPositionOfSnake(int gridSize, vector<string>& com) {
        int x = 0, y = 0, n = com.size();
        for(int i = 0; i < n; i++){
            string s = com[i];
            if(s == "UP"){
                x--;
            }
            else if(s == "DOWN"){
                x++;
            }
            else if(s == "RIGHT"){
                y++;
            }
            else{
                y--;
            }
        }
        return (x * gridSize) + y;
    }
};