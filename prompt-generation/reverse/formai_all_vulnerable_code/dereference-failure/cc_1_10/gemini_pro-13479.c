//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    int freq;
    struct node *left;
    struct node *right;
} node;

typedef struct heap {
    int size;
    int capacity;
    node **array;
} heap;

heap *create_heap(int capacity) {
    heap *h = (heap *)malloc(sizeof(heap));
    h->size = 0;
    h->capacity = capacity;
    h->array = (node **)malloc(sizeof(node *) * capacity);
    return h;
}

void swap_nodes(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(heap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->array[left]->freq < h->array[smallest]->freq) {
        smallest = left;
    }

    if (right < h->size && h->array[right]->freq < h->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        swap_nodes(&h->array[i], &h->array[smallest]);
        min_heapify(h, smallest);
    }
}

node *extract_min(heap *h) {
    if (h->size == 0) {
        return NULL;
    }

    node *min = h->array[0];
    h->array[0] = h->array[h->size - 1];
    h->size--;

    min_heapify(h, 0);

    return min;
}

void insert_node(heap *h, node *n) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->array = (node **)realloc(h->array, sizeof(node *) * h->capacity);
    }

    h->array[h->size] = n;
    h->size++;

    int i = h->size - 1;
    while (i > 0 && h->array[i]->freq < h->array[(i - 1) / 2]->freq) {
        swap_nodes(&h->array[i], &h->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

node *build_huffman_tree(char *str, int *freq, int size) {
    heap *h = create_heap(size);

    for (int i = 0; i < size; i++) {
        node *n = (node *)malloc(sizeof(node));
        n->data = str[i];
        n->freq = freq[i];
        n->left = NULL;
        n->right = NULL;
        insert_node(h, n);
    }

    while (h->size > 1) {
        node *left = extract_min(h);
        node *right = extract_min(h);

        node *n = (node *)malloc(sizeof(node));
        n->data = '\0';
        n->freq = left->freq + right->freq;
        n->left = left;
        n->right = right;
        insert_node(h, n);
    }

    return extract_min(h);
}

void print_codes(node *root, char *code, int top) {
    if (root->left) {
        code[top] = '0';
        print_codes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = '1';
        print_codes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: %s\n", root->data, code);
    }
}

void huffman_encoding(char *str, int *freq, int size) {
    node *root = build_huffman_tree(str, freq, size);

    char code[100];
    print_codes(root, code, 0);
}

int main() {
    char str[] = "Huffman Coding";
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(str) / sizeof(str[0]);

    huffman_encoding(str, freq, size);

    return 0;
}