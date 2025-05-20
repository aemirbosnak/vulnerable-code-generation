//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1MB

typedef struct node {
    char symbol;
    int frequency;
    struct node* left;
    struct node* right;
} Node;

Node* build_tree(int frequency[]) {
    int i, max_index;
    Node* root;

    max_index = 0;
    for (i = 1; i < 256; i++) {
        if (frequency[i] > frequency[max_index])
            max_index = i;
    }

    root = (Node*)malloc(sizeof(Node));
    root->symbol = max_index;
    root->frequency = frequency[max_index];
    root->left = NULL;
    root->right = NULL;

    for (i = 1; i < 256; i++) {
        if (frequency[i] == frequency[max_index]) {
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->symbol = i;
            new_node->frequency = frequency[i];
            new_node->left = NULL;
            new_node->right = NULL;
            if (i > max_index) {
                root->right = new_node;
            } else {
                root->left = new_node;
            }
        }
    }

    return root;
}

void print_tree(Node* root) {
    if (root == NULL)
        return;
    printf("%c: %d\n", root->symbol, root->frequency);
    print_tree(root->left);
    print_tree(root->right);
}

void free_tree(Node* root) {
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(int argc, char* argv[]) {
    int frequency[256];
    int i;
    Node* root;
    char* code;
    FILE* input_file, *output_file;

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "rb");
    output_file = fopen(argv[2], "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening input or output file\n");
        return 1;
    }

    if (fread(frequency, sizeof(int), 256, input_file)!= 256) {
        printf("Error reading input file\n");
        return 1;
    }

    root = build_tree(frequency);

    print_tree(root);

    code = (char*)malloc(MAX_FILE_SIZE);

    for (i = 0; i < 256; i++) {
        if (root->left!= NULL) {
            code[i] = '0';
            code[i + 1] = root->left->symbol;
        } else {
            code[i] = '1';
        }

        code[i + 2] = '\0';
    }

    fwrite(code, 1, 256 * 3, output_file);

    free(code);
    free_tree(root);

    fclose(input_file);
    fclose(output_file);

    return 0;
}