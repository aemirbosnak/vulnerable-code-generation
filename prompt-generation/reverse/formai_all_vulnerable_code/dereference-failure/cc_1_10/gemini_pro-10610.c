//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure to represent a node in the Huffman tree
typedef struct Node {
    unsigned char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

// Custom data structure to represent a priority queue
typedef struct PriorityQueue {
    int size;
    int capacity;
    Node **items;
} PriorityQueue;

// Function to create a new Node
Node *createNode(unsigned char character, int frequency) {
    Node *node = malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a new PriorityQueue
PriorityQueue *createPriorityQueue(int capacity) {
    PriorityQueue *queue = malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->items = malloc(sizeof(Node *) * capacity);
    return queue;
}

// Function to insert a Node into a PriorityQueue
void insertIntoPriorityQueue(PriorityQueue *queue, Node *node) {
    int i = queue->size;

    // Find the correct position for the new Node
    while (i > 0 && queue->items[i - 1]->frequency > node->frequency) {
        queue->items[i] = queue->items[i - 1];
        i--;
    }

    // Insert the new Node into the PriorityQueue
    queue->items[i] = node;
    queue->size++;
}

// Function to remove the root of a PriorityQueue
Node *popFromPriorityQueue(PriorityQueue *queue) {
    if (queue->size == 0) {
        return NULL;
    }

    // Store the root Node
    Node *root = queue->items[0];

    // Copy the last Node into the root position
    queue->items[0] = queue->items[queue->size - 1];

    // Decrement the size of the PriorityQueue
    queue->size--;

    return root;
}

// Function to build a Huffman tree
Node *buildHuffmanTree(PriorityQueue *queue) {
    Node *left, *right, *top;

    // While there are more than one Node in the PriorityQueue
    while (queue->size > 1) {
        // Pop the two Nodes with the lowest frequency
        left = popFromPriorityQueue(queue);
        right = popFromPriorityQueue(queue);

        // Create a new Node with the sum of the frequencies of the two Nodes
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        // Insert the new Node into the PriorityQueue
        insertIntoPriorityQueue(queue, top);
    }

    // Return the root of the Huffman tree
    return queue->items[0];
}

// Function to create a code table for the Huffman tree
char **createCodeTable(Node *root, char **table, int index) {
    // If the Node is a leaf, assign the corresponding code
    if (root->left == NULL && root->right == NULL) {
        table[index] = malloc(sizeof(char) * (index + 1));
        strcpy(table[index], "");
        return table;
    }

    // Create a code for the left subtree
    if (root->left != NULL) {
        table = createCodeTable(root->left, table, index + 1);
        for (int i = 0; i < index + 1; i++) {
            strcat(table[index + i], "0");
        }
    }

    // Create a code for the right subtree
    if (root->right != NULL) {
        table = createCodeTable(root->right, table, index + 1);
        for (int i = 0; i < index + 1; i++) {
            strcat(table[index + i], "1");
        }
    }

    return table;
}

// Function to encode a string using Huffman coding
char *encode(char *string, char **codeTable) {
    char *encodedString = malloc(sizeof(char) * (strlen(string) + 1));
    int index = 0;

    // Loop through each character in the string
    for (int i = 0; i < strlen(string); i++) {
        // Find the code for the character in the code table
        for (int j = 0; j < 256; j++) {
            if (codeTable[j] != NULL && string[i] == j) {
                // Append the code to the encoded string
                strcat(encodedString, codeTable[j]);
                index += strlen(codeTable[j]);
            }
        }
    }

    // Add a null terminator to the encoded string
    encodedString[index] = '\0';

    return encodedString;
}

// Function to decode a string using Huffman coding
char *decode(char *encodedString, Node *root) {
    char *decodedString = malloc(sizeof(char) * (strlen(encodedString) + 1));
    Node *current = root;
    int index = 0;

    // Loop through each bit in the encoded string
    for (int i = 0; i < strlen(encodedString); i++) {
        // If the bit is 0, go to the left subtree
        if (encodedString[i] == '0') {
            current = current->left;
        }

        // If the bit is 1, go to the right subtree
        else if (encodedString[i] == '1') {
            current = current->right;
        }

        // If the current Node is a leaf, append the character to the decoded string
        if (current->left == NULL && current->right == NULL) {
            decodedString[index] = current->character;
            index++;
            current = root;
        }
    }

    // Add a null terminator to the decoded string
    decodedString[index] = '\0';

    return decodedString;
}

// Main function
int main() {
    // Get the input string
    char *string = "Hello world!";

    // Create a frequency table
    int frequencies[256] = {0};
    for (int i = 0; i < strlen(string); i++) {
        frequencies[string[i]]++;
    }

    // Create a PriorityQueue
    PriorityQueue *queue = createPriorityQueue(256);

    // Insert the Nodes into the PriorityQueue
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            insertIntoPriorityQueue(queue, createNode(i, frequencies[i]));
        }
    }

    // Build the Huffman tree
    Node *root = buildHuffmanTree(queue);

    // Create a code table
    char **codeTable = malloc(sizeof(char *) * 256);
    for (int i = 0; i < 256; i++) {
        codeTable[i] = NULL;
    }
    codeTable = createCodeTable(root, codeTable, 0);

    // Encode the string
    char *encodedString = encode(string, codeTable);

    // Decode the string
    char *decodedString = decode(encodedString, root);

    // Print the original string, encoded string, and decoded string
    printf("Original string: %s\n", string);
    printf("Encoded string: %s\n", encodedString);
    printf("Decoded string: %s\n", decodedString);

    // Free the allocated memory
    for (int i = 0; i < 256; i++) {
        if (codeTable[i] != NULL) {
            free(codeTable[i]);
        }
    }
    free(codeTable);
    free(encodedString);
    free(decodedString);
    free(root);
    free(queue->items);
    free(queue);

    return 0;
}