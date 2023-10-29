 
#include<iostream>
#include<stack>
#define ALPHABETS 26
#define DEBUG true
#define DEBUG_MESSAGE(message){ if (DEBUG) std::cout << "DEBUG : " << message << std::endl;}

struct TrieNode{
  struct TrieNode* children[ALPHABETS];
  bool isEnd;

  TrieNode(){
    this->isEnd = false;
    for(int i = 0; i < ALPHABETS; i++){
      this->children[i] = nullptr;
    }
  }

  TrieNode(bool isEnd){
    TrieNode();
    this->isEnd = isEnd;
  }
};


class Trie{

private:
  TrieNode* mRoot;
  int       mWordCount;

  void purge(TrieNode* root){
    for(int i = 0; i < ALPHABETS; i++){
      if(root->children[i] != nullptr){
        purge(root->children[i]);
      }
    }
    delete root;
    DEBUG_MESSAGE("node deleted.")
  }

  bool checkValidity(const std::string& word){
    for(int i = 0; i < word.size(); i++){
      char ch = word[i];
      if(ch < 'a' or ch > 'z'){
        return false;
      }
    }
    return true;
  }

  void _printWords(const TrieNode* root, std::string& currentChars){
    if(root->isEnd){
      std::cout << currentChars << std::endl;
    }
    for(int i = 0; i < ALPHABETS; i++){
      if(root->children[i] == nullptr){
        continue;
      }
      char ch = 'a' + i;
      currentChars.push_back(ch);
      _printWords(root->children[i], currentChars);
      currentChars.pop_back();
    }
  }

  bool isEmpty(const TrieNode* node){
    if( node->isEnd ){
      return false;
    }

    bool res = true;
    for(int i = 0; i < ALPHABETS; i++){
      if(node->children[i] != nullptr){
        res = false;
        break;
      }
    }

    return res;
  }

public:

  Trie() : mRoot(new TrieNode()), mWordCount(0) {}

  ~Trie(){
    DEBUG_MESSAGE("Destructor called.")
    purge(mRoot);
  }

  void insert(const std::string& word){
    if( not checkValidity(word) ){
      return;
    }

    if(word.size() == 0){
      return;
    }

    TrieNode* currNode = mRoot;
    
    for(int i = 0; i < word.size(); i++){
      char ch = word[i];
      int charIndex = ch - 'a';

      if(currNode->children[charIndex] == nullptr){
        currNode->children[charIndex] = new TrieNode();
      }

      currNode = currNode->children[charIndex];
    }

    if(not currNode->isEnd ){
      currNode->isEnd = true;
      mWordCount++;
    }
  }

  void remove(const std::string& word){
    if( not checkValidity(word) or word.size() == 0 ){
      return;
    }

    std::stack<std::pair<TrieNode*, int>> st; // nodeptr, parentCharIndex
    st.push({mRoot, -1});

    for(int i = 0; i < word.size(); i++){
      char ch = word[i];
      int charIndex = ch - 'a';
      TrieNode* currNode = st.top().first;
      if( currNode->children[charIndex] == nullptr ){
        return;
      }
      st.push({currNode->children[charIndex], charIndex});
    }

    st.top().first->isEnd = false; // mark for deletion

    while( st.size() > 1 ){
      std::pair<TrieNode*, int> top = st.top();
      TrieNode* currNode = top.first;
      int charIndex = top.second;
      st.pop();
      if( isEmpty(currNode) ){
        TrieNode* parent = st.top().first;
        parent->children[charIndex] = nullptr;
        delete currNode;
      }
      else{
        while(not st.empty() ){
          st.pop();
        }
        break;
      }
    }

    mWordCount--;
  }

  bool search(const std::string& word){
    if( not checkValidity(word) or word.size() == 0){
      return false;
    }

    TrieNode* currNode = mRoot;

    for(int i = 0; i < word.size(); i++){
      char ch = word[i];
      int charIndex = ch - 'a';
      if( currNode->children[charIndex] == nullptr ){
        return false;
      }
      currNode = currNode->children[charIndex];
    }

    return currNode->isEnd;
  }

  void printWords(){
    std::string currentChars;
    std::cout << "Total Words : " << mWordCount << std::endl;
    _printWords(mRoot, currentChars);
  }

};


int main(){

  Trie t;

  t.insert("ball");
  t.insert("all");
  t.insert("allow");
  t.insert("baller");
  t.printWords();

  // std::cout << "search 'ball' : " << (t.search("ball") ? "true" : "false") << std::endl;
  // std::cout << "search 'baller' : " << (t.search("baller") ? "true" : "false") << std::endl;
  // std::cout << "search 'bal' : " << (t.search("bal") ? "true" : "false") << std::endl;


  DEBUG_MESSAGE("deleting \"baller\"")
  t.remove("baller");
  t.printWords();

  DEBUG_MESSAGE("deleting \"ball\"")
  t.remove("ball");
  t.printWords();

  DEBUG_MESSAGE("deleting \"all\"")
  t.remove("all");
  t.printWords();

  DEBUG_MESSAGE("deleting \"allow\"")
  t.remove("allow");
  t.printWords();

  return 0;
}