//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    int count;
    struct node *left;
    struct node *right;
} node;

node *create_node(char data[]) {
    node *new_node = (node *) malloc(sizeof(node));
    strcpy(new_node->data, data);
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node *root, char data[]) {
    if (root == NULL) {
        root = create_node(data);
    } else if (strcmp(root->data, data) == 0) {
        root->count++;
    } else if (strcmp(data, root->data) < 0) {
        insert_node(root->left, data);
    } else {
        insert_node(root->right, data);
    }
}

void pre_order_traversal(node *root) {
    if (root!= NULL) {
        printf("%s (%d)\n", root->data, root->count);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

void in_order_traversal(node *root) {
    if (root!= NULL) {
        in_order_traversal(root->left);
        printf("%s (%d)\n", root->data, root->count);
        in_order_traversal(root->right);
    }
}

void post_order_traversal(node *root) {
    if (root!= NULL) {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%s (%d)\n", root->data, root->count);
    }
}

int search_node(node *root, char data[]) {
    if (root == NULL) {
        return 0;
    } else if (strcmp(root->data, data) == 0) {
        return 1;
    } else if (strcmp(data, root->data) < 0) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

int main() {
    node *root = NULL;

    insert_node(root, "apple");
    insert_node(root, "banana");
    insert_node(root, "orange");

    printf("Pre-order traversal:\n");
    pre_order_traversal(root);

    printf("\nIn-order traversal:\n");
    in_order_traversal(root);

    printf("\nPost-order traversal:\n");
    post_order_traversal(root);

    if (search_node(root, "apple")) {
        printf("\nFound 'apple' in the tree.\n");
    } else {
        printf("\n'apple' not found in the tree.\n");
    }

    if (search_node(root, "grape")) {
        printf("\nFound 'grape' in the tree.\n");
    } else {
        printf("\n'grape' not found in the tree.\n");
    }

    return 0;
}