//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    int frequency;
    struct node *left;
    struct node *right;
} Node;

typedef struct heap {
    Node **nodes;
    int size;
} Heap;

Node *new_node(char letter, int frequency) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->letter = letter;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(Heap *heap, Node *node) {
    int i = ++heap->size;
    while (i != 1 && node->frequency < heap->nodes[i/2]->frequency) {
        heap->nodes[i] = heap->nodes[i/2];
        i /= 2;
    }
    heap->nodes[i] = node;
}

Node *pop_min(Heap *heap) {
    if (heap->size == 0) return NULL;
    Node *min = heap->nodes[1];
    Node *last = heap->nodes[heap->size--];

    int i = 1;
    int child = 2;
    while (child <= heap->size) {
        if (child < heap->size && heap->nodes[child+1]->frequency < heap->nodes[child]->frequency) child++;
        if (last->frequency > heap->nodes[child]->frequency) {
            heap->nodes[i] = heap->nodes[child];
        } else {
            break;
        }
        i = child;
        child *= 2;
    }
    heap->nodes[i] = last;

    return min;
}

void print_code(Node *node, int code[], int top) {
    if (node->left) {
        code[top] = 0;
        print_code(node->left, code, top+1);
    }
    if (node->right) {
        code[top] = 1;
        print_code(node->right, code, top+1);
    }
    if (!node->left && !node->right) {
        printf("%c: ", node->letter);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

void huffman_code(char data[], int frequency[], int size) {
    Heap heap;
    heap.nodes = (Node **)malloc((size+1) * sizeof(Node *));
    heap.size = 0;

    for (int i = 0; i < size; i++) {
        insert_node(&heap, new_node(data[i], frequency[i]));
    }

    while (heap.size > 1) {
        Node *node1 = pop_min(&heap);
        Node *node2 = pop_min(&heap);

        Node *parent = new_node('$', node1->frequency + node2->frequency);
        parent->left = node1;
        parent->right = node2;

        insert_node(&heap, parent);
    }

    int code[100];
    print_code(heap.nodes[1], code, 0);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    huffman_code(data, frequency, size);
    return 0;
}