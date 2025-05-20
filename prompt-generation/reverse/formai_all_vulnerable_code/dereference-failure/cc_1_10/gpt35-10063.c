//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// node structure for Huffman tree
typedef struct node {
    char data;
    unsigned freq;
    struct node *left, *right;
} Node;

// priority queue structure for Huffman tree nodes
typedef struct queue {
    unsigned size;
    unsigned capacity;
    Node **data;
} Queue;

// create a new node
Node *new_node(char data, unsigned freq) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// create a new priority queue
Queue *create_queue(unsigned capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->data = (Node **)malloc(capacity * sizeof(Node *));
    return queue;
}

// swap two nodes
void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

// min-heapify the priority queue
void heapify(Queue *queue, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < queue->size && queue->data[left]->freq < queue->data[smallest]->freq)
        smallest = left;

    if (right < queue->size && queue->data[right]->freq < queue->data[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swap(&queue->data[smallest], &queue->data[idx]);
        heapify(queue, smallest);
    }
}

// check if the priority queue is empty
bool is_empty(Queue *queue) {
    return queue->size == 0;
}

// extract the minimum element from the priority queue
Node *extract_min(Queue *queue) {
    Node *node = queue->data[0];
    queue->data[0] = queue->data[queue->size - 1];
    queue->size--;
    heapify(queue, 0);
    return node;
}

// insert a new node into the priority queue
void insert(Queue *queue, Node *node) {
    queue->size++;
    int i = queue->size - 1;

    while (i && node->freq < queue->data[(i - 1) / 2]->freq) {
        queue->data[i] = queue->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->data[i] = node;
}

// build the Huffman tree
Node *build_tree(char data[], unsigned freq[], unsigned size) {
    Queue *queue = create_queue(size);

    for (int i = 0; i < size; i++) {
        Node *node = new_node(data[i], freq[i]);
        insert(queue, node);
    }

    while (queue->size > 1) {
        Node *left = extract_min(queue);
        Node *right = extract_min(queue);

        Node *parent = new_node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        insert(queue, parent);
    }

    return extract_min(queue);
}

// create a lookup table for the Huffman codes
void create_lookup_table(Node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        create_lookup_table(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        create_lookup_table(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// encode the given text using the Huffman codes
void encode(Node *root, char text[]) {
    int n = strlen(text);
    int encoded_size = 0;
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        Node *temp = root;
        while (temp->data != text[i]) {
            if (temp->left && strchr(temp->left->data, text[i]) != NULL) {
                arr[encoded_size++] = 0;
                temp = temp->left;
            } else {
                arr[encoded_size++] = 1;
                temp = temp->right;
            }
        }
    }

    printf("Encoded Message: ");
    for (int i = 0; i < encoded_size; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// decode the given text using the Huffman codes
void decode(Node *root, char text[]) {
    int n = strlen(text);
    int i = 0;

    while (i < n) {
        Node *temp = root;
        while (temp->left || temp->right) {
            if (text[i++] == '0') {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        printf("%c", temp->data);
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {5, 9, 12, 13, 16, 45};
    unsigned size = sizeof(data) / sizeof(data[0]);

    Node *root = build_tree(data, freq, size);
    int arr[100], top = 0;
    create_lookup_table(root, arr, top);

    char text[] = "life is beautiful";
    printf("Original Message: %s\n", text);
    encode(root, text);

    char encoded_text[] = "110100000100101011110111000101111100011101000101";
    printf("Decoded Message: ");
    decode(root, encoded_text);

    return 0;
}