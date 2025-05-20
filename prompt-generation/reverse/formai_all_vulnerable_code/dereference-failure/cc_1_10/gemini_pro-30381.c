//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_CODE 256

typedef struct _node {
    char c;
    unsigned int freq;
    struct _node *left, *right;
} node;

typedef struct _heap {
    node **nodes;
    int size;
} heap;

void swap(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->nodes[left]->freq < h->nodes[smallest]->freq) {
        smallest = left;
    }

    if (right < h->size && h->nodes[right]->freq < h->nodes[smallest]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&h->nodes[i], &h->nodes[smallest]);
        heapify(h, smallest);
    }
}

void buildHeap(heap *h) {
    for (int i = h->size / 2 - 1; i >= 0; i--) {
        heapify(h, i);
    }
}

node *popHeap(heap *h) {
    if (h->size == 0) {
        return NULL;
    }

    node *root = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;
    heapify(h, 0);

    return root;
}

heap *createHeap(node **nodes, int size) {
    heap *h = malloc(sizeof(heap));
    h->nodes = nodes;
    h->size = size;

    buildHeap(h);

    return h;
}

node *createNode(char c, unsigned int freq) {
    node *n = malloc(sizeof(node));
    n->c = c;
    n->freq = freq;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void printCodes(node *root, char *code) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->c, code);
        return;
    }

    printCodes(root->left, strcat(code, "0"));
    printCodes(root->right, strcat(code, "1"));
}

void buildTree(heap *h) {
    while (h->size > 1) {
        node *left = popHeap(h);
        node *right = popHeap(h);

        node *parent = createNode(0, left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        h->nodes[h->size - 1] = parent;
        h->size--;
        heapify(h, 0);
    }
}

heap *createHeapFromFreqs(unsigned int *freqs) {
    node **nodes = malloc(MAX_CHAR_CODE * sizeof(node *));

    for (int i = 0; i < MAX_CHAR_CODE; i++) {
        if (freqs[i] > 0) {
            nodes[i] = createNode(i, freqs[i]);
        } else {
            nodes[i] = NULL;
        }
    }

    return createHeap(nodes, MAX_CHAR_CODE);
}

int main() {
    char *str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    unsigned int freqs[MAX_CHAR_CODE] = {0};

    for (int i = 0; i < strlen(str); i++) {
        freqs[str[i]]++;
    }

    heap *h = createHeapFromFreqs(freqs);
    buildTree(h);

    char code[100] = "";
    printCodes(h->nodes[0], code);

    return 0;
}