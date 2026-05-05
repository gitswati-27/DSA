class Solution {
public:
    int reverse(int x) {
        long long y=0;
        while(x!=0){
            int r = x%10;
            y = y*10 + r;
            if(y>INT_MAX||y<INT_MIN) return 0;
            x /= 10;
        }
        return y;
    }
};