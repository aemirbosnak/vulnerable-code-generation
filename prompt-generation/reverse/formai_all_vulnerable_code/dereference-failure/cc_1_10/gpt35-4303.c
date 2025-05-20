//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing information about nodes in the Huffman tree.
typedef struct huffman_node {
    int value;
    struct huffman_node *left;
    struct huffman_node *right;
} huffman_node;

// Structure for storing information about frequency of each character in the input.
typedef struct freq_node {
    char character;
    int freq;
} freq_node;

// Create a new node for the Huffman tree.
huffman_node *new_node(int value, huffman_node *left, huffman_node *right) {
    huffman_node *node = (huffman_node*)malloc(sizeof(huffman_node));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

// Compare function for sorting the frequency table.
int cmp_func(const void *a, const void *b) {
    freq_node *node_a = (freq_node*)a;
    freq_node *node_b = (freq_node*)b;
    return node_b->freq - node_a->freq;
}

// Build the Huffman tree.
huffman_node *build_tree(freq_node *freq_table, int table_size) {
    
    // Sort the frequency table.
    qsort(freq_table, table_size, sizeof(freq_node), cmp_func);
    
    // Create a list of leaf nodes.
    huffman_node **leaf_list = (huffman_node**)malloc(table_size * sizeof(huffman_node*));
    for (int i = 0; i < table_size; i++) {
        leaf_list[i] = new_node(freq_table[i].freq, NULL, NULL);
    }
    
    // Build the tree.
    while (table_size > 1) {
        huffman_node *left = leaf_list[table_size - 1];
        huffman_node *right = leaf_list[table_size - 2];
        huffman_node *parent = new_node(left->value + right->value, left, right);
        table_size--;
        int i = 0;
        for (i = 0; i < table_size-1; i++) {
            if (parent->value > leaf_list[i]->value) {
                break;
            }
        }
        for (int j = table_size-1; j > i; j--) {
            leaf_list[j] = leaf_list[j - 1];
        }
        leaf_list[i] = parent;
    }
    
    huffman_node *root = leaf_list[0];
    free(leaf_list);
    return root;
}

// Traverse the tree and generate codes for all characters.
void generate_codes(huffman_node *node, char code[], int depth, char **codes) {
    if (node->left == NULL && node->right == NULL) {
        code[depth] = '\0';
        codes[node->value] = strdup(code);
        return;
    }
    if (node->left != NULL) {
        code[depth] = '0';
        generate_codes(node->left, code, depth + 1, codes);
    }
    if (node->right != NULL) {
        code[depth] = '1';
        generate_codes(node->right, code, depth + 1, codes);
    }
}

// Huffman code generation function.
char **huffman_codes(char input_string[], int *output_size) {
    int freq_table[256];
    memset(freq_table, 0, sizeof(freq_table));
    int input_len = strlen(input_string);
    for (int i = 0; i < input_len; i++) {
        freq_table[(int)input_string[i]]++;
    }
    int table_size = 0;
    freq_node *freq_table_struct = (freq_node*)malloc(256 * sizeof(freq_node));
    for (int i = 0; i < 256; i++) {
        if (freq_table[i] > 0) {
            freq_table_struct[table_size].character = (char)i;
            freq_table_struct[table_size].freq = freq_table[i];
            table_size++;
        }
    }
    huffman_node *root = build_tree(freq_table_struct, table_size);
    char **codes = (char**)calloc(256, sizeof(char*));
    char code[256];
    generate_codes(root, code, 0, codes);
    free(freq_table_struct);
    *output_size = table_size;
    return codes;
}

// Print function for Huffman codes.
void print_codes(char **codes, int table_size) {
    printf("Huffman Codes:\n");
    for (int i = 0; i < table_size; i++) {
        printf("%c: %s\n", i, codes[i]);
    }
}

// Example usage.
int main() {
    char input_string[] = "The quick brown fox jumps over the lazy dog.";
    int output_size;
    char **codes = huffman_codes(input_string, &output_size);
    print_codes(codes, output_size);
    return 0;
}