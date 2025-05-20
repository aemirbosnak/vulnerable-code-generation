//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: ultraprecise
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    int freq;
    char data;
    struct node *left;
    struct node *right;
} node_t;

typedef struct min_heap {
    int size;
    int capacity;
    node_t **array;
} min_heap_t;

min_heap_t *create_min_heap(int capacity) {
    min_heap_t *min_heap = (min_heap_t *)malloc(sizeof(min_heap_t));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (node_t **)malloc(sizeof(node_t *) * capacity);
    return min_heap;
}

void destroy_min_heap(min_heap_t *min_heap) {
    for (int i = 0; i < min_heap->size; i++) {
        free(min_heap->array[i]);
    }
    free(min_heap->array);
    free(min_heap);
}

void swap_nodes(node_t **a, node_t **b) {
    node_t *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(min_heap_t *min_heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < min_heap->size && min_heap->array[left]->freq < min_heap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < min_heap->size && min_heap->array[right]->freq < min_heap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        swap_nodes(&min_heap->array[i], &min_heap->array[smallest]);
        min_heapify(min_heap, smallest);
    }
}

void insert_node(min_heap_t *min_heap, node_t *node) {
    min_heap->array[min_heap->size++] = node;

    int i = min_heap->size - 1;
    while (i > 0 && min_heap->array[i]->freq < min_heap->array[(i - 1) / 2]->freq) {
        swap_nodes(&min_heap->array[i], &min_heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

node_t *extract_min(min_heap_t *min_heap) {
    if (min_heap->size <= 0) {
        return NULL;
    }

    node_t *min = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    min_heap->size--;

    min_heapify(min_heap, 0);

    return min;
}

node_t *create_node(int freq, char data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->freq = freq;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

node_t *build_huffman_tree(char *text, int text_size) {
    int frequency[256] = {0};

    for (int i = 0; i < text_size; i++) {
        frequency[text[i]]++;
    }

    min_heap_t *min_heap = create_min_heap(text_size);

    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            insert_node(min_heap, create_node(frequency[i], i));
        }
    }

    while (min_heap->size > 1) {
        node_t *left = extract_min(min_heap);
        node_t *right = extract_min(min_heap);

        node_t *parent = create_node(left->freq + right->freq, 0);
        parent->left = left;
        parent->right = right;

        insert_node(min_heap, parent);
    }

    destroy_min_heap(min_heap);

    return extract_min(min_heap);
}

void print_huffman_codes(node_t *root, char *code, int code_size) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->data, code);
        return;
    }

    code[code_size] = '0';
    print_huffman_codes(root->left, code, code_size + 1);
    code[code_size] = '1';
    print_huffman_codes(root->right, code, code_size + 1);
}

void huffman_encoding(char *text, int text_size) {
    node_t *root = build_huffman_tree(text, text_size);

    char code[1000] = {0};
    print_huffman_codes(root, code, 0);
}

int main() {
    char text[] = "helloworld";
    int text_size = strlen(text);

    printf("Original text: %s\n", text);

    huffman_encoding(text, text_size);

    return 0;
}