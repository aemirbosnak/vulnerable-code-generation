//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    int freq;
    char data;
    struct node *left;
    struct node *right;
} node_t;

typedef struct heap {
    int size;
    node_t **nodes;
} heap_t;

heap_t *heap_new(int size) {
    heap_t *heap = malloc(sizeof(heap_t));
    if (heap == NULL) {
        return NULL;
    }

    heap->size = size;
    heap->nodes = malloc(sizeof(node_t *) * size);
    if (heap->nodes == NULL) {
        free(heap);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        heap->nodes[i] = NULL;
    }

    return heap;
}

void heap_free(heap_t *heap) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->nodes[i] != NULL) {
            free(heap->nodes[i]);
        }
    }

    free(heap->nodes);
    free(heap);
}

void heap_insert(heap_t *heap, node_t *node) {
    int i = heap->size;

    while (i > 1 && node->freq < heap->nodes[i / 2]->freq) {
        heap->nodes[i] = heap->nodes[i / 2];
        i /= 2;
    }

    heap->nodes[i] = node;
    heap->size++;
}

node_t *heap_pop(heap_t *heap) {
    node_t *root = heap->nodes[1];

    int i = 1;
    int j = 2;

    while (j < heap->size) {
        if (heap->nodes[j]->freq < heap->nodes[j + 1]->freq) {
            j++;
        }

        if (heap->nodes[i]->freq > heap->nodes[j]->freq) {
            node_t *temp = heap->nodes[i];
            heap->nodes[i] = heap->nodes[j];
            heap->nodes[j] = temp;

            i = j;
            j *= 2;
        } else {
            break;
        }
    }

    heap->nodes[i] = heap->nodes[heap->size - 1];
    heap->size--;

    return root;
}

node_t *huffman_build_tree(char *str) {
    int freq[256] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;
    }

    heap_t *heap = heap_new(256);
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            node_t *node = malloc(sizeof(node_t));
            node->freq = freq[i];
            node->data = i;
            node->left = NULL;
            node->right = NULL;

            heap_insert(heap, node);
        }
    }

    while (heap->size > 1) {
        node_t *left = heap_pop(heap);
        node_t *right = heap_pop(heap);

        node_t *parent = malloc(sizeof(node_t));
        parent->freq = left->freq + right->freq;
        parent->data = 0;
        parent->left = left;
        parent->right = right;

        heap_insert(heap, parent);
    }

    node_t *root = heap_pop(heap);
    heap_free(heap);

    return root;
}

void huffman_encode(node_t *root, char *str, char *encoded, int *index) {
    if (root == NULL) {
        return;
    }

    if (root->data != 0) {
        encoded[*index] = root->data;
        (*index)++;

        return;
    }

    huffman_encode(root->left, str, encoded, index);
    huffman_encode(root->right, str, encoded, index);
}

int main() {
    char str[] = "Hello, world!";

    node_t *root = huffman_build_tree(str);

    int encoded_size = strlen(str) * 8;
    char *encoded = malloc(encoded_size);
    int index = 0;

    huffman_encode(root, str, encoded, &index);

    encoded[index] = '\0';
    printf("Encoded string: %s\n", encoded);

    return 0;
}