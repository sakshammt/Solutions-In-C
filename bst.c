#include<stdio.h>
#include<stdlib.h>
struct node
{
    int id;
    struct node*l, *r;
};

struct node*createnode(int id)
{
    struct node *n=NULL;
    n=malloc(sizeof(struct node));
    n->id=id;
    n->l=NULL;
    n->r=NULL;  
    return(n);  
}

struct node*addnode(struct node*root,int id)
{
    struct node*n=NULL,*t=root;
    if(root==NULL)
    return(createnode(id));
    while(t!=NULL)
    {
        n=t;
        if(id<t->id)
        t=t->l;
        else if(id>t->id)
        t=t->r;
        else
        {
        printf("Already Existing\n");
        return(root);
        }
    }
    //at the parent where to add
    if(id<n->id)
    n->l=createnode(id);
    else if(id>n->id)
    n->r=createnode(id);
    else
    printf("Already Existing\n");
    return(root);
}

struct node*find(struct node*root,int x)
{
    if(root==NULL)
    return(NULL);
    
    if(root->id==x)
    return(root);

    if(x>root->id)
    return(find(root->r,x));

    else if(x<root->id)
    return(find(root->l,x));
}

struct node*delete(struct node*root, int d)
{
         struct node*t=NULL;
    if(root==NULL)
    return(NULL);

    if(d<root->id)
        root->l=delete(root->l,d);
    
    else if(d>root->id)
        root->r=delete(root->r,d);

    else //found root to be deleted
    {
        if(root->l==NULL && root->r==NULL)
        {
            free(root);
            return(NULL);
        }

        else if(root->l==NULL || root->r==NULL)
        {
            if (root->l==NULL)
            t=root->r;
            else 
            t=root->l;
            free(root);
            return(t);
        }

        t=root->r;
        while(t->l!=NULL)
        t=t->l;

        //t is to replace root
        root->id=t->id;
        root->r=delete(root->r,t->id);
    }
    return(root);
}