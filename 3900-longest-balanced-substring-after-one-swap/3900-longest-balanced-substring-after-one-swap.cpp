class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();

        int c0=0, c1=0;
        for(char c: s){
            if(c=='0') c0++;
            else c1++;
        }

        int lim = 2*min(c0,c1);
        vector<vector<int>> a(2*n + 5);
        vector<int> head(2*n + 5, 0);
        int shift = n;

        auto add = [&](int val, int i){
            a[val + shift].push_back(i);
        };

        auto valid1 = [&](int val, int t) -> int{
            if(val < -n || val>n) return -1;
            int id = val + shift;
            auto &v = a[id];
            int &h = head[id];
            while(h< (int)v.size() && v[h]<t) h++;
            if(h == (int)v.size()) return -1;
            return v[h];
        };

        int pref = 0, ans = 0;
        add(0,0);

        for(int r = 1; r<=n;r++){
            pref += (s[r-1] == '1' ? 1 : -1);
            int t = max(0, r-lim), best = INT_MAX, x;

            x = valid1(pref, t);
            if(x!=-1) best = min(best, x);

            x = valid1(pref-2, t);
            if(x!=-1) best = min(best,x);
            x = valid1(pref+2, t);
            if(x!=-1) best = min(best,x);

            if(best!= INT_MAX) ans = max(ans, r-best);

            add(pref, r);
        }
        return ans;
    }
};