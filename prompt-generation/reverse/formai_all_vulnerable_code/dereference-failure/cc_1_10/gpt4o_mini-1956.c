//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct NobleNode {
    char ch;
    int freq;
    struct NobleNode *left, *right;
} NobleNode;

typedef struct Knight {
    NobleNode *nodes[MAX_TREE_NODES];
    int size;
} Knight;

NobleNode* createNobleNode(char ch, int freq) {
    NobleNode* node = (NobleNode*) malloc(sizeof(NobleNode));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

Knight* createKnight() {
    Knight* knight = (Knight*) malloc(sizeof(Knight));
    knight->size = 0;
    return knight;
}

void insertNobleNode(Knight* knight, NobleNode* node) {
    knight->nodes[knight->size] = node;
    knight->size++;
}

void swapNobleNodes(NobleNode** a, NobleNode** b) {
    NobleNode* temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleUp(Knight* knight) {
    for (int i = knight->size - 1; i > 0; i--) {
        if (knight->nodes[i]->freq < knight->nodes[i-1]->freq) {
            swapNobleNodes(&knight->nodes[i], &knight->nodes[i-1]);
        } else {
            break;
        }
    }
}

NobleNode* extractMin(Knight* knight) {
    if (knight->size == 0) {
        return NULL;
    }
    NobleNode* minNode = knight->nodes[0];
    knight->size--;
    for (int i = 0; i < knight->size; i++) {
        knight->nodes[i] = knight->nodes[i + 1];
    }
    return minNode;
}

NobleNode* buildHuffmanTree(Knight* knight) {
    while (knight->size > 1) {
        NobleNode* left = extractMin(knight);
        NobleNode* right = extractMin(knight);
        NobleNode* merged = createNobleNode('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        insertNobleNode(knight, merged);
        bubbleUp(knight);
    }
    return extractMin(knight);
}

void printHuffmanCodes(NobleNode* root, char* array, int top) {
    if (root->left) {
        array[top] = '0';
        printHuffmanCodes(root->left, array, top + 1);
    }

    if (root->right) {
        array[top] = '1';
        printHuffmanCodes(root->right, array, top + 1);
    }

    if (!root->left && !root->right) {
        printf("Noble Character: %c | Code: ", root->ch);
        for (int i = 0; i < top; i++)
            printf("%c", array[i]);
        printf("\n");
    }
}

void freeTree(NobleNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void gatherFrequencies(const char* str, int* freq) {
    for (int i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;
}

int main() {
    printf("~~~ The Grand Huffman Coding Quest ~~~\n");

    char inputString[1024];
    printf("Enter thy parchment text: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = 0; // Remove trailing newline

    int freq[MAX_TREE_NODES] = {0};
    gatherFrequencies(inputString, freq);

    Knight* knight = createKnight();
    
    for (int i = 0; i < MAX_TREE_NODES; i++) {
        if (freq[i] > 0) {
            insertNobleNode(knight, createNobleNode((char)i, freq[i]));
        }
    }

    NobleNode* huffmanTreeRoot = buildHuffmanTree(knight);
    
    char huffmanCode[MAX_TREE_NODES];
    printf("\n~~~ Noble Codes for Characters ~~~\n");
    printHuffmanCodes(huffmanTreeRoot, huffmanCode, 0);

    freeTree(huffmanTreeRoot);
    free(knight);

    printf("~~~ The quest for compressed data hath ended! ~~~\n");
    return 0;
}