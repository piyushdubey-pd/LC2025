#include <bits/stdc++.h>
using namespace std;

class Trie{
    public:
        unordered_map<char, Trie*> children;
        bool isEnd;

        // Constructor initializes the isEnd flag to false
        Trie() : isEnd(false) {}

        ~Trie() {
            for (auto &pair : children)
            {
                delete pair.second;
            }
        }

        void insert(string s){
            Trie* node = this;

            for(char ch : s){
                if(node->children.find(ch)==node->children.end()){
                    node->children[ch] = new Trie();    
                }
                node = node->children[ch];
            }  
            node->isEnd = true; // Mark the end of the string
        }

        bool search(string s){
            Trie* node = this;

            for(char ch : s){
                if(node->children.find(ch)!=node->children.end()){
                    node = node->children[ch];
                }
                else{
                    return false;
                }
            }

            return node->isEnd; // Return true only if this is a complete word
        }
        // display trie as tree structure
        void display(string prefix = ""){
            if(isEnd){
                cout << prefix << " " << endl;

            }
            for(auto it : children){
                it.second->display(prefix + it.first);
            }
        }
};

int main(){
    Trie* root = new Trie();

    root->insert("hello");
    // root->insert("hel");
    root->insert("hell");
    root->insert("heaven");
    root->insert("heavenly");
    root->insert("hi");
    root->insert("hike");
    root->insert("hiking");

    cout << "Trie contents: ";
    root->display();

    cout << root->search("hello") << endl; // Should return 1 (true)
    cout << root->search("hel") << endl; // Should return 1 (true)
    cout << root->search("heaven") << endl; // Should return 1 (true)
    cout << root->search("heavenly") << endl; // Should return 1 (true)
    cout << root->search("hi") << endl; // Should return 1 (true)
    cout << root->search("hike") << endl; // Should return 1 (true)
    cout << root->search("hiking") << endl; // Should return 1 (true)
    cout << root->search("hello world") << endl; // Should return 0 (false)
    cout << root->search("helloo") << endl; // Should return 0 (false)
    cout << root->search("heavenly world") << endl; // Should return 0 (false)


    cout << endl;
    return 0;
}