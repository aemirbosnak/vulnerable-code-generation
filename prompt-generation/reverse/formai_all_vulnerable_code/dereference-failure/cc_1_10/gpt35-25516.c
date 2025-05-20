//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum length of the input string
#define MAX_LENGTH 100

// define the maximum size of the character array
#define MAX_SIZE 256

// define the structure for creating the Huffman tree node
struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
};

// define the structure for creating the Huffman tree
struct Tree {
    struct Node* root;
};

// define the structure for creating the Huffman code table
struct Code {
    char character;
    char* code;
};

// function to create a new node for the Huffman tree
struct Node* createNode(char character, int frequency) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to create a new tree for the Huffman code
struct Tree* createTree(struct Node* root) {
    struct Tree* tree = (struct Tree*) malloc(sizeof(struct Tree));
    tree->root = root;
    return tree;
}

// function to swap two nodes
void swapNodes(struct Node** node1, struct Node** node2) {
    struct Node* temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

// function to sort the nodes based on their frequency
void sortNodes(struct Node** nodes, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (nodes[i]->frequency > nodes[j]->frequency) {
                swapNodes(&nodes[i], &nodes[j]);
            }
        }
    }
}

// function to create the Huffman tree
struct Tree* createHuffmanTree(char* input) {
    int i, j, size, n1, n2, sum;
    struct Node* nodes[MAX_SIZE];
    size = 0;
    for (i = 0; i < strlen(input); i++) {
        int found = 0;
        for (j = 0; j < size; j++) {
            if (nodes[j]->character == input[i]) {
                nodes[j]->frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            nodes[size++] = createNode(input[i], 1);
        }
    }
    sortNodes(nodes, size);
    while (size > 1) {
        n1 = 0;
        n2 = 1;
        sum = nodes[0]->frequency + nodes[1]->frequency;
        struct Node* parent = createNode('\0', sum);
        parent->left = nodes[n1];
        parent->right = nodes[n2];
        for (i = 2; i < size; i++) {
            if (sum > nodes[i]->frequency) {
                if (sum > nodes[i + 1]->frequency) {
                    n1 = i + 1;
                    n2 = i;
                    sum = nodes[n1]->frequency + nodes[n2]->frequency;
                } else {
                    n2 = i;
                    sum += nodes[n2]->frequency;
                }
            } else if (sum > nodes[i + 1]->frequency) {
                n1 = i;
                n2 = i + 1;
                sum = nodes[n1]->frequency + nodes[n2]->frequency;
            }
            parent->left = nodes[n1];
            parent->right = nodes[n2];
        }
        nodes[n1] = parent;
        for (i = n2; i < size - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        size--;
    }
    return createTree(nodes[0]);
}

// function to create the Huffman code table
void createHuffmanCodeTable(struct Node* node, char* code, int len, struct Code* hcode, int* index) {
    if (node->left) {
        code[len] = '0';
        createHuffmanCodeTable(node->left, code, len + 1, hcode, index);
    }
    if (node->right) {
        code[len] = '1';
        createHuffmanCodeTable(node->right, code, len + 1, hcode, index);
    }
    if (!node->left && !node->right) {
        struct Code c = {node->character, (char*) malloc(sizeof(char) * len)};
        strcpy(c.code, code);
        hcode[(*index)++] = c;
    }
}

// function to encode the input string using the Huffman code table
void encodeInput(char* input, struct Code* hcode, int index) {
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        for (j = 0; j < index; j++) {
            if (input[i] == hcode[j].character) {
                printf("%s", hcode[j].code);
                break;
            }
        }
    }
}

// main function
int main() {
    char input[MAX_LENGTH];
    printf("Enter the input string: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    struct Tree* huffmanTree = createHuffmanTree(input);
    char code[MAX_SIZE];
    struct Code hcode[MAX_SIZE];
    int index = 0;
    createHuffmanCodeTable(huffmanTree->root, code, 0, hcode, &index);
    printf("Huffman Codes:\n");
    int i;
    for (i = 0; i < index; i++) {
        printf("%c: %s\n", hcode[i].character, hcode[i].code);
    }
    printf("Encoded Input: ");
    encodeInput(input, hcode, index);
    printf("\n");
    return 0;
}