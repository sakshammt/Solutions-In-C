#include<stdio.h>
//paranthesis balancing
char stack[100];
int top=-1;

void push(char c){ stack[++top]=c; }
char pop(){ return stack[top--]; }

int match(char a,char b)
{
    if(a=='('&&b==')') return 1;
    if(a=='{'&&b=='}') return 1;
    if(a=='['&&b==']') return 1;
    return 0;
}

int main()
{
       char exp[100];
    int i=0;

    printf("Enter expression: ");
    scanf("%s",exp);

    while(exp[i]!='\0')
    {
        char c=exp[i];

        if(c=='('||c=='{'||c=='[')
            push(c);

        else if(c==')'||c=='}'||c==']')
        {
            if(top==-1 || !match(pop(),c))
            {
                printf("Not Balanced");
                return 0;
            }
        }

        i++;
    }

    if(top==-1) printf("Balanced");
    else printf("Not Balanced");
}