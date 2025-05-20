//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the maximum length of input string
#define MAX_INPUT_LENGTH 100

// node structure for the Huffman tree
struct huff_node {
    char letter;
    int freq;
    struct huff_node *left;
    struct huff_node *right;
};

// function to create a new Huffman tree node
struct huff_node* create_node(char letter, int freq) {
    struct huff_node* tmp_node = (struct huff_node*)malloc(sizeof(struct huff_node));
    tmp_node->letter = letter;
    tmp_node->freq = freq;
    tmp_node->left = NULL;
    tmp_node->right = NULL;
    return tmp_node;
}

// function to find the two minimum frequency nodes in the input array
void find_min_nodes(int *min_index1, int *min_index2, struct huff_node **node_array, int num_nodes) {
    int i;
    int min_freq1 = -1, min_freq2 = -1;
    *min_index1 = -1, *min_index2 = -1;
    // loop through all the nodes to find two minimum frequency nodes
    for (i = 0; i < num_nodes; i++) {
        // if the node has not yet been processed and its frequency is less than the first minimum frequency found so far, update the first minimum frequency and index
        if (node_array[i] != NULL && node_array[i]->freq < min_freq1) {
            min_freq2 = min_freq1;
            *min_index2 = *min_index1;
            min_freq1 = node_array[i]->freq;
            *min_index1 = i;
        }
        // if the node has not yet been processed and its frequency is greater than or equal to the first minimum frequency found so far, but less than the second minimum frequency found so far, update the second minimum frequency and index
        else if (node_array[i] != NULL && node_array[i]->freq < min_freq2) {
            min_freq2 = node_array[i]->freq;
            *min_index2 = i;
        }
    }
}

// function to create a Huffman tree from the given input characters and their frequency
struct huff_node* create_huffman_tree(char *input, int *freq_array, int num_chars) {
    int i;
    // create an array of node pointers to store all the nodes of the Huffman tree
    struct huff_node **node_array = (struct huff_node**)malloc(num_chars * sizeof(struct huff_node*));
    // initialize the node array with all the input characters and their frequency as leaf nodes
    for (i = 0; i < num_chars; i++) {
        node_array[i] = create_node(input[i], freq_array[i]);
    }
    // loop until only one node is left in the node array, which will be the root node of the Huffman tree
    while (1) {
        int min_index1, min_index2;
        // find the two minimum frequency nodes in the node array
        find_min_nodes(&min_index1, &min_index2, node_array, num_chars);
        if (min_index2 == -1) {  // only one node left in the node array, which is the root node
            return node_array[min_index1];
        }
        // create a new node with the sum of the frequencies of the two minimum frequency nodes and set it as the parent of the two nodes
        struct huff_node *parent_node = create_node('\0', node_array[min_index1]->freq + node_array[min_index2]->freq);
        parent_node->left = node_array[min_index1];
        parent_node->right = node_array[min_index2];
        // set the processed nodes in the node array as NULL and place the new parent node in the array
        node_array[min_index1] = parent_node;
        node_array[min_index2] = NULL;
    }
}

// function to print the Huffman tree
void print_huffman_tree(struct huff_node *root, char *code, int depth) {
    if (root == NULL) {
        return;
    }
    if (root->letter != '\0') {
        printf("%c: %s\n", root->letter, code);
    }
    // add '0' to the code for left child and '1' for right child as we go deeper in the tree
    code[depth] = '0';
    print_huffman_tree(root->left, code, depth+1);
    code[depth] = '1';
    print_huffman_tree(root->right, code, depth+1);
}

int main() {
    char input_string[MAX_INPUT_LENGTH];
    printf("Enter the string: ");
    fgets(input_string, MAX_INPUT_LENGTH, stdin);
    int i, j;
    int freq_array[256] = {0};  // create an array of 256 integers to store the frequency of each character
    int num_chars = strlen(input_string) - 1;  // calculate the number of characters in the input string (excluding the newline character)
    char unique_chars[num_chars];  // create an array to store the unique characters in the input string
    int num_unique_chars = 0;  // initialize the number of unique characters to 0
    // loop through all characters in the input string to find the frequency of each character and the number of unique characters
    for (i = 0; i < num_chars; i++) {
        if (!strchr(unique_chars, input_string[i])) {  // if the current character is not in the array of unique characters, add it to the array and increment the number of unique characters
            unique_chars[num_unique_chars++] = input_string[i];
        }
        freq_array[input_string[i]]++;  // increment the frequency of the current character
    }
    // create a Huffman tree from the unique characters and their frequency
    struct huff_node *huff_tree = create_huffman_tree(unique_chars, freq_array, num_unique_chars);
    char code[256];
    printf("Huffman codes:\n");
    print_huffman_tree(huff_tree, code, 0);
    return 0;
}