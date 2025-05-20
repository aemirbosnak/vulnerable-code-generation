//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman Tree
typedef struct node {
    char c;
    int freq;
    struct node *left, *right;
} node_t;

// Queue structure for priority queue
typedef struct queue {
    node_t **nodes;
    int front, rear, size;
} queue_t;

// Create a new node with character c and frequency freq
node_t *new_node(char c, int freq) {
    node_t *new = malloc(sizeof(node_t));
    new->c = c;
    new->freq = freq;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Create a new queue of size size
queue_t *new_queue(int size) {
    queue_t *new = malloc(sizeof(queue_t));
    new->nodes = malloc(sizeof(node_t *) * size);
    new->front = new->rear = -1;
    new->size = size;
    return new;
}

// Insert a node into the queue
void enqueue(queue_t *q, node_t *new) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front++;
    }
    q->nodes[++q->rear] = new;
}

// Remove a node from the queue
node_t *dequeue(queue_t *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return NULL;
    }
    return q->nodes[q->front++];
}

// Check if the queue is empty
int is_empty(queue_t *q) {
    return q->front == -1;
}

// Compare two nodes based on their frequencies
int compare(const void *a, const void *b) {
    node_t *n1 = *(node_t **)a;
    node_t *n2 = *(node_t **)b;
    return n1->freq - n2->freq;
}

// Build a Huffman tree from a given set of characters and their frequencies
node_t *build_tree(char *data, int *freq, int size) {
    // Create a priority queue
    queue_t *q = new_queue(size);

    // Insert nodes into the queue
    for (int i = 0; i < size; i++) {
        enqueue(q, new_node(data[i], freq[i]));
    }

    // Build the Huffman tree
    while (!is_empty(q)) {
        // Remove two nodes with the lowest frequencies
        node_t *n1 = dequeue(q);
        node_t *n2 = dequeue(q);

        // Create a new node with the combined frequency of the two nodes
        node_t *new = new_node('\0', n1->freq + n2->freq);
        new->left = n1;
        new->right = n2;

        // Insert the new node into the queue
        enqueue(q, new);
    }

    // Return the root node of the Huffman tree
    return dequeue(q);
}

// Perform breadth-first search on the Huffman tree and print the encodings
void print_encodings(node_t *root, char *encoding, int top) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->c, encoding);
        return;
    }
    encoding[top] = '0';
    print_encodings(root->left, encoding, top + 1);
    encoding[top] = '1';
    print_encodings(root->right, encoding, top + 1);
}

// Encode a string using the Huffman tree
char *encode(node_t *root, char *source, int size) {
    // Create an array to store the encoded string
    char *encoded = malloc(size * sizeof(char));

    // Traverse the Huffman tree and build the encoded string
    for (int i = 0; i < size; i++) {
        node_t *current = root;
        int j = 0;
        while (current->left || current->right) {
            if (source[i] == current->c) {
                break;
            }
            if (current->left && source[i] == current->left->c) {
                encoded[j++] = '0';
                current = current->left;
            } else {
                encoded[j++] = '1';
                current = current->right;
            }
        }
    }

    return encoded;
}

int main() {
    // Input data
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int freq[] = {12, 6, 4, 5, 10, 4, 3, 4, 7, 2, 7, 5, 2, 3, 4, 3, 1, 5, 2, 1, 5, 5, 4, 2, 1, 1};
    int size = sizeof(data) / sizeof(data[0]);

    // Build the Huffman tree
    node_t *root = build_tree(data, freq, size);

    // Print the encodings
    char encoding[size + 1];
    print_encodings(root, encoding, 0);

    // Encode a string
    char source[] = "abcdefghijkl";
    char *encoded_string = encode(root, source, strlen(source));

    // Print the encoded string
    printf("Encoded string: %s\n", encoded_string);

    return 0;
}