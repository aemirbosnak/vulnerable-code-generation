//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HEIGHT 100
#define MAX_SYMBOLS 256

typedef struct HuffmanNode {
    int frequency;
    int symbol;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

typedef struct HuffmanCode {
    int length;
    unsigned char *code;
} HuffmanCode;

HuffmanNode *create_node(int frequency, int symbol) {
    HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    node->frequency = frequency;
    node->symbol = symbol;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void destroy_tree(HuffmanNode *root) {
    if (root == NULL) {
        return;
    }

    destroy_tree(root->left);
    destroy_tree(root->right);

    free(root);
}

HuffmanNode *build_tree(int frequencies[], int num_symbols) {
    HuffmanNode *nodes[MAX_SYMBOLS];

    for (int i = 0; i < num_symbols; i++) {
        if (frequencies[i] > 0) {
            nodes[i] = create_node(frequencies[i], i);
        }
    }

    int num_nodes = num_symbols;

    while (num_nodes > 1) {
        HuffmanNode *left_node = NULL;
        HuffmanNode *right_node = NULL;
        int min_frequency = -1;

        for (int i = 0; i < num_symbols; i++) {
            if (nodes[i] != NULL && nodes[i]->frequency < min_frequency) {
                left_node = nodes[i];
                min_frequency = nodes[i]->frequency;
            }
        }

        for (int i = 0; i < num_symbols; i++) {
            if (nodes[i] != NULL && nodes[i]->frequency < min_frequency) {
                right_node = nodes[i];
                min_frequency = nodes[i]->frequency;
            }
        }

        HuffmanNode *parent_node = create_node(left_node->frequency + right_node->frequency, -1);
        parent_node->left = left_node;
        parent_node->right = right_node;

        nodes[left_node->symbol] = parent_node;
        nodes[right_node->symbol] = NULL;

        num_nodes--;
    }

    return nodes[0];
}

void generate_codes(HuffmanNode *root, HuffmanCode codes[], int code_length, unsigned char code[]) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        codes[root->symbol].length = code_length;
        codes[root->symbol].code = (unsigned char *)malloc(code_length);
        memcpy(codes[root->symbol].code, code, code_length);

        return;
    }

    code[code_length] = 0;
    generate_codes(root->left, codes, code_length + 1, code);

    code[code_length] = 1;
    generate_codes(root->right, codes, code_length + 1, code);
}

void print_codes(HuffmanCode codes[], int num_symbols) {
    for (int i = 0; i < num_symbols; i++) {
        if (codes[i].length == 0) {
            continue;
        }

        printf("%c: ", i);

        for (int j = 0; j < codes[i].length; j++) {
            printf("%d", codes[i].code[j]);
        }

        printf("\n");
    }
}

int main() {
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int num_symbols = sizeof(frequencies) / sizeof(frequencies[0]);

    HuffmanNode *root = build_tree(frequencies, num_symbols);

    HuffmanCode codes[MAX_SYMBOLS];
    unsigned char code[MAX_TREE_HEIGHT];
    generate_codes(root, codes, 0, code);

    print_codes(codes, num_symbols);

    destroy_tree(root);

    return 0;
}