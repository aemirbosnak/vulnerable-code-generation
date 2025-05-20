//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    int freq;
    struct node *left;
    struct node *right;
};

struct node* newNode(char data, int freq) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct node* root, char data, int freq) {
    if (root == NULL) {
        root = newNode(data, freq);
        return;
    }

    if (data < root->data) {
        insertNode(root->left, data, freq);
    } else {
        insertNode(root->right, data, freq);
    }
}

void huffmanEncoding(struct node* root) {
    if (root == NULL) {
        return;
    }

    struct node* left = root->left;
    struct node* right = root->right;

    char ch = root->data;
    int freq = root->freq;

    huffmanEncoding(left);
    huffmanEncoding(right);

    printf("%c %d\n", ch, freq);
}

int main() {
    struct node* root = NULL;

    // Insert nodes into the Huffman tree
    insertNode(root, 'a', 4);
    insertNode(root, 'b', 3);
    insertNode(root, 'c', 2);
    insertNode(root, 'd', 1);

    // Perform Huffman encoding
    huffmanEncoding(root);

    return 0;
}