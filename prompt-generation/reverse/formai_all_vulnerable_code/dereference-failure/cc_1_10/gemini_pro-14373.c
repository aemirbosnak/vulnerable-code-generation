//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman tree
struct Node {
    char data;
    int freq;
    struct Node *left;
    struct Node *right;
};

// Comparator function for qsort()
int compare(const void *a, const void *b) {
    struct Node *n1 = (struct Node *)a;
    struct Node *n2 = (struct Node *)b;
    return n1->freq - n2->freq;
}

// Create a new node
struct Node *createNode(char data, int freq) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Build a Huffman tree
struct Node *buildTree(char data[], int freq[], int size) {
    struct Node *root, *left, *right;

    // Create a min heap of nodes
    struct Node *heap[size];
    for (int i = 0; i < size; i++) {
        heap[i] = createNode(data[i], freq[i]);
    }

    // Sort the min heap
    qsort(heap, size, sizeof(struct Node *), compare);

    // Build the Huffman tree
    while (size > 1) {
        // Extract the two minimum frequency nodes
        left = heap[0];
        heap[0] = heap[size - 1];
        size--;
        right = heap[0];
        heap[0] = heap[size - 1];
        size--;

        // Create a new node with the sum of the frequencies of the two nodes
        root = createNode('-', left->freq + right->freq);
        root->left = left;
        root->right = right;

        // Insert the new node into the heap
        heap[size] = root;
        size++;

        // Sort the heap
        qsort(heap, size, sizeof(struct Node *), compare);
    }

    // Return the root of the Huffman tree
    return heap[0];
}

// Print the Huffman codes
void printCodes(struct Node *root, char code[], int top) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->data, code);
        return;
    }

    // Traverse the left subtree
    code[top] = '0';
    printCodes(root->left, code, top + 1);

    // Traverse the right subtree
    code[top] = '1';
    printCodes(root->right, code, top + 1);
}

// Encode a string using the Huffman codes
char *encode(char data[], struct Node *root) {
    int size = strlen(data);
    char *encoded = (char *)malloc(size * sizeof(char));

    int top = 0;
    for (int i = 0; i < size; i++) {
        // Find the Huffman code for the character
        struct Node *node = root;
        while (node->left != NULL && node->right != NULL) {
            if (data[i] == node->left->data) {
                node = node->left;
                encoded[top++] = '0';
            } else {
                node = node->right;
                encoded[top++] = '1';
            }
        }
    }

    encoded[top] = '\0';
    return encoded;
}

// Decode a string using the Huffman codes
char *decode(char encoded[], struct Node *root) {
    int size = strlen(encoded);
    char *decoded = (char *)malloc(size * sizeof(char));

    int top = 0;
    struct Node *node = root;

    for (int i = 0; i < size; i++) {
        if (encoded[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }

        if (node->left == NULL && node->right == NULL) {
            decoded[top++] = node->data;
            node = root;
        }
    }

    decoded[top] = '\0';
    return decoded;
}

// Free the Huffman tree
void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    // Build the Huffman tree
    struct Node *root = buildTree(data, freq, size);

    // Print the Huffman codes
    char code[size];
    printCodes(root, code, 0);

    // Encode a string
    char *encoded = encode("abcdef", root);
    printf("Encoded string: %s\n", encoded);

    // Decode a string
    char *decoded = decode(encoded, root);
    printf("Decoded string: %s\n", decoded);

    // Free the Huffman tree
    freeTree(root);

    return 0;
}