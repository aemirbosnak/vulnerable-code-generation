//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node of a Huffman tree
struct HuffmanNode {
    char character;
    int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
};

// Comparison function for qsort()
int compareHuffmanNodes(const void *a, const void *b) {
    struct HuffmanNode *node1 = (struct HuffmanNode *)a;
    struct HuffmanNode *node2 = (struct HuffmanNode *)b;
    return node1->frequency - node2->frequency;
}

// Create a new Huffman node
struct HuffmanNode *createHuffmanNode(char character, int frequency) {
    struct HuffmanNode *node = (struct HuffmanNode *)malloc(sizeof(struct HuffmanNode));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Build a Huffman tree from a given frequency table
struct HuffmanNode *buildHuffmanTree(char *characters, int *frequencies, int size) {
    // Create a priority queue of Huffman nodes
    struct HuffmanNode **queue = (struct HuffmanNode **)malloc(sizeof(struct HuffmanNode *) * size);
    for (int i = 0; i < size; i++) {
        queue[i] = createHuffmanNode(characters[i], frequencies[i]);
    }

    // Sort the priority queue by frequency
    qsort(queue, size, sizeof(struct HuffmanNode *), compareHuffmanNodes);

    // Build the Huffman tree
    while (size > 1) {
        // Remove the two lowest-frequency nodes from the queue
        struct HuffmanNode *node1 = queue[0];
        queue[0] = queue[size - 1];
        size--;
        struct HuffmanNode *node2 = queue[0];
        queue[0] = queue[size - 1];
        size--;

        // Create a new node with a frequency equal to the sum of the two nodes' frequencies
        struct HuffmanNode *newNode = createHuffmanNode('\0', node1->frequency + node2->frequency);
        newNode->left = node1;
        newNode->right = node2;

        // Insert the new node into the priority queue
        queue[size] = newNode;
        size++;

        // Sort the priority queue by frequency
        qsort(queue, size, sizeof(struct HuffmanNode *), compareHuffmanNodes);
    }

    // Return the root of the Huffman tree
    return queue[0];
}

// Generate a Huffman code table
char **generateHuffmanCodeTable(struct HuffmanNode *root, char **codeTable, int *codeLength) {
    if (root->left == NULL && root->right == NULL) {
        codeTable[root->character - 'a'] = malloc(sizeof(char) * (*codeLength + 1));
        strcpy(codeTable[root->character - 'a'], "");
        (*codeLength) = 0;
        return codeTable;
    }

    if (root->left != NULL) {
        codeTable = generateHuffmanCodeTable(root->left, codeTable, codeLength);
        for (int i = 0; i < 26; i++) {
            if (codeTable[i] != NULL) {
                int len = strlen(codeTable[i]);
                codeTable[i] = realloc(codeTable[i], sizeof(char) * (len + 2));
                strcat(codeTable[i], "0");
            }
        }
    }

    if (root->right != NULL) {
        codeTable = generateHuffmanCodeTable(root->right, codeTable, codeLength);
        for (int i = 0; i < 26; i++) {
            if (codeTable[i] != NULL) {
                int len = strlen(codeTable[i]);
                codeTable[i] = realloc(codeTable[i], sizeof(char) * (len + 2));
                strcat(codeTable[i], "1");
            }
        }
    }

    (*codeLength)++;
    return codeTable;
}

// Encode a given string using the Huffman code table
char *encodeString(char *string, char **codeTable, int size) {
    char *encodedString = (char *)malloc(sizeof(char) * (strlen(string) * 10));
    int encodedStringLength = 0;
    for (int i = 0; i < strlen(string); i++) {
        strcat(encodedString, codeTable[string[i] - 'a']);
        encodedStringLength += strlen(codeTable[string[i] - 'a']);
    }
    return encodedString;
}

// Decode a given encoded string using the Huffman tree
char *decodeString(char *encodedString, struct HuffmanNode *root) {
    char *decodedString = (char *)malloc(sizeof(char) * (strlen(encodedString) + 1));
    int decodedStringLength = 0;
    struct HuffmanNode *current = root;
    for (int i = 0; i < strlen(encodedString); i++) {
        if (encodedString[i] == '0') {
            current = current->left;
        } else if (encodedString[i] == '1') {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            decodedString[decodedStringLength] = current->character;
            decodedStringLength++;
            current = root;
        }
    }
    decodedString[decodedStringLength] = '\0';
    return decodedString;
}

// Print the Huffman code table
void printHuffmanCodeTable(char **codeTable, int size) {
    for (int i = 0; i < size; i++) {
        if (codeTable[i] != NULL) {
            printf("%c: %s\n", i + 'a', codeTable[i]);
        }
    }
}

// Free the Huffman code table
void freeHuffmanCodeTable(char **codeTable, int size) {
    for (int i = 0; i < size; i++) {
        if (codeTable[i] != NULL) {
            free(codeTable[i]);
        }
    }
    free(codeTable);
}

// Free the Huffman tree
void freeHuffmanTree(struct HuffmanNode *root) {
    if (root != NULL) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    // Define the frequency table
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int frequencies[] = {8, 2, 4, 6, 10, 1, 5, 3, 9, 7, 2, 4, 6, 10, 1, 5, 3, 9, 7, 8, 2, 4, 6, 10, 1, 5};

    // Build the Huffman tree
    struct HuffmanNode *root = buildHuffmanTree(characters, frequencies, 26);

    // Generate the Huffman code table
    char **codeTable = (char **)malloc(sizeof(char *) * 26);
    int codeLength = 0;
    codeTable = generateHuffmanCodeTable(root, codeTable, &codeLength);

    // Print the Huffman code table
    printf("Huffman Code Table:\n");
    printHuffmanCodeTable(codeTable, 26);

    // Encode a given string
    char *string = "this is a test";
    char *encodedString = encodeString(string, codeTable, 26);

    // Decode the encoded string
    char *decodedString = decodeString(encodedString, root);

    // Print the encoded and decoded strings
    printf("Encoded String: %s\n", encodedString);
    printf("Decoded String: %s\n", decodedString);

    // Free the Huffman code table and tree
    freeHuffmanCodeTable(codeTable, 26);
    freeHuffmanTree(root);

    return 0;
}