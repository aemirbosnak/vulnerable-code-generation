//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 16

typedef struct huffman_node {
    char c;
    int freq;
    struct huffman_node *left;
    struct huffman_node *right;
} huffman_node;

typedef struct huffman_code {
    char c;
    char code[MAX_CODE_LEN];
} huffman_code;

huffman_node *create_node(char c, int freq) {
    huffman_node *node = malloc(sizeof(huffman_node));
    node->c = c;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void free_node(huffman_node *node) {
    if (node == NULL) {
        return;
    }
    free(node);
}

int compare_nodes(const void *a, const void *b) {
    huffman_node *node1 = *(huffman_node **)a;
    huffman_node *node2 = *(huffman_node **)b;

    return node1->freq - node2->freq;
}

huffman_node *build_tree(char *input, int input_len) {
    // Create a frequency table
    int freq_table[256] = {0};
    for (int i = 0; i < input_len; i++) {
        freq_table[input[i]]++;
    }

    // Create a list of nodes sorted by frequency
    huffman_node **nodes = malloc(sizeof(huffman_node *) * 256);
    int num_nodes = 0;
    for (int i = 0; i < 256; i++) {
        if (freq_table[i] > 0) {
            nodes[num_nodes++] = create_node(i, freq_table[i]);
        }
    }

    qsort(nodes, num_nodes, sizeof(huffman_node *), compare_nodes);

    // Build the tree
    while (num_nodes > 1) {
        huffman_node *left = nodes[0];
        huffman_node *right = nodes[1];

        huffman_node *parent = create_node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        nodes[0] = parent;
        nodes[1] = nodes[num_nodes - 1];
        num_nodes--;

        qsort(nodes, num_nodes, sizeof(huffman_node *), compare_nodes);
    }

    return nodes[0];
}

void generate_codes(huffman_node *root, huffman_code *codes, char *code, int code_len) {
    if (root == NULL) {
        return;
    }

    if (root->c != '\0') {
        codes[root->c].c = root->c;
        strcpy(codes[root->c].code, code);
        return;
    }

    code[code_len] = '0';
    code_len++;
    generate_codes(root->left, codes, code, code_len);

    code[code_len] = '1';
    code_len++;
    generate_codes(root->right, codes, code, code_len);
}

void encode(char *input, int input_len, huffman_code *codes) {
    char output[input_len * MAX_CODE_LEN + 1];
    int output_len = 0;

    for (int i = 0; i < input_len; i++) {
        strcat(output, codes[input[i]].code);
        output_len += strlen(codes[input[i]].code);
    }

    output[output_len] = '\0';

    printf("Encoded: %s\n", output);
}

void decode(char *input, int input_len, huffman_node *root) {
    char output[input_len + 1];
    int output_len = 0;

    huffman_node *current = root;
    for (int i = 0; i < input_len; i++) {
        if (input[i] == '0') {
            current = current->left;
        } else if (input[i] == '1') {
            current = current->right;
        }

        if (current->c != '\0') {
            output[output_len++] = current->c;
            current = root;
        }
    }

    output[output_len] = '\0';

    printf("Decoded: %s\n", output);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input string>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    int input_len = strlen(input);

    huffman_node *root = build_tree(input, input_len);
    huffman_code codes[256];

    char code[MAX_CODE_LEN] = {0};
    generate_codes(root, codes, code, 0);

    encode(input, input_len, codes);
    decode(input, input_len, root);

    free_node(root);

    return 0;
}