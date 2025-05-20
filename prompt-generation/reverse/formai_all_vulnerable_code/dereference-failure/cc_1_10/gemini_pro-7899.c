//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Node structure for our Huffman tree
typedef struct node {
    unsigned char ch;  // Character associated with the node
    int freq;        // Frequency of the character
    struct node *left, *right;  // Pointers to left and right children
} node;

// Queue node for node storage
typedef struct queue_node {
    node *data;
    struct queue_node *next;
} queue_node;

// Queue operations
queue_node *enqueue(queue_node *head, node *data) {
    queue_node *new_node = malloc(sizeof(queue_node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        queue_node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return head;
}

node *dequeue(queue_node **head) {
    if (*head == NULL) {
        return NULL;
    }
    node *data = (*head)->data;
    *head = (*head)->next;
    return data;
}

// Compare frequencies for sorting
int compare_freq(const void *a, const void *b) {
    node *node1 = *(node **)a;
    node *node2 = *(node **)b;
    return node1->freq - node2->freq;
}

// Build Huffman tree
node *build_tree(node *nodes, int n) {
    // Create a priority queue of nodes
    queue_node *head = NULL;
    for (int i = 0; i < n; i++) {
        head = enqueue(head, &nodes[i]);
    }

    // Build the tree
    while (head != NULL) {
        // Extract two nodes with the lowest frequencies
        node *node1 = dequeue(&head);
        node *node2 = dequeue(&head);
        if (node1 == NULL) {
            break;
        }

        // Create a parent node with the sum of frequencies
        node *parent = malloc(sizeof(node));
        parent->ch = '\0';
        parent->freq = node1->freq + node2->freq;
        parent->left = node1;
        parent->right = node2;

        // Insert the parent back into the queue
        head = enqueue(head, parent);
    }

    // Return the root of the tree
    return head ? head->data : NULL;
}

// Generate Huffman codes
void generate_codes(node *root, char *codes[], char *prefix) {
    if (root == NULL) {
        return;
    }

    if (root->ch != '\0') {
        codes[root->ch] = strdup(prefix);
    }

    generate_codes(root->left, codes, strcat(prefix, "0"));
    generate_codes(root->right, codes, strcat(prefix, "1"));
}

// Encode the input text using Huffman codes
char *encode(char *text, char *codes[]) {
    char *encoded = malloc(strlen(text) + 1);
    encoded[0] = '\0';
    for (int i = 0; i < strlen(text); i++) {
        strcat(encoded, codes[text[i]]);
    }
    return encoded;
}

// Decode the Huffman encoded text
char *decode(char *encoded, node *root) {
    char *decoded = malloc(strlen(encoded) + 1);
    decoded[0] = '\0';
    node *current = root;
    for (int i = 0; i < strlen(encoded); i++) {
        if (encoded[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->ch != '\0') {
            decoded[strlen(decoded)] = current->ch;
            current = root;
        }
    }
    return decoded;
}

// Driver code
int main() {
    // Input text
    char text[] = "Hello World!";

    // Calculate frequencies of characters
    int freq[256] = {0};
    for (int i = 0; i < strlen(text); i++) {
        freq[text[i]]++;
    }

    // Create nodes for each character
    node *nodes[256];
    int n = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            nodes[n] = malloc(sizeof(node));
            nodes[n]->ch = i;
            nodes[n]->freq = freq[i];
            nodes[n]->left = NULL;
            nodes[n]->right = NULL;
            n++;
        }
    }

    // Sort the nodes by frequency
    qsort(nodes, n, sizeof(node *), compare_freq);

    // Build Huffman tree
    node *root = build_tree(nodes, n);

    // Generate Huffman codes
    char *codes[256];
    for (int i = 0; i < 256; i++) {
        codes[i] = NULL;
    }
    generate_codes(root, codes, "");

    // Print Huffman codes
    printf("Huffman Codes:\n");
    for (int i = 0; i < 256; i++) {
        if (codes[i] != NULL) {
            printf("%c: %s\n", i, codes[i]);
        }
    }

    // Encode the input text
    char *encoded = encode(text, codes);
    printf("\nEncoded Text:\n%s\n", encoded);

    // Decode the Huffman encoded text
    char *decoded = decode(encoded, root);
    printf("\nDecoded Text:\n%s\n", decoded);

    // Free up allocated memory
    for (int i = 0; i < 256; i++) {
        free(codes[i]);
    }
    free(encoded);
    free(decoded);
    for (int i = 0; i < n; i++) {
        free(nodes[i]);
    }
    free(root);

    return 0;
}