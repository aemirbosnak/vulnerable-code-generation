//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char symbol;
    int frequency;
    struct Node *left;
    struct Node *right;
};

struct Node *buildTree(int freq[], int n) {
    struct Node *root = (struct Node*)malloc(sizeof(struct Node));
    root->symbol = '\0';
    root->frequency = 0;
    root->left = NULL;
    root->right = NULL;

    for (int i = 0; i < n; i++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->symbol = freq[i];
        newNode->frequency = freq[i];
        newNode->left = NULL;
        newNode->right = NULL;

        if (i == 0) {
            root->left = newNode;
        } else {
            struct Node *parent = root;

            while (parent->left!= NULL && freq[i] < parent->left->frequency) {
                parent = parent->left;
            }

            newNode->left = parent->left;
            parent->left = newNode;
        }

        if (i == n-1) {
            root->right = newNode;
        } else {
            struct Node *parent = root;

            while (parent->right!= NULL && freq[i] < parent->right->frequency) {
                parent = parent->right;
            }

            newNode->right = parent->right;
            parent->right = newNode;
        }
    }

    return root;
}

int huffmanEncoding(char *input, int inputLength, struct Node *root) {
    int currentSymbol = root->symbol;
    int currentLength = 0;

    for (int i = 0; i < inputLength; i++) {
        if (input[i] == currentSymbol) {
            currentLength++;
        } else {
            int newLength = currentLength + 1;
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->symbol = input[i];
            newNode->frequency = 1;
            newNode->left = root->left;
            newNode->right = root->right;
            root->left = newNode;

            currentSymbol = input[i];
            currentLength = 1;
        }
    }

    return currentLength;
}

int main() {
    int freq[] = {5, 3, 2, 4, 1};
    struct Node *root = buildTree(freq, 5);
    char input[] = "hello";
    int inputLength = strlen(input);
    int encodedLength = huffmanEncoding(input, inputLength, root);
    printf("Encoded length: %d\n", encodedLength);
    return 0;
}