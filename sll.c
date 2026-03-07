#include<stdio.h>
#include<stdlib.h>
//singly linked list
struct node
{
    int id;
    struct node* next;
};

struct node* createnode(int id)
{
    struct node* n = malloc(sizeof(struct node));
    n->id = id;
    n->next = NULL;
    return n;
}

struct node* insertfirst(struct node* h, int id)
{
    struct node* n = createnode(id);
    n->next = h;
    return n;
}

struct node* insertlast(struct node* h, int id)
{
    struct node* n = createnode(id);

    if(h == NULL)
        return n;

    struct node* t = h;

    while(t->next != NULL)
        t = t->next;

    t->next = n;
    return h;
}

struct node* find(struct node* h, int x)
{
    while(h != NULL)
    {
        if(h->id == x)
            return h;

        h = h->next;
    }

    return NULL;
}

struct node* findprev(struct node* h, int x)
{
    if(h == NULL || h->id == x)
        return NULL;

    while(h->next != NULL)
    {
        if(h->next->id == x)
            return h;

        h = h->next;
    }

    return NULL;
}

void insertafter(struct node* h, int a, int b)
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

struct node* insertbefore(struct node* h, int a, int b)
{
    struct node* prev = findprev(h,a);

    if(prev == NULL)
    {
        if(h != NULL && h->id == a)
        {
            struct node* bnode = createnode(b);
            bnode->next = h;
            return bnode;
        }

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
    while(h != NULL)
    {
        printf("%d ",h->id);
        h = h->next;
    }
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