class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int overmin = INT_MAX;
        vector<vector<int>> res;
        for(int i=1;i<n;i++){
            int diff = arr[i] - arr[i-1];
            if(diff<overmin){
                overmin = diff;
                res = {}; //emptying the res vector
                res.push_back({arr[i-1],arr[i]});
            }
            else if(diff==overmin){
                res.push_back({arr[i-1],arr[i]});
            }
        }
        return res;

    }
};