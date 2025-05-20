//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 256

typedef struct Node {
    struct Node** children;
    char symbol;
    int frequency;
} Node;

Node** buildTree(char* str) {
    int i = 0;
    int strLen = strlen(str);
    Node** tree = malloc(sizeof(Node*) * MAX_TREE_SIZE);

    for (i = 0; i < strLen; i++) {
        tree[i] = malloc(sizeof(Node));
    }

    for (i = 0; i < strLen; i++) {
        tree[i]->symbol = str[i];
        tree[i]->frequency = 1;
        tree[i]->children = NULL;
    }

    return tree;
}

void huffmanEncode(Node* root, char* encodedStr) {
    if (root) {
        huffmanEncode(root->children[0], encodedStr);
        huffmanEncode(root->children[1], encodedStr);

        char prefix = root->symbol;
        encodedStr[root->frequency] = prefix;
    }
}

int main() {
    char str[] = "abcbaabc";
    Node** tree = buildTree(str);
    char encodedStr[256] = "";

    huffmanEncode(tree[0], encodedStr);

    printf("Encoded string: %s\n", encodedStr);

    return 0;
}