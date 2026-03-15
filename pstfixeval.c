#include<stdio.h>

int stack[100];
int top=-1;

void push(int x){ stack[++top]=x; }
int pop(){ return stack[top--]; }

int isdigit(char c)
{
    if(c>='0'&&c<='9')
        return 1;
    return 0;
}

int main()
{
    char postfix[100];
    int i=0;

    printf("Enter postfix: ");
    scanf("%s",postfix);

    while(postfix[i]!='\0')
    {
        char c=postfix[i];

        if(isdigit(c))
            push(c-'0');

        else
        {
            int b=pop();
            int a=pop();

            if(c=='+') push(a+b);
            if(c=='-') push(a-b);
            if(c=='*') push(a*b);
            if(c=='/') push(a/b);
        }

        i++;
    }

    printf("Result: %d",pop());
}