//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of characters to encode
#define MAX_CHARS 256

// Struct to hold a Huffman node
struct huffman_node {
    char letter;
    int freq;
    struct huffman_node *left;
    struct huffman_node *right;
};

// Struct to hold a Huffman tree
struct huffman_tree {
    struct huffman_node *root;
};

// Struct to hold a Huffman code
struct huffman_code {
    char letter;
    char *code;
};

// Function prototypes
void print_codes(struct huffman_code codes[], int num_codes);
void build_code_table(struct huffman_node *node, char *code, int depth, struct huffman_code codes[], int *index);
void huffman_encode(struct huffman_tree *tree, char *input, char *output);
void huffman_decode(struct huffman_tree *tree, char *input, char *output);

// Main function
int main() {
    char text[] = "this is an example of huffman encoding";
    int freq[MAX_CHARS] = {0};
    
    // Count the frequency of each character in the text
    for (int i = 0; text[i] != '\0'; i++) {
        freq[(int)text[i]]++;
    }
    
    // Create a Huffman tree from the frequency table
    int num_nodes = 0;
    struct huffman_node *nodes[MAX_CHARS];
    for (int i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0) {
            nodes[num_nodes] = malloc(sizeof(struct huffman_node));
            nodes[num_nodes]->letter = (char)i;
            nodes[num_nodes]->freq = freq[i];
            nodes[num_nodes]->left = NULL;
            nodes[num_nodes]->right = NULL;
            num_nodes++;
        }
    }
    while (num_nodes > 1) {
        int min_index1 = 0;
        int min_index2 = 1;
        if (nodes[min_index2]->freq < nodes[min_index1]->freq) {
            min_index1 = 1;
            min_index2 = 0;
        }
        for (int i = 2; i < num_nodes; i++) {
            if (nodes[i]->freq < nodes[min_index1]->freq) {
                min_index2 = min_index1;
                min_index1 = i;
            } else if (nodes[i]->freq < nodes[min_index2]->freq) {
                min_index2 = i;
            }
        }
        struct huffman_node *new_node = malloc(sizeof(struct huffman_node));
        new_node->letter = '\0';
        new_node->freq = nodes[min_index1]->freq + nodes[min_index2]->freq;
        new_node->left = nodes[min_index1];
        new_node->right = nodes[min_index2];
        nodes[min_index1] = new_node;
        nodes[min_index2] = nodes[num_nodes-1];
        num_nodes--;
    }
    struct huffman_tree *tree = malloc(sizeof(struct huffman_tree));
    tree->root = nodes[0];
    
    // Build a table of Huffman codes for each character
    struct huffman_code codes[MAX_CHARS];
    int code_index = 0;
    build_code_table(tree->root, "", 0, codes, &code_index);
    
    // Print the Huffman codes
    printf("Huffman codes:\n");
    print_codes(codes, code_index);
    
    // Encode the text using Huffman coding
    char encoded_text[1000] = "";
    huffman_encode(tree, text, encoded_text);
    printf("Encoded text: %s\n", encoded_text);
    
    // Decode the encoded text using the Huffman tree
    char decoded_text[1000] = "";
    huffman_decode(tree, encoded_text, decoded_text);
    printf("Decoded text: %s\n", decoded_text);
    
    return 0;
}

// Recursive function to build a table of Huffman codes based on a Huffman tree
void build_code_table(struct huffman_node *node, char *code, int depth, struct huffman_code codes[], int *index) {
    if (node->left == NULL && node->right == NULL) {
        struct huffman_code hc = { node->letter, code };
        codes[(*index)++] = hc;
    } else {
        char left_code[100] = "";
        char right_code[100] = "";
        sprintf(left_code, "%s%d", code, 0);
        sprintf(right_code, "%s%d", code, 1);
        build_code_table(node->left, left_code, depth+1, codes, index);
        build_code_table(node->right, right_code, depth+1, codes, index);
    }
}

// Helper function to print an array of Huffman codes
void print_codes(struct huffman_code codes[], int num_codes) {
    for (int i = 0; i < num_codes; i++) {
        printf("%c: %s\n", codes[i].letter, codes[i].code);
    }
}

// Function to encode text using a Huffman tree
void huffman_encode(struct huffman_tree *tree, char *input, char *output) {
    int output_index = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        struct huffman_node *node = tree->root;
        while (node->left != NULL && node->right != NULL) {
            if (input[i] == node->left->letter) {
                output[output_index] = '0';
                node = node->left;
            } else {
                output[output_index] = '1';
                node = node->right;
            }
            output_index++;
        }
    }
    output[output_index] = '\0';
}

// Function to decode text using a Huffman tree
void huffman_decode(struct huffman_tree *tree, char *input, char *output) {
    int output_index = 0;
    struct huffman_node *node = tree->root;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }
        if (node->left == NULL && node->right == NULL) {
            output[output_index] = node->letter;
            output_index++;
            node = tree->root;
        }
    }
    output[output_index] = '\0';
}