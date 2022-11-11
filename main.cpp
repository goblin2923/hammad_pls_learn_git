#include <iostream>
#include "search.cpp"
using namespace std;

int main()
{

    Trie *t1 = new Trie();
    insertInTrie(t1);

    output_array();


    file.open("output_file.txt",ios::out);

    horizontal_search(t1);

    reverse_horizontal_search(t1);

    vertical_search(t1);

    reverse_vertical_search(t1);

    diagonal_search(t1);

    reverse_diagonal_search(t1);

    other_diagonal_search(t1);

    reverse_other_diagonal_search(t1);

    file.close();
    return 0;
}
