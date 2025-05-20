//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TREE_HT 100

typedef struct node {
    char data;
    int freq;
    struct node *left, *right;
} Node;

typedef struct min_heap {
    int size;
    int capacity;
    Node **array;
} Heap;

typedef struct huffman_tree {
    Node *root;
} HuffmanTree;

Node *new_node(char data, int freq) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

Heap *create_heap(int capacity) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (Node **) malloc(heap->capacity * sizeof(Node *));
    return heap;
}

void swap_node(Node **x, Node **y) {
    Node *temp = *x;
    *x = *y;
    *y = temp;
}

void min_heapify(Heap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != idx) {
        swap_node(&heap->array[idx], &heap->array[smallest]);
        min_heapify(heap, smallest);
    }
}

int is_heap_size_one(Heap *heap) {
    return heap->size == 1;
}

Node *extract_min(Heap *heap) {
    Node *temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    min_heapify(heap, 0);
    return temp;
}

void insert_heap(Heap *heap, Node *node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void build_heap(Heap *heap) {
    int n = heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) {
        min_heapify(heap, i);
    }
}

Heap *create_master_heap(char data[], int freq[], int size) {
    Heap *heap = create_heap(size);
    for (int i = 0; i < size; ++i) {
        heap->array[i] = new_node(data[i], freq[i]);
    }
    heap->size = size;
    build_heap(heap);
    return heap;
}

Node *build_huffman_tree(char data[], int freq[], int size) {
    Heap *heap = create_master_heap(data, freq, size);
    while (!is_heap_size_one(heap)) {
        Node *left_node = extract_min(heap);
        Node *right_node = extract_min(heap);
        Node *parent_node = new_node('$', left_node->freq + right_node->freq);
        parent_node->left = left_node;
        parent_node->right = right_node;
        insert_heap(heap, parent_node);
    }
    return extract_min(heap);
}

void print_codes(Node *root, int arr[], int top) {
    static char str[MAX_TREE_HT];
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
            str[i] = arr[i] + 48;
        }
        str[top] = '\0';
        printf(" (Code: %s)\n", str);
    }
}

void huffman_encoding(char data[], int freq[], int size) {
    Node *root = build_huffman_tree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printf("Huffman Codes:\n");
    print_codes(root, arr, top);
}

void huffman_decoding(Node *root, char *str) {
    Node *temp = root;
    printf("\nDecoded String: ");
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '0') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        if (!temp->left && !temp->right) {
            printf("%c", temp->data);
            temp = root;
        }
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    huffman_encoding(data, freq, size);
    Node *root = build_huffman_tree(data, freq, size);
    char str[] = "110110000001100001010100111";
    huffman_decoding(root, str);
    return 0;
}