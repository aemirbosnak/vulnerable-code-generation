//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct {
    char c;
    int count;
} CharInfo;

typedef struct {
    char c;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
} HuffmanNode;

typedef struct {
    HuffmanNode* root;
    int size;
} HuffmanTree;

void freeHuffmanTree(HuffmanTree* tree) {
    if (tree->root!= NULL) {
        freeHuffmanTree(tree->root->left);
        freeHuffmanTree(tree->root->right);
        free(tree->root);
    }
    free(tree);
}

void printHuffmanTree(HuffmanNode* node) {
    if (node == NULL) {
        return;
    }
    printf("%c ", node->c);
    printHuffmanTree(node->left);
    printHuffmanTree(node->right);
}

void buildHuffmanTree(HuffmanNode** root, CharInfo* infos, int size) {
    if (size == 0) {
        *root = NULL;
        return;
    }

    int maxCount = -1;
    int maxIndex = -1;

    for (int i = 0; i < size; i++) {
        if (infos[i].count > maxCount) {
            maxCount = infos[i].count;
            maxIndex = i;
        }
    }

    HuffmanNode* newNode = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    newNode->c = infos[maxIndex].c;
    newNode->left = NULL;
    newNode->right = NULL;

    infos[maxIndex].count = 0;
    infos[maxIndex].c = 0;

    HuffmanNode* current = *root;
    HuffmanNode* left = NULL;
    HuffmanNode* right = NULL;

    for (int i = 0; i < size; i++) {
        if (infos[i].count > 0) {
            if (infos[i].c == newNode->c) {
                left = (HuffmanNode*) malloc(sizeof(HuffmanNode));
                left->c = infos[i].c;
                left->left = NULL;
                left->right = NULL;
                current->left = left;
                left = NULL;
            } else {
                right = (HuffmanNode*) malloc(sizeof(HuffmanNode));
                right->c = infos[i].c;
                right->left = NULL;
                right->right = NULL;
                current->right = right;
                right = NULL;
            }
            infos[i].count = 0;
            infos[i].c = 0;
        } else {
            infos[i].count = 0;
            infos[i].c = 0;
        }
    }

    if (left!= NULL) {
        current->left = left;
        current = left;
    }

    if (right!= NULL) {
        current->right = right;
        current = right;
    }

    *root = newNode;

    buildHuffmanTree(&(newNode->left), infos, size - 1);
    buildHuffmanTree(&(newNode->right), infos, size - 1);
}

void huffmanCompression(HuffmanTree* tree, char* input, char* output) {
    for (int i = 0; i < strlen(input); i++) {
        int index = input[i];
        if (tree->root == NULL) {
            output[i] = input[i];
            continue;
        }

        int bitCount = 0;
        HuffmanNode* current = tree->root;
        while (current!= NULL) {
            if (current->c == index) {
                bitCount = 1;
                if (current->left!= NULL) {
                    bitCount += 1;
                }
                if (current->right!= NULL) {
                    bitCount += 1;
                }
                current = current->left;
                continue;
            }
            current = current->right;
        }

        if (bitCount == 0) {
            output[i] = index;
            continue;
        }

        if (bitCount == 1) {
            output[i] = (bitCount & 1)? 0 : 1;
            continue;
        }

        if (bitCount == 2) {
            output[i] = (bitCount & 3)? 0 : 1;
            continue;
        }

        output[i] = 0;
        int bit = 0;
        for (int j = 0; j < 3; j++) {
            if (bitCount & (1 << j)) {
                bit |= 1 << j;
            }
        }
        output[i] |= bit;

        if (current->left!= NULL) {
            huffmanCompression(tree->root->left, input, output);
            continue;
        }

        if (current->right!= NULL) {
            huffmanCompression(tree->root->right, input, output);
            continue;
        }
    }
}

int main() {
    char input[1024];
    char output[1024];
    char buf[1024];

    printf("Enter the input text: ");
    fgets(input, sizeof(input), stdin);

    int size = strlen(input);
    CharInfo infos[size];
    for (int i = 0; i < size; i++) {
        infos[i].c = input[i];
        infos[i].count = 0;
    }

    for (int i = 0; i < size; i++) {
        infos[input[i] - 'a'].count++;
    }

    HuffmanTree tree;
    tree.root = NULL;
    tree.size = size;

    buildHuffmanTree(&(tree.root), infos, size);

    huffmanCompression(tree.root, input, output);

    printf("Input: %s\n", input);
    printf("Compressed output: %s\n", output);
    printf("Decoded output: %s\n", buf);

    return 0;
}