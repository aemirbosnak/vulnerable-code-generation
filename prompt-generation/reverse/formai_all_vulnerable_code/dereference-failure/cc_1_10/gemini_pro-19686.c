//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node of the Huffman tree
struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

// Comparator function for qsort()
int compare(const void *a, const void *b) {
    const struct Node *node1 = a;
    const struct Node *node2 = b;
    return node1->freq - node2->freq;
}

// Creates a new node
struct Node *create_node(char ch, int freq) {
    struct Node *node = malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Builds a Huffman tree from a given set of characters and their frequencies
struct Node *build_huffman_tree(struct Node *nodes, int size) {
    // Sort the nodes by their frequencies
    qsort(nodes, size, sizeof(struct Node), compare);

    // Create a priority queue to store the nodes
    struct Node **queue = malloc(sizeof(struct Node *) * size);
    int front = 0, rear = 0;

    // Insert the nodes into the priority queue
    for (int i = 0; i < size; i++) {
        queue[rear++] = nodes + i;
    }

    // Build the Huffman tree
    while (front < rear - 1) {
        // Get the two nodes with the lowest frequencies
        struct Node *node1 = queue[front++];
        struct Node *node2 = queue[front++];

        // Create a new node with the combined frequency
        struct Node *parent = create_node('\0', node1->freq + node2->freq);
        parent->left = node1;
        parent->right = node2;

        // Insert the new node into the priority queue
        int j;
        for (j = rear - 1; j >= 0 && parent->freq < queue[j]->freq; j--) {
            queue[j + 1] = queue[j];
        }
        queue[j + 1] = parent;
        rear++;
    }

    // The root of the Huffman tree is the last node in the priority queue
    return queue[rear - 1];
}

// Encodes a given string using the Huffman tree
char *encode(struct Node *root, char *str) {
    int size = strlen(str);
    char *encoded_str = malloc(sizeof(char) * (size + 1));
    int encoded_idx = 0;

    for (int i = 0; i < size; i++) {
        struct Node *node = root;
        while (node->ch != str[i]) {
            if (str[i] <= node->ch) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        // Trace the path from the root to the node
        while (node != root) {
            if (node->ch <= root->ch) {
                encoded_str[encoded_idx++] = '0';
                node = node->left;
            } else {
                encoded_str[encoded_idx++] = '1';
                node = node->right;
            }
        }
    }

    // Terminate the encoded string
    encoded_str[encoded_idx] = '\0';

    return encoded_str;
}

// Decodes a given encoded string using the Huffman tree
char *decode(struct Node *root, char *encoded_str) {
    int size = strlen(encoded_str);
    char *decoded_str = malloc(sizeof(char) * (size + 1));
    int decoded_idx = 0;

    struct Node *node = root;

    for (int i = 0; i < size; i++) {
        if (encoded_str[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }

        if (node->ch != '\0') {
            decoded_str[decoded_idx++] = node->ch;
            node = root;
        }
    }

    // Terminate the decoded string
    decoded_str[decoded_idx] = '\0';

    return decoded_str;
}

// Main function
int main() {
    // Build a Huffman tree from a given set of characters and their frequencies
    struct Node nodes[] = {
        create_node('A', 5),
        create_node('B', 9),
        create_node('C', 12),
        create_node('D', 13),
        create_node('E', 16),
        create_node('F', 45),
    };
    int size = sizeof(nodes) / sizeof(nodes[0]);
    struct Node *root = build_huffman_tree(nodes, size);

    // Encode and decode a given string
    char *str = "ABCDE";
    char *encoded_str = encode(root, str);
    char *decoded_str = decode(root, encoded_str);

    // Print the original string, the encoded string, and the decoded string
    printf("Original string: %s\n", str);
    printf("Encoded string: %s\n", encoded_str);
    printf("Decoded string: %s\n", decoded_str);

    // Free the allocated memory
    free(encoded_str);
    free(decoded_str);
    for (int i = 0; i < size; i++) {
        free(nodes + i);
    }
    free(root);

    return 0;
}