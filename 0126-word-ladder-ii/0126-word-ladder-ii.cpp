class Solution {
private:
    void dfs(string word, string beginWord, vector<string>& seq ,unordered_map<string,int>& mpp, vector<vector<string>>& ans){
        if(word==beginWord){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int n=word.size();
        int steps=mpp[word];
        for(int i=0;i<n;i++){
            char og=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mpp.count(word) && mpp[word]+1==steps){
                    seq.push_back(word);
                    dfs(word,beginWord,seq,mpp,ans);
                    seq.pop_back();
                }
            }
            word[i]=og;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mpp;
        unordered_set<string> st(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        queue<string> q;

        q.push(beginWord);
        mpp[beginWord]=1;
        st.erase(beginWord);
        int n=beginWord.size();

        while(!q.empty()){
            string word=q.front();
            q.pop();
            int steps=mpp[word];
            if(word==endWord) break;
            
            for(int i=0;i<n;i++){
                char og=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word]=steps+1;
                    }
                }
                word[i]=og;
            }
        }

        if(mpp.count(endWord)){
            vector<string> seq={endWord};
            dfs(endWord,beginWord,seq,mpp,ans);
        }

        return ans;
    }
};