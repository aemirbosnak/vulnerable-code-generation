//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100
#define MAX_CODE_LEN 20 

typedef struct node {
    unsigned char data;
    long freq;
    struct node *left, *right;
} node;

node* createNode(unsigned char data, long freq) {
    node* temp = (node*)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

typedef struct heap {
    unsigned size, capacity;
    node** data;
} heap;

heap* createHeap(unsigned capacity) {
    heap* h = (heap*)malloc(sizeof(heap));
    h->size = 0;
    h->capacity = capacity;
    h->data = (node**)malloc(capacity * sizeof(node*));
    return h;
}

void swapNodes(node** n1, node** n2) {
    node* temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void heapify(heap* h, int idx) {
    int min = idx, left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < h->size && h->data[left]->freq < h->data[min]->freq) min = left;
    if (right < h->size && h->data[right]->freq < h->data[min]->freq) min = right;
    if (min != idx) {
        swapNodes(&h->data[min], &h->data[idx]);
        heapify(h, min);
    }
}

node* extractMin(heap* h) {
    node* temp = h->data[0];
    h->data[0] = h->data[h->size - 1];
    --h->size;
    heapify(h, 0);
    return temp;
}

void insertIntoHeap(heap* h, node* n) {
    ++h->size;
    int i = h->size - 1;
    while (i && n->freq < h->data[(i - 1) / 2]->freq) {
        h->data[i] = h->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->data[i] = n;
}

heap* createAndBuildHeap(char data[], long freq[], unsigned size) {
    heap* h = createHeap(size);
    for (int i = 0; i < size; ++i) {
        node* temp = createNode(data[i], freq[i]);
        insertIntoHeap(h, temp);
    }
    return h;
}

node* buildHuffmanTree(char data[], long freq[], unsigned size) {
    heap* h = createAndBuildHeap(data, freq, size);
    while (h->size != 1) {
        node* n1 = extractMin(h);
        node* n2 = extractMin(h);
        node* temp = createNode('$', n1->freq + n2->freq);
        temp->left = n1;
        temp->right = n2;
        insertIntoHeap(h, temp);
    }
    return extractMin(h);
}

void printCode(FILE* fp, node* root, char code[], int top) {
    if (!root) return;
    if (root->data != '$') {
        code[top] = '\0';
        fprintf(fp, "[%c:%s]\n", root->data, code);
        return;
    }
    code[top] = '0';
    printCode(fp, root->left, code, top + 1);
    code[top] = '1';
    printCode(fp, root->right, code, top + 1);
}

void HuffmanCodes(char data[], long freq[], unsigned size, char fileName[]) {
    node* root = buildHuffmanTree(data, freq, size);
    char code[MAX_TREE_HT];
    FILE* fp = fopen(fileName, "w");
    if (!fp) {
        printf("Error: Unable to open file.\n");
        return;
    }
    printCode(fp, root, code, 0);
    fclose(fp);
    printf("Huffman encodings printed to %s\n", fileName);
}

int main() {
    char dataset[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    long freq[] = {18, 12, 8, 15, 13, 10};
    unsigned size = sizeof(dataset) / sizeof(dataset[0]);
    char outputFile[] = "huffmanEncoding.txt";
    HuffmanCodes(dataset, freq, size, outputFile);
    return 0;
}