//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node {
    char symbol;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

void huffman_encode(Node* root, FILE* file) {
    fprintf(file, "%c", root->symbol);
    switch (root->symbol) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        fprintf(file, "0");
        break;
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        fprintf(file, "1");
        break;
    }
    if (root->left)
        huffman_encode(root->left, file);
    if (root->right)
        huffman_encode(root->right, file);
}

int main() {
    FILE* file = fopen("huffman.txt", "w");
    Node* root = (Node*)malloc(sizeof(Node));
    root->symbol = 'a';
    root->frequency = 5;
    root->left = NULL;
    root->right = NULL;

    Node* second = (Node*)malloc(sizeof(Node));
    second->symbol = 'e';
    second->frequency = 3;
    second->left = NULL;
    second->right = NULL;

    Node* third = (Node*)malloc(sizeof(Node));
    third->symbol = 'i';
    third->frequency = 2;
    third->left = NULL;
    third->right = NULL;

    Node* fourth = (Node*)malloc(sizeof(Node));
    fourth->symbol = 'o';
    fourth->frequency = 4;
    fourth->left = NULL;
    fourth->right = NULL;

    Node* fifth = (Node*)malloc(sizeof(Node));
    fifth->symbol = 'u';
    fifth->frequency = 1;
    fifth->left = NULL;
    fifth->right = NULL;

    root->left = second;
    second->left = third;
    third->left = fourth;
    fourth->left = fifth;

    huffman_encode(root, file);

    fclose(file);
    return 0;
}