#include<stdio.h>

char stack[100];
int top=-1;

void push(char c){ stack[++top]=c; }
char pop(){ return stack[top--]; }
char peek(){ return stack[top]; }

int prec(char c)
{
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

int isoperand(char c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
        return 1;
    return 0;
}

int main()
{
    char infix[100],postfix[100];
    int i=0,k=0;

    printf("Enter infix: ");
    scanf("%s",infix);

    while(infix[i]!='\0')
    {
        char c=infix[i];

        if(isoperand(c))
            postfix[k++]=c;

        else if(c=='(')
            push(c);

        else if(c==')')
        {
            while(peek()!='(')
                postfix[k++]=pop();
            pop();
        }

        else
        {
            while(top!=-1 && prec(peek())>=prec(c))
                postfix[k++]=pop();
            push(c);
        }

        i++;
    }

    while(top!=-1)
        postfix[k++]=pop();

    postfix[k]='\0';

    printf("Postfix: %s",postfix);
}