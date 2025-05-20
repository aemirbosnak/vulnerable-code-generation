//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node** children;
} Node;

void insert(Node* node, int data) {
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->children = NULL;
    } else if (node->children != NULL) {
        for (int i = 0; i < MAX; i++) {
            if (node->children[i] == NULL) {
                node->children[i] = (Node*)malloc(sizeof(Node));
                node->children[i]->data = data;
                node->children[i]->children = NULL;
                return;
            }
        }
    } else {
        node->children = (Node**)malloc(MAX * sizeof(Node*));
        insert(node, data);
    }
}

void traverse(Node* node) {
    printf("%d ", node->data);
    if (node->children) {
        for (int i = 0; i < MAX; i++) {
            if (node->children[i]) {
                traverse(node->children[i]);
            }
        }
    }
}

int main() {
    Node* root = NULL;
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);

    traverse(root);

    return 0;
}