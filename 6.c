#include<stdio.h>

struct stack
{
    char arr[100];
    int top;
};

int anyof6(char c)
{
    if(c=="[" || c=="]" || c=="{" || c=="}" || c=="(" || c==")")
    return(1);
    return(0);
}


int ispair(char a, char b)
{
    if (a=="(" && b==")" || a=="{" && b=="}" || a=="[" && b=="]")
    return(1);
    return(0);
}


int main()
{
    char arr[]="[{a+b}]";
    int i=0; struct stack s;
    init(&s);
    while(arr[i])
    {
            if(!anyof6(arr[i]))
            {
                i+=1;
                continue;
            }

        if(arr[i]=="[" || arr[i]=="]" || arr[i]=="{" || arr[i]=="}" || arr[i]=="(" || arr[i]==")")
        {
            push(&s,arr[i]);
            i+=1;
            continue;
        }

            if(isempty(&s) || !ispair(pop(&s),arr[i]))
            {
                printf("Imbalanced Expression\n");
                return(0);
            }
//added in git
            i+=1;
    }

    if(!isempty(&s))
    {
        printf("Imbalanced Expression\n");
        return(0);
    }

        printf("Balanced Expression\n");
}