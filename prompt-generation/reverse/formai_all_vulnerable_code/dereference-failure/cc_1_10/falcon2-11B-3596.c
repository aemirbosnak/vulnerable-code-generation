//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure to hold the Huffman tree nodes
typedef struct {
    int freq;
    char symbol;
    struct Node *left, *right;
} Node;

// Define a helper function to print the Huffman tree
void print_tree(Node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%c: %d\n", root->symbol, root->freq);
    print_tree(root->right);
}

// Define a function to compress a string using the Huffman tree
char *compress_string(char *input) {
    Node *root = NULL;
    int freqs[256] = {0};
    
    // Count the frequency of each character in the input string
    for (int i = 0; input[i]!= '\0'; i++) {
        freqs[input[i]]++;
    }
    
    // Build the Huffman tree
    for (int i = 0; i < 256; i++) {
        if (freqs[i] == 0) {
            continue;
        }
        Node *new_node = malloc(sizeof(Node));
        new_node->freq = freqs[i];
        new_node->symbol = i;
        new_node->left = NULL;
        new_node->right = NULL;
        if (root == NULL) {
            root = new_node;
        } else {
            Node *curr = root;
            while (curr->left!= NULL && curr->right!= NULL) {
                curr = curr->right;
            }
            if (curr->left == NULL) {
                curr->left = new_node;
            } else {
                curr->right = new_node;
            }
        }
    }
    
    // Traverse the Huffman tree to generate the compressed string
    Node *curr = root;
    char *compressed = (char *)malloc(strlen(input) + 1);
    int pos = 0;
    while (curr!= NULL) {
        if (curr->symbol == 0) {
            break;
        }
        compressed[pos++] = curr->symbol;
        curr = curr->left;
    }
    
    // Reverse the compressed string to get the original string
    compressed[pos] = '\0';
    int len = strlen(compressed);
    int prev = 0;
    for (int i = 0; i < len; i++) {
        if (compressed[i]!= compressed[prev]) {
            prev = i;
        }
    }
    compressed[len - prev - 1] = '\0';
    return compressed;
}

int main() {
    char input[] = "hello world";
    char *compressed = compress_string(input);
    printf("Original string: %s\n", input);
    printf("Compressed string: %s\n", compressed);
    free(compressed);
    return 0;
}