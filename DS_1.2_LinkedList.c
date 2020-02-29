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
void InsertionAfter(struct node **START ,int val,int key)
{
    struct node *q,*p;
    q = *START;
    p = getNode();
    while(q!=NULL&&q->info != val)
    {
        q = q->next;
    }
    p->info = key;
    p->next=(q->next);
    q->next=p;
}
void InsertionEnd(struct node **START,int key)
{
    struct node *q,*p;
    p = *START;
    q = getNode();
    q->info = key;
    q->next = NULL;

    if(*START==NULL)
       *START=q;
    else
    {
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next=q;
    }
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
    START = NULL;
    InsertionBeg(&START,650);
    InsertionEnd(&START,670);
    InsertionEnd(&START,450);
    InsertionEnd(&START,240);
    InsertionEnd(&START,120);
    InsertionAfter(&START,240,430);
    Traversal(START);
}
