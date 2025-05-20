//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    unsigned char symbol;
    unsigned int freq;
    struct node *left;
    struct node *right;
} node;

typedef struct huffman_tree {
    node *root;
    unsigned int size;
} huffman_tree;

huffman_tree *create_huffman_tree(unsigned char *symbols, unsigned int *freqs, unsigned int size) {
    huffman_tree *tree = malloc(sizeof(huffman_tree));
    if (tree == NULL) {
        return NULL;
    }

    tree->size = size;
    tree->root = NULL;

    for (unsigned int i = 0; i < size; i++) {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL) {
            free(tree);
            return NULL;
        }

        new_node->symbol = symbols[i];
        new_node->freq = freqs[i];
        new_node->left = NULL;
        new_node->right = NULL;

        if (tree->root == NULL) {
            tree->root = new_node;
        } else {
            node *current = tree->root;
            while (1) {
                if (new_node->freq < current->freq) {
                    if (current->left == NULL) {
                        current->left = new_node;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = new_node;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    return tree;
}

void destroy_huffman_tree(huffman_tree *tree) {
    if (tree == NULL) {
        return;
    }

    destroy_huffman_tree(tree->root->left);
    destroy_huffman_tree(tree->root->right);

    free(tree->root);
    free(tree);
}

unsigned int get_huffman_code(huffman_tree *tree, unsigned char symbol, unsigned char *code) {
    if (tree == NULL) {
        return 0;
    }

    node *current = tree->root;
    unsigned int length = 0;

    while (current != NULL) {
        if (current->symbol == symbol) {
            break;
        } else if (current->freq < symbol) {
            code[length++] = '0';
            current = current->left;
        } else {
            code[length++] = '1';
            current = current->right;
        }
    }

    return length;
}

int main() {
    unsigned char symbols[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned int freqs[] = {5, 9, 12, 13, 16, 45};
    unsigned int size = sizeof(symbols) / sizeof(symbols[0]);

    huffman_tree *tree = create_huffman_tree(symbols, freqs, size);
    if (tree == NULL) {
        printf("Error creating Huffman tree.\n");
        return 1;
    }

    unsigned char code[size];
    for (unsigned int i = 0; i < size; i++) {
        unsigned int length = get_huffman_code(tree, symbols[i], code);
        printf("%c: ", symbols[i]);
        for (unsigned int j = 0; j < length; j++) {
            printf("%c", code[j]);
        }
        printf("\n");
    }

    destroy_huffman_tree(tree);

    return 0;
}