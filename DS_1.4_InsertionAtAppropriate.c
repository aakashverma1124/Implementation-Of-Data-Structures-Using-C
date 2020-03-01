#include<stdio.h>
#include<string.h>

struct Node
{
    int info;
    struct Node* Next;
};

struct Node* getNode(int data)
{
    struct Node* p;
    p = (struct Node*)malloc(sizeof(struct Node));
    p->info = data;
    p->Next = NULL;
    return p;
};

void sortedLinkedList(struct Node** START,struct Node* p)
{
    struct Node* current;
     if (*START == NULL || (*START)-> info >= p->info)
    {
        p->Next = *START;
        *START = p;
    }
    else
    {
        current = *START;
        while (current->Next!=NULL &&
               current->Next->info < p->info)
        {
            current = current->Next;
        }
        p->Next = current->Next;
        current->Next = p;
    }
}

void Traversal(struct Node* a)
{

    while(a != NULL)
    {
        printf("%d ",a->info);
        a = a -> Next;
    }

}

int main()
{

    struct Node *START;
    START = NULL;
    struct Node* newNode = getNode(12);
    sortedLinkedList(&START,newNode);
    newNode = getNode(11);
    sortedLinkedList(&START,newNode);
    newNode = getNode(13);
    sortedLinkedList(&START,newNode);
    Traversal(START);
}


