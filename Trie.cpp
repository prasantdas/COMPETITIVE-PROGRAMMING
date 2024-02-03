#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag;
    bool containskey(char x){
        return links[x-'a']!=NULL;
    }
    void put(char y,Node* node){
        links[y-'a']=node;
    }
    Node* ref(char z){
        return links[z-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->ref(word[i]);
        }
        node->setEnd();
    }
    bool search(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node=node->ref(word[i]);
        }
        return node->isEnd()==true;
    }
    bool startswith(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containskey(prefix[i])){
                return false;
            }
            node=node->ref(prefix[i]);
        }
        return true;
    }
};

int main(){
   
    return 0;
}
