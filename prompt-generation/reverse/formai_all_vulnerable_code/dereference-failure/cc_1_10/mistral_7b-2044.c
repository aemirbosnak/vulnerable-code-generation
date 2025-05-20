//MISTRAL-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    char ch;
    int freq;
    struct node *left, *right;
} node;

node* createNode(char ch, int freq) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void traverse(node *root, char *code, int length) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        printf("%c : %s\n", root->ch, code);
    }

    traverse(root->left, code, length + 1);
    traverse(root->right, code, length + 1);
}

node* buildHuffmanTree(char data[], int size) {
    int i;
    node *left, *right, *parent;

    node *nodes[size];

    for (i = 0; i < size; i++) {
        nodes[i] = createNode(data[i], 1);
    }

    for (i = 0; i < size - 1; i++) {
        left = nodes[i];
        right = nodes[i + 1];

        parent = (node*)malloc(sizeof(node));
        parent->freq = left->freq + right->freq;
        parent->ch = '\0';
        parent->left = left;
        parent->right = right;

        if (i > 0) {
            free(nodes[i]);
        }
        nodes[i] = parent;
    }

    return nodes[size - 1];
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int size = sizeof(data) / sizeof(data[0]);

    node *root = buildHuffmanTree(data, size);
    char code[256] = {'\0'};

    traverse(root, code, 0);

    free(root);

    return 0;
}

// This is the end of the program, and I'm not sorry for the irregular style!