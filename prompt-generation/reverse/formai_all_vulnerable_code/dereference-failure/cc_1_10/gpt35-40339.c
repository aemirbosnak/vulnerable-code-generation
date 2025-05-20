//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100
#define MAX_ENCODED_STRING_SIZE 1000

/* node structure for huffman tree */
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

/* min heap structure */
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

/* encoding structure */
struct encoding {
    char symbol;
    char code[MAX_TREE_HT];
};

/* helper functions */
struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    int n = minHeap->size - 1;

    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);

    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top, struct encoding *table, int *index) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, table, index);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, table, index);
    }

    if (isLeaf(root)) {
        table[*index].symbol = root->data;
        for (int i = 0; i < top; ++i) {
            char c = (char)(((int)'0') + arr[i]);
            strcat(table[*index].code, &c);
        }
        (*index)++;
    }
}

void HuffmanCodes(char data[], int freq[], int size, struct encoding *table) {
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    int index = 0;
    printCodes(root, arr, top, table, &index);
}

void encodeMessage(char message[], char encodedString[], struct encoding *table, int tableSize) {
    int messageSize = strlen(message);
    for (int i = 0; i < messageSize; i++) {
        for (int j = 0; j < tableSize; j++) {
            if (table[j].symbol == message[i]) {
                strcat(encodedString, table[j].code);
            }
        }
    }
}

char* decodeMessage(char encodedMessage[], struct MinHeapNode* root) {
    char *decodedMessage = (char*)malloc(sizeof(char) * MAX_ENCODED_STRING_SIZE);
    struct MinHeapNode* currentNode = root;

    int i = 0;
    while (encodedMessage[i]) {
        if (encodedMessage[i] == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (isLeaf(currentNode)) {
            strncat(decodedMessage, &currentNode->data, 1);
            currentNode = root;
        }
        i++;
    }

    return decodedMessage;
}

/* main function */
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct encoding table[size];
    HuffmanCodes(data, freq, size, table);

    char message[] = "abbccddeeff";
    char encodedMessage[MAX_ENCODED_STRING_SIZE] = "";
    encodeMessage(message, encodedMessage, table, size);
    printf("Encoded Message: %s\n", encodedMessage);

    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    char *decodedMessage = decodeMessage(encodedMessage, root);
    printf("Decoded Message: %s\n", decodedMessage);

    free(decodedMessage);

    return 0;
}