//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data[50];
    struct Node *left, *right;
} Node;

Node *createNode(char str[]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, char str[]) {
    if (root == NULL)
        return createNode(str);

    if (strcmp(str, root->data) < 0)
        root->left = insert(root->left, str);

    else if (strcmp(str, root->data) > 0)
        root->right = insert(root->right, str);

    return root;
}

Node *minValueNode(Node *root) {
    Node *current = root;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, char str[]) {
    if (root == NULL)
        return root;

    if (strcmp(str, root->data) < 0)
        root->left = deleteNode(root->left, str);

    else if (strcmp(str, root->data) > 0)
        root->right = deleteNode(root->right, str);

    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);
        strcpy(root->data, temp->data);
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node *root = NULL;
    int choice, i;

    printf("Binary Search Tree: Insertion, Deletion, Traversal and Display\n");
    printf("1. Insert\n2. Delete\n3. Traversal\n4. Display\n5. Quit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char str[50];
                printf("Enter the word to be inserted: ");
                scanf("%s", str);
                root = insert(root, str);
                break;
            }
            case 2: {
                char str[50];
                printf("Enter the word to be deleted: ");
                scanf("%s", str);
                root = deleteNode(root, str);
                break;
            }
            case 3: {
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            }
            case 4: {
                printf("Display: ");
                inorderTraversal(root);
                printf("\n");
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Invalid choice! Please try again.\n");
            }
        }
    }

    return 0;
}