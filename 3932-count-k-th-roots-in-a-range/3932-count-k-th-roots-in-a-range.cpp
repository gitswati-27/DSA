class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        long long left = ceilRoot(l,k);
        long long right = floorRoot(r,k);
        if(left>right) return 0;
        return (int)(right - left + 1);
    }

    long long ceilRoot(long long n, int k){
        long long f = floorRoot(n,k);
        if(power(f,k,n)==n) return f;
        return f+1;
    }

    long long floorRoot(long long n, int k){
        long long l = 0, h = 1e9;
        long long ans = 0;

        while(l<=h){
            long long mid = l + (h - l)/2;
            if(power(mid,k,n)<=n){
                ans = mid;
                l = mid+1;
            }
            else h = mid-1;
        }
        return ans;
    }

    long long power(long long n, int k, long long lim){
        long long res = 1;
        for(int i=0;i<k;i++){
            if(n) if(res>lim/n) return lim+1;
            res *= n;
        }
        return res;
    }
};