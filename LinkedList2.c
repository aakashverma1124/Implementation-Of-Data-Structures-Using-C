#include<stdio.h>

struct node
{
    int info;
    struct node* next;
};

struct node* getNode()
{
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    return p;
};
void InsertionBeg(struct node** START,int key)
{
    struct node* p;
    p = getNode();
    p->info = key;
    p->next = *START;
    *START = p;
}
void InsertionAfter(struct node**p ,int key)
{
    struct node* q;
    q = getNode();
    q->info = key;
    q->next = (*p)->next;
    (*p)->next = q;
}

void Traversal(struct node* a)
{
    while(a != NULL)
    {
        printf("%d  ",a->info);
        a = a->next;
    }
}

int main()
{
    struct node* START;
    //struct node* a;
    START = NULL;
    //a = START;
    InsertionBeg(&START,100);
    InsertionAfter(&START,450);
    InsertionAfter(&(START->next),440);
    InsertionAfter(&(START->next->next),670);
    Traversal(START);
}
