#include<stdio.h>
#include<stdlib.h>

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
    n->next = NULL;
    n->prev = NULL;
    return n;
}

struct node* insertfirst(struct node* h,int id)
{
    struct node* n = createnode(id);

    if(h == NULL)
        return n;

    n->next = h;
    h->prev = n;

    return n;
}

struct node* insertlast(struct node* h,int id)
{
    struct node* n = createnode(id);

    if(h == NULL)
        return n;

    struct node* t = h;

    while(t->next != NULL)
        t = t->next;

    t->next = n;
    n->prev = t;

    return h;
}

struct node* find(struct node* h,int x)
{
    while(h != NULL)
    {
        if(h->id == x)
            return h;
        h = h->next;
    }
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
    bnode->prev = anode;

    if(anode->next != NULL)
        anode->next->prev = bnode;

    anode->next = bnode;
}

struct node* insertbefore(struct node* h,int a,int b)
{
    struct node* anode = find(h,a);

    if(anode == NULL)
    {
        printf("NOT FOUND\n");
        return h;
    }

    struct node* bnode = createnode(b);

    if(anode->prev == NULL)
    {
        bnode->next = anode;
        anode->prev = bnode;
        return bnode;
    }

    bnode->prev = anode->prev;
    bnode->next = anode;

    anode->prev->next = bnode;
    anode->prev = bnode;

    return h;
}

struct node* delfirst(struct node* h)
{
    if(h == NULL)
        return NULL;

    if(h->next == NULL)
    {
        free(h);
        return NULL;
    }

    struct node* t = h;

    h = h->next;
    h->prev = NULL;

    free(t);

    return h;
}

struct node* dellast(struct node* h)
{
    if(h == NULL)
        return NULL;

    if(h->next == NULL)
    {
        free(h);
        return NULL;
    }

    struct node* t = h;

    while(t->next != NULL)
        t = t->next;

    t->prev->next = NULL;

    free(t);

    return h;
}

struct node* delnode(struct node* h,int x)
{
    struct node* anode = find(h,x);

    if(anode == NULL)
    {
        printf("NOT FOUND\n");
        return h;
    }

    if(anode->prev == NULL)
        return delfirst(h);

    if(anode->next == NULL)
        return dellast(h);

    anode->prev->next = anode->next;
    anode->next->prev = anode->prev;

    free(anode);

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

    head = delnode(head,5);

    head = delfirst(head);

    head = dellast(head);

    print(head);
}