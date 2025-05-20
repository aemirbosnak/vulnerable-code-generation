//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char c;
    int freq;
    struct node *left;
    struct node *right;
} node;

typedef struct heap {
    node *arr;
    int size;
} heap;

heap *heap_create(int size) {
    heap *h = malloc(sizeof(heap));
    h->arr = malloc(sizeof(node) * size);
    h->size = 0;
    return h;
}

void heap_insert(heap *h, node *n) {
    int i = h->size++;
    while (i > 0 && n->freq < h->arr[(i - 1) / 2].freq) {
        h->arr[i] = h->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->arr[i] = *n;
}

node *heap_extract_min(heap *h) {
    node *min = &h->arr[0];
    h->arr[0] = h->arr[--h->size];
    int i = 0;
    while (i < h->size / 2) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < h->size && h->arr[left].freq < h->arr[smallest].freq)
            smallest = left;
        if (right < h->size && h->arr[right].freq < h->arr[smallest].freq)
            smallest = right;
        if (smallest != i) {
            node tmp = h->arr[i];
            h->arr[i] = h->arr[smallest];
            h->arr[smallest] = tmp;
            i = smallest;
        } else
            break;
    }
    return min;
}

void heap_destroy(heap *h) {
    free(h->arr);
    free(h);
}

node *huffman_build_tree(const char *str) {
    int freq[256] = {0};
    for (int i = 0; str[i]; i++)
        freq[str[i]]++;
    heap *h = heap_create(256);
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            node *n = malloc(sizeof(node));
            n->c = i;
            n->freq = freq[i];
            n->left = n->right = NULL;
            heap_insert(h, n);
        }
    }
    while (h->size > 1) {
        node *left = heap_extract_min(h);
        node *right = heap_extract_min(h);
        node *parent = malloc(sizeof(node));
        parent->c = '\0';
        parent->freq = left->freq + right->freq;
        parent->left = left;
        parent->right = right;
        heap_insert(h, parent);
    }
    node *root = heap_extract_min(h);
    heap_destroy(h);
    return root;
}

void huffman_encode(node *root, const char *str, unsigned char *encoded) {
    int len = strlen(str);
    int encoded_len = 0;
    for (int i = 0; i < len; i++) {
        node *curr = root;
        while (curr->left || curr->right) {
            unsigned char bit = str[i] == curr->c ? 0 : 1;
            encoded[encoded_len++] = bit;
            curr = bit ? curr->right : curr->left;
        }
        encoded[encoded_len++] = 1;
    }
    encoded[encoded_len++] = 0;
}

void huffman_decode(node *root, unsigned char *encoded) {
    int len = strlen(encoded);
    int decoded_len = 0;
    char *decoded = malloc(len);
    for (int i = 0;; i++) {
        node *curr = root;
        while (curr->left || curr->right) {
            unsigned char bit = encoded[i];
            curr = bit ? curr->right : curr->left;
        }
        if (curr->c != '\0')
            decoded[decoded_len++] = curr->c;
        if (encoded[i] == 0)
            break;
    }
    decoded[decoded_len] = '\0';
    printf("%s\n", decoded);
}

int main() {
    const char *str = "Hello, World!";
    node *root = huffman_build_tree(str);
    int len = strlen(str);
    unsigned char *encoded = malloc(len * 8 + 1);
    huffman_encode(root, str, encoded);
    huffman_decode(root, encoded);
    return 0;
}