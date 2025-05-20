//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int freq;
    char ch;
    struct node *left, *right;
} node;

typedef struct min_heap {
    int size;
    int capacity;
    node **arr;
} min_heap;

min_heap *create_min_heap(int capacity) {
    min_heap *heap = (min_heap *)malloc(sizeof(min_heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (node **)malloc(capacity * sizeof(node *));
    return heap;
}

void swap_nodes(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(min_heap *heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left]->freq < heap->arr[smallest]->freq) {
        smallest = left;
    }

    if (right < heap->size && heap->arr[right]->freq < heap->arr[smallest]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        swap_nodes(&heap->arr[i], &heap->arr[smallest]);
        min_heapify(heap, smallest);
    }
}

node *extract_min(min_heap *heap) {
    if (heap->size <= 0) {
        return NULL;
    }

    node *root = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    min_heapify(heap, 0);

    return root;
}

void insert_node(min_heap *heap, node *n) {
    if (heap->size == heap->capacity) {
        return;
    }

    heap->arr[heap->size++] = n;

    int i = heap->size - 1;

    while (i > 0 && heap->arr[i]->freq < heap->arr[(i - 1) / 2]->freq) {
        swap_nodes(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

node *build_huffman_tree(char *text, int len) {
    int freq[256] = {0};

    for (int i = 0; i < len; i++) {
        freq[text[i]]++;
    }

    min_heap *heap = create_min_heap(len);

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            node *n = (node *)malloc(sizeof(node));
            n->freq = freq[i];
            n->ch = i;
            n->left = NULL;
            n->right = NULL;

            insert_node(heap, n);
        }
    }

    while (heap->size > 1) {
        node *left = extract_min(heap);
        node *right = extract_min(heap);

        node *parent = (node *)malloc(sizeof(node));
        parent->freq = left->freq + right->freq;
        parent->ch = '\0';
        parent->left = left;
        parent->right = right;

        insert_node(heap, parent);
    }

    return extract_min(heap);
}

void print_codes(node *root, char *code, int len) {
    if (root == NULL) {
        return;
    }

    if (root->ch != '\0') {
        printf("%c: %s\n", root->ch, code);
        return;
    }

    print_codes(root->left, strcat(code, "0"), len + 1);
    print_codes(root->right, strcat(code, "1"), len + 1);
}

int main() {
    char text[] = "Huffman Coding";
    int len = strlen(text);

    node *root = build_huffman_tree(text, len);

    char code[len];
    code[0] = '\0';

    print_codes(root, code, 0);

    return 0;
}