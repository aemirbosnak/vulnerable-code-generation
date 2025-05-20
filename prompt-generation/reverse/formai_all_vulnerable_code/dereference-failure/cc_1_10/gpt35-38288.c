//FormAI DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    unsigned char symbol;
    int frequency;
    struct node *left, *right;
} NODE;

typedef struct heap {
    NODE **nodes;
    int size;
} HEAP;

// Function prototypes
HEAP *new_heap();
NODE *create_node(unsigned char symbol, int frequency);
void heap_insert(HEAP *heap, NODE *node);
NODE *heap_remove(HEAP *heap);
void heapify(HEAP *heap, int index);
void build_heap(HEAP *heap);
NODE *build_huffman_tree(HEAP *heap);
void calculate_codes(NODE *node, unsigned char *code, int depth, unsigned char **codes, int *hm_table);
int *create_hm_table();
void compress(HEAP *heap, unsigned char *input, unsigned char **output, int *output_size);
void write_header(FILE *out_file, int *hm_table);
void write_data(FILE *out_file, unsigned char *output, int output_size);

int main(int argc, char **argv) {
    HEAP *heap = new_heap();
    unsigned char *input = "abccdddddddeeeeeeeeeezzzzzzzzzz";
    unsigned char *output = NULL;
    int output_size;

    // Compress input
    compress(heap, input, &output, &output_size);

    // Write compressed data to file
    FILE *out_file = fopen("compressed.bin", "wb");
    int *hm_table = create_hm_table();
    write_header(out_file, hm_table);
    write_data(out_file, output, output_size);
    fclose(out_file);

    // Clean up
    free(output);
    free(heap->nodes);
    free(heap);
    free(hm_table);

    return 0;
}

HEAP *new_heap() {
    HEAP *heap = (HEAP *)calloc(1, sizeof(HEAP));
    heap->nodes = (NODE **)calloc(256, sizeof(NODE *));
    heap->size = 0;
    return heap;
}

NODE *create_node(unsigned char symbol, int frequency) {
    NODE *node = (NODE *)calloc(1, sizeof(NODE));
    node->symbol = symbol;
    node->frequency = frequency;
    return node;
}

void heap_insert(HEAP *heap, NODE *node) {
    heap->size++;
    int i = heap->size;
    while (i > 1 && heap->nodes[i/2]->frequency > node->frequency) {
        heap->nodes[i] = heap->nodes[i/2];
        i /= 2;
    }
    heap->nodes[i] = node;
}

NODE *heap_remove(HEAP *heap) {
    NODE *node = heap->nodes[1];
    heap->nodes[1] = heap->nodes[heap->size];
    heap->size--;
    heapify(heap, 1);
    return node;
}

void heapify(HEAP *heap, int index) {
    int child_index, i = index;
    NODE *tmp = heap->nodes[i];
    while (2 * i <= heap->size) {
        child_index = 2 * i;
        if (child_index < heap->size && heap->nodes[child_index+1]->frequency < heap->nodes[child_index]->frequency)
            child_index++;
        if (heap->nodes[child_index]->frequency < tmp->frequency) {
            heap->nodes[i] = heap->nodes[child_index];
            i = child_index;
        }
        else
            break;
    }
    heap->nodes[i] = tmp;
}

void build_heap(HEAP *heap) {
    int i, symbol_counts[256] = {0};
    unsigned char *input = "abccdddddddeeeeeeeeeezzzzzzzzzz";

    // Count frequency of each symbol in input
    for (i = 0; i < strlen(input); i++)
        symbol_counts[input[i]]++;

    // Create a node for each symbol that appears in input
    // and insert it into the heap
    for (i = 0; i < 256; i++) {
        if (symbol_counts[i] > 0) {
            NODE *node = create_node(i, symbol_counts[i]);
            heap_insert(heap, node);
        }
    }
}

NODE *build_huffman_tree(HEAP *heap) {
    int i;
    while (heap->size > 1) {
        NODE *left_node = heap_remove(heap);
        NODE *right_node = heap_remove(heap);
        NODE *new_node = create_node(0, left_node->frequency + right_node->frequency);
        new_node->left = left_node;
        new_node->right = right_node;
        heap_insert(heap, new_node);
    }
    return heap->nodes[1];
}

int *create_hm_table() {
    HEAP *heap = new_heap();
    build_heap(heap);
    NODE *huffman_tree = build_huffman_tree(heap);

    unsigned char *code = (unsigned char *)calloc(256, sizeof(unsigned char));
    unsigned char **codes = (unsigned char **)calloc(256, sizeof(unsigned char *));
    int *hm_table = (int *)calloc(256, sizeof(int));

    calculate_codes(huffman_tree, code, 0, codes, hm_table);

    free(codes);
    free(heap->nodes);
    free(heap);

    return hm_table;
}

void calculate_codes(NODE *node, unsigned char *code, int depth, unsigned char **codes, int *hm_table) {
    if (!node->left && !node->right) {
        codes[node->symbol] = (unsigned char *)calloc(depth, sizeof(unsigned char));
        memcpy(codes[node->symbol], code, depth);
        hm_table[node->symbol] = depth;
        return;
    }

    code[depth] = '0';
    calculate_codes(node->left, code, depth + 1, codes, hm_table);

    code[depth] = '1';
    calculate_codes(node->right, code, depth + 1, codes, hm_table);
}

void compress(HEAP *heap, unsigned char *input, unsigned char **output, int *output_size) {
    int i, j, length = strlen(input);
    unsigned char *code = (unsigned char *)calloc(256, sizeof(unsigned char));
    unsigned char **codes = (unsigned char **)calloc(256, sizeof(unsigned char *));
    int *hm_table = create_hm_table();
    for (i = 0; i < 256; i++) {
        if (hm_table[i] > 0) {
            codes[i] = (unsigned char *)calloc(hm_table[i], sizeof(unsigned char));
            memcpy(codes[i], hm_table + i, hm_table[i]);
        }
    }

    *output_size = 0;
    *output = (unsigned char *)calloc((length+1)*8, sizeof(unsigned char));

    for (i = 0; i < length; i++) {
        memcpy(code, codes[input[i]], hm_table[input[i]]);
        for (j = 0; j < hm_table[input[i]]; j++) {
            (*output)[*output_size] = code[j];
            (*output_size)++;
        }
    }

    // Clean up
    for (i = 0; i < 256; i++) free(codes[i]);
    free(codes);
    free(code);
    free(hm_table);
}

void write_header(FILE *out_file, int *hm_table) {
    int i;
    for (i = 0; i < 256; i++)
        fwrite(&hm_table[i], sizeof(int), 1, out_file);
}

void write_data(FILE *out_file, unsigned char *output, int output_size) {
    fwrite(output, sizeof(unsigned char), output_size, out_file);
}