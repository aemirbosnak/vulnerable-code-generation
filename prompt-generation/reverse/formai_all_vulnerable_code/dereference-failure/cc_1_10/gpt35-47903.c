//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100
#define MAX_CODE_LEN 100

typedef struct node {
    char data;
    unsigned freq;
    struct node *left, *right;
} node;

typedef struct min_heap {
    unsigned size;
    unsigned capacity;
    node **array;
} min_heap;

typedef struct codebook {
    char symbol;
    char code[MAX_CODE_LEN];
} codebook;

node* new_node(char data, unsigned freq) {
    node* temp = (node *)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

min_heap* create_min_heap(unsigned capacity) {
    min_heap* heap = (min_heap *)malloc(sizeof(min_heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (node **)malloc(heap->capacity * sizeof(node *));
    return heap;
}

void swap_node(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(min_heap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;

    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;

    if (smallest != index) {
        swap_node(&heap->array[smallest], &heap->array[index]);
        min_heapify(heap, smallest);
    }
}

int is_size_one(min_heap* heap) {
    return (heap->size == 1);
}

node* extract_min(min_heap* heap) {
    node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    min_heapify(heap, 0);
    return temp;
}

void insert_node(min_heap* heap, node* new_node) {
    ++heap->size;
    int i = heap->size - 1;

    while (i && new_node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->array[i] = new_node;
}

min_heap* build_min_heap(char data[], int freq[], int size) {
    min_heap* heap = create_min_heap(size);

    for (int i = 0; i < size; ++i)
        heap->array[i] = new_node(data[i], freq[i]);

    heap->size = size;
    int i = size / 2 - 1;

    while (i >= 0) {
        min_heapify(heap, i);
        --i;
    }

    return heap;
}

node* build_huff_tree(char data[], int freq[], int size) {
    node *left, *right, *top;
    min_heap* heap = build_min_heap(data, freq, size);

    while (!is_size_one(heap)) {
        left = extract_min(heap);
        right = extract_min(heap);
        top = new_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert_node(heap, top);
    }

    return extract_min(heap);
}

void generate_codebook(node* root, char code[], int top, codebook codes[], int *j) {
    if (root->left) {
        code[top] = '0';
        generate_codebook(root->left, code, top + 1, codes, j);
    }

    if (root->right) {
        code[top] = '1';
        generate_codebook(root->right, code, top + 1, codes, j);
    }

    if (root->left == NULL && root->right == NULL) {
        codes[*j].symbol = root->data;
        memcpy(codes[*j].code, code, top);
        codes[*j].code[top] = '\0';
        (*j)++;
    }
}

void print_codebook(codebook codes[], int n) {
    printf("\nHuffman Codebook:");
    for (int i = 0; i < n; ++i)
        printf("\n%c : %s", codes[i].symbol, codes[i].code);
}

void huffman_encoding(char data[], int freq[], int size) {
    node* root = build_huff_tree(data, freq, size);
    codebook codes[size];
    char code[MAX_CODE_LEN];
    int top = 0, j = 0;
    generate_codebook(root, code, top, codes, &j);
    print_codebook(codes, j);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    huffman_encoding(data, freq, size);
    return 0;
}