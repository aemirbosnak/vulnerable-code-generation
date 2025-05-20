//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int freq;
    char data;
    struct node *left;
    struct node *right;
};

struct huff_code {
    char *code;
    int len;
};

struct min_heap {
    struct node **arr;
    int size;
    int max_size;
};

struct min_heap *create_min_heap(int max_size) {
    struct min_heap *min_heap = (struct min_heap *)malloc(sizeof(struct min_heap));
    min_heap->arr = (struct node **)malloc(max_size * sizeof(struct node *));
    min_heap->size = 0;
    min_heap->max_size = max_size;
    return min_heap;
}

void swap_nodes(struct node **a, struct node **b) {
    struct node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(struct min_heap *min_heap, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < min_heap->size && min_heap->arr[left]->freq < min_heap->arr[smallest]->freq) {
        smallest = left;
    }
    if (right < min_heap->size && min_heap->arr[right]->freq < min_heap->arr[smallest]->freq) {
        smallest = right;
    }
    if (smallest != i) {
        swap_nodes(&min_heap->arr[i], &min_heap->arr[smallest]);
        min_heapify(min_heap, smallest);
    }
}

struct node *extract_min(struct min_heap *min_heap) {
    struct node *min = min_heap->arr[0];
    min_heap->arr[0] = min_heap->arr[min_heap->size - 1];
    min_heap->size--;
    min_heapify(min_heap, 0);
    return min;
}

void insert_node(struct min_heap *min_heap, struct node *node) {
    if (min_heap->size == min_heap->max_size) {
        return;
    }
    min_heap->arr[min_heap->size] = node;
    min_heap->size++;
    int i = min_heap->size - 1;
    while (i > 0 && min_heap->arr[i]->freq < min_heap->arr[(i - 1) / 2]->freq) {
        swap_nodes(&min_heap->arr[i], &min_heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct node *build_huffman_tree(int *freq, int size) {
    struct min_heap *min_heap = create_min_heap(size);
    for (int i = 0; i < size; i++) {
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->freq = freq[i];
        node->data = i;
        node->left = NULL;
        node->right = NULL;
        insert_node(min_heap, node);
    }
    while (min_heap->size > 1) {
        struct node *left = extract_min(min_heap);
        struct node *right = extract_min(min_heap);
        struct node *parent = (struct node *)malloc(sizeof(struct node));
        parent->freq = left->freq + right->freq;
        parent->data = '\0';
        parent->left = left;
        parent->right = right;
        insert_node(min_heap, parent);
    }
    return min_heap->arr[0];
}

void generate_huff_codes(struct node *root, struct huff_code *huff_codes, int *code, int top) {
    if (root->left == NULL && root->right == NULL) {
        huff_codes[root->data].code = (char *)malloc(top + 1);
        memcpy(huff_codes[root->data].code, code, top);
        huff_codes[root->data].code[top] = '\0';
        return;
    }
    code[top] = 0;
    generate_huff_codes(root->left, huff_codes, code, top + 1);
    code[top] = 1;
    generate_huff_codes(root->right, huff_codes, code, top + 1);
}

void print_huff_codes(struct huff_code *huff_codes, int size) {
    for (int i = 0; i < size; i++) {
        if (huff_codes[i].len > 0) {
            printf("%c: %s\n", i, huff_codes[i].code);
        }
    }
}

int main() {
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(freq) / sizeof(freq[0]);
    struct node *root = build_huffman_tree(freq, size);
    struct huff_code *huff_codes = (struct huff_code *)malloc(size * sizeof(struct huff_code));
    for (int i = 0; i < size; i++) {
        huff_codes[i].code = NULL;
        huff_codes[i].len = 0;
    }
    int code[100];
    int top = 0;
    generate_huff_codes(root, huff_codes, code, top);
    print_huff_codes(huff_codes, size);
    return 0;
}