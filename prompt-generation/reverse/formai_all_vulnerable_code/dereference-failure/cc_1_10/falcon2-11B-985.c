//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int freq;
    struct node *left, *right;
} node;

node* createNode(char word[], int freq) {
    node* newNode = (node*) malloc(sizeof(node));
    strcpy(newNode->word, word);
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(node* root, char word[], int freq) {
    if (root == NULL) {
        root = createNode(word, freq);
    } else {
        if (strcmp(root->word, word) > 0) {
            insert(root->left, word, freq);
        } else if (strcmp(root->word, word) < 0) {
            insert(root->right, word, freq);
        }
    }
}

void buildHuffmanTree(node* root) {
    node* minNode;
    while (root->left!= NULL && root->right!= NULL) {
        minNode = root;
        root = root->left? root->left : root->right;
        root->left = minNode->left;
        root->right = minNode->right;
        free(minNode);
    }
}

void freeNode(node* node) {
    if (node!= NULL) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

int getCodeLength(node* root) {
    int codeLength = 0;
    node* currNode = root;
    while (currNode!= NULL) {
        codeLength += (currNode->freq? 1 : 0) + (currNode->freq? 1 : 0);
        currNode = currNode->freq? currNode->left : currNode->right;
    }
    return codeLength;
}

void generateHuffmanCode(node* root) {
    int codeLength = getCodeLength(root);
    node* currNode = root;
    char code[codeLength];
    int i = 0;
    while (currNode!= NULL) {
        code[i++] = currNode->word[0];
        currNode = currNode->freq? currNode->left : currNode->right;
    }
    code[i] = '\0';
    printf("Huffman Code: %s\n", code);
}

void encode(node* root, char* word) {
    if (strcmp(word, root->word) == 0) {
        generateHuffmanCode(root);
    }
}

void decode(node* root, char* word) {
    char code[getCodeLength(root)];
    node* currNode = root;
    int i = 0;
    while (currNode!= NULL) {
        code[i++] = currNode->word[0];
        currNode = currNode->freq? currNode->left : currNode->right;
    }
    code[i] = '\0';
    printf("Decoded word: %s\n", word);
}

int main() {
    node* root = NULL;
    char words[4][MAX_WORD_LENGTH] = {"a", "b", "c", "d"};
    int freq[4] = {2, 3, 1, 4};
    for (int i = 0; i < 4; i++) {
        insert(root, words[i], freq[i]);
    }
    buildHuffmanTree(root);
    generateHuffmanCode(root);
    encode(root, "b");
    decode(root, "b");
    encode(root, "a");
    decode(root, "a");
    encode(root, "d");
    decode(root, "d");
    encode(root, "c");
    decode(root, "c");
    freeNode(root);
    return 0;
}