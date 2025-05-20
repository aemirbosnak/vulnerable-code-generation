//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    int freq;
    struct node *left, *right;
} node;

node *create_node(char data, int freq) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->freq = freq;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void swap_nodes(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

struct min_heap {
    int size;
    int capacity;
    node **array;
};

struct min_heap *create_min_heap(int capacity) {
    struct min_heap *min_heap = (struct min_heap *)malloc(sizeof(struct min_heap));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (node **)malloc(capacity * sizeof(node *));
    return min_heap;
}

void min_heapify(struct min_heap *min_heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < min_heap->size && min_heap->array[left]->freq < min_heap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < min_heap->size && min_heap->array[right]->freq < min_heap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        swap_nodes(&min_heap->array[smallest], &min_heap->array[idx]);
        min_heapify(min_heap, smallest);
    }
}

int is_size_one(struct min_heap *min_heap) {
    return (min_heap->size == 1);
}

node *extract_min(struct min_heap *min_heap) {
    node *temp = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    --min_heap->size;
    min_heapify(min_heap, 0);
    return temp;
}

void insert_min_heap(struct min_heap *min_heap, node *node) {
    ++min_heap->size;
    int i = min_heap->size - 1;
    while (i && node->freq < min_heap->array[(i - 1) / 2]->freq) {
        min_heap->array[i] = min_heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    min_heap->array[i] = node;
}

void build_min_heap(struct min_heap *min_heap) {
    int n = min_heap->size;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        min_heapify(min_heap, i);
    }
}

node *build_huffman_tree(char data[], int freq[], int size) {
    struct min_heap *min_heap = create_min_heap(size);

    for (int i = 0; i < size; ++i) {
        min_heap->array[i] = create_node(data[i], freq[i]);
    }

    min_heap->size = size;
    build_min_heap(min_heap);

    while (!is_size_one(min_heap)) {
        node *left = extract_min(min_heap);
        node *right = extract_min(min_heap);

        node *top = create_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insert_min_heap(min_heap, top);
    }

    return extract_min(min_heap);
}

void print_codes(node *root, char code[], int top) {
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

void huffman_encoding(char data[], int freq[], int size) {
    node *root = build_huffman_tree(data, freq, size);

    char code[100];
    print_codes(root, code, 0);
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    huffman_encoding(arr, freq, size);

    return 0;
}