//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 256

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
    bool is_leaf;
};

struct PriorityQueue {
    struct Node* queue[ALPHABET_SIZE];
    int size;
};

struct Node* get_node(char ch, bool is_leaf) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = ch;
    new_node->is_leaf = is_leaf;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct PriorityQueue* create_priority_queue() {
    struct PriorityQueue* new_queue = (struct PriorityQueue*) malloc(sizeof(struct PriorityQueue));
    new_queue->size = 0;
    return new_queue;
}

bool is_empty_queue(struct PriorityQueue* queue) {
    return queue->size == 0;
}

bool is_full_queue(struct PriorityQueue* queue) {
    return queue->size == ALPHABET_SIZE;
}

void enqueue(struct PriorityQueue* queue, struct Node* node) {
    if (is_full_queue(queue)) {
        printf("Queue is full, cannot enqueue any more nodes.\n");
        return;
    }
    int i = ++queue->size;
    while (i > 1 && node->data < queue->queue[i / 2]->data) {
        queue->queue[i] = queue->queue[i / 2];
        i = i / 2;
    }
    queue->queue[i] = node;
}

struct Node* dequeue(struct PriorityQueue* queue) {
    if (is_empty_queue(queue)) {
        printf("Queue is empty, cannot dequeue any nodes.\n");
        return NULL;
    }
    int i, child;
    struct Node* min_element, * last_element;
    min_element = queue->queue[1];
    last_element = queue->queue[queue->size--];
    for (i = 1; i * 2 <= queue->size; i = child) {
        child = i * 2;
        if (child != queue->size && queue->queue[child + 1]->data < queue->queue[child]->data)
            child++;
        if (last_element->data > queue->queue[child]->data)
            queue->queue[i] = queue->queue[child];
        else
            break;
    }
    queue->queue[i] = last_element;
    return min_element;
}

void destroy_queue(struct PriorityQueue* queue) {
    free(queue);
}

void print_codes(struct Node* node, int arr[], int top) {
    if (node->left) {
        arr[top] = 0;
        print_codes(node->left, arr, top + 1);
    }

    if (node->right) {
        arr[top] = 1;
        print_codes(node->right, arr, top + 1);
    }

    if (node->is_leaf) {
        printf("%c: ", node->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void huffman_encoding(char data[], int freq[], int size) {
    struct PriorityQueue* queue = create_priority_queue();
    for (int i = 0; i < size; i++) {
        struct Node* node = get_node(data[i], true);
        enqueue(queue, node);
    }
    while (queue->size > 1) {
        struct Node* node1 = dequeue(queue);
        struct Node* node2 = dequeue(queue);
        struct Node* parent = get_node('\0', false);
        parent->left = node1;
        parent->right = node2;
        parent->is_leaf = false;
        enqueue(queue, parent);
    }
    int code_arr[size];
    printf("Huffman Codes:\n");
    print_codes(queue->queue[1], code_arr, 0);
    destroy_queue(queue);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    huffman_encoding(data, freq, size);
    return 0;
}