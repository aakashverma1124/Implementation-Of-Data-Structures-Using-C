#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkedList.h"
struct Node
{
    int info;
    struct Node* Next;
};
struct Node* concatenate(struct Node* a,struct Node* b)
{
    struct Node* p;
    p = a;
    if(a == NULL && b == NULL)
    {
        return NULL;
    }
    else if(a == NULL)
        {
            return b;
        }
    else if(b == NULL)
            return a;
    else
    {
            while(p->Next != NULL)
            {
                p = p->Next;
            }
            p->Next = b;
    }
    return a;
}

int main()
{
    struct Node *a;
    struct Node *b;
    struct Node *START;
    struct Node *START2;
    START = NULL;
    START2 = NULL;
    InsertionBeg(&START,100);
    InsertionEnd(&START,200);
    InsertionEnd(&START,300);
    InsertionEnd(&START,500);
    InsertionBeg(&START2,320);
    InsertionEnd(&START2,420);
    InsertionEnd(&START2,320);
    InsertionEnd(&START2,220);
    a = START;
    b = START2;
    Traversal(a);
    printf("\n\n");
    Traversal(b);
    printf("\n\n");
    struct Node* final = concatenate(a,b);
    Traversal(final);
}

