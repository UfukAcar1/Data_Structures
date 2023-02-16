#ifndef Chains_h
#define Chains_h
#include<stdlib.h>
//Node struct

struct Node
{ 
    int data;
    struct Node *next;
};

//Insert elements in sorted way
void SortedInsert(struct Node **H,int key)
{    
    struct Node *temp, *q=NULL, *p=*H;

    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=key;
    temp->next=NULL;
    if(*H==NULL)
        *H=temp;
    else
    {
        while(p && p->data<key)
        {
            q=p;
            p=p->next;
        }
        //Insert data at head noe
        if(p==*H)
        {
            temp->next=*H;
            *H=temp;
        }
        else
        //Insert data at between two nodes
        {
            temp->next=q->next;
            q->next=temp;
        }
    }
}

//Search Method
struct Node *Search(struct Node *p,int key)
    {
    while(p!=NULL)
    {
        if(key==p->data)
    {
        return p;
        }
        p=p->next;
    }
    return NULL;
}
    #endif /* Chains_h */