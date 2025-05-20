//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        root = create_node(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder_traversal(Node* root, FILE* output_file) {
    if (root != NULL) {
        inorder_traversal(root->left, output_file);
        fprintf(output_file, "%d ", root->key);
        inorder_traversal(root->right, output_file);
    }
}

int main() {
    srand(time(NULL));
    int num_nodes = 1000;
    int i;
    Node* root = NULL;

    printf("Generating random keys and inserting into binary search tree...\n");
    for (i = 0; i < num_nodes; i++) {
        root = insert(root, rand() % 1000);
    }

    FILE* output_file = fopen("output.txt", "w");
    printf("Performing inorder traversal and writing to output file...\n");
    inorder_traversal(root, output_file);
    fclose(output_file);

    printf("Binary search tree constructed successfully!\n");
    return 0;
}