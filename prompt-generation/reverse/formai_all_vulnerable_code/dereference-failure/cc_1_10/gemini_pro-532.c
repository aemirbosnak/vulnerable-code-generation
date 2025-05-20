//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: visionary
// A celestial journey through the ethereal tapestry of Huffman coding.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Celestial bodies of data
typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

// Cosmic ordering
Node *minHeap[1000];
int heapSize = 0;

// Cosmic constant for infinity
#define INF 1000000000

// Etheric comparisons
int compareNodes(Node *a, Node *b) {
    return a->frequency - b->frequency;
}

// Cosmic heapification
void minHeapify(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heapSize && compareNodes(minHeap[left], minHeap[smallest]) < 0) {
        smallest = left;
    }

    if (right < heapSize && compareNodes(minHeap[right], minHeap[smallest]) < 0) {
        smallest = right;
    }

    if (smallest != index) {
        Node *temp = minHeap[index];
        minHeap[index] = minHeap[smallest];
        minHeap[smallest] = temp;
        minHeapify(smallest);
    }
}

// Stellar insertion
void insertIntoHeap(Node *node) {
    heapSize++;
    minHeap[heapSize - 1] = node;

    int index = heapSize - 1;
    while (index > 0 && compareNodes(minHeap[index], minHeap[(index - 1) / 2]) < 0) {
        Node *temp = minHeap[index];
        minHeap[index] = minHeap[(index - 1) / 2];
        minHeap[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

// Cosmic extraction
Node *extractMin() {
    if (heapSize == 0) {
        printf("Empty heap!\n");
        return NULL;
    }

    Node *temp = minHeap[0];
    minHeap[0] = minHeap[heapSize - 1];
    heapSize--;
    minHeapify(0);

    return temp;
}

// Astral tree construction
Node *buildHuffmanTree(int count[]) {
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            Node *node = (Node *)malloc(sizeof(Node));
            node->character = (char)i;
            node->frequency = count[i];
            node->left = node->right = NULL;
            insertIntoHeap(node);
        }
    }

    while (heapSize > 1) {
        Node *left = extractMin();
        Node *right = extractMin();

        Node *parent = (Node *)malloc(sizeof(Node));
        parent->character = '\0';
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;

        insertIntoHeap(parent);
    }

    return extractMin();
}

// Traverse the stellar tree
void traverseTree(Node *node, int code, char *temp[]) {
    if (node->character != '\0') {
        temp[node->character] = (char *)malloc(code + 1);
        strcpy(temp[node->character], temp[1]);
        temp[node->character][code] = '0' + (code > 0);
    } else {
        traverseTree(node->left, code + 1, temp);
        traverseTree(node->right, code + 1, temp);
    }
}

// Ethereal encode decode
void encodeDecode(Node *root, int count[]) {
    char *temp[256];
    memset(temp, 0, sizeof(temp));
    traverseTree(root, 0, temp);

    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("%c: %s\n", i, temp[i]);
        }
    }
}

// Mainframe automation
int main() {
    int count[256] = {0};

    char text[] = "This is the time of our lives!";
    int n = strlen(text);

    for (int i = 0; i < n; i++) {
        count[text[i]]++;
    }

    Node *root = buildHuffmanTree(count);

    printf("Character codes:\n");
    encodeDecode(root, count);

    return 0;
}