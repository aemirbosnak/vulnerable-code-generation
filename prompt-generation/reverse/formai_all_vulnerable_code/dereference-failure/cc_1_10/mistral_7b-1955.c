//MISTRAL-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char data;
    unsigned char freq;
    struct Node* left;
    struct Node* right;
} Node;

void getFrequency(const char* input, int* frequencies, int length) {
    for (int i = 0; i < length; ++i) {
        frequencies[input[i]]++;
    }
}

void buildHuffmanTree(int* frequencies, Node** root, int size) {
    Node** nodes = malloc(size * sizeof(Node*));

    for (int i = 0; i < size; ++i) {
        nodes[i] = malloc(sizeof(Node));
        nodes[i]->data = (char)i;
        nodes[i]->freq = frequencies[i];
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }

    for (int i = 0; i < size - 1; ++i) {
        int min1 = i, min2 = i + 1;

        if (nodes[min1]->freq > nodes[min2]->freq) {
            min1 = min2;
            min2 = i;
        }

        nodes[i] = nodes[min1];

        if (i != size - 2) {
            nodes[i + 1]->freq += nodes[min1]->freq;
        }

        free(nodes[min1]);
    }

    *root = nodes[size - 1];

    for (int i = 0; i < size; ++i) {
        free(nodes[i]);
    }

    free(nodes);
}

void encode(Node* root, char* code, const char data) {
    if (root == NULL) {
        return;
    }

    if (root->data == data) {
        printf("%c: %s\n", data, code);
        return;
    }

    encode(root->left, code, data);
    encode(root->right, code, data);

    code[root->freq]++;
}

int main(void) {
    const char input[] = "This is a Huffman coding example.";

    int length = sizeof(input) / sizeof(input[0]);
    int frequencies[256] = {0};

    getFrequency(input, frequencies, length);

    Node* root = NULL;
    buildHuffmanTree(frequencies, &root, 256);

    char code[256] = {0};
    encode(root, code, 0);

    free(root);

    printf("Generated Huffman code:\n");
    for (int i = 0; i < 256; ++i) {
        if (code[i] > 0) {
            putchar(i);
            putchar(':');
            printf("%s\n", code + i);
        }
    }

    return 0;
}