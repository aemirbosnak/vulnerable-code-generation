//FormAI DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert(Node *node, int data) {
    if (node == NULL) {
        node = create_node(data);
    } else if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

void print_tree(Node *root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;

    print_tree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    print_tree(root->left, space);
}

int main() {
    Node *root = NULL;
    int data;
    char input[50];

    printf("Enter numbers to add to tree (type \"done\" when finished):\n");
    while (1) {
        printf("> ");
        fgets(input, 50, stdin);
        if (strcmp(input, "done\n") == 0) {
            break;
        }
        data = strtol(input, NULL, 10);
        root = insert(root, data);
    }

    printf("\nTree visualization:\n");
    print_tree(root, 0);

    return 0;
}