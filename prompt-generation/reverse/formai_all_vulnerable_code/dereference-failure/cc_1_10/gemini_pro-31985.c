//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    unsigned char c;
    unsigned int freq;
    struct node *left, *right;
} node;

typedef struct heap {
    node **nodes;
    int size;
} heap;

heap *create_heap(int size) {
    heap *h = malloc(sizeof(heap));
    h->nodes = malloc(sizeof(node *) * size);
    h->size = 0;
    return h;
}

void heap_push(heap *h, node *n) {
    h->nodes[h->size++] = n;
    int i = h->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->nodes[i]->freq < h->nodes[parent]->freq) {
            node *tmp = h->nodes[i];
            h->nodes[i] = h->nodes[parent];
            h->nodes[parent] = tmp;
            i = parent;
        } else {
            break;
        }
    }
}

node *heap_pop(heap *h) {
    node *n = h->nodes[0];
    h->nodes[0] = h->nodes[--(h->size)];
    int i = 0;
    while (i < h->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left >= h->size) {
            break;
        }
        int min_index = i;
        if (h->nodes[left]->freq < h->nodes[min_index]->freq) {
            min_index = left;
        }
        if (right < h->size && h->nodes[right]->freq < h->nodes[min_index]->freq) {
            min_index = right;
        }
        if (min_index != i) {
            node *tmp = h->nodes[i];
            h->nodes[i] = h->nodes[min_index];
            h->nodes[min_index] = tmp;
            i = min_index;
        } else {
            break;
        }
    }
    return n;
}

node *create_node(unsigned char c, unsigned int freq) {
    node *n = malloc(sizeof(node));
    n->c = c;
    n->freq = freq;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node *huffman_tree(unsigned char *str, int len) {
    unsigned int freq[256] = {0};
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }

    heap *h = create_heap(len);
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            heap_push(h, create_node(i, freq[i]));
        }
    }

    while (h->size > 1) {
        node *left = heap_pop(h);
        node *right = heap_pop(h);
        node *parent = create_node(0, left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        heap_push(h, parent);
    }

    return heap_pop(h);
}

void print_codes(node *root, char *code, int len) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->c, code);
    } else {
        char left_code[len + 1];
        strcpy(left_code, code);
        left_code[len] = '0';
        print_codes(root->left, left_code, len + 1);

        char right_code[len + 1];
        strcpy(right_code, code);
        right_code[len] = '1';
        print_codes(root->right, right_code, len + 1);
    }
}

void compress(unsigned char *str, int len) {
    node *root = huffman_tree(str, len);

    char code[len];
    print_codes(root, code, 0);
}

int main() {
    unsigned char *str = "Hello World!";
    int len = strlen(str);

    compress(str, len);

    return 0;
}