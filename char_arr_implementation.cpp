#include <iostream>
#include "tries_implementation.cpp"

#define row 7
#define column 12

using namespace std;


int main()
{

    Trie *t1 = new Trie();

    //should not be found jbtw
    // string x = "help";

    //t1->insertWord(x);
    
    fstream test;
    test.open("dictionary_uwu.txt",ios::in);

     //checking whether the file is open
    if (test.is_open())
    {
      string uwu;

      while(getline(test, uwu))
      {
        t1->insertWord(uwu);
      }
        cout<<"\nDictionary trie created succassfully!\n";
    }

    char arr[row][column] = {
                             {'d','o','g','x','b','x','x','x','n','o','o','n'}
                            ,{'r','h','e','l','l','o','t','h','e','r','e','x'}
                            ,{'o','k','c','i','u','q','b','r','o','w','n','m'}
                            ,{'w','x','w','g','e','x','l','x','h','j','i','j'}
                            ,{'o','o','z','o','k','v','u','x','d','r','o','w'}
                            ,{'r','l','x','d','r','x','e','x','t','x','j','a'}
                            ,{'d','r','o','w','b','l','o','n','k','g','o','d'}
                            };

    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    string word;

    int wordSi=0, wordSj=0;
    int wordEi=0, wordEj=0;
    
    int i=0,j=0;
    int starti=0,startj=0;

    bool s=1;
    
    for (;i<row;)
    {
        i=starti;
        j=startj;
        wordSi=i;
        wordSj=j;

        for(;j<column;j++)
        {
            word+=arr[i][j];
            wordEj=j;
            wordEi=i; 
            if (t1->searchWord(word) && word.length()>=3)
            {
                cout<<"\nWord : "<<word<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")";
            }
        }

        word.clear();
        
        startj++;

        if(startj==column)
        {
            starti++;
            startj=0;
        }

        if (starti==row)
            break;

    }
    cout<<"\nReverse horizontal";
    i=wordEi=starti=0;
    wordSj=j=startj=column-1;
    for (;i<row;)
    {
        i=starti;
        j=startj;
        wordSi=i;
        wordSj=j;

        for(;j>=0;j--)
        {
            word+=arr[i][j];
            wordEj=j;
            wordEi=i; 
            if (t1->searchWord(word) && word.length()>=3)
            {
                cout<<"\nWord : "<<word<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")";
            }
        }

        word.clear();
        
        startj--;

        if(startj==0)
        {
            starti++;
            startj=column-1;
        }

        if (starti==row)
            break;

    }

    cout<<"\nVertical";

    
    return 0;
}

