//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data;
    int count;
    struct node *left;
    struct node *right;
} Node;

Node *create_node(char data, int count) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->count = count;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert_node(Node *root, char data, int count) {
    if (root == NULL) {
        return create_node(data, count);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data, count);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data, count);
    } else {
        root->count += count;
    }
    return root;
}

void print_tree(Node *root, int space) {
    if (root == NULL) {
        return;
    }
    print_tree(root->right, space + 10);
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%c (%d)\n", root->data, root->count);
    print_tree(root->left, space + 10);
}

int main() {
    Node *root = NULL;
    char input[MAX_SIZE];
    int count;
    while (fgets(input, MAX_SIZE, stdin)!= NULL) {
        sscanf(input, "%c %d", &root->data, &count);
        root = insert_node(root, root->data, count);
    }
    printf("Binary search tree:\n");
    print_tree(root, 0);
    return 0;
}