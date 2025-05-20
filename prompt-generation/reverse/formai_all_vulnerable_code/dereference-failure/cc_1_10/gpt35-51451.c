//FormAI DATASET v1.0 Category: Image compression ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUES 256

// Define the Huffman tree node
typedef struct huff_node {
    unsigned char pixel;
    int freq;
    struct huff_node* left;
    struct huff_node* right;
} huff_node;

// Initialize the Huffman tree node
huff_node* init_node(unsigned char pixel, int freq) {
    huff_node* node = (huff_node*)malloc(sizeof(huff_node));
    node->pixel = pixel;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define the Huffman tree
typedef struct huff_tree {
    huff_node* root;
} huff_tree;

// Initialize the Huffman tree
huff_tree* init_tree() {
    huff_tree* tree = (huff_tree*)malloc(sizeof(huff_tree));
    tree->root = NULL;
    return tree;
}

// Insert a node in the Huffman tree
void insert_node(huff_node** nodes, int* size, huff_node* node) {
    int i;
    for (i = (*size)++; (i > 0) && (node->freq < nodes[i - 1]->freq); i--)
        nodes[i] = nodes[i - 1];
    nodes[i] = node;
}

// Construct the Huffman tree
huff_node* construct_tree(int* freq) {
    huff_node* nodes[MAX_PIXEL_VALUES];
    huff_node* node;
    huff_node* left;
    huff_node* right;
    int size = 0;
    int i;

    // Initialize the leaf nodes
    for (i = 0; i < MAX_PIXEL_VALUES; i++) {
        if (freq[i] > 0) {
            node = init_node(i, freq[i]);
            insert_node(nodes, &size, node);
        }
    }

    // Construct the Huffman tree
    while (size > 1) {
        left = nodes[--size];
        right = nodes[--size];
        node = init_node(0, left->freq + right->freq);
        node->left = left;
        node->right = right;
        insert_node(nodes, &size, node);
    }

    // Return the root node of the Huffman tree
    return nodes[0];
}

// Generate the lookup table
void generate_table(huff_node* node, unsigned int code, int len, unsigned int* table) {
    if (node->left == NULL && node->right == NULL) {
        table[node->pixel] = (code << (32 - len)) | len;
    }
    else {
        generate_table(node->left, code << 1, len + 1, table);
        generate_table(node->right, (code << 1) | 1, len + 1, table);
    }
}

// Compress the image file
void compress(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");
    int freq[MAX_PIXEL_VALUES] = { 0 };
    unsigned char pixel;
    unsigned int code;
    int len;
    huff_node* root;
    unsigned int table[MAX_PIXEL_VALUES] = { 0 };
    int i;

    // Count the frequency of occurrence of each pixel value
    while (fread(&pixel, 1, 1, input)) {
        freq[pixel]++;
    }

    // Construct the Huffman tree
    root = construct_tree(freq);

    // Generate the lookup table
    generate_table(root, 0, 0, table);

    // Write the Huffman coding tree parameters to the output file
    fwrite(freq, sizeof(int), MAX_PIXEL_VALUES, output);

    // Write the compressed image data to the output file
    fseek(input, 0, SEEK_SET);
    code = 0;
    len = 0;
    while (fread(&pixel, 1, 1, input)) {
        code |= table[pixel] >> len;
        len += (table[pixel] & 0xff);
        while (len >= 8) {
            fputc(code >> 24, output);
            code <<= 8;
            len -= 8;
        }
    }
    if (len > 0) {
        fputc(code >> 24, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Decompress the image file
void decompress(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");
    int freq[MAX_PIXEL_VALUES];
    unsigned char pixel;
    unsigned int code = 0;
    int len = 0;
    int i;

    // Read the Huffman coding tree parameters from the input file
    fread(freq, sizeof(int), MAX_PIXEL_VALUES, input);

    // Construct the Huffman tree
    huff_node* root = construct_tree(freq);

    // Decompress the image data and write it to the output file
    huff_node* node = root;
    while ((pixel = fgetc(input)) != EOF) {
        code |= ((unsigned int)pixel) << (24 - len);
        len += 8;
        while (len >= node->freq) {
            if (node->left == NULL && node->right == NULL) {
                fputc(node->pixel, output);
                node = root;
            }
            else {
                node = (code & (1 << 31)) ? node->right : node->left;
                code <<= 1;
                len--;
            }
        }
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

int main() {
    // Compress the image file
    compress("lena.bmp", "lena.bin");

    // Decompress the image file
    decompress("lena.bin", "lena_new.bmp");

    return 0;
}