//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int freq;
    char data;
    struct node *left;
    struct node *right;
} node_t;

typedef struct tree {
    struct node *root;
} tree_t;

tree_t *create_tree() {
    tree_t *tree = (tree_t *)malloc(sizeof(tree_t));
    tree->root = NULL;
    return tree;
}

node_t *create_node(int freq, char data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->freq = freq;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(tree_t *tree, node_t *node) {
    if (tree->root == NULL) {
        tree->root = node;
        return;
    }

    node_t *current = tree->root;
    while (1) {
        if (node->freq < current->freq) {
            if (current->left == NULL) {
                current->left = node;
                return;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

void print_tree(node_t *node, char *code) {
    if (node == NULL) {
        return;
    }

    if (node->data != '\0') {
        printf("%c: %s\n", node->data, code);
    }

    print_tree(node->left, strcat(code, "0"));
    print_tree(node->right, strcat(code, "1"));
}

void huffman_coding(char *text) {
    int freq[256] = {0};
    for (int i = 0; text[i] != '\0'; i++) {
        freq[text[i]]++;
    }

    tree_t *tree = create_tree();
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            node_t *node = create_node(freq[i], i);
            insert_node(tree, node);
        }
    }

    char code[256] = {0};
    print_tree(tree->root, code);
}

int main() {
    char text[] = "Hello World!";
    huffman_coding(text);
    return 0;
}