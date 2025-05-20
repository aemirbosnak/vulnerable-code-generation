//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct node {
    int frequency;
    char character;
    struct node *left;
    struct node *right;
} node;

typedef struct heap {
    int size;
    struct node **array;
} heap;

heap *create_heap(int size) {
    heap *h = (heap *)malloc(sizeof(heap));
    h->size = 0;
    h->array = (node **)calloc(size, sizeof(node *));
    return h;
}

void swap(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(heap *h, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < h->size && h->array[left]->frequency < h->array[smallest]->frequency) {
        smallest = left;
    }
    if (right < h->size && h->array[right]->frequency < h->array[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&h->array[i], &h->array[smallest]);
        min_heapify(h, smallest);
    }
}

node *extract_min(heap *h) {
    if (h->size == 0) {
        return NULL;
    }
    node *min = h->array[0];
    h->array[0] = h->array[h->size - 1];
    h->size--;
    min_heapify(h, 0);
    return min;
}

void insert(heap *h, node *n) {
    h->size++;
    int i = h->size - 1;
    while (i > 0 && n->frequency < h->array[(i - 1) / 2]->frequency) {
        h->array[i] = h->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->array[i] = n;
}

heap *build_heap(int *frequency, char *characters, int size) {
    heap *h = create_heap(size);
    for (int i = 0; i < size; i++) {
        if (frequency[i] > 0) {
            node *n = (node *)malloc(sizeof(node));
            n->frequency = frequency[i];
            n->character = characters[i];
            n->left = NULL;
            n->right = NULL;
            insert(h, n);
        }
    }
    return h;
}

node *build_huffman_tree(heap *h) {
    while (h->size > 1) {
        node *left = extract_min(h);
        node *right = extract_min(h);
        node *parent = (node *)malloc(sizeof(node));
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;
        insert(h, parent);
    }
    return extract_min(h);
}

void print_codes(node *root, char *code, int length) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->character, code);
        return;
    }
    char *left_code = (char *)calloc(length + 1, sizeof(char));
    strcpy(left_code, code);
    strcat(left_code, "0");
    char *right_code = (char *)calloc(length + 1, sizeof(char));
    strcpy(right_code, code);
    strcat(right_code, "1");
    print_codes(root->left, left_code, length + 1);
    print_codes(root->right, right_code, length + 1);
}

void huffman_coding(int *frequency, char *characters, int size) {
    heap *h = build_heap(frequency, characters, size);
    node *root = build_huffman_tree(h);
    print_codes(root, "", 0);
}

int main() {
    int frequency[] = {5, 9, 12, 13, 16, 45};
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int size = sizeof(frequency) / sizeof(frequency[0]);
    huffman_coding(frequency, characters, size);
    return 0;
}