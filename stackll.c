#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* push(struct node* top,int x)
{
    struct node* n = malloc(sizeof(struct node));

    n->data = x;
    n->next = top;

    return n;
}

struct node* pop(struct node* top)
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return NULL;
    }

    struct node* t = top;

    top = top->next;
    free(t);

    return top;
}

void print(struct node* top)
{
    while(top != NULL)
    {
        printf("%d ",top->data);
        top = top->next;
    }
}

int main()
{
    struct node* top = NULL;

    top = push(top,10);
    top = push(top,20);
    top = push(top,30);

    print(top);

    top = pop(top);

    printf("\nAfter pop:\n");
    print(top);
}