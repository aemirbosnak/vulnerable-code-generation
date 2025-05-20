//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SYMBOLS 256

// A node in the Huffman tree
struct node {
    int data;
    int freq;
    struct node *left, *right;
};

// A min-heap of nodes
struct heap {
    int size;
    struct node **nodes;
};

// Creates a new node with the given data and frequency
struct node *create_node(int data, int freq) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Inserts a node into the min-heap
void insert_node(struct heap *heap, struct node *node) {
    heap->nodes[heap->size] = node;
    heap->size++;

    // Heapify the heap
    int i = heap->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->nodes[i]->freq < heap->nodes[parent]->freq) {
            struct node *temp = heap->nodes[i];
            heap->nodes[i] = heap->nodes[parent];
            heap->nodes[parent] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

// Extracts the root node from the min-heap
struct node *extract_min(struct heap *heap) {
    struct node *min_node = heap->nodes[0];
    heap->size--;

    // Swap the root node with the last node
    heap->nodes[0] = heap->nodes[heap->size];

    // Heapify the heap
    int i = 0;
    while (i < heap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        int smallest = i;
        if (left < heap->size && heap->nodes[left]->freq < heap->nodes[smallest]->freq) {
            smallest = left;
        }
        if (right < heap->size && heap->nodes[right]->freq < heap->nodes[smallest]->freq) {
            smallest = right;
        }

        if (smallest != i) {
            struct node *temp = heap->nodes[i];
            heap->nodes[i] = heap->nodes[smallest];
            heap->nodes[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }

    return min_node;
}

// Creates a min-heap of nodes
struct heap *create_heap(int frequencies[], int size) {
    struct heap *heap = (struct heap *)malloc(sizeof(struct heap));
    heap->size = 0;
    heap->nodes = (struct node **)malloc(sizeof(struct node *) * size);

    for (int i = 0; i < size; i++) {
        if (frequencies[i] > 0) {
            struct node *node = create_node(i, frequencies[i]);
            insert_node(heap, node);
        }
    }

    return heap;
}

// Builds a Huffman tree from the min-heap
struct node *build_huffman_tree(struct heap *heap) {
    while (heap->size > 1) {
        struct node *left_child = extract_min(heap);
        struct node *right_child = extract_min(heap);

        struct node *parent = create_node(-1, left_child->freq + right_child->freq);
        parent->left = left_child;
        parent->right = right_child;

        insert_node(heap, parent);
    }

    return extract_min(heap);
}

// Prints the Huffman codes for the symbols
void print_huffman_codes(struct node *root, int code[], int top) {
    if (root->left == NULL && root->right == NULL) {
        printf("%d: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
        return;
    }

    code[top] = 0;
    print_huffman_codes(root->left, code, top + 1);
    code[top] = 1;
    print_huffman_codes(root->right, code, top + 1);
}

// Encodes a string using the Huffman codes
char *encode_string(struct node *root, char *string) {
    int size = strlen(string);
    char *encoded_string = (char *)malloc(sizeof(char) * size * 8);
    int top = 0;

    for (int i = 0; i < size; i++) {
        struct node *current = root;
        while (current->left != NULL && current->right != NULL) {
            if (string[i] == current->data) {
                break;
            } else if (string[i] < current->data) {
                current = current->left;
                encoded_string[top++] = '0';
            } else {
                current = current->right;
                encoded_string[top++] = '1';
            }
        }

        if (current->left == NULL && current->right == NULL) {
            encoded_string[top++] = '0';
        }
    }

    encoded_string[top] = '\0';
    return encoded_string;
}

// Decodes a string using the Huffman codes
char *decode_string(struct node *root, char *encoded_string) {
    int size = strlen(encoded_string);
    char *decoded_string = (char *)malloc(sizeof(char) * size);
    int top = 0;

    struct node *current = root;
    for (int i = 0; i < size; i++) {
        if (encoded_string[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            decoded_string[top++] = current->data;
            current = root;
        }
    }

    decoded_string[top] = '\0';
    return decoded_string;
}

int main() {
    // Get the frequencies of the symbols
    int frequencies[MAX_SYMBOLS] = {0};
    char string[] = "Hello world!";
    for (int i = 0; string[i] != '\0'; i++) {
        frequencies[string[i]]++;
    }

    // Create a min-heap of nodes
    struct heap *heap = create_heap(frequencies, MAX_SYMBOLS);

    // Build a Huffman tree from the min-heap
    struct node *root = build_huffman_tree(heap);

    // Print the Huffman codes for the symbols
    int code[MAX_SYMBOLS];
    printf("Huffman Codes:\n");
    print_huffman_codes(root, code, 0);

    // Encode the string using the Huffman codes
    char *encoded_string = encode_string(root, string);
    printf("\nEncoded String: %s\n", encoded_string);

    // Decode the string using the Huffman codes
    char *decoded_string = decode_string(root, encoded_string);
    printf("\nDecoded String: %s\n", decoded_string);

    return 0;
}