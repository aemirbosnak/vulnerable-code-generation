//FormAI DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return(node);
}

void insert(struct node** root, int data)
{
    if(*root==NULL)
    {
        *root=newNode(data);
        return;
    }
    if(data<((*root)->data))
    {
        insert(&((*root)->left),data);
    }
    else if(data>((*root)->data))
    {
        insert(&((*root)->right),data);
    }
}

void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    struct node* root=NULL;
    int n, data;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        insert(&root,data);
    }
    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);
    return 0;
}