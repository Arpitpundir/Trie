#include<bits/stdc++.h>
using namespace std;
class TrieNode{
  public:
  bool isEnd;
  vector<TrieNode*> children;
  TrieNode(){
    isEnd = false;
    children = vector<TrieNode*> (26, NULL);
  }
};

class Trie(){
  public:
  TrieNode* root;
  Trie(vector<string> &words){
    root = new TrieNode();
    int n=words.size();
    for(int i=0;i<n;i++){
      this.addWord(words[i]);
    }
  }
  TrieNode* getRoot(){
    return root;
  }
  void addWord(string currWord){
    TrieNode* curr = this.root;
    int currWordSize = currWord.size();
    for(int i=0;i<currWordSize;i++){
      int currCharInd = currWord[i]-'a';
      if(curr->children[currCharInd] == NULL){
        curr->children[currCharInd] = new TrieNode();
      }
      curr = curr->children[currCharInd];
    }
    curr->isEnd = true;
  }
}
int main(){

}
