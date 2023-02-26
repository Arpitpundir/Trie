class TrieNode{
    public:
    bool isEnd;
    vector<TrieNode*> child;
    TrieNode(){
        this->isEnd = false;
        this->child.resize(26, NULL);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    public: 
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int wordSize = word.size();
        TrieNode* currNode = this->root;
        for(int i = 0;i < wordSize; i++){
            int currCharInd = word[i]-'a';
            if(!currNode->child[currCharInd]){
                currNode->child[currCharInd] = new TrieNode();
            }
            currNode = currNode->child[currCharInd];
        }
        currNode->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int wordSize = word.size();
        TrieNode* currNode = this->root;
        if(wordSize == 0) return true;
        for(int i=0;i<wordSize;i++){
            int currCharInd = word[i]-'a';
            if(!currNode || !currNode->child[currCharInd]) return false;
            currNode = currNode->child[currCharInd];
        }
        if(currNode->isEnd) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        int wordSize = word.size();
        TrieNode* currNode = this->root;
        if(wordSize == 0) return true;
        for(int i=0;i<wordSize;i++){
            int currCharInd = word[i]-'a';
            if(!currNode || !currNode->child[currCharInd]) return false;
            currNode = currNode->child[currCharInd];
        }
        if(currNode) return true;
        return false;
    }
};