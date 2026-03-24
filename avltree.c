#include<stdio.h>
#include<stdlib.h>
struct node
{
    int id;
    struct node *l,*r;
    int h;
};

int max(int a,int b)
{
    if(a>b)
    return(a);

    return(b);
}

struct node *leftrotate(struct node*root)
{
    //assumption:right child to root exists
    struct node*nr=root->r;
    root->r=nr->l;
    nr->l=root;

    root->h=(max(height(root->l),height(root->r))+1);
    nr->h=(max(height(root->l),height(root->r))+1);
    return(nr);
}

struct node *rightrotate(struct node*root)
{
    //assumption:left child to root exists
    struct node*nr=root->l;
    root->l=nr->r;
    nr->r=root;

    root->h=(max(height(root->l),height(root->r))+1);
    nr->h=(max(height(root->l),height(root->r))+1);
    return(nr);
}

struct node*RLrotate(struct node*root)
{
    //RR on right child, followed by LR on root
    //assumption:Right child exists and left child to right child also exists
    //solution for RSLH

    root->r=rightrotate(root->r);
    return(leftrotate(root));
}

struct node*LRrotate(struct node*root)
{
    //LL on left child, followed by RR on root
    //assumption:Right child exists and left child to right child also exists
    //solution for LSRH

    root->l=leftrotate(root->l);
    return(rightrotate(root));
}

struct node*createnode(int id)
{
    struct node*n=NULL; 
    n=malloc(sizeof(struct node));
    n->id=id;
    n->l=NULL;
    n->r=NULL;
    n->h=0;
    retrurn(n);
}

struct node*addnode(struct node*root,int id)
{
    if(root==NULL)
    return(createnode(id));

    if(id<root->id)
    root->l=addnode(root->l,id);

    if(id>root->id);
    
}