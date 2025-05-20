//FormAI DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL)
        return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

struct node* search(struct node* root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

int main()
{
    int choice = 0, key = 0;
    struct node* root = NULL;
    do
    {
        printf("\n----------------------------\n");
        printf("1. Insert a node\n");
        printf("2. Search for a node\n");
        printf("3. Traverse the tree (Inorder)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Node inserted successfully!\n");
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key) == NULL)
                    printf("Node not found in the tree!\n");
                else
                    printf("Node found in the tree!\n");
                break;

            case 3:
                printf("\nINORDER TRAVERSAL: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (choice != 4);

    return 0;
}