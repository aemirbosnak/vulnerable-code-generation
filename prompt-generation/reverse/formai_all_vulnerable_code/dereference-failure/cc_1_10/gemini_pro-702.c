//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
} node;

typedef struct heap {
    node *nodes[MAX_SIZE];
    int size;
} heap;

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
        node *temp = h->nodes[i];
        h->nodes[i] = h->nodes[smallest];
        h->nodes[smallest] = temp;
        heapify(h, smallest);
    }
}

void build_heap(heap *h, node *nodes[], int size) {
    h->size = size;

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(h, i);
    }
}

node *pop_min(heap *h) {
    if (h->size == 0) {
        return NULL;
    }

    node *min = h->nodes[0];

    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;
    heapify(h, 0);

    return min;
}

node *huffman_tree(char *message) {
    int frequencies[MAX_SIZE] = {0};

    for (int i = 0; message[i] != '\0'; i++) {
        frequencies[(int) message[i]]++;
    }

    heap h;
    node *nodes[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        if (frequencies[i] > 0) {
            nodes[i] = malloc(sizeof(node));
            nodes[i]->character = (char) i;
            nodes[i]->frequency = frequencies[i];
            nodes[i]->left = NULL;
            nodes[i]->right = NULL;
        }
    }

    build_heap(&h, nodes, MAX_SIZE);

    while (h.size > 1) {
        node *left = pop_min(&h);
        node *right = pop_min(&h);

        node *parent = malloc(sizeof(node));
        parent->character = '\0';
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;

        h.nodes[h.size++] = parent;
        heapify(&h, h.size - 1);
    }

    return pop_min(&h);
}

void print_codes(node *root, char *code, char *codes[]) {
    if (root->left == NULL && root->right == NULL) {
        codes[(int) root->character] = strdup(code);
        return;
    }

    char left_code[MAX_SIZE] = {0};
    char right_code[MAX_SIZE] = {0};

    strcpy(left_code, code);
    strcpy(right_code, code);

    strcat(left_code, "0");
    strcat(right_code, "1");

    print_codes(root->left, left_code, codes);
    print_codes(root->right, right_code, codes);
}

void encode(char *message, char *codes[], char *encoded_message) {
    for (int i = 0; message[i] != '\0'; i++) {
        strcat(encoded_message, codes[(int) message[i]]);
    }
}

void decode(char *encoded_message, node *root, char *decoded_message) {
    node *current = root;

    for (int i = 0; encoded_message[i] != '\0'; i++) {
        if (encoded_message[i] == '0') {
            current = current->left;
        } else if (encoded_message[i] == '1') {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            decoded_message[i] = current->character;
            current = root;
        }
    }
}

int main() {
    char message[] = "Hello, world!";

    node *root = huffman_tree(message);
    char *codes[MAX_SIZE] = {0};
    print_codes(root, "", codes);

    char encoded_message[MAX_SIZE] = {0};
    encode(message, codes, encoded_message);

    char decoded_message[MAX_SIZE] = {0};
    decode(encoded_message, root, decoded_message);

    printf("Original message: %s\n", message);
    printf("Encoded message: %s\n", encoded_message);
    printf("Decoded message: %s\n", decoded_message);

    return 0;
}