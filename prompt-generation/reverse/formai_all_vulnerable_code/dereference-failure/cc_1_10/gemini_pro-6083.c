//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODES 256

typedef struct {
    unsigned char symbol;
    unsigned int frequency;
} Node;

typedef struct {
    Node *nodes;
    unsigned int size;
    unsigned int capacity;
} Heap;

typedef struct {
    unsigned char *code;
    unsigned int length;
} Code;

Heap *heap_create(unsigned int capacity) {
    Heap *heap = malloc(sizeof(Heap));
    heap->nodes = malloc(sizeof(Node) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void heap_destroy(Heap *heap) {
    free(heap->nodes);
    free(heap);
}

void heap_insert(Heap *heap, Node node) {
    unsigned int i = heap->size++;
    while (i > 0 && node.frequency < heap->nodes[(i - 1) / 2].frequency) {
        heap->nodes[i] = heap->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->nodes[i] = node;
}

Node heap_extract_min(Heap *heap) {
    Node min = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];
    unsigned int i = 0;
    while (i < heap->size / 2) {
        unsigned int left = 2 * i + 1;
        unsigned int right = 2 * i + 2;
        unsigned int smallest = i;
        if (left < heap->size && heap->nodes[left].frequency < heap->nodes[smallest].frequency) {
            smallest = left;
        }
        if (right < heap->size && heap->nodes[right].frequency < heap->nodes[smallest].frequency) {
            smallest = right;
        }
        if (i == smallest) {
            break;
        }
        Node tmp = heap->nodes[i];
        heap->nodes[i] = heap->nodes[smallest];
        heap->nodes[smallest] = tmp;
        i = smallest;
    }
    return min;
}

Code *huffman_encode(const unsigned char *data, unsigned int length) {
    unsigned int frequencies[MAX_CODES] = {0};
    for (unsigned int i = 0; i < length; i++) {
        frequencies[data[i]]++;
    }

    Heap *heap = heap_create(MAX_CODES);
    for (unsigned int i = 0; i < MAX_CODES; i++) {
        if (frequencies[i] > 0) {
            Node node = {i, frequencies[i]};
            heap_insert(heap, node);
        }
    }

    Code *codes = malloc(sizeof(Code) * MAX_CODES);
    memset(codes, 0, sizeof(Code) * MAX_CODES);

    while (heap->size > 1) {
        Node left = heap_extract_min(heap);
        Node right = heap_extract_min(heap);
        Node parent = {0, left.frequency + right.frequency};
        heap_insert(heap, parent);

        codes[left.symbol].length = codes[right.symbol].length + 1;
        codes[right.symbol].length = codes[left.symbol].length;

        for (unsigned int i = 0; i < codes[left.symbol].length; i++) {
            codes[left.symbol].code[i] = 0;
            codes[right.symbol].code[i] = 1;
        }
    }

    heap_destroy(heap);
    return codes;
}

void huffman_decode(const Code *codes, const unsigned char *data, unsigned int length, unsigned char *decoded) {
    unsigned int index = 0;
    unsigned int code = 0;
    for (unsigned int i = 0; i < length; i++) {
        code = (code << 1) | data[i];
        for (unsigned int j = 0; j < MAX_CODES; j++) {
            if (codes[j].length <= index || code != codes[j].code[index]) {
                continue;
            }
            decoded[index++] = j;
            index = 0;
            code = 0;
            break;
        }
    }
}

int main() {
    unsigned char data[] = "hello world";
    unsigned int length = strlen(data);
    Code *codes = huffman_encode(data, length);

    unsigned char *encoded = malloc(length * 8);
    memset(encoded, 0, length * 8);
    unsigned int encoded_length = 0;
    for (unsigned int i = 0; i < length; i++) {
        memcpy(encoded + encoded_length, codes[data[i]].code, codes[data[i]].length);
        encoded_length += codes[data[i]].length;
    }

    unsigned char *decoded = malloc(length);
    memset(decoded, 0, length);
    huffman_decode(codes, encoded, encoded_length, decoded);

    printf("Original: %s\n", data);
    printf("Encoded: ");
    for (unsigned int i = 0; i < encoded_length; i++) {
        printf("%d", encoded[i]);
    }
    printf("\n");
    printf("Decoded: %s\n", decoded);

    free(codes);
    free(encoded);
    free(decoded);
    return 0;
}