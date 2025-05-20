//FormAI DATASET v1.0 Category: Binary search trees ; Style: happy
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

int search(Node* root, int data) {
    if (root == NULL) {
        return 0;
    }
    else if (root->data == data) {
        return 1;
    }
    else if (data <= root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);

    printf("Searching for 20: %d\n", search(root, 20));
    printf("Searching for 25: %d\n", search(root, 25));
    printf("Searching for 5: %d\n", search(root, 5));
    
    printf("Wow, the search function works perfectly!\n");
    printf("I'm so excited that my binary search tree works so well!\n");
    
    return 0;
}