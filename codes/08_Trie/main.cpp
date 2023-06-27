#include<vector>
#include<string>
using namespace std;
class trie
{
    class node
    {
    public:
        node **children;
        bool isEndOfWord;
        bool lastPrefix;
        int nchildren;
        node(int size)
        {
            this->isEndOfWord = false;
            this->lastPrefix = false;
            nchildren=0;
            this->children = new node *[size];
            for (int i = 0; i < size; i++)
                children[i] = nullptr;
        }
        ~node()
        {
            delete[] children;
        }
    };
    node *root;
    int size;
    char ichar;
    int words;

public:
    trie(int psize, char pichar)
    {
        this->size = psize;
        this->root = new node(this->size);
        this->ichar = pichar;
        this->words = 0;
    }
    ~trie()
    {
        delete this->root;
    }
    void insert(const std::string &key)
    {
        node *curr = this->root;
        for (char ch : key)
        {
            int index = ch - this->ichar;
            if (curr->children[index] == nullptr)
            {
                curr->children[index] = new node(this->size);
                curr->nchildren++;
            }else
            {
                curr->lastPrefix=true;
            }
            if(curr->nchildren>1)curr->lastPrefix=false;
         

            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    string search(const std::string &key)
    {
        string word = "";
        node *curr = this->root;
        for (char ch : key)
        {
            int index = ch - this->ichar;
            if (curr->children[index] != nullptr  && curr->lastPrefix && !curr->isEndOfWord)
            {
                word=word+ch;
            }
            else break;
            curr = curr->children[index];
        }
        return word;
    }
    void build(std::vector<std::string> bank)
    {
        for (auto &&i : bank)
        {
            this->insert(i);
            this->words++;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      const int ALPHABET_SIZE = 26;
      trie objtrie = trie(ALPHABET_SIZE, 'a');
      objtrie.build(strs);
      if (strs.size()==1){
          return strs[0];
      }
      return objtrie.search(strs[0]);
    }
};
