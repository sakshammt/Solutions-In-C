#include<stdio.h>

#define SIZE 100

struct stack
{
    int arr[SIZE];
    int top;
};

void init(struct stack *s)
{
    s->top = -1;
}

void push(struct stack *s, int x)
{
    if(s->top == SIZE-1)
    {
        printf("Stack Overflow\n");
        return;
    }

    s->top++;
    s->arr[s->top] = x;
}

int pop(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int x = s->arr[s->top];
    s->top--;
    return x;
}

int peek(struct stack *s)
{
    if(s->top == -1)
        return -1;

    return s->arr[s->top];
}

void print(struct stack *s)
{
    for(int i=s->top;i>=0;i--)
        printf("%d ",s->arr[i]);
}

int main()
{
    struct stack s;

    init(&s);

    push(&s,10);
    push(&s,20);
    push(&s,30);

    print(&s);

    printf("\nPopped: %d",pop(&s));
}