//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *root = NULL;

Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node *node, int data) {
    if (node == NULL) {
        return create_node(data);
    }
    if (data < node->data) {
        node->left = insert_node(node->left, data);
    } else if (data > node->data) {
        node->right = insert_node(node->right, data);
    }
    return node;
}

Node* min_value_node(Node *node) {
    while (node->left!= NULL) {
        node = node->left;
    }
    return node;
}

Node* delete_node(Node *node, int data) {
    if (node == NULL) {
        return NULL;
    }
    if (data < node->data) {
        node->left = delete_node(node->left, data);
    } else if (data > node->data) {
        node->right = delete_node(node->right, data);
    } else {
        if (node->left == NULL) {
            Node *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            Node *temp = node->left;
            free(node);
            return temp;
        }
        Node *temp = min_value_node(node->right);
        node->data = temp->data;
        node->right = delete_node(node->right, temp->data);
    }
    return node;
}

void inorder_traversal(Node *node) {
    if (node!= NULL) {
        inorder_traversal(node->left);
        printf("%d ", node->data);
        inorder_traversal(node->right);
    }
}

int main() {
    srand(time(0));
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        root = insert_node(root, rand() % 100);
    }
    printf("Inorder traversal of the binary search tree:\n");
    inorder_traversal(root);
    printf("\n");
    return 0;
}