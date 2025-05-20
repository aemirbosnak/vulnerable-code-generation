//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MAX_TREE_HT 100

typedef struct node {
    char data;
    unsigned frequency;
    struct node *left, *right;
} node;

typedef struct min_heap {
    unsigned size;
    unsigned capacity;
    node** array;
} min_heap;

typedef struct code {
    char bits[MAX_TREE_HT];
    int length;
} code;

min_heap* create_min_heap(unsigned capacity) {
    min_heap* heap = (min_heap*) malloc(sizeof(min_heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (node**) malloc(heap->capacity * sizeof(node*));
    return heap;
}

node* create_node(char data, unsigned frequency) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->left = new_node->right = NULL;
    new_node->data = data;
    new_node->frequency = frequency;
    return new_node;
}

void swap_nodes(node** a, node** b) {
    node* temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(min_heap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != index) {
        swap_nodes(&heap->array[smallest], &heap->array[index]);
        min_heapify(heap, smallest);
    }
}

bool is_leaf(node* node) {
    return !(node->left) && !(node->right);
}

min_heap* build_min_heap(char data[], int frequency[], int size) {
    min_heap* heap = create_min_heap(size);
    for (int i = 0; i < size; ++i) {
        heap->array[i] = create_node(data[i], frequency[i]);
    }
    heap->size = size;
    for (int i = (heap->size - 1) / 2; i >= 0; --i) {
        min_heapify(heap, i);
    }
    return heap;
}

node* extract_min_node(min_heap* heap) {
    node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    min_heapify(heap, 0);
    return temp;
}

void insert_node(min_heap* heap, node* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void print_codes(node* root, code* c, FILE* output) {
    if (!root) {
        return;
    }
    if (is_leaf(root)) {
        fprintf(output, "%c:%s\n", root->data, c->bits);
    }
    ++c->length;
    c->bits[c->length - 1] = '0';
    print_codes(root->left, c, output);
    c->bits[c->length - 1] = '1';
    print_codes(root->right, c, output);
    --c->length;
}

void huffman_code(char data[], int freq[], int size, FILE* output) {
    node *left, *right, *top;
    min_heap* heap = build_min_heap(data, freq, size);
    while (heap->size != 1) {
        left = extract_min_node(heap);
        right = extract_min_node(heap);
        top = create_node('#', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insert_node(heap, top);
    }
    code* c = (code*) malloc(sizeof(code));
    print_codes(extract_min_node(heap), c, output);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    FILE* output = fopen("codes.txt", "w");
    if (output == NULL)
    {
        printf("Error opening codes.txt!");
        exit(1);
    }
    huffman_code(data, freq, size, output);
    fclose(output);
    return 0;
}