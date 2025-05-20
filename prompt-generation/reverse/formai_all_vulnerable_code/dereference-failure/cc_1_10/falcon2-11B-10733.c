//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: dynamic
#include <stdio.h>

/* Node for BST */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Function to create a new node */
struct node* createNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

/* Function to insert a node in BST */
void insert(struct node* root, int data)
{
    if(root == NULL)
        root = createNode(data);
    else if(data < root->data)
        insert(root->left, data);
    else if(data > root->data)
        insert(root->right, data);
}

/* Function to search a node in BST */
int search(struct node* root, int data)
{
    if(root == NULL)
        return 0;
    else if(data == root->data)
        return 1;
    else if(data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

/* Function to print preorder traversal of BST */
void printPreorder(struct node* root)
{
    if(root!= NULL) {
        printf("%d ", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

int main()
{
    struct node* root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Preorder traversal of BST is:\n");
    printPreorder(root);
    printf("\n");

    printf("Data searched is %d\n", search(root, 20));
    printf("Data searched is %d\n", search(root, 70));

    return 0;
}