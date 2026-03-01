class Solution {
public:
    class Node{
    public: 
        Node *children[26];
        bool endsWith;
        string word;

        Node(){
            endsWith = false;
            word = "";
            for(int i=0;i<26;i++) children[i] = nullptr;
        }

        bool containsKey(char ch){
            return children[ch-'a'] != nullptr;
        }

        void put(char ch, Node* node){
            children[ch - 'a'] = node;
        }

        Node* get(char ch){
            return children[ch-'a'];
        }
    };

    Node *root = new Node();
    vector<string> result;
    int n, m;

    void insert(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->endsWith = true;
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, Node* node){
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '$')
            return;

        char ch = board[i][j];

        if(!node->containsKey(ch))
            return;

        node = node->get(ch);

        if(node->endsWith){
            result.push_back(node->word);
            node->endsWith = false; 
        }

        board[i][j] = '$';  

        dfs(board, i+1, j, node);
        dfs(board, i-1, j, node);
        dfs(board, i, j+1, node);
        dfs(board, i, j-1, node);

        board[i][j] = ch; 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();

        for(string &word : words){
            insert(word);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(root->containsKey(board[i][j])){
                    dfs(board, i, j, root);
                }
            }
        }

        return result;
    }
};