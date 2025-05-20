//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char ch;
    int frequency;
    struct node *left, *right;
} Node;

typedef struct priority_queue {
    int size;
    Node **arr;
} PriorityQueue;

Node *new_node(char ch, int frequency, Node *left, Node *right) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->ch = ch;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}

PriorityQueue *new_priority_queue(int capacity) {
    PriorityQueue *queue = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->arr = (Node **) malloc(capacity * sizeof(Node *));
    return queue;
}

void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(PriorityQueue *queue, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < queue->size && queue->arr[left]->frequency < queue->arr[smallest]->frequency) {
        smallest = left;
    }
    if (right < queue->size && queue->arr[right]->frequency < queue->arr[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&queue->arr[index], &queue->arr[smallest]);
        min_heapify(queue, smallest);
    }
}

int is_leaf_node(Node *node) {
    return node->left == NULL && node->right == NULL;
}

PriorityQueue *build_priority_queue(char *str, int *frequencies) {
    int idx = 0;
    while (str[idx] != '\0') {
        frequencies[(int) str[idx]]++;
        idx++;
    }
    PriorityQueue *queue = new_priority_queue(idx);
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] != 0) {
            queue->arr[queue->size++] = new_node((char) i, frequencies[i], NULL, NULL);
        }
    }
    for (int i = queue->size / 2 - 1; i >= 0; i--) {
        min_heapify(queue, i);
    }
    return queue;
}

void insert_priority_queue(PriorityQueue *queue, Node *node) {
    queue->size++;
    int idx = queue->size - 1;
    queue->arr[idx] = node;
    while (idx != 0 && queue->arr[idx]->frequency < queue->arr[(idx - 1) / 2]->frequency) {
        swap(&queue->arr[idx], &queue->arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

Node *delete_priority_queue(PriorityQueue *queue) {
    Node *node = queue->arr[0];
    queue->arr[0] = queue->arr[queue->size - 1];
    queue->size--;
    min_heapify(queue, 0);
    return node;
}

void generate_codes(Node *node, int code, int len, int *codes[]) {
    if (node == NULL) {
        return;
    }
    if (is_leaf_node(node)) {
        codes[(int) node->ch][0] = code;
        codes[(int) node->ch][1] = len;
    } else {
        generate_codes(node->left, code << 1, len + 1, codes);
        generate_codes(node->right, (code << 1) | 1, len + 1, codes);
    }
}

void huffman_encoding(char *str) {
    int frequencies[256] = {0};
    PriorityQueue *queue = build_priority_queue(str, frequencies);
    while (queue->size > 1) {
        Node *a = delete_priority_queue(queue);
        Node *b = delete_priority_queue(queue);
        Node *c = new_node('\0', a->frequency + b->frequency, a, b);
        insert_priority_queue(queue, c);
    }
    int *codes[256];
    for (int i = 0; i < 256; i++) {
        codes[i] = (int *) malloc(2 * sizeof(int));
    }
    generate_codes(queue->arr[0], 0, 0, codes);
    printf("Huffman codes for characters:\n");
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] != 0) {
            printf("%c: ", (char) i);
            for (int j = 0; j < codes[i][1]; j++) {
                printf("%d", (codes[i][0] >> j) & 1);
            }
            printf("\n");
        }
    }
}

int main() {
    char str[] = "hello world";
    huffman_encoding(str);
    return 0;
}