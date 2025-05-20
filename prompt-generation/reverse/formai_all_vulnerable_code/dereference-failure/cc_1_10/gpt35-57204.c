//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for nodes in the Huffman tree
typedef struct huff_node_t {
    char value;
    int frequency;
    struct huff_node_t* left;
    struct huff_node_t* right;
} huff_node;

// Define a structure for the Huffman tree
typedef struct huff_tree_t {
    huff_node* root;
} huff_tree;

// Define a function to create a new Huffman tree node
huff_node* new_huff_node(char value, int frequency) {
    huff_node* node = (huff_node*) malloc(sizeof(huff_node));
    node->value = value;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define a function to compare two nodes based on frequency
int compare_nodes(const void* a, const void* b) {
    huff_node* node_a = *(huff_node**)a;
    huff_node* node_b = *(huff_node**)b;
    return (node_a->frequency - node_b->frequency);
}

// Define a function to build a Huffman tree from the provided character frequency table
huff_tree* build_huff_tree(int frequencies[]) {
    // Create an array of Huffman tree nodes representing each character
    huff_node* nodes[256];
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            nodes[i] = new_huff_node((char)i, frequencies[i]);
        } else {
            nodes[i] = NULL;
        }
    }

    // Sort the nodes by frequency
    qsort(nodes, 256, sizeof(huff_node*), compare_nodes);

    // Build the Huffman tree from the sorted nodes
    while (1) {
        // Find the smallest frequency node that hasn't been added to the tree yet
        huff_node* min_node = NULL;
        for (int i = 0; i < 256; i++) {
            if (nodes[i] != NULL) {
                min_node = nodes[i];
                nodes[i] = NULL;
                break;
            }
        }
        if (min_node == NULL) {
            break;
        }

        // Find the next smallest frequency node that hasn't been added to the tree yet
        huff_node* next_node = NULL;
        for (int i = 0; i < 256; i++) {
            if (nodes[i] != NULL) {
                next_node = nodes[i];
                nodes[i] = NULL;
                break;
            }
        }

        // Combine the two smallest nodes into a single parent node
        huff_node* parent_node = new_huff_node('\0', min_node->frequency + next_node->frequency);
        parent_node->left = min_node;
        parent_node->right = next_node;

        // Add the parent node back into the sorted node array
        nodes[parent_node->value] = parent_node;
    }

    // Create a new Huffman tree from the final parent node
    huff_tree* tree = (huff_tree*) malloc(sizeof(huff_tree));
    tree->root = nodes[0];

    return tree;
}

// Define a function to recursively traverse the Huffman tree and encode each character
void encode_helper(huff_node* node, int depth, char* encoding_table[]) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        // Found a leaf node, create an encoding string for the character
        char* encoding = (char*) malloc(depth + 1);
        for (int i = 0; i < depth; i++) {
            encoding[i] = encoding_table[i][0];
        }
        encoding[depth] = '\0';
        encoding_table[node->value] = encoding;
    } else {
        // Traverse the left and right subtrees, appending a 0 to the encoding if we go left and a 1 if we go right
        char left_encoding[2] = "0";
        char right_encoding[2] = "1";
        int left_depth = depth + 1;
        int right_depth = depth + 1;
        encode_helper(node->left, left_depth, encoding_table);
        encode_helper(node->right, right_depth, encoding_table);
        if (node->left != NULL) {
            strcat(encoding_table[node->value], left_encoding);
        }
        if (node->right != NULL) {
            strcat(encoding_table[node->value], right_encoding);
        }
    }
}

// Define a function to encode a string using the provided Huffman tree and encoding table
char* encode_string(huff_tree* tree, char* input_string, char* encoding_table[]) {
    // Create a buffer to hold the encoded string
    int input_length = strlen(input_string);
    int max_output_length = input_length * 8;
    char* encoded_string = (char*) malloc(max_output_length + 1);
    encoded_string[0] = '\0';

    // Encode each character in the input string using the Huffman tree and encoding table
    for (int i = 0; i < input_length; i++) {
        strcat(encoded_string, encoding_table[input_string[i]]);
    }

    return encoded_string;
}

int main() {
    // Define a sample input string and create a character frequency table for it
    char* input_string = "hello world";
    int frequencies[256] = {0};
    int input_length = strlen(input_string);
    for (int i = 0; i < input_length; i++) {
        frequencies[input_string[i]]++;
    }

    // Build a Huffman tree from the character frequency table and create an encoding table for it
    huff_tree* tree = build_huff_tree(frequencies);
    char* encoding_table[256];
    for (int i = 0; i < 256; i++) {
        encoding_table[i] = NULL;
    }
    encode_helper(tree->root, 0, encoding_table);

    // Encode the input string using the Huffman tree and encoding table and print the result
    char* encoded_string = encode_string(tree, input_string, encoding_table);
    printf("Input string: %s\n", input_string);
    printf("Encoded string: %s\n", encoded_string);

    // Clean up the memory used by the Huffman tree and encoding table
    free(encoded_string);
    for (int i = 0; i < 256; i++) {
        if (encoding_table[i] != NULL) {
            free(encoding_table[i]);
        }
    }
    free(tree->root);
    free(tree);

    return 0;
}