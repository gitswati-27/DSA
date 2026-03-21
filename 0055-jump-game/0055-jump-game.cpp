class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;
        int n=nums.size(), pos = 0;
        while(pos<n){
            if(nums[pos]==0) return false;
            int next = -1, steps=-1;
            for(int j = 1;j<=nums[pos];j++){
                if(pos+j>=n-1) return true;
                //if(nums[pos+j]<steps) continue;
                int reach = pos+j+nums[pos+j];
                if(reach>steps){
                    next = pos+j;
                    steps = reach;
                }
            }
            pos = next;
        }
        if(pos<n-1) return false;
        return true;
    }
};