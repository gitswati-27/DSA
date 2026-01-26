class Solution {
public:
    int countPrimes(int n) {
        if (n<2) return 0;
        vector<bool> sieve(n,true);
        sieve[0] = sieve[1] = false;
        int i=2;
        while(i*i<n){
            if(sieve[i]){
                for(int j=i*i;j<n;j+=i){
                    sieve[j] = false;
                }
            }
            i++;
        }
        int c=0;
        for(bool val: sieve){
            if(val) c++;
        }
        return c;
    }
};