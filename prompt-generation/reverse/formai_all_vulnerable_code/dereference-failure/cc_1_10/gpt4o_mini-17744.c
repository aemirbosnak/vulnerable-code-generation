//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 100
#define MAX_CHARS 256

// Define the structure for a Huffman tree node
struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
};

// Function to create a new tree node
struct Node* createNode(char character, int frequency) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to compare two nodes (for sorting)
int compare(const void* a, const void* b) {
    return ((struct Node*)a)->frequency - ((struct Node*)b)->frequency;
}

// Function to print the Huffman codes assigned to characters
void printCodes(struct Node* root, char* code, int depth) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        printf("Character: '%c' Code: %s\n", root->character, code);
        return;
    }

    // Traverse left
    code[depth] = '0';
    printCodes(root->left, code, depth + 1);
    
    // Traverse right
    code[depth] = '1';
    printCodes(root->right, code, depth + 1);
}

// Create a Huffman tree from the character frequencies
struct Node* createHuffmanTree(char characters[], int frequencies[], int size) {
    struct Node** nodes = (struct Node**)malloc(size * sizeof(struct Node*));
    for (int i = 0; i < size; ++i)
        nodes[i] = createNode(characters[i], frequencies[i]);

    qsort(nodes, size, sizeof(struct Node*), compare);

    while (size > 1) {
        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct Node* newNode = createNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        nodes[1] = newNode; // Replace the first two nodes with the new node
        size--;

        qsort(nodes, size, sizeof(struct Node*), compare);
    }

    struct Node* root = nodes[0];
    free(nodes);
    return root;
}

// Function to encode a message using the Huffman tree
void encodeMessage(struct Node* root, const char* message) {
    char code[MAX_TREE_HEIGHT];
    int depth = 0;
    printf("Encoding message: '%s'\n", message);
    
    for (int i = 0; message[i] != '\0'; i++) {
        struct Node* current = root;
        printf("Character: '%c' Code: ", message[i]);
        
        // Traverse tree to find code for the character
        while (current->left || current->right) {
            if (message[i] == current->left->character) {
                printf("0");
                current = current->left;
            } else if (message[i] == current->right->character) {
                printf("1");
                current = current->right;
            } else {
                break; // Just for safety, should never happen
            }
        }
    }
    printf("\n");
}

// Main function to run the Huffman Coding program
int main() {
    char characters[] = { 'a', 'b', 'c', 'd', 'e' };
    int frequencies[] = { 5, 9, 12, 13, 16 };
    int size = sizeof(characters) / sizeof(characters[0]);

    // Create Huffman Tree
    struct Node* root = createHuffmanTree(characters, frequencies, size);

    // Display Huffman codes
    char code[MAX_TREE_HEIGHT];
    printCodes(root, code, 0);

    // Encode a sample message
    const char* message = "abcde";
    encodeMessage(root, message);
    
    return 0;
}