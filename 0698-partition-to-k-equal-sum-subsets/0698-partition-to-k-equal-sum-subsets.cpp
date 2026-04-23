class Solution {
public:
    bool backtrack(int idx, vector<int>& nums, vector<int>& buckets, int target) {
        if (idx == nums.size()) return true;
        int num = nums[idx];

        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i] + num > target) continue;

            //place number
            buckets[i] += num;

            if (backtrack(idx + 1, nums, buckets, target))
                return true;

            //undo
            buckets[i] -= num;

            if (buckets[i] == 0) break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for (int num : nums) total += num;

        if (total % k != 0) return false;

        int target = total / k;

        sort(nums.rbegin(), nums.rend()); 
        if (nums[0] > target) return false;

        vector<int> buckets(k, 0);

        return backtrack(0, nums, buckets, target);
    }
};