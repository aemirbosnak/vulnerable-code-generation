//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
};

struct heap {
    int size;
    int capacity;
    struct node **nodes;
};

struct node *new_node(char character, int frequency) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct heap *new_heap(int capacity) {
    struct heap *heap = (struct heap *) malloc(sizeof(struct heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->nodes = (struct node **) malloc(sizeof(struct node *) * capacity);

    return heap;
}

void swap_nodes(struct node **a, struct node **b) {
    struct node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct heap *heap, int index) {
    int smallest = index;
    int left = (index * 2) + 1;
    int right = (index * 2) + 2;

    if (left < heap->size && heap->nodes[left]->frequency < heap->nodes[smallest]->frequency)
        smallest = left;

    if (right < heap->size && heap->nodes[right]->frequency < heap->nodes[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swap_nodes(&heap->nodes[smallest], &heap->nodes[index]);
        heapify(heap, smallest);
    }
}

void build_heap(struct heap *heap) {
    int n = heap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; i--)
        heapify(heap, i);
}

struct node *extract_min(struct heap *heap) {
    struct node *temp = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return temp;
}

void insert_node(struct heap *heap, struct node *node) {
    heap->size++;
    int i = heap->size - 1;

    while (i > 0 && node->frequency < heap->nodes[(i - 1) / 2]->frequency) {
        heap->nodes[i] = heap->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->nodes[i] = node;
}

struct node *build_huffman_tree(char characters[], int frequencies[], int size) {
    struct node *left, *right, *top;
    struct heap *heap = new_heap(size);

    for (int i = 0; i < size; ++i) {
        heap->nodes[i] = new_node(characters[i], frequencies[i]);
    }

    heap->size = size;
    build_heap(heap);

    while (heap->size > 1) {
        left = extract_min(heap);
        right = extract_min(heap);
        top = new_node('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insert_node(heap, top);
    }

    return extract_min(heap);
}

void print_codes(struct node *root, int array[], int top) {
    if (root->left) {
        array[top] = 0;
        print_codes(root->left, array, top + 1);
    }

    if (root->right) {
        array[top] = 1;
        print_codes(root->right, array, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; ++i) {
            printf("%d", array[i]);
        }
        printf("\n");
    }
}

int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);
    struct node *root = build_huffman_tree(characters, frequencies, size);
    int codes[size];
    int top = 0;

    print_codes(root, codes, top);

    return 0;
}