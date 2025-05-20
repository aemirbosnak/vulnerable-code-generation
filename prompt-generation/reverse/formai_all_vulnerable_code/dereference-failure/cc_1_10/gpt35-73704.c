//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
    char data;
    int frequency;
    struct node_t* left;
    struct node_t* right;
} node;

typedef struct huff_table_t {
    node* root;
    int table_size;
} huff_table;

// Function to create a new node
node* new_node(char data, int frequency, node* left, node* right) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->frequency = frequency;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

// Function to create a new huff_table
huff_table* new_table(node* root, int table_size) {
    huff_table* new_table = malloc(sizeof(huff_table));
    new_table->root = root;
    new_table->table_size = table_size;
    return new_table;
}

// Function to free the memory used by a node
void free_node(node* n) {
    if (n == NULL) {
        return;
    }
    free_node(n->left);
    free_node(n->right);
    free(n);
}

// Function to free the memory used by a huff_table
void free_table(huff_table* t) {
    free_node(t->root);
    free(t);
}

// Function to compare two nodes based on their frequencies
int compare_nodes(const void* a, const void* b) {
    node** na = (node**) a;
    node** nb = (node**) b;
    return ((*na)->frequency - (*nb)->frequency);
}

// Function to build a Huffman Tree
node* build_huffman_tree(int* frequencies, size_t size) {
    node** nodes = malloc(sizeof(node*) * size);
    
    for (size_t i = 0; i < size; i++) {
        nodes[i] = new_node((char) i, frequencies[i], NULL, NULL);
    }
    
    while (size > 1) {
        qsort(nodes, size, sizeof(node*), compare_nodes);
        node* left = nodes[0];
        node* right = nodes[1];
        node* parent = new_node('\0', left->frequency + right->frequency, left, right);
        nodes[0] = parent;
        nodes[1] = nodes[size - 1];
        size--;
    }
    
    node* root = nodes[0];
    free(nodes);
    return root;
}

// Function to print a binary string
void print_binary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
}

// Function to encode a message using a Huffman Table
unsigned char* encode_message(huff_table* table, char* message, size_t message_size, size_t* encoded_size) {
    unsigned char* encoded = calloc(1, message_size);
    size_t index = 0;
    
    for (size_t i = 0; i < message_size; i++) {
        node* n = table->root;
        
        while (n->left != NULL && n->right != NULL) {
            if (message[i] == n->left->data) {
                encoded[index] |= 1 << (7 - (index % 8));
                n = n->left;
            } else {
                n = n->right;
            }
            index++;
        }
    }
    
    *encoded_size = index / 8 + (index % 8 == 0 ? 0 : 1);
    return encoded;
}

// Function to decode a message using a Huffman Table
char* decode_message(huff_table* table, unsigned char* encoded, size_t encoded_size, size_t message_size) {
    char* message = calloc(1, message_size + 1);
    size_t index = 0;
    
    for (size_t i = 0; i < encoded_size; i++) {
        for (int j = 7; j >= 0 && index < message_size; j--) {
            node* n = table->root;
            
            while (n->left != NULL && n->right != NULL && index < message_size) {
                if ((encoded[i] >> j) & 1) {
                    n = n->left;
                } else {
                    n = n->right;
                }
                index++;
            }
            
            if (index <= message_size) {
                message[index - 1] = n->data;
            }
        }
    }
    
    return message;
}

int main() {
    int frequencies[] = {10, 15, 12, 3, 4, 13, 1};
    size_t size = sizeof(frequencies) / sizeof(int);
    node* root = build_huffman_tree(frequencies, size);
    huff_table* table = new_table(root, size);
    
    char* message = "huffman encoding example";
    size_t message_size = strlen(message);
    size_t encoded_size;
    unsigned char* encoded = encode_message(table, message, message_size, &encoded_size);
    char* decoded = decode_message(table, encoded, encoded_size, message_size);
    
    printf("Huffman Encoding Example\n");
    printf("Original message: %s\n", message);
    printf("Encoded message: ");
    for (size_t i = 0; i < encoded_size; i++) {
        print_binary(encoded[i]);
        printf(" ");
    }
    printf("\nDecoded message: %s\n", decoded);
    
    free(encoded);
    free(decoded);
    free_table(table);
    return 0;
}