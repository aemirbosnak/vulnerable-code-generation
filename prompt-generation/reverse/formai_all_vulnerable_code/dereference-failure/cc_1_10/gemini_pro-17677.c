//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
} node;

typedef struct huffman_tree {
    node *root;
} huffman_tree;

node *create_node(char character, int frequency) {
    node *new_node = malloc(sizeof(node));
    new_node->character = character;
    new_node->frequency = frequency;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

huffman_tree *create_huffman_tree(node **nodes, int size) {
    huffman_tree *new_tree = malloc(sizeof(huffman_tree));
    new_tree->root = NULL;

    while (size > 1) {
        node *left = nodes[0];
        node *right = nodes[1];

        node *parent = create_node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        for (int i = 0; i < size - 2; i++) {
            nodes[i] = nodes[i + 2];
        }
        size -= 2;
        nodes[size - 1] = parent;
    }

    new_tree->root = nodes[0];
    return new_tree;
}

void print_code(node *root, char *code) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->character, code);
    } else {
        char left_code[strlen(code) + 1];
        strcpy(left_code, code);
        strcat(left_code, "0");
        print_code(root->left, left_code);

        char right_code[strlen(code) + 1];
        strcpy(right_code, code);
        strcat(right_code, "1");
        print_code(root->right, right_code);
    }
}

void free_huffman_tree(node *root) {
    if (root->left != NULL) {
        free_huffman_tree(root->left);
    }

    if (root->right != NULL) {
        free_huffman_tree(root->right);
    }

    free(root);
}

int main() {
    char *input = "this is a test string";
    int frequencies[256] = {0};

    for (int i = 0; i < strlen(input); i++) {
        frequencies[input[i]]++;
    }

    node *nodes[256];
    int size = 0;

    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            nodes[size++] = create_node(i, frequencies[i]);
        }
    }

    huffman_tree *tree = create_huffman_tree(nodes, size);
    print_code(tree->root, "");
    free_huffman_tree(tree->root);
    return 0;
}