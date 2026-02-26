class Solution {

private:
    void addOne(string&s){
        int carry = 1;
        const int len = s.size();
        for(int i=len-1;i>=0;--i){
            int sum = s[i]-'0'+carry;
            if(sum==0 || sum == 2){
                s[i]='0';
                if(sum==0){
                    carry=0;
                }
                else{
                    carry=1;
                }
                continue;
            }
            else{
                s[i]='1';
                carry=0;
                continue;
            }
        }
        if(carry==1){
            s = '1'+s;
        }
    }

public:
    int numSteps(string s) {
        int len = s.size();
        int ops = 0;
        while(s.size()>1){
            if(s[s.size()-1]=='1'){
                addOne(s);
            }
            else{
                s.pop_back();
            }
            ++ops;
        }
        return ops;
    }
};