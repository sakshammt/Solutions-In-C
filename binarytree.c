#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createTree()
{
    int x;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if(x == -1)
        return NULL;

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    printf("Enter left child of %d\n", x);
    newnode->left = createTree();

    printf("Enter right child of %d\n", x);
    newnode->right = createTree();

    return newnode;
}

void inorder(struct node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node*root)
{
    if(root==NULL)
    return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node*root)
{
    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int countNodes(struct node* root)
{
    if(root == NULL)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

int countleaf(struct node*root)
{
    if(root==NULL)
    return(0);

    if(root->left==NULL && root->right==NULL)
    return(1);

    return(countleaf(root->left)+countleaf(root->right));
}

int max(int l, int r)
{
    if(l>r)
        return(l);
    else
        return(r);
}

int height(struct node*root)
{
    if(root==NULL)
    return(0);

    int lh=height(root->left);
    int rh=height(root->right);

    return(max(lh,rh)+1);
}

int main()
{
    struct node *root;

    printf("Create Binary Tree\n");
    root = createTree();

    printf("\nInorder Traversal:\n");
    inorder(root);

    printf("\nPreorder Traversal:\n");
    preorder(root);

    printf("\nPostorder Traversal:\n");
    postorder(root);

    printf("\nTotal Nodes: %d\n", countNodes(root));

    printf("Leaf Nodes: %d\n", countleaf(root));

    printf("Height of Tree: %d\n", height(root));

    return 0;
}