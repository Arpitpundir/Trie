class TrieNode{
    public:
    bool isEnd;
    vector<TrieNode*> child;
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            child.push_back(NULL);
        }
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(vector<string> words){
        root=new TrieNode;
        int l=words.size();
        for(int i=0;i<l;i++){
            addWord(words[i]);
        }
    }
    void addWord(string word){
        int l=word.size();
        TrieNode* curr=root;
        for(int i=0;i<l;i++){
            char c=word[i];
            if(curr->child[c-'a']==NULL){
                curr->child[c-'a']=new TrieNode;
            }
            curr=curr->child[c-'a'];
        }
        curr->isEnd=true;
    }
};
class Solution {
public:
    void dfs(vector<vector<char> >&board,int x,int y,TrieNode* root,string word,unordered_set<string> &res){
       // cout<<"ahah"<<endl;
        if(x<0||x>=board.size()||y<0||y>=board[0].size()||board[x][y]==' '){
            return;
        }
        char c=board[x][y];
        word=word+c;
        root=root->child[c-'a'];
        if(root==NULL)
            return;
        if(root->isEnd){
            res.insert(word);
            //return;
        }
        board[x][y]=' ';
        dfs(board,x+1,y,root,word,res);
        dfs(board,x-1,y,root,word,res);
        dfs(board,x,y+1,root,word,res);
        dfs(board,x,y-1,root,word,res);
        board[x][y]=c;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie=new Trie(words);
        TrieNode* root=trie->root;
        unordered_set<string> res;
        int n=board.size(),m=board[0].size();
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                dfs(board,x,y,root,"",res);
            }
        }
        vector<string> ans;
        ans.assign(res.begin(),res.end());
        return ans;
    }
};
