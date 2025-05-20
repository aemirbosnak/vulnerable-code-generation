//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cryptic
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct tree_node {
    char data;
    int freq;
    struct tree_node *left;
    struct tree_node *right;
};

struct min_heap {
    struct tree_node **arr;
    int size;
    int capacity;
};

struct tree_node *create_node(char data, int freq) {
    struct tree_node *node = (struct tree_node *)malloc(sizeof(struct tree_node));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct min_heap *create_min_heap(int capacity) {
    struct min_heap *heap = (struct min_heap *)malloc(sizeof(struct min_heap));
    heap->arr = (struct tree_node **)malloc(capacity * sizeof(struct tree_node *));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap_nodes(struct tree_node **a, struct tree_node **b) {
    struct tree_node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(struct min_heap *heap, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < heap->size && heap->arr[left]->freq < heap->arr[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->arr[right]->freq < heap->arr[smallest]->freq)
        smallest = right;
    if (smallest != i) {
        swap_nodes(&heap->arr[i], &heap->arr[smallest]);
        min_heapify(heap, smallest);
    }
}

struct tree_node *extract_min(struct min_heap *heap) {
    struct tree_node *root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    --heap->size;
    min_heapify(heap, 0);
    return root;
}

void insert_node(struct min_heap *heap, struct tree_node *node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->arr[(i - 1) / 2]->freq) {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->arr[i] = node;
}

struct tree_node *build_huffman_tree(int freq[], int size) {
    struct min_heap *heap = create_min_heap(size);
    for (int i = 0; i < size; ++i)
        insert_node(heap, create_node(0, freq[i]));
    while (heap->size > 1) {
        struct tree_node *left = extract_min(heap);
        struct tree_node *right = extract_min(heap);
        struct tree_node *parent = create_node(0, left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        insert_node(heap, parent);
    }
    return extract_min(heap);
}

void print_codes(struct tree_node *root, char code[]) {
    if (root->left) {
        code[strlen(code)] = '0';
        print_codes(root->left, code);
        code[strlen(code) - 1] = '\0';
    }
    if (root->right) {
        code[strlen(code)] = '1';
        print_codes(root->right, code);
        code[strlen(code) - 1] = '\0';
    }
    if (!root->left && !root->right)
        printf("%c: %s\n", root->data, code);
}

void huffman_coding(char data[], int freq[], int size) {
    struct tree_node *root = build_huffman_tree(freq, size);
    char code[100];
    code[0] = '\0';
    print_codes(root, code);
}

int main() {
    char data[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int freq[] = {5, 9, 12, 13, 16, 45, 50, 52, 60, 66, 70, 72, 73, 80, 85, 89, 91, 96, 100, 101, 102, 105, 106, 107, 108};
    int size = sizeof(data) / sizeof(data[0]);
    huffman_coding(data, freq, size);
    return 0;
}