//FormAI DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

void insert(Node** root, int data) {
    if(*root == NULL) {
        (*root) = (Node*) malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->left = (*root)->right = NULL;
    } else if(data > (*root)->data) {
        insert(&((*root)->right), data);
    } else {
        insert(&((*root)->left), data);
    }
}

Node* search(Node* root, int data) {
    if(root == NULL) {
        return NULL;
    }
    if(data == root->data) {
        return root;
    } else if(data > root->data) {
        return search(root->right, data);
    } else {
        return search(root->left, data);
    }
}

int main() {
    Node* root = NULL;
    int n, data;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &data);
        insert(&root, data);
    }

    printf("Enter the element to search: ");
    scanf("%d", &data);

    Node* result = search(root, data);
    if(result == NULL) {
        printf("%d not found in the BST\n", data);
    } else {
        printf("%d found in the BST\n", result->data);
    }

    return 0;
}