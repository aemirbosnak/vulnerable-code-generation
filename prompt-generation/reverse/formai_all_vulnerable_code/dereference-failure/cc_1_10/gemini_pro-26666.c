//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct node {
    char data;
    int freq;
    struct node *left;
    struct node *right;
} node;

typedef struct heap {
    int size;
    node **arr;
} heap;

heap *createHeap(int max_size) {
    heap *h = malloc(sizeof(heap));
    h->size = 0;
    h->arr = malloc(sizeof(node *) * max_size);
    return h;
}

void swap(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->arr[left]->freq < h->arr[smallest]->freq) {
        smallest = left;
    }

    if (right < h->size && h->arr[right]->freq < h->arr[smallest]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

void insert(heap *h, node *n) {
    h->arr[h->size++] = n;
    int i = h->size - 1;

    while (i > 0 && h->arr[i]->freq < h->arr[(i - 1) / 2]->freq) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

node *extractMin(heap *h) {
    node *min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    heapify(h, 0);

    return min;
}

node *buildHuffmanTree(heap *h) {
    while (h->size > 1) {
        node *left = extractMin(h);
        node *right = extractMin(h);

        node *parent = malloc(sizeof(node));
        parent->freq = left->freq + right->freq;
        parent->left = left;
        parent->right = right;

        insert(h, parent);
    }

    return extractMin(h);
}

void printCodes(node *root, char *code) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->data, code);
        return;
    }

    printCodes(root->left, strcat(code, "0"));
    printCodes(root->right, strcat(code, "1"));
}

void huffmanEncoding(char *data) {
    int freq[MAX_SIZE] = {0};
    int i;

    for (i = 0; data[i] != '\0'; i++) {
        freq[data[i]]++;
    }

    heap *h = createHeap(MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++) {
        if (freq[i] > 0) {
            node *n = malloc(sizeof(node));
            n->data = i;
            n->freq = freq[i];
            n->left = NULL;
            n->right = NULL;

            insert(h, n);
        }
    }

    node *root = buildHuffmanTree(h);

    char code[MAX_SIZE] = "";
    printCodes(root, code);
}

int main() {
    char data[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    huffmanEncoding(data);
    return 0;
}