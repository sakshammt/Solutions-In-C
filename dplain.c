#include<stdlib.h>
#include<stdio.h>

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

int plaindrome(struct node*h)
{
    struct node*t=NULL;
    if(h==NULL)
    return(0);

    t=reverse(h);
    while(t!=NULL && h!=NULL)
    {
        if(t->id==h->id)
        {
            t=t->next;
            h=h->next;
        }
        else 
        return(0);
    }

    return(1);
}


int main()
{
    struct node*h1=NULL;
    struct node*h2=NULL;
    struct node*p=NULL;
    struct node*q=NULL;
    int l=0;
    int s=0;

    h1=insertfirst(h1,1);
    h1=insertfirst(h1,1);
    h1=insertfirst(h1,1);
    h1=insertfirst(h1,1);
    print(h1);
    printf("\n");

    h2=insertfirst(h2,8);
    h2=insertlast(h2,7);
    h2=insertlast(h2,6);
    h2=insertlast(h2,5);
    print(h2);
    printf("\n");

    l=loop(h1);
    if(l)
    printf("YES LOOP\n");
    else
    printf("NO LOOP\n");


    s=plaindrome(h1);
    if(s)
    printf("YES Palindrome\n");
    else
    printf ("NO Palindrome\n");

}