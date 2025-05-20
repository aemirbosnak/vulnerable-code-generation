//FormAI DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1024

typedef struct frequency_node {
    char character;
    int frequency;
    struct frequency_node *left_child, *right_child;
} FNode;

typedef struct encoding_node {
    char character;
    char code[MAX_BUFFER_SIZE];
} ENode;

FNode *create_node(char character, int frequency) {
    FNode *new_node = (FNode *) malloc(sizeof(FNode));
    new_node->character = character;
    new_node->frequency = frequency;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

void swap_nodes(FNode **node_a, FNode **node_b) {
    FNode *temp = *node_a;
    *node_a = *node_b;
    *node_b = temp;
}

void sort_array(FNode **array, int array_size) {
    int i, j;
    for(i = 0; i < array_size - 1; i++) {
        for(j = i+1; j < array_size; j++) {
            if(array[i]->frequency > array[j]->frequency) {
                swap_nodes(&array[i], &array[j]);
            }
        }
    }
}

bool is_leaf(FNode *node) {
    return node->left_child == NULL && node->right_child == NULL;
}

void generate_encoding(FNode *node, char prefix[], int depth, ENode **encoding_table, int *encoding_table_size) {
    if(node->left_child) {
        prefix[depth] = '0';
        generate_encoding(node->left_child, prefix, depth + 1, encoding_table, encoding_table_size);
    }
    if(node->right_child) {
        prefix[depth] = '1';
        generate_encoding(node->right_child, prefix, depth + 1, encoding_table, encoding_table_size);
    }
    if(is_leaf(node)) {
        ENode *new_node = (ENode *) malloc(sizeof(ENode));
        new_node->character = node->character;
        strcpy(new_node->code, prefix);
        encoding_table[*encoding_table_size] = new_node;
        (*encoding_table_size)++;
    }
}

void compress_file(char *source_file, char *target_file) {
    // Open source file
    FILE *source_fp = fopen(source_file, "r");
    if(source_fp == NULL) {
        printf("Error opening source file!\n");
        exit(1);
    }

    // Calculate frequency of each character
    int frequency[256] = {0};
    char buffer[MAX_BUFFER_SIZE];
    int read_count;
    while((read_count = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, source_fp)) > 0) {
        for(int i = 0; i < read_count; i++) {
            frequency[(int) buffer[i]]++;
        }
    }

    // Create frequency nodes from frequency array
    FNode *nodes[256];
    int node_count = 0;
    for(int i = 0; i < 256; i++) {
        if(frequency[i] > 0) {
            nodes[node_count] = create_node((char) i, frequency[i]);
            node_count++;
        }
    }

    // Sort frequency nodes based on their frequency (ascending)
    sort_array(nodes, node_count);

    // Build Huffman tree based on sorted frequency nodes
    while(node_count > 1) {
        FNode *new_node = create_node('\0', nodes[0]->frequency + nodes[1]->frequency);
        new_node->left_child = nodes[0];
        new_node->right_child = nodes[1];
        nodes[0] = new_node;
        node_count--;
        for(int i = 1; i < node_count; i++) {
            nodes[i] = nodes[i+1];
        }
        // Sort the array after inserting new node
        sort_array(nodes, node_count);
    }

    // Generate encoding table from Huffman tree
    ENode *encoding_table[256];
    int encoding_table_size = 0;
    char prefix[MAX_BUFFER_SIZE] = {0};
    generate_encoding(nodes[0], prefix, 0, encoding_table, &encoding_table_size);

    // Open target file
    FILE *target_fp = fopen(target_file, "wb");
    if(target_fp == NULL) {
        printf("Error opening target file!\n");
        exit(1);
    }

    // Write encoding table to target file
    fwrite(&encoding_table_size, sizeof(int), 1, target_fp);
    for(int i = 0; i < encoding_table_size; i++) {
        fwrite(&encoding_table[i]->character, sizeof(char), 1, target_fp);
        fwrite(encoding_table[i]->code, sizeof(char), MAX_BUFFER_SIZE, target_fp);
    }

    // Move file pointer of source file to beginning
    fseek(source_fp, 0L, SEEK_SET);

    // Compress source file data and write it to target file
    int buffer_index = 0;
    char compressed_buffer[MAX_BUFFER_SIZE] = {0};
    while((read_count = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, source_fp)) > 0) {
        for(int i = 0; i < read_count; i++) {
            for(int j = 0; j < encoding_table_size; j++) {
                if(buffer[i] == encoding_table[j]->character) {
                    int code_length = strlen(encoding_table[j]->code);
                    for(int k = 0; k < code_length; k++) {
                        if(buffer_index == MAX_BUFFER_SIZE) {
                            fwrite(compressed_buffer, sizeof(char), MAX_BUFFER_SIZE, target_fp);
                            buffer_index = 0;
                            memset(compressed_buffer, 0, MAX_BUFFER_SIZE);
                        }
                        compressed_buffer[buffer_index] = encoding_table[j]->code[k];
                        buffer_index++;
                    }
                    break;
                }
            }
        }
    }

    // Write remaining data to target file
    if(buffer_index > 0) {
        fwrite(compressed_buffer, sizeof(char), buffer_index, target_fp);
    }

    // Close source and target files
    fclose(source_fp);
    fclose(target_fp);
}

