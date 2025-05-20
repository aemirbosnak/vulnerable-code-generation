//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* left_child;
    struct node* right_child;
};
  
struct node* create_node(int value)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return(new_node);
}
  
struct node* insert_node(struct node* root, int value)
{
    if (root == NULL) 
        return(create_node(value));
    else
    {
        if (value <= root->value)
            root->left_child = insert_node(root->left_child, value);
        else
            root->right_child = insert_node(root->right_child, value);
        return(root);
    }
}

void inorder_traversal(struct node* root)
{
    if (root == NULL) 
        return;
    inorder_traversal(root->left_child);
    printf("%d -> ", root->value);
    inorder_traversal(root->right_child);
}

int main()
{
    struct node* root = NULL;
    root = insert_node(root, 10);
    insert_node(root, 20);
    insert_node(root, 30);
    insert_node(root, 40);
    insert_node(root, 50);
    printf("Inorder Traversal of BST: \n");
    inorder_traversal(root);
    printf("\n");
    return 0;
}