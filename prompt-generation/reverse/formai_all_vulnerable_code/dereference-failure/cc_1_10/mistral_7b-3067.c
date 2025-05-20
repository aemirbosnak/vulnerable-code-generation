//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

#define MAX_HEIGHT 10

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void printSpace(int num) {
    for (int i = 0; i < num; i++) {
        printf(" ");
    }
}

void printNode(Node* node, int level) {
    if (node == NULL) {
        printSpace(level * 2 + 3);
        printf("Empty\n");
        return;
    }

    printSpace(level * 2);
    printf("%d\n", node->data);

    printNode(node->left, level + 1);
    printNode(node->right, level + 1);
}

void createNode(Node** node, int data) {
    *node = (Node*) malloc(sizeof(Node));
    (*node)->data = data;
    (*node)->left = NULL;
    (*node)->right = NULL;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        createNode(&root, data);
        return root;
    }

    if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Visualizing Tree:\n");
    printNode(root, 0);

    return 0;
}