//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman tree
typedef struct Node {
    char ch;
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

// Queue node structure
typedef struct QueueNode {
    Node *node;
    struct QueueNode *next;
} QueueNode;

// Queue operations
QueueNode *enqueue(QueueNode *head, Node *node) {
    QueueNode *new_node = (QueueNode *) malloc(sizeof(QueueNode));
    new_node->node = node;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        QueueNode *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

Node *dequeue(QueueNode **head) {
    if (*head == NULL) {
        return NULL;
    }
    Node *node = (*head)->node;
    *head = (*head)->next;
    return node;
}

// Huffman tree creation
Node *create_huffman_tree(char *data, int size) {
    // Create a frequency table
    int freq[256] = {0};
    for (int i = 0; i < size; i++) {
        freq[data[i]]++;
    }

    // Create a priority queue of nodes
    QueueNode *head = NULL;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            Node *node = (Node *) malloc(sizeof(Node));
            node->ch = i;
            node->freq = freq[i];
            node->left = NULL;
            node->right = NULL;
            head = enqueue(head, node);
        }
    }

    // Build the Huffman tree
    while (head->next != NULL) {
        // Dequeue two nodes with the lowest frequency
        Node *left_node = dequeue(&head);
        Node *right_node = dequeue(&head);

        // Create a new node with the sum of frequencies
        Node *parent_node = (Node *) malloc(sizeof(Node));
        parent_node->ch = '\0';
        parent_node->freq = left_node->freq + right_node->freq;
        parent_node->left = left_node;
        parent_node->right = right_node;

        // Enqueue the new node back into the queue
        head = enqueue(head, parent_node);
    }

    // The last node in the queue is the root of the Huffman tree
    return dequeue(&head);
}

// Huffman encoding
char *encode(Node *root, char *data, int size) {
    char *encoded_data = (char *) malloc(size * 8);
    int index = 0;
    for (int i = 0; i < size; i++) {
        Node *temp = root;
        while (temp->left != NULL || temp->right != NULL) {
            if (data[i] == temp->ch) {
                break;
            }
            if (data[i] < temp->ch) {
                temp = temp->left;
                encoded_data[index++] = '0';
            } else {
                temp = temp->right;
                encoded_data[index++] = '1';
            }
        }
        while (temp != NULL) {
            encoded_data[index++] = temp->ch == '0' ? '0' : '1';
            temp = temp->right;
        }
    }
    encoded_data[index] = '\0';
    return encoded_data;
}

// Huffman decoding
char *decode(Node *root, char *encoded_data) {
    char *decoded_data = (char *) malloc(strlen(encoded_data));
    int index = 0;
    Node *temp = root;
    for (int i = 0; encoded_data[i] != '\0'; i++) {
        if (encoded_data[i] == '0') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        if (temp->left == NULL && temp->right == NULL) {
            decoded_data[index++] = temp->ch;
            temp = root;
        }
    }
    decoded_data[index] = '\0';
    return decoded_data;
}

// Main function
int main() {
    // Input data
    char data[] = "HELLOWORLD";
    int size = strlen(data);

    // Create Huffman tree
    Node *root = create_huffman_tree(data, size);

    // Encode and decode the data
    char *encoded_data = encode(root, data, size);
    char *decoded_data = decode(root, encoded_data);

    // Print the results
    printf("Original data: %s\n", data);
    printf("Encoded data: %s\n", encoded_data);
    printf("Decoded data: %s\n", decoded_data);

    return 0;
}