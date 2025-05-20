//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure to hold the character and its frequency
struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char character, int frequency) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to compare two nodes based on their frequencies
int compareNodes(const void *a, const void *b) {
    struct Node *node1 = (struct Node*)a;
    struct Node *node2 = (struct Node*)b;
    return node1->frequency - node2->frequency;
}

// Function to build a Huffman tree from a given array of characters and their frequencies
struct Node* buildTree(char characters[], int frequencies[], int size) {
    // Create a priority queue to store the nodes
    struct Node *queue[size];

    // Initialize the priority queue
    for (int i = 0; i < size; i++) {
        queue[i] = createNode(characters[i], frequencies[i]);
    }

    // Sort the priority queue based on frequencies
    qsort(queue, size, sizeof(struct Node*), compareNodes);

    // Build the Huffman tree
    while (size > 1) {
        // Remove the two nodes with the lowest frequencies from the priority queue
        struct Node *node1 = queue[0];
        struct Node *node2 = queue[1];
        queue[0] = queue[size - 1];
        size--;

        // Create a new node with the combined frequency of the two nodes
        struct Node *parentNode = createNode('\0', node1->frequency + node2->frequency);
        parentNode->left = node1;
        parentNode->right = node2;

        // Insert the new node into the priority queue
        queue[0] = parentNode;

        // Sort the priority queue based on frequencies
        qsort(queue, size, sizeof(struct Node*), compareNodes);
    }

    // Return the root of the Huffman tree
    return queue[0];
}

// Function to print the Huffman codes for each character
void printCodes(struct Node *root, char code[]) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->character, code);
        return;
    }

    // Traverse the left subtree
    code[strlen(code)] = '0';
    printCodes(root->left, code);
    code[strlen(code) - 1] = '\0';

    // Traverse the right subtree
    code[strlen(code)] = '1';
    printCodes(root->right, code);
    code[strlen(code) - 1] = '\0';
}

// Function to encode a given string using Huffman coding
char* encode(struct Node *root, char* message) {
    int length = strlen(message);
    char *encodedMessage = (char*)malloc(length * 8 + 1);
    int index = 0;

    for (int i = 0; i < length; i++) {
        struct Node *node = root;
        while (node->left != NULL || node->right != NULL) {
            if (message[i] == node->character) {
                break;
            } else if (message[i] < node->character) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        while (node != NULL) {
            if (node->left == NULL && node->right == NULL) {
                encodedMessage[index++] = '1';
            } else {
                encodedMessage[index++] = '0';
                if (node->left != NULL) {
                    node = node->left;
                } else {
                    node = node->right;
                }
            }
        }
    }

    encodedMessage[index] = '\0';
    return encodedMessage;
}

// Function to decode a given string using Huffman coding
char* decode(struct Node *root, char* encodedMessage) {
    int length = strlen(encodedMessage);
    char *decodedMessage = (char*)malloc(length + 1);
    int index = 0;

    struct Node *node = root;
    for (int i = 0; i < length; i++) {
        if (encodedMessage[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }

        if (node->left == NULL && node->right == NULL) {
            decodedMessage[index++] = node->character;
            node = root;
        }
    }

    decodedMessage[index] = '\0';
    return decodedMessage;
}

int main() {
    // Define the characters and their frequencies
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 4};
    int size = sizeof(characters) / sizeof(characters[0]);

    // Build the Huffman tree
    struct Node *root = buildTree(characters, frequencies, size);

    // Print the Huffman codes for each character
    printf("Huffman Codes:\n");
    char code[100];
    printCodes(root, code);

    // Encode a given message
    char message[] = "this is an example";
    char *encodedMessage = encode(root, message);
    printf("\nEncoded Message: %s\n", encodedMessage);

    // Decode the encoded message
    char *decodedMessage = decode(root, encodedMessage);
    printf("Decoded Message: %s\n", decodedMessage);

    return 0;
}