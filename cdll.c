#include<stdio.h>
#include<stdlib.h>
//circular doubly ll
struct node
{
    int id;
    struct node *next;
    struct node *prev;
};

struct node* createnode(int id)
{
    struct node* n = malloc(sizeof(struct node));
    n->id = id;
    n->next = n;
    n->prev = n;
    return n;
}

struct node* insertfirst(struct node* h, int id)
{
    struct node* n = createnode(id);

    if(h == NULL)
        return n;

    struct node* last = h->prev;

    n->next = h;
    n->prev = last;

    last->next = n;
    h->prev = n;

    return n;
}

struct node* insertlast(struct node* h, int id)
{
    struct node* n = createnode(id);

    if(h == NULL)
        return n;

    struct node* last = h->prev;

    n->next = h;
    n->prev = last;

    last->next = n;
    h->prev = n;

    return h;
}

struct node* find(struct node* h, int x)
{
    if(h == NULL)
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

void print(struct node* h)
{
    if(h == NULL)
        return;

    struct node* t = h;

    do
    {
        printf("%d ", t->id);
        t = t->next;
    }
    while(t != h);
}

int main()
{
    struct node* head = NULL;

    head = insertfirst(head,1);
    head = insertlast(head,2);
    head = insertlast(head,3);
    head = insertfirst(head,0);

    print(head);
}