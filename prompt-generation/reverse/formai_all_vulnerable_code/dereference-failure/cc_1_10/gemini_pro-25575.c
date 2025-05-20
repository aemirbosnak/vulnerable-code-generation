//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: synchronous
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

typedef struct min_heap {
    node *array[MAX_SIZE];
    int size;
} min_heap;

node *create_node(char character, int frequency) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->character = character;
    new_node->frequency = frequency;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

min_heap *create_min_heap() {
    min_heap *new_heap = (min_heap *)malloc(sizeof(min_heap));
    new_heap->size = 0;
    return new_heap;
}

void swap_nodes(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(min_heap *heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heap->size && heap->array[left]->frequency < heap->array[index]->frequency) {
        smallest = left;
    }

    if (right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != index) {
        swap_nodes(&heap->array[index], &heap->array[smallest]);
        min_heapify(heap, smallest);
    }
}

void build_min_heap(min_heap *heap) {
    for (int i = heap->size / 2 - 1; i >= 0; i--) {
        min_heapify(heap, i);
    }
}

node *extract_min(min_heap *heap) {
    if (heap->size == 0) {
        return NULL;
    }

    node *min_node = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    min_heapify(heap, 0);

    return min_node;
}

void insert_node(min_heap *heap, node *new_node) {
    heap->array[heap->size++] = new_node;
    int index = heap->size - 1;

    while (index > 0 && heap->array[index]->frequency < heap->array[(index - 1) / 2]->frequency) {
        swap_nodes(&heap->array[index], &heap->array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

node *build_huffman_tree(min_heap *heap) {
    while (heap->size > 1) {
        node *left = extract_min(heap);
        node *right = extract_min(heap);

        node *new_node = create_node(' ', left->frequency + right->frequency);
        new_node->left = left;
        new_node->right = right;

        insert_node(heap, new_node);
    }

    return extract_min(heap);
}

void print_huffman_code(node *root, char *code, int code_length) {
    if (root == NULL) {
        return;
    }

    if (root->character != ' ') {
        printf("%c: %s\n", root->character, code);
        return;
    }

    print_huffman_code(root->left, strcat(code, "0"), code_length + 1);
    print_huffman_code(root->right, strcat(code, "1"), code_length + 1);
}

char *encode_string(node *root, char *string) {
    char *encoded_string = (char *)malloc(strlen(string) * 8 + 1);
    int encoded_index = 0;

    for (int i = 0; i < strlen(string); i++) {
        node *current_node = root;

        while (current_node->character != string[i]) {
            if (current_node->left->character == string[i]) {
                current_node = current_node->left;
                encoded_string[encoded_index++] = '0';
            } else {
                current_node = current_node->right;
                encoded_string[encoded_index++] = '1';
            }
        }
    }

    encoded_string[encoded_index] = '\0';
    return encoded_string;
}

char *decode_string(node *root, char *encoded_string) {
    char *decoded_string = (char *)malloc(strlen(encoded_string) + 1);
    int decoded_index = 0;
    node *current_node = root;

    for (int i = 0; i < strlen(encoded_string); i++) {
        if (encoded_string[i] == '0') {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }

        if (current_node->character != ' ') {
            decoded_string[decoded_index++] = current_node->character;
            current_node = root;
        }
    }

    decoded_string[decoded_index] = '\0';
    return decoded_string;
}

int main() {
    char string[] = "This is a test string";
    int frequencies[MAX_SIZE] = {0};

    for (int i = 0; i < strlen(string); i++) {
        frequencies[string[i]]++;
    }

    min_heap *heap = create_min_heap();

    for (int i = 0; i < MAX_SIZE; i++) {
        if (frequencies[i] > 0) {
            insert_node(heap, create_node(i, frequencies[i]));
        }
    }

    build_min_heap(heap);
    node *root = build_huffman_tree(heap);

    char code[MAX_SIZE] = "";
    print_huffman_code(root, code, 0);

    char *encoded_string = encode_string(root, string);
    printf("Encoded string: %s\n", encoded_string);

    char *decoded_string = decode_string(root, encoded_string);
    printf("Decoded string: %s\n", decoded_string);

    return 0;
}