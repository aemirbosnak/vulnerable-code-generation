//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int freq;
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(char data, int freq) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertNode(Node *root, Node *node) {
    if (root == NULL) return node;
    if (root->freq > node->freq) {
        root->left = insertNode(root->left, node);
    } else {
        root->right = insertNode(root->right, node);
    }
    return root;
}

void printTree(Node *root) {
    if (root == NULL) return;
    printf("%c: %d\n", root->data, root->freq);
    printTree(root->left);
    printTree(root->right);
}

void printCodes(Node *root, char code[], int top) {
    if (root == NULL) return;
    if (root->data != '\0') {
        code[top] = '\0';
        printf("%c: %s\n", root->data, code);
        return;
    }
    code[top] = '0';
    printCodes(root->left, code, top + 1);
    code[top] = '1';
    printCodes(root->right, code, top + 1);
}

void encode(Node *root, char *message, int len) {
    char code[MAX_SIZE];
    int i, top = 0;
    for (i = 0; i < len; i++) {
        printCodes(root, code, top);
        top = 0;
    }
}

int main() {
    int freq[] = {5, 9, 12, 13, 16, 45};
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int len = sizeof(freq) / sizeof(int);
    
    Node *root = NULL;
    for (int i = 0; i < len; i++) {
        root = insertNode(root, createNode(data[i], freq[i]));
    }
    
    printTree(root);
    
    char message[] = "abcabc";
    int len2 = strlen(message);
    
    encode(root, message, len2);
    
    return 0;
}