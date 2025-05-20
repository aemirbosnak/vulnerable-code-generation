//FormAI DATASET v1.0 Category: Compression algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant for maximum input size
#define MAX_INPUT_SIZE 10000

// Define structure for nodes in binary tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node_t;

// Function to create new node with specified data
node_t* create_node(int data) {
    node_t* node = malloc(sizeof(node_t));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to insert new node into binary tree
void insert_node(node_t* root, int data) {
    if (data < root->data) {
        if (root->left == NULL) {
            root->left = create_node(data);
        } else {
            insert_node(root->left, data);
        }
    } else {
        if (root->right == NULL) {
            root->right = create_node(data);
        } else {
            insert_node(root->right, data);
        }
    }
}

// Function to recursively traverse binary tree from root and append 1 or 0 to output string based on direction of traversal
void compress_tree(node_t* root, char* output, int* index) {
    if (root == NULL) {
        return;
    }

    // Append 1 for left traversal and 0 for right traversal
    if (root->left != NULL) {
        output[*index] = '1';
        (*index)++;
        compress_tree(root->left, output, index);
    }
    if (root->right != NULL) {
        output[*index] = '0';
        (*index)++;
        compress_tree(root->right, output, index);
    }
}

// Function to read input string from command line or file and insert each character into binary tree
node_t* build_tree(char* input) {
    node_t* root = NULL;

    for (int i = 0; i < strlen(input); i++) {
        if (root == NULL) {
            root = create_node(input[i]);
        } else {
            insert_node(root, input[i]);
        }
    }

    return root;
}

// Function to write compressed output to file
void write_output(char* output) {
    FILE* f = fopen("compressed.txt", "w");

    if (f == NULL) {
        printf("Error opening file\n");
        return;
    }

    fprintf(f, "%s", output);
    fclose(f);
}

// Main function
int main() {
    // Allocate memory for input and output strings
    char* input = malloc(MAX_INPUT_SIZE);
    char* output = malloc(MAX_INPUT_SIZE);

    // Read input from command line or file
    scanf("%[^\n]s", input);

    // Build binary tree and compress tree structure to output string
    node_t* root = build_tree(input);
    int index = 0;
    compress_tree(root, output, &index);

    // Write compressed output to file
    write_output(output);

    // Free memory for input, output, and binary tree
    free(input);
    free(output);

    return 0;
}