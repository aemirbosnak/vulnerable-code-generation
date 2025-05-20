//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int freq;
    char ch;
    struct node *left;
    struct node *right;
} node;

node *create_node(char ch, int freq) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->ch = ch;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void swap_nodes(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(node **heap, int i, int heap_size) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap_size && heap[left]->freq < heap[smallest]->freq) {
        smallest = left;
    }
    if (right < heap_size && heap[right]->freq < heap[smallest]->freq) {
        smallest = right;
    }
    if (smallest != i) {
        swap_nodes(&heap[i], &heap[smallest]);
        min_heapify(heap, smallest, heap_size);
    }
}

void build_min_heap(node **heap, int heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        min_heapify(heap, i, heap_size);
    }
}

node *extract_min(node **heap, int *heap_size) {
    node *min = heap[0];
    heap[0] = heap[*heap_size - 1];
    *heap_size = *heap_size - 1;
    min_heapify(heap, 0, *heap_size);
    return min;
}

void insert_node(node **heap, node *new_node, int *heap_size) {
    int i = *heap_size;
    heap[i] = new_node;
    *heap_size = *heap_size + 1;
    while (i > 0 && heap[i]->freq < heap[(i - 1) / 2]->freq) {
        swap_nodes(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

node *build_huffman_tree(char *str, int *freq, int size) {
    node **heap = (node **)malloc(sizeof(node *) * size);
    int heap_size = 0;
    for (int i = 0; i < size; i++) {
        insert_node(heap, create_node(str[i], freq[i]), &heap_size);
    }
    while (heap_size > 1) {
        node *left = extract_min(heap, &heap_size);
        node *right = extract_min(heap, &heap_size);
        node *new_node = create_node('\0', left->freq + right->freq);
        new_node->left = left;
        new_node->right = right;
        insert_node(heap, new_node, &heap_size);
    }
    return heap[0];
}

void print_codes(node *root, char *code, int code_len) {
    if (root == NULL) {
        return;
    }
    if (root->ch != '\0') {
        printf("%c: %s\n", root->ch, code);
        return;
    }
    print_codes(root->left, strcat(code, "0"), code_len + 1);
    print_codes(root->right, strcat(code, "1"), code_len + 1);
}

int main() {
    char *str = "Hello";
    int freq[] = {1, 1, 1, 1, 1};
    int size = 5;
    node *root = build_huffman_tree(str, freq, size);
    char code[100];
    print_codes(root, code, 0);
    return 0;
}