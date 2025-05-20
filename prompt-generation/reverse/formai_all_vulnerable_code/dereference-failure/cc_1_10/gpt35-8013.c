//FormAI DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }
    else if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* search(Node* root, int value)
{
    if(root == NULL || root->data == value)
    {
        return root;
    }
    else if(value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

void inorder(Node* node)
{
    if(node != NULL)
    {
        inorder(node->left);
        printf("%d -> ", node->data);
        inorder(node->right);
    }
}

int main()
{
    Node* root = NULL;
    int choice, value;
    while(1)
    {
        printf("\nMenu:\n1. Insert\n2. Search\n3. Inorder Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if(search(root, value))
                {
                    printf("Value is present in the BST.\n");
                }
                else
                {
                    printf("Value is not present in the BST.\n");
                }
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("NULL\n");
                break;
            case 4:
                printf("Exiting program!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    return 0;
}