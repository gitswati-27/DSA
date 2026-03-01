class WordDictionary {
    WordDictionary* children[26];
    bool endsWith;
public:
    WordDictionary() {
        endsWith = false;
        for(int i=0;i<26;i++) children[i] = nullptr;
    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        for(char c: word){
            if(!node->children[c-'a']) node->children[c-'a'] = new WordDictionary();
            node = node->children[c-'a'];
        }
        node->endsWith = true;
    }
    
    bool search(string word) {
        WordDictionary *node = this;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(c=='.'){
                for(auto ch: node->children){
                    if(ch && ch->search(word.substr(i+1))) return true;
                }
                return false;
            }
            if(node->children[c-'a']==nullptr) return false;
            node = node->children[c-'a'];
        }
        return node && node->endsWith;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */