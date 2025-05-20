//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 256

typedef struct node {
    int symbol;
    int freq;
    struct node *left;
    struct node *right;
} node_t;

typedef struct huffman_code {
    int symbol;
    char *code;
} huffman_code_t;

node_t *create_node(int symbol, int freq) {
    node_t *node = malloc(sizeof(node_t));
    node->symbol = symbol;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void destroy_node(node_t *node) {
    if (node->left != NULL) {
        destroy_node(node->left);
    }
    if (node->right != NULL) {
        destroy_node(node->right);
    }
    free(node);
}

node_t *build_huffman_tree(int *symbols, int *freqs, int size) {
    node_t *nodes[MAX_SYMBOLS];
    for (int i = 0; i < size; i++) {
        nodes[i] = create_node(symbols[i], freqs[i]);
    }

    while (size > 1) {
        int min1 = -1;
        int min2 = -1;
        for (int i = 0; i < size; i++) {
            if (nodes[i] != NULL) {
                if (min1 == -1 || nodes[i]->freq < nodes[min1]->freq) {
                    min2 = min1;
                    min1 = i;
                } else if (min2 == -1 || nodes[i]->freq < nodes[min2]->freq) {
                    min2 = i;
                }
            }
        }

        node_t *new_node = create_node(-1, nodes[min1]->freq + nodes[min2]->freq);
        new_node->left = nodes[min1];
        new_node->right = nodes[min2];

        nodes[min1] = new_node;
        nodes[min2] = NULL;
        size--;
    }

    return nodes[0];
}

void generate_huffman_codes(node_t *root, huffman_code_t *codes, char *code, int length) {
    if (root->left == NULL && root->right == NULL) {
        codes[root->symbol].code = malloc(length + 1);
        memcpy(codes[root->symbol].code, code, length);
        codes[root->symbol].code[length] = '\0';
    } else {
        char new_code[length + 1];
        memcpy(new_code, code, length);
        new_code[length] = '0';
        generate_huffman_codes(root->left, codes, new_code, length + 1);

        memcpy(new_code, code, length);
        new_code[length] = '1';
        generate_huffman_codes(root->right, codes, new_code, length + 1);
    }
}

void destroy_huffman_codes(huffman_code_t *codes, int size) {
    for (int i = 0; i < size; i++) {
        free(codes[i].code);
    }
}

void print_huffman_codes(huffman_code_t *codes, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %s\n", codes[i].symbol, codes[i].code);
    }
}

int main() {
    int symbols[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int freqs[] = {5, 9, 12, 13, 16, 45, 67, 89};
    int size = sizeof(symbols) / sizeof(symbols[0]);

    node_t *root = build_huffman_tree(symbols, freqs, size);

    huffman_code_t codes[MAX_SYMBOLS];
    memset(codes, 0, sizeof(codes));
    generate_huffman_codes(root, codes, "", 0);

    print_huffman_codes(codes, size);

    destroy_huffman_codes(codes, size);
    destroy_node(root);

    return 0;
}