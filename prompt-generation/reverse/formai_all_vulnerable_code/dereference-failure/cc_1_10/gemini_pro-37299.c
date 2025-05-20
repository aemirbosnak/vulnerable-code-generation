//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    unsigned char character;
    unsigned int frequency;
    struct node *left;
    struct node *right;
} node_t;

typedef struct code {
    unsigned char *bits;
    unsigned int length;
} code_t;

void swap(node_t **a, node_t **b) {
    node_t *temp = *a;
    *a = *b;
    *b = temp;
}

node_t *min_heapify(node_t **array, unsigned int size, unsigned int i) {
    unsigned int left = 2 * i + 1;
    unsigned int right = 2 * i + 2;
    unsigned int smallest = i;

    if (left < size && array[left]->frequency < array[smallest]->frequency) {
        smallest = left;
    }

    if (right < size && array[right]->frequency < array[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&array[i], &array[smallest]);
        min_heapify(array, size, smallest);
    }

    return array[i];
}

node_t *build_min_heap(node_t **array, unsigned int size) {
    for (unsigned int i = size / 2; i >= 0; i--) {
        min_heapify(array, size, i);
    }

    return array[0];
}

node_t *huffman_tree(node_t **array, unsigned int size) {
    while (size > 1) {
        node_t *left = build_min_heap(array, size);
        array[size - 1] = left;
        size--;

        node_t *right = build_min_heap(array, size);
        array[size - 1] = right;
        size--;

        node_t *parent = malloc(sizeof(node_t));
        parent->character = '\0';
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;

        array[size - 1] = parent;
        size--;
    }

    return array[0];
}

void print_codes(node_t *root, code_t *code, unsigned int index) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->character);

        for (unsigned int i = 0; i < index; i++) {
            printf("%c", code[i].bits[i]);
        }

        printf("\n");

        return;
    }

    code[index].bits = malloc(sizeof(unsigned char) * (index + 1));
    memcpy(code[index].bits, code[index - 1].bits, index);
    code[index].bits[index] = '0';
    code[index].length++;

    print_codes(root->left, code, index + 1);

    memcpy(code[index].bits, code[index - 1].bits, index);
    code[index].bits[index] = '1';
    code[index].length++;

    print_codes(root->right, code, index + 1);
}

void huffman_codes(node_t *root) {
    code_t *code = malloc(sizeof(code_t) * 100);
    code[0].bits = malloc(sizeof(unsigned char));
    code[0].bits[0] = '0';
    code[0].length = 1;

    print_codes(root, code, 0);

    for (unsigned int i = 0; i < 100; i++) {
        free(code[i].bits);
    }

    free(code);
}

int main(void) {
    unsigned char *input = "This is an example of Huffman coding";
    unsigned int frequency[256] = {0};

    for (unsigned int i = 0; i < strlen(input); i++) {
        frequency[input[i]]++;
    }

    node_t **array = malloc(sizeof(node_t *) * 256);
    unsigned int index = 0;

    for (unsigned int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            array[index] = malloc(sizeof(node_t));
            array[index]->character = i;
            array[index]->frequency = frequency[i];
            array[index]->left = NULL;
            array[index]->right = NULL;

            index++;
        }
    }

    node_t *root = huffman_tree(array, index);

    huffman_codes(root);

    for (unsigned int i = 0; i < index; i++) {
        free(array[i]);
    }

    free(array);
    free(root);

    return 0;
}