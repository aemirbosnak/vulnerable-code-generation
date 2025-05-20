//FormAI DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of input string
#define BITS_PER_BYTE 8 // Number of bits in one byte

// Struct to hold each symbol and its corresponding frequency
typedef struct {
    char symbol;
    int freq;
} symbol_freq_t;

// Struct to hold each symbol and its corresponding binary code
typedef struct {
    char symbol;
    char *code;
} huffman_code_t;

// Struct to hold information about each node in the Huffman tree
typedef struct node_t {
    char symbol;
    int freq;
    struct node_t *left;
    struct node_t *right;
} node_t;

// Function to read input string from user
void get_input_string(char *input) {
    printf("Enter the input string to be compressed:\n");
    fgets(input, MAX_SIZE, stdin);
}

// Function to calculate frequency of each symbol in the input string
void calculate_symbol_freq(char *input, symbol_freq_t *symbol_freq, int *num_unique_symbols) {
    int i, j, is_duplicate;
    *num_unique_symbols = 0;
    for (i=0; input[i] != '\0' && input[i] != '\n'; i++) {
        is_duplicate = 0;
        for (j=0; j<*num_unique_symbols; j++) {
            if (symbol_freq[j].symbol == input[i]) {
                symbol_freq[j].freq++;
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            symbol_freq[*num_unique_symbols].symbol = input[i];
            symbol_freq[*num_unique_symbols].freq = 1;
            (*num_unique_symbols)++;
        }
    }
}

// Function to compare two symbols based on their frequency
int compare_symbol_freq(const void *a, const void *b) {
    symbol_freq_t *symbol_freq_a = (symbol_freq_t *) a;
    symbol_freq_t *symbol_freq_b = (symbol_freq_t *) b;
    return symbol_freq_a->freq - symbol_freq_b->freq;
}

// Function to build a Huffman tree given an array of symbols and their frequencies
node_t *build_huffman_tree(symbol_freq_t *symbol_freq, int num_symbols) {
    int i, j, num_nodes = num_symbols;
    node_t *nodes = (node_t *) calloc(num_nodes, sizeof(node_t));
    for (i=0; i<num_symbols; i++) {
        nodes[i].symbol = symbol_freq[i].symbol;
        nodes[i].freq = symbol_freq[i].freq;
    }
    for (i=num_symbols; i<num_nodes; i++) {
        nodes[i].freq = nodes[i-1].freq + nodes[i-2].freq;
        nodes[i].left = &nodes[i-2];
        nodes[i].right = &nodes[i-1];
        for (j=i-3; j>=0; j--) {
            if (nodes[i].freq >= nodes[j].freq) {
                break;
            }
            node_t temp = nodes[j];
            nodes[j] = nodes[i];
            nodes[i] = temp;
        }
    }
    return &nodes[num_nodes-1];
}

// Function to extract Huffman code for each symbol from the Huffman tree
void extract_huffman_code(node_t *node, char *prefix_code, huffman_code_t *huffman_code, int *num_codes) {
    if (node->left != NULL) {
        char *new_prefix_code = (char *) calloc(BITS_PER_BYTE, sizeof(char));
        sprintf(new_prefix_code, "%s0", prefix_code); // Left child is represented by a 0
        extract_huffman_code(node->left, new_prefix_code, huffman_code, num_codes);
        sprintf(new_prefix_code, "%s1", prefix_code); // Right child is represented by a 1
        extract_huffman_code(node->right, new_prefix_code, huffman_code, num_codes);
        free(new_prefix_code);
    }
    else { // Reached a leaf node, so add the symbol and its code to huffman_code array
        huffman_code[*num_codes].symbol = node->symbol;
        huffman_code[*num_codes].code = (char *) calloc(BITS_PER_BYTE, sizeof(char));
        strcpy(huffman_code[*num_codes].code, prefix_code);
        (*num_codes)++;
    }
}

// Function to compress the input string using the Huffman code
void compress_input(char *input, huffman_code_t *huffman_code, int num_codes, char *compressed_output) {
    int i, j, k;
    for (i=0; input[i] != '\0' && input[i] != '\n'; i++) {
        for (j=0; j<num_codes; j++) {
            if (input[i] == huffman_code[j].symbol) {
                for (k=0; k<strlen(huffman_code[j].code); k++) {
                    compressed_output[strlen(compressed_output)] = huffman_code[j].code[k];
                }
                break;
            }
        }
    }
}

// Function to display the Huffman codes for each symbol
void display_huffman_code(huffman_code_t *huffman_code, int num_codes) {
    int i;
    printf("Huffman Codes:\n");
    for (i=0; i<num_codes; i++) {
        printf("%c: %s\n", huffman_code[i].symbol, huffman_code[i].code);
    }
}

// Main function
int main() {
    char input[MAX_SIZE], compressed_output[MAX_SIZE/BITS_PER_BYTE];
    symbol_freq_t symbol_freq[MAX_SIZE];
    huffman_code_t huffman_code[MAX_SIZE];
    node_t *root;
    int num_unique_symbols, num_codes = 0;
    get_input_string(input);
    calculate_symbol_freq(input, symbol_freq, &num_unique_symbols);
    qsort(symbol_freq, num_unique_symbols, sizeof(symbol_freq_t), compare_symbol_freq);
    root = build_huffman_tree(symbol_freq, num_unique_symbols);
    extract_huffman_code(root, "", huffman_code, &num_codes);
    compress_input(input, huffman_code, num_codes, compressed_output);
    display_huffman_code(huffman_code, num_codes);
    printf("\nCompressed Output: %s\n", compressed_output);
    return 0;
}