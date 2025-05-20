//FormAI DATASET v1.0 Category: Image compression ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of Huffman codes
#define MAX_CODE_LENGTH 256

// Define Huffman tree node struct
typedef struct node_t {
    int freq;
    unsigned char symbol;
    struct node_t* left;
    struct node_t* right;
} node;

// Define Huffman code struct
typedef struct {
    unsigned char bits[MAX_CODE_LENGTH];
    int length;
} hcode;

// Define array to store frequency of each symbol
int frequencies[256] = { 0 };

// Define array to store each symbols' Huffman code
hcode codes[256];

// Function to count frequency of each symbol
void count_frequencies(FILE* input_file) {
    unsigned char buffer[1];
    while (fread(buffer, 1, 1, input_file) == 1) {
        frequencies[buffer[0]]++;
    }
}

// Function to create Huffman tree
node* create_huffman_tree() {
    // Initialize priority queue
    node** queue = (node**)malloc(sizeof(node*) * 256);
    int queue_size = 0;
    int i;
    for (i = 0; i < 256; i++) {
        if(frequencies[i] != 0) {
            node* new_node = (node*)malloc(sizeof(node));
            new_node->freq = frequencies[i];
            new_node->symbol = (unsigned char)i;
            new_node->left = NULL;
            new_node->right = NULL;
            queue[queue_size] = new_node;
            queue_size++;
        }
    }
    // Create Huffman tree from priority queue
    while (queue_size > 1) {
        // Remove two nodes with lowest frequency from queue
        node* first_node = queue[0];
        for (i = 1; i < queue_size; i++) {
            if (queue[i]->freq < first_node->freq) {
                first_node = queue[i];
            }
        }
        for (i = 0; i < queue_size; i++) {
            if (queue[i] == first_node) {
                queue[i] = queue[queue_size - 1];
                queue_size--;
                break;
            }
        }
        node* second_node = queue[0];
        for (i = 1; i < queue_size; i++) {
            if (queue[i]->freq < second_node->freq) {
                second_node = queue[i];
            }
        }
        for (i = 0; i < queue_size; i++) {
            if (queue[i] == second_node) {
                queue[i] = queue[queue_size - 1];
                queue_size--;
                break;
            }
        }
        // Create new node with sum of frequencies and add it to queue
        node* new_node = (node*)malloc(sizeof(node));
        new_node->freq = first_node->freq + second_node->freq;
        new_node->symbol = 0;
        new_node->left = first_node;
        new_node->right = second_node;
        queue[queue_size] = new_node;
        queue_size++;
    }
    free(queue);
    // Return root node of Huffman tree
    return queue[0];
}

// Function to generate Huffman codes for each symbol in tree
void generate_huffman_codes(node* root, unsigned char bits[], int length) {
    if (root->left == NULL && root->right == NULL) {
        memcpy(codes[root->symbol].bits, bits, length);
        codes[root->symbol].length = length;
        return;
    }
    bits[length] = 0;
    generate_huffman_codes(root->left, bits, length + 1);
    bits[length] = 1;
    generate_huffman_codes(root->right, bits, length + 1);
}

// Function to write Huffman codes and compressed data to output file
void write_compressed_data(FILE* input_file, FILE* output_file) {
    int i;
    // Write Huffman codes to output file
    for (i = 0; i < 256; i++) {
        fwrite(&codes[i].length, sizeof(int), 1, output_file);
        fwrite(&codes[i].bits, sizeof(unsigned char), codes[i].length, output_file);
    }
    // Write compressed data to output file
    unsigned char buffer[1];
    int buffer_index = 0;
    unsigned char compressed_buffer[8];
    int compressed_buffer_index = 0;
    int compressed_data_size = 0;
    while (fread(buffer, 1, 1, input_file) == 1) {
        hcode code = codes[buffer[0]];
        for (i = 0; i < code.length; i++) {
            compressed_buffer[compressed_buffer_index] = code.bits[i];
            compressed_buffer_index++;
            if (compressed_buffer_index == 8) {
                unsigned char compressed_byte = 0;
                int j;
                for (j = 0; j < 8; j++) {
                    if (compressed_buffer[j] == 1) {
                        compressed_byte |= (1 << (7 - j));
                    }
                }
                fwrite(&compressed_byte, sizeof(unsigned char), 1, output_file);
                compressed_buffer_index = 0;
                compressed_data_size++;
            }
        }
        buffer_index++;
    }
    if (compressed_buffer_index > 0) {
        unsigned char compressed_byte = 0;
        int j;
        for (j = 0; j < compressed_buffer_index; j++) {
            if (compressed_buffer[j] == 1) {
                compressed_byte |= (1 << (7 - j));
            }
        }
        fwrite(&compressed_byte, sizeof(unsigned char), 1, output_file);
        compressed_data_size++;
    }
    printf("Compressed data size: %d bytes\n", compressed_data_size);
}

int main(int argc, char const *argv[]) {
    // Read input and output file names from command line arguments
    if (argc != 3) {
        printf("Usage: ./compress input_file output_file\n");
        return 1;
    }
    const char* input_file_name = argv[1];
    const char* output_file_name = argv[2];
    // Open input file for reading
    FILE* input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Failed to open input file '%s'\n", input_file_name);
        return 1;
    }
    // Count frequency of each symbol in input file
    count_frequencies(input_file);
    // Create Huffman tree
    node* root = create_huffman_tree();
    // Generate Huffman codes for each symbol in Huffman tree
    unsigned char bits[MAX_CODE_LENGTH];
    generate_huffman_codes(root, bits, 0);
    // Close input file and open output file for writing
    fclose(input_file);
    FILE* output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Failed to open output file '%s'\n", output_file_name);
        return 1;
    }
    // Open input file again for reading
    input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Failed to open input file '%s'\n", input_file_name);
        return 1;
    }
    // Write Huffman codes and compressed data to output file
    write_compressed_data(input_file, output_file);
    // Close files and free memory used by Huffman tree
    fclose(input_file);
    fclose(output_file);
    return 0;
}