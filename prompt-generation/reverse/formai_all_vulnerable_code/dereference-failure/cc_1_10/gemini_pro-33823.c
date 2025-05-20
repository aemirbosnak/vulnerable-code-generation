//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct node {
    char ch;
    int freq;
    struct node *left, *right;
} node;

typedef struct min_heap {
    int size;
    node **arr;
} min_heap;

min_heap *create_min_heap(int capacity) {
    min_heap *heap = (min_heap *) malloc(sizeof(min_heap));
    heap->size = 0;
    heap->arr = (node **) malloc(capacity * sizeof(node *));
    return heap;
}

void min_heap_swap(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heap_min(min_heap *heap, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < heap->size && heap->arr[left]->freq < heap->arr[i]->freq) {
        smallest = left;
    }
    if (right < heap->size && heap->arr[right]->freq < heap->arr[smallest]->freq) {
        smallest = right;
    }
    if (smallest != i) {
        min_heap_swap(&heap->arr[smallest], &heap->arr[i]);
        min_heap_min(heap, smallest);
    }
}

void min_heap_insert(min_heap *heap, node *n) {
    heap->arr[heap->size] = n;
    heap->size++;
    int i = heap->size - 1;
    while (i > 0 && heap->arr[i]->freq < heap->arr[(i - 1) / 2]->freq) {
        min_heap_swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

node *min_heap_extract_min(min_heap *heap) {
    if (heap->size <= 0) {
        return NULL;
    }
    node *min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    min_heap_min(heap, 0);
    return min;
}

void min_heap_build(min_heap *heap) {
    for (int i = (heap->size - 1) / 2; i >= 0; i--) {
        min_heap_min(heap, i);
    }
}

node *create_node(char ch, int freq) {
    node *n = (node *) malloc(sizeof(node));
    n->ch = ch;
    n->freq = freq;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node *huffman_tree(int freq[], char ch[], int size) {
    min_heap *heap = create_min_heap(size);
    for (int i = 0; i < size; i++) {
        node *n = create_node(ch[i], freq[i]);
        min_heap_insert(heap, n);
    }
    min_heap_build(heap);
    while (heap->size > 1) {
        node *left = min_heap_extract_min(heap);
        node *right = min_heap_extract_min(heap);
        node *n = create_node('$', left->freq + right->freq);
        n->left = left;
        n->right = right;
        min_heap_insert(heap, n);
    }
    return min_heap_extract_min(heap);
}

void print_codes(node *root, char code[], int top) {
    if (root->ch != '$') {
        code[top] = root->ch;
        printf("%c: %s\n", root->ch, code);
        return;
    }
    code[top] = '0';
    print_codes(root->left, code, top + 1);
    code[top] = '1';
    print_codes(root->right, code, top + 1);
}

void huffman_coding(int freq[], char ch[], int size) {
    node *root = huffman_tree(freq, ch, size);
    char code[MAX_CHAR];
    print_codes(root, code, 0);
}

int main() {
    char ch[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(ch) / sizeof(ch[0]);
    huffman_coding(freq, ch, size);
    return 0;
}