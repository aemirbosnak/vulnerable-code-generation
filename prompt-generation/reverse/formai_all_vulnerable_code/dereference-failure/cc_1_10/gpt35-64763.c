//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char letter;
    int frequency;
    struct node *left;
    struct node *right;
};

typedef struct node node;

int compareNodes(const void *a, const void *b) {
    int freq_a = ((node*)a)->frequency;
    int freq_b = ((node*)b)->frequency;

    return freq_a - freq_b;
}

node* createNode(char letter, int frequency) {
    node *temp = (node*) malloc(sizeof(node));
    temp->letter = letter;
    temp->frequency = frequency;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

node* buildTree(node **nodes, int numNodes) {
    while (numNodes > 1) {
        qsort(nodes, numNodes, sizeof(node*), compareNodes);

        node *leftChild = nodes[0];
        node *rightChild = nodes[1];

        node *parent = createNode('*', leftChild->frequency + rightChild->frequency);
        parent->left = leftChild;
        parent->right = rightChild;

        nodes[0] = parent;
        nodes[1] = nodes[numNodes-1];
        numNodes--;

        free(rightChild);
    }

    return nodes[0];
}

void printCodes(node *root, char *code, int index) {
    if (root == NULL) return;

    if (root->letter != '*') {
        printf("%c: %s\n", root->letter, code);
    }

    code[index] = '0';
    printCodes(root->left, code, index+1);

    code[index] = '1';
    printCodes(root->right, code, index+1);
}

int main() {
    char *text = "this is a test string";
    int freq[256] = {0};

    int i;
    for (i = 0; i < strlen(text); i++) {
        freq[(int)text[i]]++;
    }

    node **nodes = (node**) malloc(sizeof(node*) * 256);
    int numNodes = 0;

    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            nodes[numNodes] = createNode((char)i, freq[i]);
            numNodes++;
        }
    }

    node *root = buildTree(nodes, numNodes);

    char code[256];
    code[0] = '\0';
    printCodes(root, code, 0);

    return 0;
}