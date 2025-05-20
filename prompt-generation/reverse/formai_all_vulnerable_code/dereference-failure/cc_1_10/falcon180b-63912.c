//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct node {
    char data;
    int freq;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->freq = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (root->data == data) {
        root->freq++;
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    root->freq = 1 + getFreq(root->left) + getFreq(root->right);

    if (root->freq < 0) {
        root->freq = 0;
    }

    return root;
}

int getFreq(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return root->freq;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%c (%d)\n", root->data, root->freq);
    inorder(root->right);
}

int main() {
    char input[MAX_SIZE];
    int i = 0;

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    Node* root = NULL;
    for (i = 0; input[i]!= '\0'; i++) {
        input[i] = tolower(input[i]);
        root = insert(root, input[i]);
    }

    printf("Inorder traversal of the Huffman tree:\n");
    inorder(root);

    return 0;
}