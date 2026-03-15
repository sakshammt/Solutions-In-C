struct node*reverse(struct node*h)
{
    struct node*l=NULL,*c=NULL,*r=NULL;
    l=h;
    c=h->next;
    r=c->next;
    h->next=NULL;

    while(1)
    {
        c->next=l;
        l=c;
        c=r;
        if(c==NULL)
        break;
        r=c->next;
    }
    return(l);
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