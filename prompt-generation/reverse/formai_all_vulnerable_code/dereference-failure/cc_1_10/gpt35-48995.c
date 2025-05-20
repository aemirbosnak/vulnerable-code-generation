//FormAI DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000 // Maximum length of input string
#define MAX_CODE_SIZE 1000 // Maximum size of compressed code
#define CODE_LEN 6 // Length of compressed code
#define NUM_CHARS 256 // Number of possible characters


// Node structure for binary tree used in Huffman encoding
struct huff_node {
    int freq;
    unsigned char c;
    struct huff_node* left;
    struct huff_node* right;
};

// Structure to hold code for each character in input string
struct code {
    unsigned char c;
    char* c_str;
};

// Function to calculate frequency of each character in input string
int* calc_freq(char* str) {
    int* freq_arr = (int*) calloc(NUM_CHARS, sizeof(int));
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        freq_arr[(int)str[i]]++;
    }

    return freq_arr;
}

// Function to initialize node for binary tree
struct huff_node* init_node(unsigned char c, int freq) {
    struct huff_node* node = (struct huff_node*) malloc(sizeof(struct huff_node));
    node->c = c;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to compare two nodes based on their frequency
int cmp_freq(const void* a, const void* b) {
    struct huff_node** pa = (struct huff_node**)a;
    struct huff_node** pb = (struct huff_node**)b;

    return ((*pa)->freq) - ((*pb)->freq);
}

// Function to build Huffman binary tree
struct huff_node* build_huff_tree(int* freq_arr) {
    struct huff_node** heap = (struct huff_node**) malloc(NUM_CHARS * sizeof(struct huff_node*));
    int heap_size = 0;

    for (int i = 0; i < NUM_CHARS; i++) {
        if (freq_arr[i] > 0) {
            heap[heap_size++] = init_node(i, freq_arr[i]);
        }
    }

    while (heap_size > 1) {
        qsort(heap, heap_size, sizeof(struct huff_node*), cmp_freq);
        struct huff_node* node1 = heap[0];
        struct huff_node* node2 = heap[1];
        int freq_sum = node1->freq + node2->freq;
        struct huff_node* new_node = init_node('\0', freq_sum);

        new_node->left = node1;
        new_node->right = node2;

        heap[0] = new_node;
        heap[1] = heap[--heap_size];
    }

    free(heap);
    return heap[0];
}

// Recursive function to generate code for each character in binary tree
void gen_codes(struct huff_node* node, char* str, int depth, struct code* code_arr) {
    if (node == NULL) {
        return;
    }

    if (node->left == NULL && node->right == NULL) {
        for (int i = 0; i < depth; i++) {
            code_arr[(int)node->c].c_str[i] = str[i];
        }
        code_arr[(int)node->c].c_str[depth] = '\0';
        return;
    }

    str[depth] = '0';
    gen_codes(node->left, str, depth + 1, code_arr);

    str[depth] = '1';
    gen_codes(node->right, str, depth + 1, code_arr);
}

// Function to compress input string using Huffman encoding
char* huff_encode(char* str, struct code* code_arr) {
    int len = strlen(str);
    char* compressed_str = (char*) malloc(MAX_CODE_SIZE * sizeof(char));
    compressed_str[0] = '\0';

    for (int i = 0; i < len; i++) {
        strcat(compressed_str, code_arr[(int)str[i]].c_str);
    }

    return compressed_str;
}

// Function to decompress Huffman encoded binary string
char* huff_decode(char* bin_str, struct huff_node* root) {
    int len = strlen(bin_str);
    char* decompressed_str = (char*) malloc(MAX_LEN * sizeof(char));
    struct huff_node* node = root;

    for (int i = 0; i < len; i++) {
        if (bin_str[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }

        if (node->left == NULL && node->right == NULL) {
            decompressed_str[i] = node->c;
            node = root;
        }
    }

    decompressed_str[len] = '\0';
    return decompressed_str;
}

int main() {
    char input_str[MAX_LEN];
    printf("Enter input string: ");
    scanf("%[^\n]%*c", input_str);

    int* freq_arr = calc_freq(input_str);
    struct huff_node* root = build_huff_tree(freq_arr);
    struct code code_arr[NUM_CHARS];
    for (int i = 0; i < NUM_CHARS; i++) {
        code_arr[i].c = (unsigned char) i;
        code_arr[i].c_str = (char*) malloc(CODE_LEN * sizeof(char));
    }
    char str[CODE_LEN];
    gen_codes(root, str, 0, code_arr);

    char* compressed_str = huff_encode(input_str, code_arr);
    printf("Compressed string: %s\n", compressed_str);

    char* decompressed_str = huff_decode(compressed_str, root);
    printf("Decompressed string: %s\n", decompressed_str);

    for (int i = 0; i < NUM_CHARS; i++) {
        free(code_arr[i].c_str);
    }
    free(freq_arr);
    free(root);
    free(compressed_str);
    free(decompressed_str);

    return 0;
}