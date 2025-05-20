//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int frequency;
    char character;
    struct node *left;
    struct node *right;
} Node;

typedef struct heap {
    int size;
    Node **nodes;
} Heap;

Node *create_node(int frequency, char character, Node *left, Node *right) {
    Node *node = malloc(sizeof(Node));
    node->frequency = frequency;
    node->character = character;
    node->left = left;
    node->right = right;
    return node;
}

Heap *create_heap(int capacity) {
    Heap *heap = malloc(sizeof(Heap));
    heap->size = 0;
    heap->nodes = malloc(capacity * sizeof(Node*));
    return heap;
}

void swap_nodes(Node **node1, Node **node2) {
    Node *temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

void heapify(Heap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size && heap->nodes[left]->frequency < heap->nodes[smallest]->frequency) {
        smallest = left;
    }
    if (right < heap->size && heap->nodes[right]->frequency < heap->nodes[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != index) {
        swap_nodes(&heap->nodes[index], &heap->nodes[smallest]);
        heapify(heap, smallest);
    }
}

void insert_node(Heap *heap, Node *node) {
    int index = heap->size++;
    heap->nodes[index] = node;
    while (index > 0 && heap->nodes[(index - 1) / 2]->frequency > heap->nodes[index]->frequency) {
        swap_nodes(&heap->nodes[(index - 1) / 2], &heap->nodes[index]);
        index = (index - 1) / 2;
    }
}

Node *extract_min(Heap *heap) {
    Node *node = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];
    heapify(heap, 0);
    return node;
}

Node *build_huffman_tree(char *text) {
    int frequency[256] = {0};
    for (int i = 0; text[i] != '\0'; i++) {
        frequency[text[i]]++;
    }
    Heap *heap = create_heap(256);
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            Node *node = create_node(frequency[i], i, NULL, NULL);
            insert_node(heap, node);
        }
    }
    while (heap->size > 1) {
        Node *left = extract_min(heap);
        Node *right = extract_min(heap);
        Node *parent = create_node(left->frequency + right->frequency, '$', left, right);
        insert_node(heap, parent);
    }
    return extract_min(heap);
}

void print_codes(Node *node, int *code, int top) {
    if (node->left) {
        code[top] = 0;
        print_codes(node->left, code, top + 1);
    }
    if (node->right) {
        code[top] = 1;
        print_codes(node->right, code, top + 1);
    }
    if (!node->left && !node->right) {
        printf("%c: ", node->character);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

void huffman_encoding(char *text) {
    Node *root = build_huffman_tree(text);
    int code[256] = {0};
    int top = 0;
    print_codes(root, code, top);
}

int main() {
    char text[] = "This is an example of Huffman Encoding";
    huffman_encoding(text);
    return 0;
}