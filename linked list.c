#include <stdio.h>
#include <stdlib.h>

//declare
struct node
{
    int value;
    struct node *next;
};
typedef struct node NODE;




NODE *createList(int *arr,int len)
{
    int i;
    NODE *current,*first,*previous;

    for(i=0; i<len; i++)
    {
        current=(NODE*)malloc(sizeof(NODE));

        current->value=arr[i];
        if(i==0)
            first=current;
        else
            previous->next=current;

        current->next=NULL;
        previous=current;

    }
    return first;
}

void printList(NODE *first)
{
    NODE* node=first;
    if(first==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(node!=NULL)
        {

            printf("%5d",node->value);
            node=node->next;
        }
        printf("\n");
    }

}



void freeList(NODE *first)
{
    NODE *current,*tmp;
    current=first;
    while(current!=NULL)
    {
        tmp=current;
        current=current->next;
        free(tmp);
    }

}

NODE *searchNode(NODE *first,int item)
{
    NODE *node=first;
    while(node!=NULL)
    {
        if(node->value == item)
            return node;
        else
            node=node->next;
    }
    return NULL;
}

void insertNode(NODE *node,int item)
{
    NODE *newnode;
    newnode=malloc(sizeof(NODE));
    newnode->value  = item;
    newnode->next = node->next;
    node->next  = newnode;
}


int main()
{

    NODE *first,*noe;
    int arr[]= {14,27,32,46};
    first=createList(arr,4);

    printList(first);

    noe=searchNode(first,32);
    printf("%p",noe);

    return 0;
}
