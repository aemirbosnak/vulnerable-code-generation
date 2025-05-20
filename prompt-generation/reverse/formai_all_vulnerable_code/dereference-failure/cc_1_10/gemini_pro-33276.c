//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int frequency;
    char character;
    struct node *left, *right;
} node;

typedef struct heap {
    int size;
    node **nodes;
} heap;

heap *create_heap(int capacity) {
    heap *h = malloc(sizeof(heap));
    h->size = 0;
    h->nodes = malloc(sizeof(node *) * capacity);
    return h;
}

void destroy_heap(heap *h) {
    for (int i = 0; i < h->size; i++) {
        free(h->nodes[i]);
    }
    free(h->nodes);
    free(h);
}

void swap_nodes(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->nodes[left]->frequency < h->nodes[smallest]->frequency) {
        smallest = left;
    }

    if (right < h->size && h->nodes[right]->frequency < h->nodes[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != i) {
        swap_nodes(&h->nodes[smallest], &h->nodes[i]);
        heapify(h, smallest);
    }
}

node *extract_min(heap *h) {
    if (h->size == 0) {
        return NULL;
    }

    node *min = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;
    heapify(h, 0);
    return min;
}

void insert_node(heap *h, node *n) {
    h->nodes[h->size] = n;
    h->size++;
    int i = h->size - 1;

    while (i > 0 && h->nodes[(i - 1) / 2]->frequency > h->nodes[i]->frequency) {
        swap_nodes(&h->nodes[(i - 1) / 2], &h->nodes[i]);
        i = (i - 1) / 2;
    }
}

node *build_huffman_tree(char *message) {
    int frequency[256] = {0};
    for (int i = 0; message[i] != '\0'; i++) {
        frequency[message[i]]++;
    }

    heap *h = create_heap(256);

    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            node *n = malloc(sizeof(node));
            n->frequency = frequency[i];
            n->character = i;
            n->left = NULL;
            n->right = NULL;
            insert_node(h, n);
        }
    }

    while (h->size > 1) {
        node *left = extract_min(h);
        node *right = extract_min(h);

        node *parent = malloc(sizeof(node));
        parent->frequency = left->frequency + right->frequency;
        parent->character = '\0';
        parent->left = left;
        parent->right = right;
        insert_node(h, parent);
    }

    destroy_heap(h);
    return extract_min(h);
}

void print_huffman_code(node *root, char *code) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->character, code);
    } else {
        print_huffman_code(root->left, strcat(code, "0"));
        print_huffman_code(root->right, strcat(code, "1"));
    }
}

void encode_message(node *root, char *message, char *encoded_message) {
    int index = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        node *current = root;
        while (current->left != NULL && current->right != NULL) {
            if (message[i] == current->character) {
                break;
            } else if (current->character > message[i]) {
                current = current->left;
                encoded_message[index++] = '0';
            } else {
                current = current->right;
                encoded_message[index++] = '1';
            }
        }
        encoded_message[index++] = current->character;
    }
    encoded_message[index] = '\0';
}

void decode_message(node *root, char *encoded_message, char *decoded_message) {
    int index = 0;
    node *current = root;
    while (encoded_message[index] != '\0') {
        if (encoded_message[index] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == NULL && current->right == NULL) {
            decoded_message[index++] = current->character;
            current = root;
        }
        index++;
    }
    decoded_message[index] = '\0';
}

int main() {
    char message[] = "Hello world!";
    node *huffman_tree = build_huffman_tree(message);
    char huffman_code[256];
    print_huffman_code(huffman_tree, huffman_code);

    char encoded_message[1024];
    encode_message(huffman_tree, message, encoded_message);
    printf("Encoded message: %s\n", encoded_message);

    char decoded_message[1024];
    decode_message(huffman_tree, encoded_message, decoded_message);
    printf("Decoded message: %s\n", decoded_message);
    return 0;
}