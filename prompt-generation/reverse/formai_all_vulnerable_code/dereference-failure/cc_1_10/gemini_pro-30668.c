//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int freq;
    char c;
    struct node *left, *right;
} node;

typedef struct min_heap {
    int size;
    node **nodes;
} min_heap;

node *create_node(char c, int freq) {
    node *n = malloc(sizeof(node));
    n->c = c;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

min_heap *create_heap(int size) {
    min_heap *h = malloc(sizeof(min_heap));
    h->size = 0;
    h->nodes = malloc(sizeof(node *) * size);
    return h;
}

void swap_nodes(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(min_heap *h, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < h->size && h->nodes[left]->freq < h->nodes[smallest]->freq) {
        smallest = left;
    }

    if (right < h->size && h->nodes[right]->freq < h->nodes[smallest]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        swap_nodes(&h->nodes[i], &h->nodes[smallest]);
        min_heapify(h, smallest);
    }
}

node *extract_min(min_heap *h) {
    if (h->size == 0) {
        return NULL;
    }

    node *min = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;
    min_heapify(h, 0);
    return min;
}

void insert_node(min_heap *h, node *n) {
    h->nodes[h->size] = n;
    h->size++;
    int i = h->size - 1;
    while (i > 0 && h->nodes[(i - 1) / 2]->freq > h->nodes[i]->freq) {
        swap_nodes(&h->nodes[i], &h->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void build_heap(min_heap *h) {
    int i;
    for (i = (h->size - 1) / 2; i >= 0; i--) {
        min_heapify(h, i);
    }
}

node *build_tree(min_heap *h) {
    if (h->size == 0) {
        return NULL;
    }

    while (h->size > 1) {
        node *left = extract_min(h);
        node *right = extract_min(h);
        node *parent = create_node(' ', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        insert_node(h, parent);
    }

    return extract_min(h);
}

void print_codes(node *root, char *code, char **codes) {
    if (root->left == NULL && root->right == NULL) {
        codes[root->c] = code;
    } else {
        char *left_code = malloc(strlen(code) + 1);
        strcpy(left_code, code);
        strcat(left_code, "0");
        print_codes(root->left, left_code, codes);
        free(left_code);

        char *right_code = malloc(strlen(code) + 1);
        strcpy(right_code, code);
        strcat(right_code, "1");
        print_codes(root->right, right_code, codes);
        free(right_code);
    }
}

char **get_codes(node *root, char **codes) {
    char *code = malloc(1);
    code[0] = '\0';
    print_codes(root, code, codes);
    free(code);
    return codes;
}

void encode(char *message, char **codes) {
    char *encoded_message = malloc(strlen(message) + 1);
    strcpy(encoded_message, "");

    int i;
    for (i = 0; i < strlen(message); i++) {
        strcat(encoded_message, codes[message[i]]);
    }

    printf("Encoded message: %s\n", encoded_message);
    free(encoded_message);
}

void decode(char *encoded_message, node *root) {
    node *current = root;
    char *decoded_message = malloc(strlen(encoded_message) + 1);
    strcpy(decoded_message, "");

    int i;
    for (i = 0; i < strlen(encoded_message); i++) {
        if (encoded_message[i] == '0') {
            current = current->left;
        } else if (encoded_message[i] == '1') {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            strncat(decoded_message, &current->c, 1);
            current = root;
        }
    }

    printf("Decoded message: %s\n", decoded_message);
    free(decoded_message);
}

int main() {
    char message[] = "Hello, world!";

    int frequency[256] = {0};
    int i;
    for (i = 0; i < strlen(message); i++) {
        frequency[message[i]]++;
    }

    min_heap *h = create_heap(256);
    for (i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            insert_node(h, create_node(i, frequency[i]));
        }
    }

    build_heap(h);
    node *root = build_tree(h);

    char **codes = malloc(256 * sizeof(char *));
    for (i = 0; i < 256; i++) {
        codes[i] = malloc(1);
        codes[i][0] = '\0';
    }

    get_codes(root, codes);
    encode(message, codes);
    decode("010010000110010101101100011011000110111100100000011101110110111101110010011011010110010100100000011110010110111101110101", root);

    for (i = 0; i < 256; i++) {
        free(codes[i]);
    }
    free(codes);

    return 0;
}