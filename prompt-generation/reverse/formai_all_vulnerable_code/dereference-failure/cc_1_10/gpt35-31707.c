//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the character input
#define MAX_INPUT_LENGTH 1000

// Define the maximum number of characters possible
#define MAX_CHARACTERS 256

struct node {
    int weight;
    int is_leaf;
    struct node *left, *right;
};

// Create a new node
struct node *new_node(int weight, int is_leaf) {
    struct node *node = (struct node*) malloc(sizeof(struct node));

    // Set node values
    node->weight = weight;
    node->is_leaf = is_leaf;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Free the memory associated with the Huffman tree
void free_tree(struct node *node) {
    if (node == NULL) {
        return;
    }

    // Free the subtrees
    free_tree(node->left);
    free_tree(node->right);

    // Free the node itself
    free(node);
}

// Traverse the tree and create codes
void build_codes(char *code_array[], struct node *node, char *code) {
    if (node->is_leaf) {
        // Set the code in the code array
        code_array[node->weight] = strdup(code);
    } else {
        // Traverse the left subtree and update the code
        char *new_code = strdup(code);
        strcat(new_code, "0");
        build_codes(code_array, node->left, new_code);

        // Traverse the right subtree and update the code
        strcat(code, "1");
        build_codes(code_array, node->right, code);
    }
}

// Sort the list of nodes by weight
void sort_list(struct node *list[], int length) {
    // Bubble sort
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - 1 - i; j++) {
            if (list[j]->weight > list[j+1]->weight) {
                struct node *temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

// Build the Huffman tree
struct node *build_tree(int frequency_array[]) {
    // Create a list of nodes
    struct node *list[MAX_CHARACTERS];
    int i;
    for (i = 0; i < MAX_CHARACTERS; i++) {
        if (frequency_array[i] > 0) {
            list[i] = new_node(frequency_array[i], 1);
        } else {
            list[i] = NULL;
        }
    }

    // Sort the list in ascending order of weight
    int length = MAX_CHARACTERS;
    while (length > 1) {
        sort_list(list, length);

        // Combine the two smallest nodes into one
        struct node *new_node = (struct node*) malloc(sizeof(struct node));
        new_node->weight = list[0]->weight + list[1]->weight;
        new_node->is_leaf = 0;
        new_node->left = list[0];
        new_node->right = list[1];

        // Replace the two smallest nodes with the new node
        list[0] = new_node;
        list[1] = NULL;

        // Decrement the length
        length--;
    }

    return list[0];
}

// Display the codes for each character
void display_codes(char *code_array[]) {
    int i;
    for (i = 0; i < MAX_CHARACTERS; i++) {
        if (code_array[i] != NULL) {
            printf("%c: %s\n", (char) i, code_array[i]);
        }
    }
}

int main() {
    // Read the input string
    char input_string[MAX_INPUT_LENGTH];
    printf("Enter a string: ");
    fgets(input_string, MAX_INPUT_LENGTH, stdin);

    // Compute the frequency of each character
    int frequency_array[MAX_CHARACTERS] = { 0 };
    int i;
    for (i = 0; i < strlen(input_string); i++) {
        frequency_array[(int) input_string[i]]++;
    }

    // Build the Huffman tree
    struct node *huffman_tree = build_tree(frequency_array);

    // Build the codes for each character
    char *code_array[MAX_CHARACTERS] = { NULL };
    char code[MAX_CHARACTERS] = { 0 };
    build_codes(code_array, huffman_tree, code);

    // Display the codes
    printf("\nCodes:\n");
    display_codes(code_array);

    // Free the Huffman tree
    free_tree(huffman_tree);

    return 0;
}