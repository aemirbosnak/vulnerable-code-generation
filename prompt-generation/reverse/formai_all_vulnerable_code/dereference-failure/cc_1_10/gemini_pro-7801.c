//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(struct node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data <= (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

struct node *search_node(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data <= root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

void print_node(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        print_node(root->left);
        print_node(root->right);
    }
}

int main() {
    struct node *root = NULL;

    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 2);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 20);

    struct node *found_node = search_node(root, 7);
    if (found_node != NULL) {
        printf("Found node with data %d\n", found_node->data);
    } else {
        printf("Node with data 7 not found\n");
    }

    print_node(root);
    printf("\n");

    return 0;
}