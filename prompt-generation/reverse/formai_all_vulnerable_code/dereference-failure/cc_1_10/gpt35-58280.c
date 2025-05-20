//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int character;
    int frequency;
    struct node* left;
    struct node* right;
} Node;

typedef struct priority_queue {
    int size;
    int capacity;
    Node** array;
} Priority_Queue;

Node* create_node(int character, int frequency) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->character = character;
    new_node->frequency = frequency;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Priority_Queue* create_priority_queue(int capacity) {
    Priority_Queue* new_pq = (Priority_Queue*)malloc(sizeof(Priority_Queue));
    new_pq->size = 0;
    new_pq->capacity = capacity;
    new_pq->array = (Node**)malloc(capacity * sizeof(Node*));
    for (int i = 0; i < capacity; i++) {
        new_pq->array[i] = NULL;
    }
    return new_pq;
}

void swap_node(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Priority_Queue* pq, int index) {
    int smallest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    if (left_child < pq->size && pq->array[left_child]->frequency < pq->array[smallest]->frequency) {
        smallest = left_child;
    }
    if (right_child < pq->size && pq->array[right_child]->frequency < pq->array[smallest]->frequency) {
        smallest = right_child;
    }
    if (smallest != index) {
        swap_node(&pq->array[smallest], &pq->array[index]);
        heapify(pq, smallest);
    }
}

int is_size_one(Priority_Queue* pq) {
    return pq->size == 1;
}

Node* extract_min(Priority_Queue* pq) {
    Node* min = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    heapify(pq, 0);
    return min;
}

void insert(Priority_Queue* pq, Node* node) {
    pq->size++;
    int index = pq->size - 1;
    while (index && node->frequency < pq->array[(index - 1) / 2]->frequency) {
        pq->array[index] = pq->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    pq->array[index] = node;
}

int is_leaf(Node* node) {
    return (node->left == NULL) && (node->right == NULL);
}

Priority_Queue* create_queue(int* frequency, int size) {
    Priority_Queue* queue = create_priority_queue(size);
    for (int i = 0; i < size; i++) {
        Node* node = create_node(i, frequency[i]);
        insert(queue, node);
    }
    return queue;
}

Node* build_tree(int* frequency, int size) {
    Priority_Queue* queue = create_queue(frequency, size);
    while (!is_size_one(queue)) {
        Node* left = extract_min(queue);
        Node* right = extract_min(queue);
        Node* new_node = create_node(-1, left->frequency + right->frequency);
        new_node->left = left;
        new_node->right = right;
        insert(queue, new_node);
    }
    return extract_min(queue);
}

void print_codes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }
    if (is_leaf(root)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void huffman_encoding(int* frequency, int size) {
    Node* root = build_tree(frequency, size);
    int arr[size];
    int top = 0;
    print_codes(root, arr, top);
}

int main() {
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(frequency) / sizeof(frequency[0]);
    huffman_encoding(frequency, size);
    return 0;
}