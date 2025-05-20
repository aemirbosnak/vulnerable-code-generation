//FormAI DATASET v1.0 Category: Binary search trees ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

//structure definition of a binary search tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

//function to create a new node
struct node *new_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

//function to insert a node in the binary search tree
struct node *insert_node(struct node *root, int data)
{
    if (root == NULL)
    {
        return new_node(data);
    }
    else if (data < root->data)
    {
        root->left = insert_node(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert_node(root->right, data);
    }
    return root;
}

//function to perform inorder traversal of the binary search tree
void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

//function to find the minimum value node in the binary search tree
struct node *min_value_node(struct node *node)
{
    struct node *current_node = node;
    while (current_node && current_node->left != NULL)
    {
        current_node = current_node->left;
    }
    return current_node;
}

//function to delete a node from the binary search tree
struct node *delete_node(struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete_node(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else
        {
            struct node *temp = min_value_node(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

//main function
int main()
{
    struct node *root = NULL;
    int choice = 0;
    int data = 0;
    int flag = 0;
    while (1)
    {
        printf("\n********** MENU **********\n");
        printf("1. Insert a node\n");
        printf("2. Traverse the tree\n");
        printf("3. Delete a node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            root = insert_node(root, data);
            break;
        case 2:
            printf("\nInorder Traversal: ");
            inorder_traversal(root);
            break;
        case 3:
            printf("\nEnter the data to be deleted: ");
            scanf("%d", &data);
            flag = 0;
            root = delete_node(root, data);
            if (flag == 0)
            {
                printf("\nData not found\n");
            }
            else
            {
                printf("\nData deleted successfully\n");
            }
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong choice\n");
            break;
        }
    }
    return 0;
}