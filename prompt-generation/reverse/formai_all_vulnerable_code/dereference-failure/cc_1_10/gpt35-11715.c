//FormAI DATASET v1.0 Category: Compression algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 1024

// A structure that holds the information for each compressed symbol
typedef struct symbol_info {
    char compressed;
    int frequency;
} symbol_info;

// A structure that holds the information for each node in the huffman tree
typedef struct node {
    char symbol;
    int frequency;
    struct node *left_child;
    struct node *right_child;
} node;

// A structure that holds the compressed data and its length
typedef struct compressed_data {
    char *data;
    int length;
} compressed_data;

// A function to count the frequency of each symbol in the given message
void count_frequency(char *message, symbol_info *symbols, int *num_symbols) {
    int i = 0, j;
    bool found;
    *num_symbols = 0;
    while (message[i]) {
        found = false;
        for (j = 0; j < *num_symbols; j++) {
            if (symbols[j].compressed == message[i]) {
                found = true;
                symbols[j].frequency ++;
                break;
            }
        }
        if (!found) {
            symbols[*num_symbols].compressed = message[i];
            symbols[*num_symbols].frequency = 1;
            (*num_symbols) ++;
        }
        i++;
    }
}

// A function to sort the symbols array according to the symbols' frequency
void sort_symbols(symbol_info *symbols, int num_symbols) {
    int i, j;
    symbol_info temp;
    for (i = 0; i < num_symbols - 1; i++) {
        for (j = i + 1; j < num_symbols; j++) {
            if (symbols[i].frequency > symbols[j].frequency) {
                temp = symbols[i];
                symbols[i] = symbols[j];
                symbols[j] = temp;
            }
        }
    }
}

// A function to create a huffman tree using the sorted symbols array
node *create_huffman_tree(symbol_info *symbols, int num_symbols) {
    int i, j;
    node *root = NULL, *left_child, *right_child, *new_node;
    while (num_symbols > 1) {
        left_child = (node*) malloc(sizeof(node));
        left_child->frequency = symbols[0].frequency;
        left_child->symbol = symbols[0].compressed;
        left_child->left_child = NULL;
        left_child->right_child = NULL;
        
        right_child = (node*) malloc(sizeof(node));
        right_child->frequency = symbols[1].frequency;
        right_child->symbol = symbols[1].compressed;
        right_child->left_child = NULL;
        right_child->right_child = NULL;
        
        new_node = (node*) malloc(sizeof(node));
        new_node->frequency = left_child->frequency + right_child->frequency;
        new_node->symbol = '\0';
        new_node->left_child = left_child;
        new_node->right_child = right_child;
        
        i = 2;
        while (i < num_symbols && new_node->frequency > symbols[i].frequency) {
            symbols[i - 2] = symbols[i];
            i ++;
        }
        symbols[i - 2] = (symbol_info) { '\0', new_node->frequency };
        num_symbols --;
        for (j = num_symbols - 1; j >= i - 1; j--) {
            symbols[j + 1] = symbols[j];
        }
        symbols[i - 1] = (symbol_info) { '\0', new_node->frequency };
        num_symbols --;
        for (j = num_symbols - 1; j >= i - 2; j--) {
            symbols[j + 1] = symbols[j];
        }
        symbols[i - 2] = (symbol_info) { '\0', new_node->frequency };
        num_symbols ++;
        
        root = new_node;
    }
    return root;
}

// A function to generate the compressed code for each symbol using the huffman tree
void generate_compressed_codes(node *root, char *current_code, symbol_info *symbols, int depth) {
    if (!root) {
        return;
    }
    if (!root->left_child && !root->right_child) {
        int i;
        for (i = 0; i < 256; i++) {
            if (symbols[i].compressed == root->symbol) {
                symbols[i].frequency = depth;
                sprintf(symbols[i].compressed, "%s", current_code);
                break;
            }
        }
    }
    else {
        char *left_code = (char*) malloc(sizeof(char) * (depth + 1));
        sprintf(left_code, "%s%c", current_code, '0');
        generate_compressed_codes(root->left_child, left_code, symbols, depth + 1);
        char *right_code = (char*) malloc(sizeof(char) * (depth + 1));
        sprintf(right_code, "%s%c", current_code, '1');
        generate_compressed_codes(root->right_child, right_code, symbols, depth + 1);
    }
}

// A function to compress a message using the generated compressed codes
compressed_data compress_data(char *message, symbol_info *symbols) {
    int i, j, len_message = strlen(message);
    char *compressed = (char*) malloc(sizeof(char) * MAX_SIZE);
    int compressed_index = 0;
    for (i = 0; i < len_message; i++) {
        for (j = 0; j < 256; j++) {
            if (symbols[j].compressed == message[i]) {
                sprintf(&compressed[compressed_index], "%s", symbols[j].compressed);
                compressed_index += symbols[j].frequency;
                break;
            }
        }
    }
    compressed_data result = { compressed, compressed_index };
    return result;
}

// A function to decompress the compressed code using the huffman tree
void decompress_data(char *compressed, int len_compressed, node *root) {
    int i = 0;
    node *current_node = root;
    while (i < len_compressed) {
        if (!current_node->left_child && !current_node->right_child) {
            printf("%c", current_node->symbol);
            current_node = root;
        }
        else {
            if (compressed[i] == '0') {
                current_node = current_node->left_child;
            }
            else {
                current_node = current_node->right_child;
            }
            i++;
        }
    }
    printf("\n");
}

// The main function
int main() {
    char message[MAX_SIZE], *compressed;
    symbol_info symbols[256];
    int num_symbols, i, j, choice;
    node *root;
    compressed_data compressed_data;
    printf("Enter the message to compress: ");
    scanf("%[^\n]%*c", message);
    count_frequency(message, symbols, &num_symbols);
    sort_symbols(symbols, num_symbols);
    root = create_huffman_tree(symbols, num_symbols);
    generate_compressed_codes(root, "", symbols, 0);
    compressed_data = compress_data(message, symbols);
    printf("Compressed Data: %s\n", compressed_data.data);
    printf("Decompressed Data: ");
    decompress_data(compressed_data.data, compressed_data.length, root);
    return 0;
}