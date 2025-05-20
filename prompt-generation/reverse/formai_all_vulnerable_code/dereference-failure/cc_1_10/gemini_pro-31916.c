//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 256

typedef struct node {
    int freq;
    char data;
    struct node *left, *right;
} node;

typedef struct heap {
    node *nodes[MAX_CODE_LEN];
    int size;
} heap;

node *create_node(char data, int freq) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

heap *create_heap() {
    heap *new_heap = malloc(sizeof(heap));
    new_heap->size = 0;
    return new_heap;
}

void swap(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(heap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->nodes[left]->freq < h->nodes[smallest]->freq) {
        smallest = left;
    }

    if (right < h->size && h->nodes[right]->freq < h->nodes[smallest]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&h->nodes[i], &h->nodes[smallest]);
        min_heapify(h, smallest);
    }
}

node *extract_min(heap *h) {
    if (h->size == 0) {
        return NULL;
    }

    node *min = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;
    min_heapify(h, 0);

    return min;
}

void insert_heap(heap *h, node *new_node) {
    h->size++;
    int i = h->size - 1;

    while (i > 0 && h->nodes[(i - 1) / 2]->freq > new_node->freq) {
        h->nodes[i] = h->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    h->nodes[i] = new_node;
}

node *create_huffman_tree(char *str) {
    heap *h = create_heap();

    int freq[256] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            insert_heap(h, create_node(i, freq[i]));
        }
    }

    while (h->size > 1) {
        node *left = extract_min(h);
        node *right = extract_min(h);

        node *new_node = create_node('$', left->freq + right->freq);
        new_node->left = left;
        new_node->right = right;

        insert_heap(h, new_node);
    }

    return extract_min(h);
}

void create_huffman_codes(node *root, char *codes[], char *code, int code_len) {
    if (root == NULL) {
        return;
    }

    if (root->data != '$') {
        codes[root->data] = malloc(code_len + 1);
        strcpy(codes[root->data], code);
        return;
    }

    create_huffman_codes(root->left, codes, strcat(code, "0"), code_len + 1);
    create_huffman_codes(root->right, codes, strcat(code, "1"), code_len + 1);
}

char *encode_huffman(char *str, char *codes[]) {
    int encoded_len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        encoded_len += strlen(codes[str[i]]);
    }

    char *encoded_str = malloc(encoded_len + 1);
    encoded_str[0] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        strcat(encoded_str, codes[str[i]]);
    }

    return encoded_str;
}

void decode_huffman(node *root, char *encoded_str) {
    int i = 0;
    node *curr = root;

    while (encoded_str[i] != '\0') {
        if (encoded_str[i] == '0') {
            curr = curr->left;
        } else {
            curr = curr->right;
        }

        if (curr->data != '$') {
            printf("%c", curr->data);
            curr = root;
        }

        i++;
    }
}

int main() {
    char str[] = "Huffman coding is a lossless data compression algorithm.";

    node *root = create_huffman_tree(str);

    char *codes[256] = {NULL};
    create_huffman_codes(root, codes, "", 0);

    char *encoded_str = encode_huffman(str, codes);
    printf("Encoded string: %s\n", encoded_str);

    printf("Decoded string: ");
    decode_huffman(root, encoded_str);
    printf("\n");

    return 0;
}