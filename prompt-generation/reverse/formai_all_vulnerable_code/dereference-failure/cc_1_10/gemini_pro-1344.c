//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    int freq;
    struct node *left, *right;
} Node;

Node *createNode(char data, int freq) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insertNode(Node *root, Node *node) {
    if (root == NULL || root->freq >= node->freq) {
        node->right = root;
        return node;
    } else {
        root->right = insertNode(root->right, node);
        return root;
    }
}

Node *buildTree(char data[], int freq[], int size) {
    Node *root = NULL;
    for (int i = 0; i < size; i++) {
        root = insertNode(root, createNode(data[i], freq[i]));
    }
    return root;
}

void printCodes(Node *root, char code[]) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->data, code);
        return;
    }
    code[strlen(code)] = '0';
    printCodes(root->left, code);
    code[strlen(code) - 1] = '1';
    printCodes(root->right, code);
}

void encode(Node *root, char data[], char code[]) {
    if (root == NULL) {
        return;
    }
    if (root->data == data[0]) {
        strcat(code, "0");
    } else {
        strcat(code, "1");
        encode(root->left, data, code);
        encode(root->right, data, code);
    }
}

void decode(Node *root, char code[]) {
    Node *current = root;
    for (int i = 0; i < strlen(code); i++) {
        if (code[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data);
            current = root;
        }
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {45, 13, 12, 16, 9, 5};

    Node *root = buildTree(data, freq, 6);
    
    char code[100];
    printCodes(root, code);

    char message[] = "abcaba";

    encode(root, message, code);

    printf("Encoded message: %s\n", code);

    decode(root, code);

    return 0;
}