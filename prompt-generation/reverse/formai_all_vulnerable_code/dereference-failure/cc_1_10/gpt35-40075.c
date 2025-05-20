//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define the structure for the Huffman node
struct HuffmanNode {
    char data;
    unsigned int freq;
    struct HuffmanNode *left, *right;
};

// Define the structure for the Huffman tree
struct HuffmanTree {
    unsigned int size;
    struct HuffmanNode **nodes;
};

// Define the structure for the Huffman table
struct HuffmanTable {
    unsigned int size;
    unsigned int *bit_lengths;
    unsigned int *codes;
};

// Function to create a new Huffman node
struct HuffmanNode* new_huffman_node(char data, unsigned int freq) {
    struct HuffmanNode* node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

// Function to compare two Huffman nodes by frequency
int huffman_node_compare(const void* a, const void* b) {
    const struct HuffmanNode *node_a = *(const struct HuffmanNode**) a;
    const struct HuffmanNode *node_b = *(const struct HuffmanNode**) b;
    
    return node_a->freq - node_b->freq;
}

// Function to create a new Huffman tree
struct HuffmanTree* new_huffman_tree() {
    struct HuffmanTree* tree = (struct HuffmanTree*) malloc(sizeof(struct HuffmanTree));
    
    tree->size = 0;
    tree->nodes = NULL;
    
    return tree;
}

// Function to add a Huffman node to the tree
void huffman_tree_add_node(struct HuffmanTree* tree, struct HuffmanNode* node) {
    tree->size++;
    tree->nodes = (struct HuffmanNode**) realloc(tree->nodes, sizeof(struct HuffmanNode*) * tree->size);
    
    tree->nodes[tree->size - 1] = node;
}

// Function to build the Huffman tree
void huffman_tree_build(struct HuffmanTree* tree) {
    while (tree->size > 1) {
        qsort(tree->nodes, tree->size, sizeof(struct HuffmanNode*), huffman_node_compare);
        
        struct HuffmanNode* left_node = tree->nodes[0];
        struct HuffmanNode* right_node = tree->nodes[1];
        struct HuffmanNode* parent_node = new_huffman_node('\0', left_node->freq + right_node->freq);
        
        parent_node->left = left_node;
        parent_node->right = right_node;
        
        tree->nodes[0] = parent_node;
        tree->nodes[1] = tree->nodes[tree->size - 1];
        tree->size--;
    }
}

// Function to build the Huffman table
void huffman_table_build(struct HuffmanTable* table, struct HuffmanNode* node, unsigned int code, unsigned int length) {
    if (node->left) {
        huffman_table_build(table, node->left, (code << 1) | 0, length + 1);
    }
    
    if (node->right) {
        huffman_table_build(table, node->right, (code << 1) | 1, length + 1);
    }
    
    if (!node->left && !node->right) {
        table->size++;
        table->bit_lengths = (unsigned int*) realloc(table->bit_lengths, sizeof(unsigned int) * table->size);
        table->codes = (unsigned int*) realloc(table->codes, sizeof(unsigned int) * table->size);
        
        table->bit_lengths[table->size - 1] = length;
        table->codes[table->size - 1] = code;
    }
}

// Function to encode data with Huffman coding
void huffman_encode(char* input, unsigned int input_size, char* output, unsigned int* output_size, struct HuffmanTable* table) {
    unsigned int output_capacity = *output_size;
    *output_size = 0;
    unsigned int code = 0;
    unsigned int length = 0;
    
    for (unsigned int i = 0; i < input_size; i++) {
        char c = input[i];
        
        for (unsigned int j = 0; j < table->size; j++) {
            if (table->bit_lengths[j] == 0) {
                continue;
            }
            
            if (table->codes[j] == c) {
                code |= (1 << length);
                length++;
                
                if (length >= 32) {
                    output[*output_size] = (char) (code >> 24);
                    output[*output_size + 1] = (char) (code >> 16);
                    output[*output_size + 2] = (char) (code >> 8);
                    output[*output_size + 3] = (char) (code >> 0);
                    *output_size += 4;
                    code = 0;
                    length = 0;
                    
                    if (*output_size + 4 > output_capacity) {
                        output_capacity *= 2;
                        output = (char*) realloc(output, output_capacity);
                    }
                }
            }
        }
    }
    
    if (length > 0) {
        code <<= (32 - length);
        output[*output_size] = (char) (code >> 24);
        output[*output_size + 1] = (char) (code >> 16);
        output[*output_size + 2] = (char) (code >> 8);
        output[*output_size + 3] = (char) (code >> 0);
        *output_size += 4;
    }
}

// Function to decode data with Huffman coding
void huffman_decode(char* input, unsigned int input_size, char* output, unsigned int* output_size, struct HuffmanNode* root) {
    struct HuffmanNode* node = root;
    
    for (unsigned int i = 0; i < input_size; i += 4) {
        unsigned int code = ((unsigned int) input[i] << 24) | ((unsigned int) input[i + 1] << 16) | ((unsigned int) input[i + 2] << 8) | ((unsigned int) input[i + 3] << 0);
        
        for (int j = 0; j < 32; j++) {
            if (code & (1 << (31 - j))) {
                node = node->right;
            } else {
                node = node->left;
            }
            
            if (!node->left && !node->right) {
                output[*output_size] = node->data;
                *output_size += 1;
                node = root;
            }
        }
    }
}

// Main function
int main() {
    // Initialize variables
    char input[] = "hello world";
    unsigned int input_size = strlen(input);
    char *output = (char*) malloc(input_size * 4);
    unsigned int output_size = input_size * 4;
    struct HuffmanTree* tree = new_huffman_tree();
    struct HuffmanTable* table = (struct HuffmanTable*) malloc(sizeof(struct HuffmanTable));
    table->size = 0;
    table->bit_lengths = NULL;
    table->codes = NULL;
    
    // Count the frequencies of each character
    unsigned int frequencies[256] = {0};
    
    for (unsigned int i = 0; i < input_size; i++) {
        frequencies[(unsigned int) input[i]]++;
    }
    
    // Create Huffman nodes for each character
    for (unsigned int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            huffman_tree_add_node(tree, new_huffman_node((char) i, frequencies[i]));
        }
    }
    
    // Build the Huffman tree and table
    huffman_tree_build(tree);
    huffman_table_build(table, tree->nodes[0], 0, 0);
    
    // Encode and decode the input
    huffman_encode(input, input_size, output, &output_size, table);
    char* decoded_output = (char*) malloc(input_size);
    unsigned int decoded_output_size = 0;
    huffman_decode(output, output_size, decoded_output, &decoded_output_size, tree->nodes[0]);
    
    // Print the results
    printf("Input: %s\n", input);
    printf("Encoded output:\n");
    
    for (unsigned int i = 0; i < output_size; i++) {
        printf("%02x", (unsigned char)(output[i]));
    }
    printf("\n");
    
    printf("Decoded output: %s\n", decoded_output);
    
    // Free the memory
    free(output);
    free(decoded_output);
    free(tree);
    free(table->bit_lengths);
    free(table->codes);
    free(table);
    
    return 0;
}