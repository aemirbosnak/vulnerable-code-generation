//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a Huffman Tree node
struct Node {
    char value;
    int weight;
    struct Node *left;
    struct Node *right;
};

// Struct for a Huffman Code entry
struct CodeEntry {
    char value;
    char *code;
};

// Function to create a new Huffman Tree node
struct Node* newNode(int weight, char value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->weight = weight;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to create a Huffman Tree
void createTree(struct Node **root, int frequency[], char value[], int size) {
    struct Node *temp;
    int i, j;

    // Create an array of nodes for each character
    struct Node *nodes[size];
    for(i = 0; i < size; i++) {
        nodes[i] = newNode(frequency[i], value[i]);
    }

    // Create the tree by combining nodes with minimum weight
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(nodes[j]->weight > nodes[j+1]->weight) {
                temp = nodes[j];
                nodes[j] = nodes[j+1];
                nodes[j+1] = temp;
            }
        }
        temp = newNode(nodes[0]->weight + nodes[1]->weight, '$');
        temp->left = nodes[0];
        temp->right = nodes[1];
        nodes[0] = temp;
    }

    *root = nodes[0];
}

// Function to assign codes to each node in the Huffman Tree
void assignCode(struct Node *node, char *code, int index, struct CodeEntry **codes, int *size) {
    if(node->value != '$') {
        (*size)++;
        (*codes) = (struct CodeEntry*) realloc((*codes), (*size) * sizeof(struct CodeEntry));
        (*codes)[(*size) - 1].value = node->value;
        (*codes)[(*size) - 1].code = (char*) malloc((index + 1) * sizeof(char));
        strncpy((*codes)[(*size) - 1].code, code, index);
        (*codes)[(*size) - 1].code[index] = '\0';
    }
    else {
        code[index] = '0';
        assignCode(node->left, code, index + 1, codes, size);
        code[index] = '1';
        assignCode(node->right, code, index + 1, codes, size);
    }
}

// Function to encode a message using the Huffman Tree codes
char* encodeMessage(char *message, struct CodeEntry *codes, int size) {
    char *encodedMessage = (char*) malloc(sizeof(char));
    encodedMessage[0] = '\0';
    int i, j;

    // Loop through each character in the message and add its code to the encoded message
    for(i = 0; message[i] != '\0'; i++) {
        for(j = 0; j < size; j++) {
            if(message[i] == codes[j].value) {
                encodedMessage = (char*) realloc(encodedMessage, (strlen(encodedMessage) + strlen(codes[j].code) + 1) * sizeof(char));
                strcat(encodedMessage, codes[j].code);
                break;
            }
        }
    }

    return encodedMessage;
}

int main() {
    char message[1000];
    int frequency[256] = {0};
    char value[256];
    int size = 0, i, j;

    // Get input from user
    printf("Enter message to encode: ");
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = 0;

    // Get frequency of each character in the message
    for(i = 0; message[i] != '\0'; i++) {
        int found = 0;
        for(j = 0; j < size && !found; j++) {
            if(message[i] == value[j]) {
                found = 1;
                frequency[j]++;
            }
        }
        if(!found) {
            value[size] = message[i];
            frequency[size]++;
            size++;
        }
    }

    struct Node *root;
    struct CodeEntry *codes = NULL;
    int codesSize = 0;

    // Create Huffman Tree
    createTree(&root, frequency, value, size);

    // Assign codes to Huffman Tree nodes
    char code[100];
    assignCode(root, code, 0, &codes, &codesSize);

    // Print Huffman Tree codes
    printf("\nHuffman Tree codes:\n");
    for(i = 0; i < codesSize; i++) {
        printf("%c: %s\n", codes[i].value, codes[i].code);
    }

    // Encode message using Huffman Tree codes
    char *encodedMessage = encodeMessage(message, codes, codesSize);
    printf("\nEncoded message: %s\n", encodedMessage);

    return 0;
}