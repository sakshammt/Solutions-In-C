#include<stdio.h>
#include<stdlib.h>
//doubly linked list
struct node
{
    int id;
    struct node* next;
};

struct node* createnode(int id)
{
    struct node* n = malloc(sizeof(struct node));
    n->id = id;
    n->next = n;      // circular self link
    return n;
}

struct node* insertfirst(struct node* h,int id)
{
    struct node* n = createnode(id);

    if(h==NULL)
        return n;

    struct node* t = h;

    while(t->next != h)
        t = t->next;

    n->next = h;
    t->next = n;

    return n;     // new head
}

struct node* insertlast(struct node* h,int id)
{
    struct node* n = createnode(id);

    if(h==NULL)
        return n;

    struct node* t = h;

    while(t->next != h)
        t = t->next;

    t->next = n;
    n->next = h;

    return h;
}

struct node* find(struct node* h,int x)
{
    if(h==NULL)
        return NULL;

    struct node* t = h;

    do
    {
        if(t->id == x)
            return t;

        t = t->next;
    }
    while(t != h);

    return NULL;
}

struct node* findprev(struct node* h,int x)
{
    if(h==NULL || h->id==x)
        return NULL;

    struct node* t = h;

    do
    {
        if(t->next->id == x)
            return t;

        t = t->next;
    }
    while(t != h);

    return NULL;
}

void insertafter(struct node* h,int a,int b)
{
    struct node* anode = find(h,a);

    if(anode == NULL)
    {
        printf("NOT FOUND\n");
        return;
    }

    struct node* bnode = createnode(b);

    bnode->next = anode->next;
    anode->next = bnode;
}

struct node* insertbefore(struct node* h,int a,int b)
{
    struct node* prev = findprev(h,a);

    if(prev == NULL)
    {
        if(h!=NULL && h->id==a)
            return insertfirst(h,b);

        printf("NOT FOUND\n");
        return h;
    }

    struct node* bnode = createnode(b);

    bnode->next = prev->next;
    prev->next = bnode;

    return h;
}

void print(struct node* h)
{
    if(h==NULL)
        return;

    struct node* t = h;

    do
    {
        printf("%d ",t->id);
        t = t->next;
    }
    while(t != h);
}

int main()
{
    struct node* head = NULL;

    head = insertfirst(head,3);
    head = insertfirst(head,2);
    head = insertfirst(head,1);

    head = insertlast(head,4);

    insertafter(head,2,5);

    head = insertbefore(head,3,9);

    print(head);
}