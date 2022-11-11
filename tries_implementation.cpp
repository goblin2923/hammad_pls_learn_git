#include <iostream>
#include <fstream>
#include <string>
#define size 26
using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode *children[size];
        bool isTerminal;    //end of word

        //constructor
        TrieNode(char ch)
        {
            data = ch;

            for (int i = 0; i < size; i++)
            {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie
{
    public:
        TrieNode *root;
        Trie()
        {
            root = new TrieNode('\0');
        }

    void insertS(TrieNode *root, string input)
    {
        //base case
        if(input.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        //We assume that the words will be lowercase//
        int index = input[0] - 'a';

        //To traverse through the trie and insert nodes after the root//
        TrieNode *childPtr = NULL;

        //If the character is present//
        if(root->children[index] != NULL)
        {
            childPtr = root->children[index];
        }

        //else if the character isn't present//
        else
        {
            childPtr = new TrieNode (input[0]);
            root->children[index] = childPtr;
        }
        
        /*
        Recursively calling the function.
        
        The function sends child node as parameter 
        and substring of input starting from first character
        */
        insertS(childPtr,input.substr(1));

    }

    void insertWord(string input)
    {
        insertS(root,input);
        // cout<<"\nWord inserted\n";
    }

    bool searchUTill(TrieNode *root, string key)
    {
        //Base case//
        if (key.length()==0)
        {
            return root->isTerminal;
        }

            int index = key[0] - 'a';

            TrieNode* child;

            //If the first character is present//
            if(root->children[index] != NULL)
            {
                child = root->children[index];
            }

            /*If the first character is absent, 
              key isn't avalable in trie*/
            else
            {
                return false;
            }
            
            return searchUTill(child, key.substr(1));
    }
    
    bool searchWord(string key)
    {
        if(searchUTill(root, key))
        {
            // cout<<"\nFOUND!";
            return 1;
        }
        else
        {
            // cout<<"\nNOT HERE!";
            return 0;
        }
    }
};
