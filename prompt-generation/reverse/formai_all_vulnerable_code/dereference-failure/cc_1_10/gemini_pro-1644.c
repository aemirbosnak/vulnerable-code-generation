//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node of a Huffman tree
struct Node {
    char data;
    int frequency;
    struct Node *left, *right;
};

// Huffman tree
struct Tree {
    struct Node *root;
};

// Create a new node
struct Node *createNode(char data, int frequency) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Create a new tree
struct Tree *createTree() {
    struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
    tree->root = NULL;
    return tree;
}

// Insert a node into a tree
void insertNode(struct Tree *tree, struct Node *node) {
    if (tree->root == NULL) {
        tree->root = node;
        return;
    }

    struct Node *current = tree->root;
    struct Node *parent = NULL;

    while (current != NULL) {
        parent = current;

        if (node->frequency < current->frequency) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (node->frequency < parent->frequency) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}

// Build a Huffman tree from a given string
struct Tree *buildTree(char *string) {
    struct Tree *tree = createTree();

    int frequencies[256] = {0};

    for (int i = 0; i < strlen(string); i++) {
        frequencies[string[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            struct Node *node = createNode(i, frequencies[i]);
            insertNode(tree, node);
        }
    }

    return tree;
}

// Encode a string using a Huffman tree
char *encode(struct Tree *tree, char *string) {
    char *encodedString = (char *)malloc(strlen(string) * 8 + 1);
    int index = 0;

    for (int i = 0; i < strlen(string); i++) {
        struct Node *current = tree->root;

        while (current != NULL) {
            if (current->data == string[i]) {
                break;
            } else if (current->frequency < current->left->frequency) {
                encodedString[index++] = '0';
                current = current->left;
            } else {
                encodedString[index++] = '1';
                current = current->right;
            }
        }
    }

    encodedString[index] = '\0';

    return encodedString;
}

// Decode a string using a Huffman tree
char *decode(struct Tree *tree, char *encodedString) {
    char *decodedString = (char *)malloc(strlen(encodedString) + 1);
    int index = 0;

    struct Node *current = tree->root;

    for (int i = 0; i < strlen(encodedString); i++) {
        if (encodedString[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            decodedString[index++] = current->data;
            current = tree->root;
        }
    }

    decodedString[index] = '\0';

    return decodedString;
}

// Print a Huffman tree
void printTree(struct Tree *tree) {
    if (tree->root == NULL) {
        return;
    }

    struct Node *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = tree->root;

    while (front != rear) {
        struct Node *node = queue[front++];

        printf("%c (%d)", node->data, node->frequency);

        if (node->left != NULL) {
            queue[rear++] = node->left;
        }

        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}

// Free a Huffman tree
void freeTree(struct Tree *tree) {
    if (tree->root == NULL) {
        return;
    }

    struct Node *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = tree->root;

    while (front != rear) {
        struct Node *node = queue[front++];

        if (node->left != NULL) {
            queue[rear++] = node->left;
        }

        if (node->right != NULL) {
            queue[rear++] = node->right;
        }

        free(node);
    }
}

int main() {
    char *string = "Hello, world!";

    struct Tree *tree = buildTree(string);

    char *encodedString = encode(tree, string);

    char *decodedString = decode(tree, encodedString);

    printf("Original string: %s\n", string);
    printf("Encoded string: %s\n", encodedString);
    printf("Decoded string: %s\n", decodedString);

    freeTree(tree);

    return 0;
}