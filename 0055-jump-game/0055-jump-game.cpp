class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;
        int maxi = nums[0];
        int n=nums.size(), pos = 0;
        for(int i=0;i<n;i++){
            if(i>maxi) return false;
            if(maxi >= n-1) return true;
            int reach = i + nums[i];
            maxi = max(maxi, reach);
        }
        return true;
    }
};