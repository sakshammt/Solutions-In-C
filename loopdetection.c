#include<stdio.h>
#include<stdlib.h>
struct node
{
    int id;
    struct node* next;
};

struct node* createnode(int id)
{
    struct node* n = malloc(sizeof(struct node));

    if(n == NULL)
    {
        printf("Memory allocation failed\n");
        return(NULL);
    }

    n->id = id;
    n->next = NULL;
    return (n);
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

struct node* reverse(struct node* h)
{
    struct node *prev = NULL;
    struct node *curr = h;
    struct node *next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void print(struct node* h)
{
    while(h != NULL)
    {
        printf("%d ",h->id);
        h = h->next;
    }
}

 int loop(struct node*h)
{
    struct node*slow=h;
    struct node*fast=h;

    if(h==NULL)
    return(0);
    while(fast != NULL && fast->next != NULL)    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
        return(1);
    }
    return(0);
}

int main()
{
    struct node*h1=NULL;
    struct node*h2=NULL;
    struct node*p=NULL;
    struct node*q=NULL;

    h1=insertfirst(h1,9);
    h1=insertfirst(h1,7);
    h1=insertfirst(h1,6);
    h1=insertfirst(h1,8);
    print(h1);
    printf("\n");

    h2=insertfirst(h2,3);
    h2=insertlast(h2,5);
    h2=insertlast(h2,7);
    h2=insertlast(h2,8);
    print(h2);
    printf("\n");

}