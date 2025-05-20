//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int frequency;
    char data;
    struct node *left;
    struct node *right;
} node;

typedef struct heap {
    int size;
    int capacity;
    node **array;
} heap;

heap *create_heap(int capacity) {
    heap *h = malloc(sizeof(heap));
    h->size = 0;
    h->capacity = capacity;
    h->array = malloc(sizeof(node *) * capacity);
    return h;
}

void destroy_heap(heap *h) {
    free(h->array);
    free(h);
}

void swap_nodes(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(heap *h, int i) {
    int parent = (i - 1) / 2;
    while (i > 0 && h->array[i]->frequency < h->array[parent]->frequency) {
        swap_nodes(&h->array[i], &h->array[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void heapify_down(heap *h, int i) {
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
        swap_nodes(&h->array[i], &h->array[smallest]);
        heapify_down(h, smallest);
    }
}

void insert_node(heap *h, node *n) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->array = realloc(h->array, sizeof(node *) * h->capacity);
    }
    h->array[h->size] = n;
    h->size++;
    heapify_up(h, h->size - 1);
}

node *extract_min(heap *h) {
    if (h->size == 0) {
        return NULL;
    }
    node *min = h->array[0];
    h->array[0] = h->array[h->size - 1];
    h->size--;
    heapify_down(h, 0);
    return min;
}

node *create_node(char data, int frequency) {
    node *n = malloc(sizeof(node));
    n->data = data;
    n->frequency = frequency;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void destroy_node(node *n) {
    free(n);
}

void build_huffman_tree(heap *h) {
    while (h->size > 1) {
        node *left = extract_min(h);
        node *right = extract_min(h);
        node *parent = create_node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        insert_node(h, parent);
    }
}

void print_huffman_codes(node *root, char *code, int code_length) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->data, code);
        return;
    }
    code[code_length] = '0';
    print_huffman_codes(root->left, code, code_length + 1);
    code[code_length] = '1';
    print_huffman_codes(root->right, code, code_length + 1);
}

void encode_huffman(char *input, char *output) {
    int frequency[256] = { 0 };
    for (int i = 0; input[i] != '\0'; i++) {
        frequency[input[i]]++;
    }
    heap *h = create_heap(256);
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            insert_node(h, create_node(i, frequency[i]));
        }
    }
    build_huffman_tree(h);
    char code[100];
    int code_length = 0;
    print_huffman_codes(h->array[0], code, code_length);
    FILE *input_file = fopen(input, "r");
    FILE *output_file = fopen(output, "w");
    char c;
    while ((c = fgetc(input_file)) != EOF) {}
    fclose(input_file);
    fclose(output_file);
}

int main() {
    char input[] = "input.txt";
    char output[] = "output.txt";
    encode_huffman(input, output);
    return 0;
}