//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman Coding Node
struct huffman_node {
    char symbol;
    unsigned int frequency;
    struct huffman_node *left, *right;
};

// Function to create a new Huffman Coding Node
struct huffman_node* new_node(char symbol, unsigned int frequency, struct huffman_node *left, struct huffman_node *right) {
    struct huffman_node *node = malloc(sizeof(struct huffman_node));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}

// Binary Heap Node
struct binary_heap_node {
    struct huffman_node *data;
    struct binary_heap_node *left, *right;
};

// Function to create a new Binary Heap Node
struct binary_heap_node* new_binary_heap_node(struct huffman_node *data) {
    struct binary_heap_node *node = malloc(sizeof(struct binary_heap_node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to swap Binary Heap Node pointers
void swap_binary_heap_nodes(struct binary_heap_node **a, struct binary_heap_node **b) {
    struct binary_heap_node *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to minimize Binary Heap Node
void min_heapify(struct binary_heap_node *root) {
    struct binary_heap_node *smallest = root;
    if (root->left && root->left->data->frequency < smallest->data->frequency) {
        smallest = root->left;
    }
    if (root->right && root->right->data->frequency < smallest->data->frequency) {
        smallest = root->right;
    }
    if (smallest != root) {
        swap_binary_heap_nodes(&root, &smallest);
        min_heapify(smallest);
    }
}

// Function to extract minimum Binary Heap Node
struct binary_heap_node* extract_minimum(struct binary_heap_node **root) {
    struct binary_heap_node *minimum = *root;
    if ((*root)->left) {
        minimum = (*root)->left;
    }
    else if ((*root)->right->data->frequency < minimum->data->frequency) {
        minimum = (*root)->right;
    }
    if (minimum == *root) {
        *root = NULL;
    }
    return minimum;
}

// Function to insert Binary Heap Node
void insert_binary_heap_node(struct binary_heap_node **root, struct binary_heap_node *node) {
    if ((*root)->data->frequency > node->data->frequency) {
        node->left = *root;
        *root = node;
    }
    else {
        struct binary_heap_node *current = *root;
        while (current->right && current->right->data->frequency < node->data->frequency) {
            current = current->right;
        }
        node->left = current->right;
        current->right = node;
    }
}

// Function to build Huffman Coding Tree
struct huffman_node* build_huffman_tree(struct huffman_node **symbols, unsigned int count) {
    struct binary_heap_node *root = malloc(sizeof(struct binary_heap_node));
    root->data = symbols[0];
    for (unsigned int i = 1; i < count; i++) {
        struct binary_heap_node *node = new_binary_heap_node(symbols[i]);
        insert_binary_heap_node(&root, node);
    }
    while (root->right) {
        struct binary_heap_node *node = new_binary_heap_node(NULL);
        node->left = extract_minimum(&root);
        node->right = extract_minimum(&root);
        node->data = new_node('\0', node->left->data->frequency + node->right->data->frequency, node->left->data, node->right->data);
        insert_binary_heap_node(&root, node);
    }
    return root->data;
}

// Function to print Huffman Codes
void print_huffman_codes(struct huffman_node *root, int *buffer, int depth) {
    if (root->left) { // Internal Node
        buffer[depth] = 0;
        print_huffman_codes(root->left, buffer, depth + 1);
        buffer[depth] = 1;
        print_huffman_codes(root->right, buffer, depth + 1);
    }
    else { // Leaf Node
        printf("%c: ", root->symbol);
        for (int i = 0; i < depth; i++) {
            printf("%d", buffer[i]);
        }
        printf("\n");
    }
}

// Function to allocate memory for Huffman Coding Nodes
void allocate_huffman_nodes(struct huffman_node **nodes, char *symbols, unsigned int *frequencies, unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
        nodes[i] = new_node(symbols[i], frequencies[i], NULL, NULL);
    }
}

int main() {
    char symbols[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    unsigned int frequencies[] = { 200, 50, 60, 100, 70, 20, 10 };
    unsigned int count = sizeof(symbols) / sizeof(symbols[0]);
    struct huffman_node *nodes[count];
    allocate_huffman_nodes(nodes, symbols, frequencies, count);
    struct huffman_node *root = build_huffman_tree(nodes, count);
    int buffer[count - 1];
    printf("Huffman Codes:\n");
    print_huffman_codes(root, buffer, 0);
    return 0;
}