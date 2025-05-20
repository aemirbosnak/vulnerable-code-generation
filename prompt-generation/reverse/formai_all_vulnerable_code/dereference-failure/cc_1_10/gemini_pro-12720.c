//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

// Node of the Huffman tree
struct node {
    int freq;
    char data;
    struct node *left, *right;
};

// Comparator for sorting the nodes by frequency
int cmp(const void *a, const void *b) {
    struct node *n1 = (struct node *)a;
    struct node *n2 = (struct node *)b;
    return n1->freq - n2->freq;
}

// Create a new node
struct node *create_node(int freq, char data) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->freq = freq;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Build the Huffman tree
struct node *build_tree(int *freq, int size) {
    struct node **nodes = (struct node **)malloc(sizeof(struct node *) * size);
    for (int i = 0; i < size; i++) {
        nodes[i] = create_node(freq[i], (char)i);
    }

    // Sort the nodes by frequency
    qsort(nodes, size, sizeof(struct node *), cmp);

    // Build the tree recursively
    while (size > 1) {
        // Extract the two nodes with the lowest frequencies
        struct node *n1 = nodes[0];
        struct node *n2 = nodes[1];

        // Create a new node with the sum of the frequencies of the two nodes
        struct node *parent = create_node(n1->freq + n2->freq, '\0');

        // Set the left and right children of the new node
        parent->left = n1;
        parent->right = n2;

        // Remove the two nodes from the array
        nodes[0] = nodes[size - 1];
        size--;

        // Sort the array again
        qsort(nodes, size, sizeof(struct node *), cmp);

        // Insert the new node into the array
        nodes[size - 1] = parent;
    }

    return nodes[0];
}

// Generate the code for each character
void generate_codes(struct node *root, char *code, int *top) {
    if (root == NULL) {
        return;
    }

    if (root->data != '\0') {
        // If it's a leaf node, store the code in the array
        code[*top] = '\0';
        printf("%c: %s\n", root->data, code);
        return;
    }

    // If it's not a leaf node, add 0 to the code and recurse on the left child
    code[*top] = '0';
    (*top)++;
    generate_codes(root->left, code, top);

    // Add 1 to the code and recurse on the right child
    code[*top] = '1';
    (*top)++;
    generate_codes(root->right, code, top);
}

// Encode the message using the Huffman code
char *encode(char *message, struct node *root) {
    int size = strlen(message);
    char *encoded = (char *)malloc(size * 8 + 1);
    int top = 0;

    for (int i = 0; i < size; i++) {
        struct node *curr = root;
        while (curr->data != message[i]) {
            if (curr->left != NULL && curr->data > message[i]) {
                curr = curr->left;
                encoded[top] = '0';
                top++;
            } else if (curr->right != NULL) {
                curr = curr->right;
                encoded[top] = '1';
                top++;
            }
        }
    }

    encoded[top] = '\0';
    return encoded;
}

// Decode the message using the Huffman code
char *decode(char *encoded, struct node *root) {
    int size = strlen(encoded);
    char *decoded = (char *)malloc(size + 1);
    struct node *curr = root;

    for (int i = 0; i < size; i++) {
        if (encoded[i] == '0') {
            curr = curr->left;
        } else if (encoded[i] == '1') {
            curr = curr->right;
        }

        if (curr->data != '\0') {
            decoded[i] = curr->data;
            curr = root;
        }
    }

    decoded[size] = '\0';
    return decoded;
}

int main() {
    // Input the frequencies of the characters
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(freq) / sizeof(freq[0]);

    // Build the Huffman tree
    struct node *root = build_tree(freq, size);

    // Generate the codes for each character
    char code[100];
    int top = 0;
    generate_codes(root, code, &top);

    // Encode the message
    char message[] = "this is a test message";
    char *encoded = encode(message, root);

    // Decode the message
    char *decoded = decode(encoded, root);

    // Print the encoded and decoded messages
    printf("Encoded message: %s\n", encoded);
    printf("Decoded message: %s\n", decoded);

    return 0;
}