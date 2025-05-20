//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TREE_ Nodes 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void insert(Node* node, int data) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

void visualize(Node* node) {
    printf("%d ", node->data);
    if (node->left) {
        printf("L ");
        visualize(node->left);
    }
    if (node->right) {
        printf("R ");
        visualize(node->right);
    }
    printf("\n");
}

int main() {
    Node* root = NULL;
    insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 25);
    insert(root, 40);
    insert(root, 35);

    visualize(root);

    return 0;
}