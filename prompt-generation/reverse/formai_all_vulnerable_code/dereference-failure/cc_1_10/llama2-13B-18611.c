//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_VALUE 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int insert(Node** root, int data) {
    Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return 0;
    }

    if (data < (*root)->data) {
        if ((*root)->left == NULL) {
            (*root)->left = newNode;
            return 0;
        }
        insert((*root)->left, data);
    } else {
        if ((*root)->right == NULL) {
            (*root)->right = newNode;
            return 0;
        }
        insert((*root)->right, data);
    }

    return 1;
}

int search(Node* root, int data) {
    if (root == NULL) {
        return -1;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return 0;
    }
}

int main() {
    Node* root = NULL;

    int data;
    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &data);
        insert(&root, data);
    }

    printf("Enter a value to search: ");
    int searchValue = 0;
    scanf("%d", &searchValue);

    int found = search(root, searchValue);
    if (found == -1) {
        printf("Not found\n");
    } else {
        printf("Found at %d\n", found);
    }

    return 0;
}