class NumArray {
public:
//SEGMENT TREE IMPLEMENTATION (ARRAYS ARE PREFERRED)
    vector<int> st;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n);
        buildTree(0,0,n-1,nums);
    }
    
    void buildTree(int i, int l, int r, vector<int>& nums){
        if(l==r){
            st[i] = nums[r];
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*i + 1, l, mid, nums);
        buildTree(2*i + 2, mid+1, r, nums);
        st[i] = st[2*i+1] + st[2*i + 2];
    }

    int query(int i, int l, int r, int ql, int qr){
        if(r<ql || l>qr) return 0;
        if(ql<=l && r<=qr) return st[i];

        int mid = (l+r)/2;
        return query(2*i + 1,l,mid,ql,qr) + query(2*i + 2,mid+1,r,ql,qr);
    }

    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */