//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int freq;
    char data;
    struct node *left;
    struct node *right;
} node;

typedef struct min_heap {
    int size;
    int capacity;
    struct node **array;
} min_heap;

min_heap *create_min_heap(int capacity) {
    min_heap *heap = (min_heap *)malloc(sizeof(min_heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (node **)malloc(capacity * sizeof(node *));
    return heap;
}

void swap_nodes(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(min_heap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        swap_nodes(&heap->array[smallest], &heap->array[idx]);
        min_heapify(heap, smallest);
    }
}

void insert_node(min_heap *heap, node *n) {
    heap->size++;
    int i = heap->size - 1;

    while (i && n->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->array[i] = n;
}

node *extract_min(min_heap *heap) {
    node *temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    min_heapify(heap, 0);
    return temp;
}

void print_codes(node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void build_huffman_tree(char data[], int freq[], int size) {
    min_heap *heap = create_min_heap(size);

    for (int i = 0; i < size; i++) {
        node *n = (node *)malloc(sizeof(node));
        n->data = data[i];
        n->freq = freq[i];
        n->left = NULL;
        n->right = NULL;
        insert_node(heap, n);
    }

    while (heap->size != 1) {
        node *left = extract_min(heap);
        node *right = extract_min(heap);

        node *parent = (node *)malloc(sizeof(node));
        parent->data = '\0';
        parent->freq = left->freq + right->freq;
        parent->left = left;
        parent->right = right;

        insert_node(heap, parent);
    }

    int arr[100];
    int top = 0;
    print_codes(heap->array[0], arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    build_huffman_tree(data, freq, size);

    return 0;
}