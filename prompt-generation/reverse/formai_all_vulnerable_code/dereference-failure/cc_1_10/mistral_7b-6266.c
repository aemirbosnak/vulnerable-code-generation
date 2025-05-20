//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: Dennis Ritchie
// Dennis Ritchie style binary search tree example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char key[30];
    int height;
    struct Node *left, *right;
} Node;

int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node *newNode(char *str) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->key, str);
    node->height = 0;
    node->left = node->right = NULL;
    return node;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, char *str) {
    if (node == NULL)
        return newNode(str);

    if (strcmp(str, node->key) < 0)
        node->left = insert(node->left, str);
    else if (strcmp(str, node->key) > 0)
        node->right = insert(node->right, str);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1) {
        if (height(node->left->left) >= height(node->left->right))
            node = rightRotate(node);
        else {
            node->left = leftRotate(node->left);
            node = rightRotate(node);
        }
    }

    return node;
}

void printInOrder(Node *root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%s ", root->key);
        printInOrder(root->right);
    }
}

int main() {
    Node *root = NULL;

    char str[30];
    int choice;

    while (1) {
        printf("\n1.Insert\n2.Print\n3.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the string to insert: ");
                scanf("%s", str);
                root = insert(root, str);
                break;
            case 2:
                printf("Inorder traversal of tree:\n");
                printInOrder(root);
                printf("\n");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}