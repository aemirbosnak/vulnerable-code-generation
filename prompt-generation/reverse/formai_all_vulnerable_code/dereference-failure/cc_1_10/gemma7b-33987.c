//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdlib.h>

#define MAX_TREE_ Nodes 1000

typedef struct Node {
    struct Node* left;
    struct Node* right;
    int data;
} Node;

Node* newNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

void insert(Node* node, int data) {
    if (node == NULL) {
        node = newNode(data);
    } else if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

int search(Node* node, int data) {
    if (node == NULL) {
        return 0;
    } else if (node->data == data) {
        return 1;
    } else if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

int main() {
    Node* root = newNode(20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 25);
    insert(root, 40);

    if (search(root, 25) == 1) {
        printf("Data found!\n");
    } else {
        printf("Data not found!\n");
    }

    return 0;
}