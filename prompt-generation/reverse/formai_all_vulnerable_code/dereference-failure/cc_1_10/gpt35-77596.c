//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman tree
struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
};

// Array of Node structures to store frequencies of characters in input file
struct Node* countFrequency(FILE* file_pointer, int* size) {
    struct Node* freq_list = (struct Node*) malloc(sizeof(struct Node) * 256);
    memset(freq_list, 0, sizeof(struct Node) * 256);
    unsigned char c;
    while (fread(&c, sizeof(unsigned char), 1, file_pointer)) {
        freq_list[c].character = c;
        freq_list[c].frequency += 1;
        *size += 1;
    }
    return freq_list;
}

// Comparator function for qsort to sort Nodes by frequency in increasing order
int cmpfunc(const void* a, const void* b) {
    struct Node* node_a = (struct Node*) a;
    struct Node* node_b = (struct Node*) b;
    return node_a->frequency - node_b->frequency;
}

// Create Huffman tree from frequency list
struct Node* createHuffmanTree(struct Node* freq_list) {
    struct Node* priority_queue[256];
    int front = 0, back = -1;
    for (int i = 0; i < 256; i++) {
        if (freq_list[i].frequency > 0) {
            struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
            new_node->character = freq_list[i].character;
            new_node->frequency = freq_list[i].frequency;
            new_node->left = NULL;
            new_node->right = NULL;
            priority_queue[++back] = new_node;
        }
    }
    while (back - front > 0) {
        struct Node* first = priority_queue[front++];
        struct Node* second = priority_queue[front++];
        struct Node* combined = (struct Node*) malloc(sizeof(struct Node));
        combined->character = '\0';
        combined->frequency = first->frequency + second->frequency;
        combined->left = first;
        combined->right = second;
        int insert_index = front;
        for (int i = front; i <= back; i++) {
            if (combined->frequency < priority_queue[i]->frequency) {
                insert_index = i;
                break;
            }
        }
        for (int i = back + 1; i > insert_index; i--) {
            priority_queue[i] = priority_queue[i - 1];
        }
        priority_queue[insert_index] = combined;
        back += 1;
    }
    return priority_queue[front];
}

// Create mapping between characters and their Huffman codes
void createCodeMap(char* code_map[], struct Node* node, char* code, int depth) {
    if (node == NULL) return;
    if (node->left == NULL && node->right == NULL) {
        code[depth] = '\0';
        code_map[node->character] = (char*) malloc(strlen(code) + 1);
        strncpy(code_map[node->character], code, strlen(code) + 1);
        return;
    }
    code[depth] = '0';
    createCodeMap(code_map, node->left, code, depth + 1);
    code[depth] = '1';
    createCodeMap(code_map, node->right, code, depth + 1);
}

// Write Huffman encoded data to output file
void writeEncodedData(FILE* input_file_pointer, FILE* output_file_pointer,
                      char* code_map[]) {
    unsigned char c, current_byte = 0;
    int current_bit = 0;
    while (fread(&c, sizeof(unsigned char), 1, input_file_pointer)) {
        char* code = code_map[c];
        for (int i = 0; i < strlen(code); i++) {
            if (current_bit == 8) {
                fwrite(&current_byte, sizeof(unsigned char), 1, output_file_pointer);
                current_byte = 0;
                current_bit = 0;
            }
            if (code[i] == '1') {
                current_byte |= (1 << current_bit);
            }
            current_bit += 1;
        }
    }
    if (current_bit > 0) {
        while (current_bit < 8) {
            current_byte <<= 1;
            current_bit += 1;
        }
        fwrite(&current_byte, sizeof(unsigned char), 1, output_file_pointer);
    }
}

// Main function to compress file
void compressFile(char* input_file_path, char* output_file_path) {
    FILE* input_file_pointer = fopen(input_file_path, "rb");
    if (input_file_pointer == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    FILE* output_file_pointer = fopen(output_file_path, "wb");
    if (output_file_pointer == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    int size = 0;
    struct Node* freq_list = countFrequency(input_file_pointer, &size);
    struct Node* huffman_tree_root = createHuffmanTree(freq_list);
    char* code_map[256];
    char code[256];
    memset(code, 0, sizeof(char) * 256);
    createCodeMap(code_map, huffman_tree_root, code, 0);
    fwrite(&size, sizeof(int), 1, output_file_pointer);
    fwrite(freq_list, sizeof(struct Node), 256, output_file_pointer);
    fseek(input_file_pointer, 0, SEEK_SET);
    writeEncodedData(input_file_pointer, output_file_pointer, code_map);
    fclose(input_file_pointer);
    fclose(output_file_pointer);
}

// Main function to decompress file
void decompressFile(char* input_file_path, char* output_file_path) {
    FILE* input_file_pointer = fopen(input_file_path, "rb");
    if (input_file_pointer == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    FILE* output_file_pointer = fopen(output_file_path, "wb");
    if (output_file_pointer == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    int size;
    fread(&size, sizeof(int), 1, input_file_pointer);
    struct Node freq_list[256];
    fread(freq_list, sizeof(struct Node), 256, input_file_pointer);
    struct Node* huffman_tree_root = createHuffmanTree(freq_list);
    unsigned char current_byte, c = '\0';
    int bit_index = 8;
    while (size > 0) {
        if (bit_index == 8) {
            fread(&current_byte, sizeof(unsigned char), 1, input_file_pointer);
            bit_index = 0;
        }
        if (current_byte & (1 << bit_index)) {
            huffman_tree_root = huffman_tree_root->right;
        } else {
            huffman_tree_root = huffman_tree_root->left;
        }
        if (huffman_tree_root->left == NULL && huffman_tree_root->right == NULL) {
            c = huffman_tree_root->character;
            fwrite(&c, sizeof(unsigned char), 1, output_file_pointer);
            huffman_tree_root = createHuffmanTree(freq_list);
            size -= 1;
        }
        bit_index += 1;
    }
    fclose(input_file_pointer);
    fclose(output_file_pointer);
}

int main() {
    char input_file_path[] = "input.txt";
    char compressed_file_path[] = "compressed.bin";
    char decompressed_file_path[] = "output.txt";
    compressFile(input_file_path, compressed_file_path);
    decompressFile(compressed_file_path, decompressed_file_path);
    return 0;
}