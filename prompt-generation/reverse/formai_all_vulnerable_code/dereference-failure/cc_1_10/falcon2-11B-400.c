//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 256

struct node {
    char symbol;
    int frequency;
    struct node* left;
    struct node* right;
};

struct node* createNode(char symbol, int frequency) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->symbol = symbol;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void buildHuffmanTree(struct node** root) {
    int numNodes = 0;
    int i, j;

    struct node* nodes[MAX_SIZE];
    memset(nodes, 0, sizeof(nodes));

    for (i = 0; i < MAX_SIZE; i++) {
        nodes[i] = createNode(i + 'a', 1);
    }

    while (numNodes < MAX_SIZE - 1) {
        int minFreq = 1000000;
        int minIndex = -1;

        for (i = 0; i < numNodes; i++) {
            if (nodes[i]->frequency < minFreq && nodes[i]->frequency!= 0) {
                minFreq = nodes[i]->frequency;
                minIndex = i;
            }
        }

        struct node* node1 = nodes[minIndex];
        struct node* node2 = createNode('_', 0);
        node1->left = node2;
        node2->right = node1;
        nodes[minIndex] = node2;

        numNodes--;
    }

    *root = nodes[0];
}

void huffmanEncode(struct node* root, char* source) {
    int i;
    char* destination = (char*)malloc(strlen(source) * sizeof(char));
    memset(destination, 0, strlen(source) * sizeof(char));

    for (i = 0; i < strlen(source); i++) {
        struct node* node = root;

        while (node!= NULL) {
            if (node->symbol == source[i]) {
                destination[i] = (char)node->symbol;
                break;
            }

            node = node->right;
        }
    }

    printf("Huffman encoded string: %s\n", destination);
}

int main() {
    char* source = "abbacdabbacd";
    struct node* root = NULL;
    buildHuffmanTree(&root);
    huffmanEncode(root, source);
    return 0;
}