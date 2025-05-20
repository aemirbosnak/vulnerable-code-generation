//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert_node(struct node *root, int data)
{
    if (root == NULL)
        return create_node(data);
    else
    {
        if (data <= root->data)
            root->left = insert_node(root->left, data);
        else
            root->right = insert_node(root->right, data);
    }
    return root;
}

struct node *search_node(struct node *root, int data)
{
    if (root == NULL)
        return NULL;
    else
    {
        if (data == root->data)
            return root;
        else if (data <= root->data)
            return search_node(root->left, data);
        else
            return search_node(root->right, data);
    }
}

void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert_node(root, 10);
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 2);
    insert_node(root, 7);
    insert_node(root, 12);
    insert_node(root, 20);

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    struct node *found_node = search_node(root, 15);
    if (found_node == NULL)
        printf("Node not found.\n");
    else
        printf("Node found: %d\n", found_node->data);

    return 0;
}