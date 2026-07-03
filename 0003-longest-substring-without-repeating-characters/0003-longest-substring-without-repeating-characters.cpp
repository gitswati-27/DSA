class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int longest = 0;
        unordered_set<char> a;

        for(int r=0;r<s.size();r++){
            while (a.count(s[r])){
                a.erase(s[l]);
                l++;
            }
            a.insert(s[r]);
            longest = max(longest, r-l+1);
        }

        return longest;
    }
};