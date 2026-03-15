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

struct node* add(struct node* p, struct node* q)
{
    struct node* head = NULL;
    struct node* tail = NULL;
    int carry = 0;

    while(p != NULL || q != NULL || carry != 0)
    {
        int sum = carry;

        if(p != NULL)
        {
            sum += p->id;
            p = p->next;
        }

        if(q != NULL)
        {
            sum += q->id;
            q = q->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        struct node* n = createnode(digit);

        if(head == NULL)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }

    return (head);
}

int main()
{
    struct node*h1=NULL;
    struct node*h2=NULL;
    struct node*p=NULL;
    struct node*q=NULL;
    struct node*ans=NULL;

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

    p=reverse(h1);
    print(p);
    printf("\n");

    q=reverse(h2);
    print(q);
    printf("\n");

    ans=add(p,q);
    print(ans);
    printf("\n");
}