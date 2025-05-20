//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold the Huffman tree
typedef struct huffman_node {
    char symbol;                // The symbol for this node, '\0' if not a leaf node
    int frequency;              // The frequency of this symbol or sum of frequencies of subtrees
    struct huffman_node *left;  // Left child of the node
    struct huffman_node *right; // Right child of the node
} HuffmanNode;

// Struct to hold the Huffman table
typedef struct huffman_table {
    char symbol;           // The symbol of the code
    char *code;            // The code generated for this symbol
    struct huffman_table *next; // Pointer to the next entry in the table
} HuffmanTable;

// Allocates a new HuffmanNode with the given symbol and frequency
HuffmanNode *allocate_node(char symbol, int frequency) {
    HuffmanNode *new_node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    new_node->symbol = symbol;
    new_node->frequency = frequency;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Frees the memory allocated for a HuffmanNode
void free_node(HuffmanNode *node) {
    if (node == NULL) return;
    free_node(node->left);
    free_node(node->right);
    free(node);
}

// Computes the frequency table for the given input string
int *compute_frequency_table(char *input_string) {
    int *frequency_table = (int *)calloc(256, sizeof(int));
    for (int i = 0; i < strlen(input_string); i++) {
        frequency_table[(int)input_string[i]]++;
    }
    return frequency_table;
}

// Constructs the Huffman tree for the given frequency table
HuffmanNode *construct_huffman_tree(int *frequency_table) {
    // Create a min-priority queue of nodes
    int num_nodes = 0;
    for (int i = 0; i < 256; i++) {
        if (frequency_table[i] > 0) num_nodes++;
    }
    HuffmanNode **min_priority_queue = (HuffmanNode **)malloc(num_nodes * sizeof(HuffmanNode *));
    int queue_index = 0;
    for (int i = 0; i < 256; i++) {
        if (frequency_table[i] > 0) {
            min_priority_queue[queue_index++] = allocate_node(i, frequency_table[i]);
        }
    }

    // Build the Huffman tree
    while (queue_index > 1) {
        // Remove the two lowest frequency nodes from the queue
        HuffmanNode *left_child = min_priority_queue[0];
        HuffmanNode *right_child = min_priority_queue[1];
        memmove(min_priority_queue, min_priority_queue + 2, sizeof(HuffmanNode *) * (queue_index - 2));
        queue_index -= 2;

        // Create a new parent node and add it to the queue
        int parent_frequency = left_child->frequency + right_child->frequency;
        HuffmanNode *parent_node = allocate_node('\0', parent_frequency);
        parent_node->left = left_child;
        parent_node->right = right_child;
        min_priority_queue[queue_index++] = parent_node;

        // Sort the queue by increasing frequency
        int i = queue_index - 1;
        while (i > 0 && min_priority_queue[i]->frequency < min_priority_queue[i - 1]->frequency) {
            HuffmanNode *temp = min_priority_queue[i];
            min_priority_queue[i] = min_priority_queue[i - 1];
            min_priority_queue[i - 1] = temp;
            i--;
        }
    }

    // The last remaining node is the root of the Huffman tree
    HuffmanNode *root_node = min_priority_queue[0];

    // Free the memory allocated for the min-priority queue
    free(min_priority_queue);

    return root_node;
}

// Recursive function to generate the Huffman table
void generate_huffman_table_recursive(HuffmanNode *node, char *bitstring, int bitstring_length, HuffmanTable **table_tail) {
    // If this is a leaf node, add its code to the Huffman table
    if (node->symbol != '\0') {
        HuffmanTable *new_entry = (HuffmanTable *)malloc(sizeof(HuffmanTable));
        new_entry->symbol = node->symbol;
        new_entry->code = (char *)malloc((bitstring_length + 1) * sizeof(char));
        strcpy(new_entry->code, bitstring);
        new_entry->next = NULL;
        (*table_tail)->next = new_entry;
        *table_tail = new_entry;
        return;
    }

    // Else traverse the tree
    char left_bitstring[bitstring_length + 2], right_bitstring[bitstring_length + 2];
    strcpy(left_bitstring, bitstring);
    strcat(left_bitstring, "0");
    strcpy(right_bitstring, bitstring);
    strcat(right_bitstring, "1");
    generate_huffman_table_recursive(node->left, left_bitstring, bitstring_length + 1, table_tail);
    generate_huffman_table_recursive(node->right, right_bitstring, bitstring_length + 1, table_tail);
}

// Generates the Huffman table for the given Huffman tree
HuffmanTable *generate_huffman_table(HuffmanNode *root_node) {
    // Generate the Huffman table recursively
    HuffmanTable *table_head = (HuffmanTable *)malloc(sizeof(HuffmanTable));
    table_head->next = NULL;
    HuffmanTable *table_tail = table_head;
    generate_huffman_table_recursive(root_node, "", 0, &table_tail);

    // Return the head of the Huffman table
    return table_head;
}

// Encodes the input string using the given Huffman table
char *encode_string(char *input_string, HuffmanTable *huffman_table) {
    // Create an output buffer
    size_t output_buffer_size = 1024;
    char *output_buffer = (char *)malloc(output_buffer_size * sizeof(char));
    output_buffer[0] = '\0';

    // Loop through the input string and add the corresponding Huffman code to the output buffer
    for (int i = 0; i < strlen(input_string); i++) {
        HuffmanTable *current_entry = huffman_table->next;
        while (current_entry != NULL && current_entry->symbol != input_string[i]) {
            current_entry = current_entry->next;
        }
        if (current_entry == NULL) {
            printf("Error: could not find Huffman code for input symbol '%c'\n", input_string[i]);
            free(output_buffer);
            return NULL;
        }
        strcat(output_buffer, current_entry->code);
        if (strlen(output_buffer) + 32 > output_buffer_size) {
            output_buffer_size *= 2;
            output_buffer = (char *)realloc(output_buffer, output_buffer_size * sizeof(char));
        }
    }

    return output_buffer;
}

int main() {
    // Input string
    char *input_string = "hello world";

    // Compute the frequency table for the input string
    int *frequency_table = compute_frequency_table(input_string);

    // Construct the Huffman tree for the input string
    HuffmanNode *huffman_tree = construct_huffman_tree(frequency_table);

    // Generate the Huffman table for the Huffman tree
    HuffmanTable *huffman_table = generate_huffman_table(huffman_tree);

    // Encode the input string using the Huffman table
    char *encoded_string = encode_string(input_string, huffman_table);
    printf("Input string: %s\nEncoded string: %s\n", input_string, encoded_string);

    // Free the memory allocated for the frequency table and Huffman tree
    free(frequency_table);
    free_node(huffman_tree);

    // Free the memory allocated for the Huffman table
    HuffmanTable *current_entry = huffman_table->next;
    while (current_entry != NULL) {
        HuffmanTable *next_entry = current_entry->next;
        free(current_entry->code);
        free(current_entry);
        current_entry = next_entry;
    }
    free(huffman_table);

    // Free the memory allocated for the encoded string
    free(encoded_string);

    return 0;
}