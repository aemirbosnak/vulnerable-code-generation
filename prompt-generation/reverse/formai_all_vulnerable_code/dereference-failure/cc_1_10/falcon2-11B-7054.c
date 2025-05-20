//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

int main() {
    Node* root = NULL;

    // Insert the elements into the binary search tree
    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 25);
    insert(root, 22);
    insert(root, 18);

    // Print the binary search tree in a funny way
    printf("Binary search tree:\n");
    printf(" 10\n");
    printf(" / \\\n");
    printf(" 5 20\n");
    printf(" / \\\n");
    printf(" 3 7\n");
    printf(" / \\\n");
    printf(" 15 25\n");
    printf(" / \\\n");
    printf(" 22 18\n");

    // Free the memory used by the binary search tree
    while (root!= NULL) {
        Node* temp = root;
        root = root->left;
        free(temp);
    }

    return 0;
}