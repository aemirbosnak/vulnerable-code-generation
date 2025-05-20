//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Huffman tree node struct
struct h_node {
    char data;
    int freq;
    struct h_node *left, *right;
};

// Huffman tree struct
struct h_tree {
    int size;
    struct h_node *root;
};

// Huffman code struct
struct h_code {
    char *code;
    int length;
};

// Character frequency array
int char_freq[256];

// Huffman node comparator function for priority queue
int cmp_nodes(const void *a, const void *b) {
    const struct h_node *node1 = *(const struct h_node **)a;
    const struct h_node *node2 = *(const struct h_node **)b;
    return (node1->freq) - (node2->freq);
}

// Allocate memory for new Huffman tree node
struct h_node *new_h_node(char data, int freq) {
    struct h_node *node = (struct h_node *)malloc(sizeof(struct h_node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Build Huffman tree given character frequencies
struct h_tree *build_h_tree() {
    struct h_tree *tree = (struct h_tree *)malloc(sizeof(struct h_tree));
    tree->root = NULL;
    tree->size = 0;

    // Create priority queue for Huffman tree nodes
    int num_nodes = 0;
    struct h_node *nodes[256];
    for (int i = 0; i < 256; i++) {
        if (char_freq[i]) {
            nodes[num_nodes++] = new_h_node(i, char_freq[i]);
        }
    }
    qsort(nodes, num_nodes, sizeof(struct h_node *), cmp_nodes); // Sort nodes by frequency

    // Build Huffman tree from priority queue
    while (num_nodes > 1) {
        struct h_node *node1 = nodes[--num_nodes];
        struct h_node *node2 = nodes[--num_nodes];
        struct h_node *parent = new_h_node('#', node1->freq + node2->freq);
        parent->left = node1;
        parent->right = node2;
        nodes[num_nodes++] = parent;
        qsort(nodes, num_nodes, sizeof(struct h_node *), cmp_nodes); // Re-sort nodes by frequency
    }

    if (num_nodes > 0) {
        tree->root = nodes[0];
        tree->size = 1;
    }

    return tree;
}

// Encode a character using Huffman tree
void *encode_char(void *data) {
    struct h_node *node = (struct h_node *) data;
    char *encode = (char *)malloc(256 * sizeof(char)); // Allocate memory for encoded string
    memset(encode, '\0', 256 * sizeof(char)); // Initialize encoded string with null characters
    int index = 0;
    while (node != NULL && node->data != '#') {
        if (node->left && node->left->data != '#') {
            encode[index++] = '0';
            node = node->left;
        } else if (node->right && node->right->data != '#') {
            encode[index++] = '1';
            node = node->right;
        } else {
            break;
        }
    }
    struct h_code *code = (struct h_code *)malloc(sizeof(struct h_code)); // Allocate memory for Huffman code
    code->code = (char *)malloc(index * sizeof(char)); // Allocate memory for encoded string without extra null characters
    strcpy(code->code, encode); // Copy encoded string to Huffman code struct
    code->length = index; // Set length of encoded string
    free(encode); // Free temporary memory for encoded string
    return code;
}

int main() {
    // Input string to be encoded
    char input[100];
    printf("Enter string to be encoded:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    // Calculate character frequencies
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        char_freq[(int)input[i]]++;
    }

    // Build Huffman tree
    struct h_tree *tree = build_h_tree();

    // Multi-threaded encoding using Huffman tree
    pthread_t threads[len];
    for (int i = 0; i < len; i++) {
        pthread_create(&threads[i], NULL, encode_char, (void *)tree->root);
    }

    // Print Huffman codes
    printf("Huffman codes:\n");
    for (int i = 0; i < len; i++) {
        struct h_code *code;
        pthread_join(threads[i], (void **)&code);
        printf("%c: %s\n", tree->root->data, code->code);
        free(code->code);
        free(code);
    }

    // Free memory
    free(tree->root);
    free(tree);

    return 0;
}