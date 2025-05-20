//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
} node_t;

typedef struct tree {
    node_t *root;
} tree_t;

typedef struct code {
    char character;
    char *code;
} code_t;

void insert_node(tree_t *tree, char character, int frequency) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->character = character;
    new_node->frequency = frequency;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        node_t *current_node = tree->root;
        while (1) {
            if (frequency < current_node->frequency) {
                if (current_node->left == NULL) {
                    current_node->left = new_node;
                    break;
                } else {
                    current_node = current_node->left;
                }
            } else {
                if (current_node->right == NULL) {
                    current_node->right = new_node;
                    break;
                } else {
                    current_node = current_node->right;
                }
            }
        }
    }
}

void build_tree(tree_t *tree, char *string) {
    int frequency[256] = {0};

    for (int i = 0; i < strlen(string); i++) {
        frequency[(int)string[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            insert_node(tree, (char)i, frequency[i]);
        }
    }
}

void generate_code(tree_t *tree, node_t *node, char *code, int length) {
    if (node->left == NULL && node->right == NULL) {
        code[length] = '\0';
        printf("%c: %s\n", node->character, code);
    } else {
        code[length] = '0';
        generate_code(tree, node->left, code, length + 1);
        code[length] = '1';
        generate_code(tree, node->right, code, length + 1);
    }
}

void compress(char *string, code_t *codes, int num_codes) {
    char *compressed_string = (char *)malloc(strlen(string) * 8);
    int compressed_string_length = 0;

    for (int i = 0; i < strlen(string); i++) {
        for (int j = 0; j < num_codes; j++) {
            if (string[i] == codes[j].character) {
                strcat(compressed_string, codes[j].code);
                compressed_string_length += strlen(codes[j].code);
                break;
            }
        }
    }

    compressed_string[compressed_string_length] = '\0';

    printf("Compressed string: %s\n", compressed_string);
}

int main() {
    char string[] = "Hello world!";
    tree_t tree;
    tree.root = NULL;

    build_tree(&tree, string);

    char code[256] = {0};
    generate_code(&tree, tree.root, code, 0);

    code_t codes[256];
    int num_codes = 0;

    for (int i = 0; i < 256; i++) {
        if (code[i] != '\0') {
            codes[num_codes].character = (char)i;
            codes[num_codes].code = (char *)malloc(strlen(code) + 1);
            strcpy(codes[num_codes].code, code);
            num_codes++;
        }
    }

    compress(string, codes, num_codes);

    return 0;
}