//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct min_heap_node {
    char data;
    unsigned freq;
    struct min_heap_node *left, *right;
};
struct min_heap {
    unsigned size;
    unsigned capacity;
    struct min_heap_node **arr;
};
struct min_heap_node *new_min_heap_node(char data, unsigned freq) {
    struct min_heap_node *temp = (struct min_heap_node *)malloc(sizeof(struct min_heap_node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}
struct min_heap *create_min_heap(unsigned capacity) {
    struct min_heap *min_heap = (struct min_heap *)malloc(sizeof(struct min_heap));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->arr = (struct min_heap_node **)malloc(min_heap->capacity * sizeof(struct min_heap_node *));
    return min_heap;
}
void swap_min_heap_node(struct min_heap_node **a, struct min_heap_node **b) {
    struct min_heap_node *temp = *a;
    *a = *b;
    *b = temp;
}
void min_heapify(struct min_heap *min_heap, unsigned idx) {
    unsigned smallest = idx;
    unsigned left = 2 * idx + 1;
    unsigned right = 2 * idx + 2;
    if (left < min_heap->size && min_heap->arr[left]->freq < min_heap->arr[smallest]->freq)
        smallest = left;
    if (right < min_heap->size && min_heap->arr[right]->freq < min_heap->arr[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swap_min_heap_node(&min_heap->arr[smallest], &min_heap->arr[idx]);
        min_heapify(min_heap, smallest);
    }
}
int is_size_one(struct min_heap *min_heap) {
    return (min_heap->size == 1);
}
struct min_heap_node *extract_min(struct min_heap *min_heap) {
    struct min_heap_node *temp = min_heap->arr[0];
    min_heap->arr[0] = min_heap->arr[min_heap->size - 1];
    --min_heap->size;
    min_heapify(min_heap, 0);
    return temp;
}
void insert_min_heap(struct min_heap *min_heap, struct min_heap_node *min_heap_node) {
    ++min_heap->size;
    unsigned i = min_heap->size - 1;
    while (i && min_heap_node->freq < min_heap->arr[(i - 1) / 2]->freq) {
        min_heap->arr[i] = min_heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    min_heap->arr[i] = min_heap_node;
}
void build_min_heap(struct min_heap *min_heap) {
    unsigned n = min_heap->size;
    for (int i = n / 2 - 1; i >= 0; --i)
        min_heapify(min_heap, i);
}
struct min_heap *create_and_build_min_heap(char data[], unsigned freq[], unsigned size) {
    struct min_heap *min_heap = create_min_heap(size);
    for (unsigned i = 0; i < size; ++i)
        min_heap->arr[i] = new_min_heap_node(data[i], freq[i]);
    min_heap->size = size;
    build_min_heap(min_heap);
    return min_heap;
}
struct min_heap_node *Huffman_tree(char data[], unsigned freq[], unsigned size) {
    struct min_heap *min_heap = create_and_build_min_heap(data, freq, size);
    struct min_heap_node *left, *right, *top;
    while (!is_size_one(min_heap)) {
        left = extract_min(min_heap);
        right = extract_min(min_heap);
        top = new_min_heap_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert_min_heap(min_heap, top);
    }
    return extract_min(min_heap);
}
void print_Huffman_codes(struct min_heap_node *root, char code[], unsigned top) {
    if (root->left) {
        code[top] = '0';
        print_Huffman_codes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        print_Huffman_codes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: %s\n", root->data, code);
        return;
    }
}
void Huffman_codes(char data[], unsigned freq[], unsigned size) {
    struct min_heap_node *root = Huffman_tree(data, freq, size);
    char code[100];
    print_Huffman_codes(root, code, 0);
}
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {5, 9, 12, 13, 16, 45};
    unsigned size = sizeof(data) / sizeof(data[0]);
    Huffman_codes(data, freq, size);
    return 0;
}