//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 20

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

int random_number_generator(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void generate_random_tree(Node** tree, int height) {
    if (*tree == NULL) {
        *tree = create_node(random_number_generator(1, 100));
    }
    if (height > 1) {
        generate_random_tree(&(*tree)->left, height - 1);
        generate_random_tree(&(*tree)->right, height - 1);
    }
}

void inorder_traversal(Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    srand(time(NULL));
    Node* root = NULL;
    printf("Generating random binary search tree of height %d and width %d:\n", HEIGHT, WIDTH);
    generate_random_tree(&root, HEIGHT);
    printf("The random binary search tree is:\n");
    inorder_traversal(root);
    printf("\n");
    free(root);
    return 0;
}