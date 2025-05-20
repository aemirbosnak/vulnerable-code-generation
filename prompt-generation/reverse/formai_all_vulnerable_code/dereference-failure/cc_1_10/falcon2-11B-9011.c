//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DEPTH 32
#define MAX_DISTANCE 255

typedef struct Node {
    char symbol;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char symbol, int frequency) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int compareNodes(const void* a, const void* b) {
    Node* nodeA = (Node*) a;
    Node* nodeB = (Node*) b;
    return nodeA->frequency - nodeB->frequency;
}

void printCode(Node* root, int depth, char* code) {
    if (root == NULL) {
        return;
    }
    int distance = 0;
    while (root->left!= NULL) {
        distance++;
        root = root->left;
    }
    code[depth] = (char) distance;
    printCode(root->right, depth + 1, code);
}

char* huffmanCode(Node* root) {
    char* code = (char*) malloc(sizeof(char) * MAX_DISTANCE);
    int depth = 0;
    printCode(root, depth, code);
    return code;
}

Node* buildTree(Node* nodes[], int nodeCount) {
    Node* root = NULL;
    int frequency = 0;
    for (int i = 0; i < nodeCount; i++) {
        Node* node = nodes[i];
        if (root == NULL) {
            root = node;
            frequency = node->frequency;
        } else if (frequency < node->frequency) {
            root = node;
            frequency = node->frequency;
        }
    }
    qsort(nodes, nodeCount, sizeof(Node), compareNodes);
    for (int i = 0; i < nodeCount / 2; i++) {
        Node* left = nodes[i];
        Node* right = nodes[i + 1];
        Node* node = createNode(left->symbol, left->frequency + right->frequency);
        node->left = left;
        node->right = right;
        nodes[i] = node;
        nodes[i + 1] = NULL;
    }
    return root;
}

int main() {
    Node* nodes[] = {
        createNode('a', 5),
        createNode('b', 3),
        createNode('c', 7),
        createNode('d', 1),
        createNode('e', 4)
    };
    int nodeCount = sizeof(nodes) / sizeof(Node*);
    Node* root = buildTree(nodes, nodeCount);
    char* code = huffmanCode(root);
    printf("Code: %s\n", code);
    free(code);
    return 0;
}