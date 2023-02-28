class TrieNode{
    public:
    bool isEnd;
    vector<TrieNode*> child;
    TrieNode(){
        this->isEnd = false;
        child = vector<TrieNode*>(26, NULL);
    }
};
class WordDictionary {
    TrieNode *trieRoot;
public:
    WordDictionary() {
        this->trieRoot = new TrieNode();
    }
    
    void addWord(string word) {
        int wordSize = word.size();
        TrieNode *currNode = this->trieRoot;
        for(int i=0;i<wordSize;i++){
            int currChar = word[i] - 'a';
            if(currNode->child[currChar] == NULL){
                currNode->child[currChar] = new TrieNode();
            }
            currNode = currNode->child[currChar];
        }
        currNode->isEnd = true;
    }
    
    bool search(string word) {
        int wordSize = word.size();
        TrieNode *currNode = this->trieRoot;
        return this->searchRecursive(word, 0, currNode);
    }

    bool searchRecursive(string &word, int index, TrieNode *currNode){
      /*
      * if curr char is . then i can match . to any child of curr node, if index is last then and no child is there with isEnd as true
      * then return false, else if index is not last then call searchRecursive on all children of currNode
      * if curr char is not . then check for child that matches curr char, if no child is there return false
      * if child is there and it is last index and child has isEnd as true then return true
      * else if child is there and it is not last index then call searchRecursive on child
      */
        if(word[index] == '.'){
                for(int j=0;j<26;j++){
                    if(index == word.size()-1){
                        if(currNode->child[j] && currNode->child[j]->isEnd){
                            return true;
                        }else if(j == 25){
                            return false;
                        }
                    }else{
                        if(currNode->child[j] != NULL && this->searchRecursive(word, index+1, currNode->child[j])){
                            return true;
                        }
                    }
                }
                return false;
        }else{
            int currChar = word[index]-'a';
            if(index == word.size()-1){
                if(currNode->child[currChar] && currNode->child[currChar]->isEnd){
                  return true;
                }else{
                    return false;
                }
            }else{
                if(currNode->child[currChar] && this->searchRecursive(word, index+1, currNode->child[currChar])){
                    return true;
                }else{
                    return false;
                }
            }
        }
    }
};