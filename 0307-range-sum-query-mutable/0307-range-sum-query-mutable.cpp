class NumArray {
public:
    vector<int> BIT;
    vector<int> arr;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        BIT.resize(n + 1, 0);
        arr = nums;

        for(int i = 0; i < n; i++) {
            init(i, nums[i]);
        }
    }

    void init(int i, int val) {
        i++;
        while(i <= n) {
            BIT[i] += val;
            i += i & (-i);
        }
    }

    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        init(index, diff);
    }

    int getSum(int i) {
        int sum = 0;
        i++;
        while(i > 0) {
            sum += BIT[i];
            i -= i & (-i);
        }
        return sum;
    }

    int sumRange(int left, int right) {
        return getSum(right) - getSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */