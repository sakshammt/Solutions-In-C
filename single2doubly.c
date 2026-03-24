#include<stdio.h>
#include<stdlib.h>


struct node
{
    int id;
    struct node*next;
};

struct dnode
{
    int id;
    struct dnode *next;
    struct dnode *prev;
};

struct dnode* creatednode(int id)
{
    struct dnode* n = malloc(sizeof(struct dnode));
    n->id = id;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

struct dnode* insertdlast(struct dnode* h,int id)
{
    struct dnode* n = creatednode(id);

    if(h == NULL)
        return n;

    struct dnode* t = h;

    while(t->next != NULL)
        t = t->next;

    t->next = n;
    n->prev = t;

    return h;
}

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

struct dnode*c2d(struct node*h)
{
    struct dnode*n=NULL;
    while(h!=NULL)
    {
        n=insertdlast(n,h->id);
        h=h->next;
    }
    return(n);
}

void print(struct node* h)
{
    while(h != NULL)
    {
        printf("%d ",h->id);
        h = h->next;
    }
}

void dprint(struct dnode* h)
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
    struct dnode*doubly=NULL;

    head = insertfirst(head,3);
    head = insertfirst(head,2);
    head = insertfirst(head,1);
    head = insertlast(head,4);
    printf("SINGLY:");
    print(head);
    doubly=c2d(head);
    printf("DOUBLY:");
    dprint(doubly);
}