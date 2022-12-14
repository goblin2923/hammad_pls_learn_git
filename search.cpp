#include <iostream>
#include "tries_implementation.cpp"
#define row 7
#define column 12
#define minLen 3

using namespace std;

ofstream file;

char arr[row][column] = {
                          {'d','o','g','x','b','x','x','x','n','o','o','n'}
                         ,{'r','h','e','l','l','o','t','h','e','r','e','x'}
                         ,{'o','k','c','i','u','q','b','r','o','w','n','m'}
                         ,{'w','x','w','g','e','x','l','x','h','j','i','j'}
                         ,{'o','o','z','o','k','v','u','x','d','r','o','w'}
                         ,{'r','l','x','d','r','x','e','x','t','x','j','a'}
                         ,{'d','r','o','w','b','l','o','n','k','g','o','d'}
                        };

void insertInTrie(Trie *t1)
{
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
}



void output_array()
{
       cout<<"\n\tPUZZLE\n\n";

    for (int i = 0; i < row; i++)
    {
       // cout<<i<<" ";

        for (int j = 0; j < column; j++)
        {
            cout<<arr[i][j]<<" ";
        }

        cout<<"\n";
    }

}

void horizontal_search(Trie *t1)
{
    string word;

    int wordSi=0, wordSj=0;
    int wordEi=0, wordEj=0;
    
    int i=0,j=0;
    int starti=0,startj=0;
    

    cout<<"\n\nHORIZONTAL\n";
    file<<"Horizontal\n";
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
            if (t1->searchWord(word) && word.length()>=minLen)
            {
                file<<word<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")\n";
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
}

void reverse_horizontal_search(Trie *t1)
{
    string word;

    int wordSi=0, wordSj=0;
    int wordEi=0, wordEj=0;
    
    int i=0,j=0;
    int starti=0,startj=0;

    cout<<"\n\nREVERSE HORIZONTAL\n";
    file<<"Reverse Horizontal\n";
    i=wordEi=starti=0;
    j=wordSj=startj=column-1;

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
            if (t1->searchWord(word) && word.length()>=minLen)
            {
                file<<word<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")\n";
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
}

void vertical_search(Trie *t1)
{
    string word;

    int wordSi=0, wordSj=0;
    int wordEi=0, wordEj=0;
    
    int i=0,j=0;
    int starti=0,startj=0;

    cout<<"\n\nVERTICAL\n";
    file<<"Vertical\n";

    i=wordEi=starti=0;
    j=wordSj=startj=0;
    
    for (;j<column;)
    {
        i=starti;
        j=startj;
        wordSi=i;
        wordSj=j;
        for(;i<row;i++)
        {
            word+=arr[i][j];
            wordEj=j;
            wordEi=i; 
            if (t1->searchWord(word) && word.length()>=minLen)
            {
                file<<word<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")\n";
            }
        }
        word.clear();
        starti++;
        if(starti==row)
        {
            startj++;
            starti=0;
        }
        if (startj==column)
            break;
    }
}

void reverse_vertical_search(Trie *t1)
{

    string word;

    int wordSi=0, wordSj=0;
    int wordEi=0, wordEj=0;
    
    int i=0,j=0;
    int starti=0,startj=0;

    cout<<"\n\nVERTICALLY BACKWARDS\n";
    file<<"Vertically Backwards\n";
    i=wordEi=starti=row-1;
    j=wordSj=startj=0;

    for (;j<column;)
    {
        i=starti;
        j=startj;
        wordSi=i;
        wordSj=j;
        for(;i!=0;i--)
        {
            word+=arr[i][j];
            wordEj=j;
            wordEi=i; 
            if (t1->searchWord(word) && word.length()>=minLen)
            {
                file<<word<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")\n";
            }
        }
        word.clear();
        starti--;
        if(starti==0)
        {
            startj++;
            starti=row-1;
        }
        if (startj==column)
            break;
    }
}

void diagonal_search(Trie *t1)
{
    string word;
    string tempw;

    int wordSi=0, wordSj=0;
    int wordEi=0, wordEj=0;
    
    int i=0,j=0;
    int k,temp=0, temp2=0;
    //Diagonal Search
	cout<<"\n\nDIAGONAL\n";
    file<<"Diagonal\n";
    
    for (;;)
    {
        if(i!=column)
        {
            k=i++;
        }
        else if(temp!=row)
        {
            temp++;
            k=i-1;
        }
        else break;
        j=temp;

        wordSi=j;
        wordSj=k;
        // cout<<"\n";
        while(k>=0 && j<row)
        {
            // cout<<arr[j][k];
            word+=arr[j][k];
            wordEj=k;
            wordEi=j; 
            if (t1->searchWord(word) && word.length()>=minLen)
            {
                file<<word<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")\n";
            }
            j++;k--;
        }
        tempw=word;
        for(int s;tempw.length()>minLen;)
        {
            ++wordSi;++wordSj;
            tempw=tempw.substr(1);
            if (t1->searchWord(tempw))
            {
                file<<tempw<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")\n";
            }
        }
        word.clear();        
    }
}

void reverse_diagonal_search(Trie *t1)
{

    string word;
    string tempw;

    int wordSi=0, wordSj=0;
    int wordEi=0, wordEj=0;
    
    int i=0,j=0;
    int k,temp=0, temp2=0;
    //Reverse Diagonal Search
    cout<<"\n\nREVERSE DIAGONAL\n";
    file<<"Reverse Diagonal\n";

    for (;;)
    {
        if(i!=row)
        {
            k=i++;
            j=0;
        }
        else if(temp!=column)
        {
            temp++;
            k=row-1;
            j=temp2++;
        }
        else break;

        wordSi=j;
        wordSj=k;
        // cout<<"\n";
        while(k>=0 && j<column)
        {
            // cout<<arr[k][j];
            word+=arr[k][j];
            wordEj=j;
            wordEi=k; 
            if (t1->searchWord(word) && word.length()>=minLen)
            {
                file<<word<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")\n";
            }
            j++;k--;
        }
        tempw=word;
        for(int s;tempw.length()>minLen;)
        {
            ++wordSi;++wordSj;
            tempw=tempw.substr(1);

            if (t1->searchWord(tempw))
            {
                file<<tempw<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")\n";
            }
        }
        word.clear();        
    }
}

void other_diagonal_search(Trie *t1)
{
	cout<<"\n\nOTHER DIAGONAL\n";
    file<<"Other Diagonal\n";

    string word;
    string tempw;

    int wordSi=0, wordSj=0;
    int wordEi=0, wordEj=0;
    
    int i=0,j=0;
    int k,temp=0, temp2=0;
    i=wordEi=column-1;
    j=wordSj=0;

    wordSi=i;
    wordSj=j;
    k=temp=0;
    for (;;)
    {
        if(i!=0)
        {
            k=i--;
        }
        else if(temp!=row)
        {
            temp++;
            k=0;
        }
        else break;
        j=temp;

        wordSi=j;
        wordSj=k;
        while(k<column && j<row)
        {
            // cout<<arr[j][k];
            word+=arr[j][k];
            wordEj=k;
            wordEi=j; 
            if (t1->searchWord(word) && word.length()>=3)
            {
                cout<<"\nWord : "<<word<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")";
            }
            j++;k++;
        }
        // cout<<"\n";
        string tempw=word;
        for(int s;tempw.length()>minLen;)
        {
            ++wordSi;++wordSj;
            tempw=tempw.substr(1);
            if (t1->searchWord(tempw))
            {
                cout<<"\nWord : "<<tempw<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")";
            }
        }
        word.clear();        
    }
}

void reverse_other_diagonal_search(Trie *t1)
{
    string word;
    string tempw;

    int wordSi=0, wordSj=0;
    int wordEi=0, wordEj=0;
    
    int i=0,j=0;
    int starti=0,startj=0;
    int k=0,temp=0, temp2=0;

//Reverse Other Diagonal Search
    cout<<"\n\nREVERSE OTHER DIAGONAL\n";
    file<<"Reverse Other Diagonal\n";

    i=wordEi=wordSi=column-1;
    j=wordSj=startj=0;


    for (;;)
    {
        if(temp!=row)
        {
            k=column-1;
            j=temp++;
        }
        else if(temp2!=column)
        {
            temp2++;
            k=--i;
            j=row-1;
        }
        else break;

        wordSi=j;
        wordSj=k;
        while(j>=0&&k>=0)
        {
            // cout<<arr[j][k];
            word+=arr[j][k];
            wordEj=k;
            wordEi=j; 
            if (t1->searchWord(word) && word.length()>=minLen)
            {
                file<<word<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")\n";
            }
            j--;k--;
        }
        // cout<<"\n";
        tempw=word;
        for(int s;tempw.length()>minLen;)
        {
            ++wordSi;++wordSj;
            tempw=tempw.substr(1);

            if (t1->searchWord(tempw))
            {
                file<<tempw<< " ("<<wordSi<<","<<wordSj<<") ("<<wordEi<<","<<wordEj<<")\n";
            }
        }
        word.clear();        
    }
}
