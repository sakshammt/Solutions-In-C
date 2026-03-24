int power(int x)
{
    int p=1;
    while(x>0)
    {
        p=p*2;
        x-=1;
    }
    return p; 
}

int b2d(struct node*h)
{
    struct node*t=h;
    int count=0,sum=0;

    while(h!=NULL)
    {
        count+=1;
        h=h->next;
    }
    count-=1;
    printf("count is %d\n",count);
    while(t!=NULL)
    {
        if(t->id==1)
        {
        sum=sum+power(count);
        printf("%d\n",sum);
        count-=1;
        t=t->next;
        }

        else
        {
        t=t->next;
        count-=1;
        }

    }
    return(sum);
}