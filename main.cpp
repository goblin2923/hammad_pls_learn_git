#include <iostream>
#include "search.cpp"
using namespace std;

int main()
{

    Trie *t1 = new Trie();
    insertInTrie(t1);

    output_array();

    string word;
    string tempw;

    int wordSi=0, wordSj=0;
    int wordEi=0, wordEj=0;
    
    int i=0,j=0;
    int starti=0,startj=0;
    int k,temp=0;
    int temp2=0;



    horizontal_search(t1, word, i, j, starti, startj, wordSi, wordSj, wordEi, wordEj);

    reverse_horizontal_search(t1, word, i, j, starti, startj, wordSi, wordSj, wordEi, wordEj);

    vertical_search(t1, word, i, j, starti, startj, wordSi, wordSj, wordEi, wordEj);

    reverse_vertical_search(t1, word, i, j, starti, startj, wordSi, wordSj, wordEi, wordEj);

    diagonal_search(t1, word, i, j, starti, startj, wordSi, wordSj, wordEi, wordEj, k, temp, tempw);


    reverse_diagonal_search(t1, word, i, j, starti, startj, wordSi, wordSj, wordEi, wordEj, k, temp, temp2, tempw);

    other_diagonal_search(t1, word, i, j, starti, startj, wordSi, wordSj, wordEi, wordEj, k, temp, temp2,tempw);

    reverse_other_diagonal_search(t1, word, i, j, starti, startj, wordSi, wordSj, wordEi, wordEj, k, temp, temp2,tempw);

    file.close();
    return 0;
}
