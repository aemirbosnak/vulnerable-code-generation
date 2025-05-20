//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the Huffman tree
struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
};

// A utility function to create a new node
struct Node* createNode(char character, unsigned frequency) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->character = character;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

// A comparison function for the priority queue
int compare(const void *a, const void *b) {
    return ((*(struct Node**)a)->frequency - (*(struct Node**)b)->frequency);
}

// Build the Huffman tree
struct Node* buildHuffmanTree(char characters[], int frequency[], int size) {
    int n = size;
    struct Node **nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    
    for (int i = 0; i < n; i++)
        nodes[i] = createNode(characters[i], frequency[i]);

    while (n > 1) {
        // Sort nodes based on frequency
        qsort(nodes, n, sizeof(struct Node*), compare);
        
        // Combine two smallest nodes
        struct Node* left = nodes[0];
        struct Node* right = nodes[1];
        struct Node* combined = createNode('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;

        // Replace the smallest two nodes with the new combined node
        nodes[1] = combined;
        nodes[0] = nodes[n - 1]; // eliminate the first
        n--;
    }
    
    struct Node* root = nodes[0];
    free(nodes);
    return root;
}

// Generate Huffman Codes
void generateHuffmanCodes(struct Node* root, int code[], int depth, char *huffmanCodes[]) {
    if (root->left) {
        code[depth] = 0;
        generateHuffmanCodes(root->left, code, depth + 1, huffmanCodes);
    }

    if (root->right) {
        code[depth] = 1;
        generateHuffmanCodes(root->right, code, depth + 1, huffmanCodes);
    }

    if (!(root->left) && !(root->right)) {
        char *codeString = (char *)malloc((depth + 1) * sizeof(char));
        for (int i = 0; i < depth; i++)
            codeString[i] = (code[i] == 0) ? '0' : '1';
        codeString[depth] = '\0';
        huffmanCodes[root->character] = codeString;
    }
}

// Encode the input string using Huffman codes
void encodeHuffman(char *input, char *huffmanCodes[], char *output) {
    output[0] = '\0'; // Initialize the output
    for (int i = 0; i < strlen(input); i++) {
        strcat(output, huffmanCodes[input[i]]);
    }
}

// Decode a Huffman encoded string
void decodeHuffman(struct Node* root, char *encodedString) {
    struct Node* current = root;
    for (int i = 0; i < strlen(encodedString); i++) {
        current = (encodedString[i] == '0') ? current->left : current->right;

        if (!(current->left) && !(current->right)) {
            printf("%c", current->character);
            current = root;
        }
    }
    printf("\n");
}

// Free the memory allocated for the Huffman tree
void freeTree(struct Node* node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

// Main function to handle input and output
int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45}; 
    int size = sizeof(characters) / sizeof(characters[0]);

    struct Node* root = buildHuffmanTree(characters, frequency, size);
    
    char *huffmanCodes[256] = {0}; // 256 for ASCII characters
    int code[256], top = 0;

    generateHuffmanCodes(root, code, 0, huffmanCodes);
    printf("Huffman Codes:\n");
    for (int i = 0; i < 256; i++) {
        if (huffmanCodes[i]) {
            printf("Character '%c': %s\n", i, huffmanCodes[i]);
        }
    }

    char input[] = "abcdef";
    char encoded[256];
    encodeHuffman(input, huffmanCodes, encoded);

    printf("\nEncoded string: %s\n", encoded);
    printf("Decoded string: ");
    decodeHuffman(root, encoded);

    // Free allocated memory
    for (int i = 0; i < 256; i++) {
        if (huffmanCodes[i]) {
            free(huffmanCodes[i]);
        }
    }
    freeTree(root);
    
    return 0;
}