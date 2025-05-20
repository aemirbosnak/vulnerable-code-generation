//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100

typedef struct {
    char symbol;
    int count;
    struct node *left, *right;
} node;

node* build_tree(node *root, char *symbol, int count) {
    if (count == 0) {
        root->symbol = symbol[0];
        return root;
    }
    node *new_node = (node*) malloc(sizeof(node));
    new_node->symbol = symbol[0];
    new_node->left = build_tree(root->left, symbol, count/2);
    new_node->right = build_tree(root->right, symbol, count/2);
    root = new_node;
    return root;
}

node* huffman_coding(char *symbols, int *counts, int num_symbols) {
    if (num_symbols == 1) {
        node *root = (node*) malloc(sizeof(node));
        root->symbol = symbols[0];
        root->count = counts[0];
        return root;
    }
    node *root = build_tree(NULL, symbols[0], counts[0]);
    for (int i = 1; i < num_symbols; i++) {
        node *new_node = build_tree(root, symbols[i], counts[i]);
        if (new_node->count < root->count) {
            root = new_node;
        }
    }
    return root;
}

int huffman_decode(node *root, char *symbol, int *count) {
    if (root == NULL) {
        return 0;
    }
    if (root->symbol!= '\0') {
        symbol[0] = root->symbol;
        return root->count;
    }
    return huffman_decode(root->left, symbol, count) +
           huffman_decode(root->right, symbol, count);
}

int huffman_encode(node *root, char *symbol, int *count) {
    if (root == NULL) {
        return 0;
    }
    if (root->symbol!= '\0') {
        symbol[0] = root->symbol;
        return root->count;
    }
    return huffman_encode(root->left, symbol, count) +
           huffman_encode(root->right, symbol, count);
}

int main() {
    char symbols[] = {'a', 'b', 'c', 'd'};
    int counts[] = {2, 4, 5, 7};
    int num_symbols = sizeof(symbols) / sizeof(char);
    node *root = huffman_coding(symbols, counts, num_symbols);
    char encoded[MAX_SYMBOLS];
    int encoded_length = 0;
    for (int i = 0; i < num_symbols; i++) {
        char symbol = symbols[i];
        int count = counts[i];
        encoded_length += huffman_encode(root, &symbol, &count);
        printf("%d %c\n", count, symbol);
    }
    printf("%d\n", encoded_length);
    for (int i = 0; i < encoded_length; i++) {
        char symbol = encoded[i];
        int count = huffman_decode(root, &symbol, &count);
        printf("%d %c\n", count, symbol);
    }
    return 0;
}