void decompress_file(char *source_file, char *target_file) {
    // Open source file
    FILE *source_fp = fopen(source_file, "rb");
    if(source_fp == NULL) {
        printf("Error opening source file!\n");
        exit(1);
    }

    // Read encoding table from source file
    int encoding_table_size;
    fread(&encoding_table_size, sizeof(int), 1, source_fp);
    ENode *encoding_table[256];
    for(int i = 0; i < encoding_table_size; i++) {
        ENode *new_node = (ENode *) malloc(sizeof(ENode));
        fread(&new_node->character, sizeof(char), 1, source_fp);
        fread(new_node->code, sizeof(char), MAX_BUFFER_SIZE, source_fp);
        encoding_table[i] = new_node;
    }

    // Open target file
    FILE *target_fp = fopen(target_file, "wb");
    if(target_fp == NULL) {
        printf("Error opening target file!\n");
        exit(1);
    }

    // Decompress source file data and write it to target file
    int buffer_index = 0;
    char compressed_buffer[MAX_BUFFER_SIZE] = {0};
    int code_length;
    char code[MAX_BUFFER_SIZE];
    char decoded_character;
    while(fread(code, sizeof(char), MAX_BUFFER_SIZE, source_fp) > 0) {
        code_length = strlen(code);
        for(int i = 0; i < code_length; i++) {
            compressed_buffer[buffer_index] = code[i];
            buffer_index++;
            for(int j = 0; j < encoding_table_size; j++) {
                if(strncmp(compressed_buffer, encoding_table[j]->code, buffer_index) == 0) {
                    if(strlen(compressed_buffer) < strlen(encoding_table[j]->code)) {
                        // Continue reading compressed data until entire code is read
                        break;
                    }
                    decoded_character = encoding_table[j]->character;
                    fwrite(&decoded_character, sizeof(char), 1, target_fp);
                    // Reset the buffer index to read next code
                    buffer_index = 0;
                    memset(compressed_buffer, 0, MAX_BUFFER_SIZE);
                    break;
                }
            }
        }
    }

    // Close source and target files
    fclose(source_fp);
    fclose(target_fp);
}

int main() {
    char source_file[] = "source.txt";
    char compressed_file[] = "compressed.bin";
    char decompressed_file[] = "decompressed.txt";

    // Compress source file and write output to compressed file
    compress_file(source_file, compressed_file);

    // Decompress compressed file and write output to decompressed file
    decompress_file(compressed_file, decompressed_file);

    return 0;
}