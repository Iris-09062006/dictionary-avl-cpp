#include"library.h"
struct Word
{
    string english, mean;
};
struct Node{
    Word word;
    Node* pLeft;
    Node* pRight;
    Node(Word x){
        word = x;
        pLeft = NULL;
        pRight = NULL;
    }
};

