//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

typedef struct Node {
    unsigned char symbol;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct MinHeap {
    size_t size;
    Node** arr;
} MinHeap;

typedef struct CodeTable {
    char** table;
} CodeTable;

Node* new_node(unsigned char symbol) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->symbol = symbol;
    node->left = NULL;
    node->right = NULL;
    return node;
}

MinHeap* new_heap(size_t capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->arr = (Node**)calloc(capacity, sizeof(Node*));
    return heap;
}

CodeTable* new_table() {
    CodeTable* table = (CodeTable*)malloc(sizeof(CodeTable));
    table->table = (char**)calloc(SIZE, sizeof(char*));
    return table;
}

void swap(Node** arr, size_t a, size_t b) {
    Node* temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void min_heapify(MinHeap* heap, size_t i) {
    size_t smallest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    if (left < heap->size && heap->arr[left]->symbol < heap->arr[smallest]->symbol) {
        smallest = left;
    }
    if (right < heap->size && heap->arr[right]->symbol < heap->arr[smallest]->symbol) {
        smallest = right;
    }
    if (smallest != i) {
        swap(heap->arr, i, smallest);
        min_heapify(heap, smallest);
    }
}

Node* extract_min(MinHeap* heap) {
    Node* min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    min_heapify(heap, 0);
    return min;
}

void insert(MinHeap* heap, Node* node) {
    heap->size++;
    size_t i = heap->size - 1;
    while (i > 0 && node->symbol < heap->arr[(i - 1) / 2]->symbol) {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->arr[i] = node;
}

MinHeap* build_heap(unsigned int* freq) {
    MinHeap* heap = new_heap(SIZE);
    for (unsigned int i = 0; i < SIZE; i++) {
        if (freq[i] > 0) {
            insert(heap, new_node((unsigned char)i));
        }
    }
    while (heap->size > 1) {
        Node* left = extract_min(heap);
        Node* right = extract_min(heap);
        Node* combined = new_node(0);
        combined->left = left;
        combined->right = right;
        insert(heap, combined);
    }
    return heap;
}

void generate_codes(Node* root, char* code, size_t index, CodeTable* table) {
    if (root->left) {
        code[index] = '0';
        generate_codes(root->left, code, index + 1, table);
    }
    if (root->right) {
        code[index] = '1';
        generate_codes(root->right, code, index + 1, table);
    }
    if (!root->left && !root->right) {
        code[index] = '\0';
        size_t symbol = (size_t)root->symbol;
        table->table[symbol] = (char*)malloc(strlen(code) + 1);
        strcpy(table->table[symbol], code);
    }
}

CodeTable* build_code_table(MinHeap* heap) {
    CodeTable* table = new_table();
    char code[SIZE];
    generate_codes(heap->arr[0], code, 0, table);
    return table;
}

void compress(FILE* input, FILE* output) {
    unsigned int freq[SIZE] = {0};
    unsigned char buffer;
    while (fread(&buffer, 1, 1, input)) {
        freq[buffer]++;
    }
    MinHeap* heap = build_heap(freq);
    CodeTable* table = build_code_table(heap);
    fwrite(freq, sizeof(unsigned int), SIZE, output);
    rewind(input);
    unsigned char bits = 0;
    unsigned int count = 0;
    while (fread(&buffer, 1, 1, input)) {
        size_t symbol = (size_t)buffer;
        char* code = table->table[symbol];
        size_t len = strlen(code);
        for (size_t i = 0; i < len; i++) {
            bits <<= 1;
            bits |= (code[i] == '1');
            count++;
            if (count == 8) {
                fwrite(&bits, 1, 1, output);
                bits = 0;
                count = 0;
            }
        }
    }
    if (count > 0) {
        bits <<= (8 - count);
        fwrite(&bits, 1, 1, output);
    }
}

void decompress(FILE* input, FILE* output) {
    unsigned int freq[SIZE];
    fread(freq, sizeof(unsigned int), SIZE, input);
    MinHeap* heap = build_heap(freq);
    Node* root = heap->arr[0];
    unsigned long long int size = ftell(input);
    fseek(input, 0, SEEK_END);
    size -= ftell(input);
    fseek(input, sizeof(unsigned int) * SIZE, SEEK_SET);
    Node* curr = root;
    unsigned char buffer;
    for (unsigned long long int i = 0; i < size * 8; i++) {
        if (!curr->left && !curr->right) {
            fwrite(&curr->symbol, 1, 1, output);
            curr = root;
        }
        fread(&buffer, 1, 1, input);
        unsigned char mask = 128 >> (i % 8);
        if (buffer & mask) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    if (!curr->left && !curr->right) {
        fwrite(&curr->symbol, 1, 1, output);
        curr = root;
    }
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s [compress/decompress] [input file] [output file]\n", argv[0]);
        return 1;
    }
    FILE* input = fopen(argv[2], "rb");
    if (!input) {
        printf("Could not open input file!\n");
        return 1;
    }
    FILE* output = fopen(argv[3], "wb");
    if (!output) {
        printf("Could not open output file!\n");
        return 1;
    }
    if (!strcmp(argv[1], "compress")) {
        compress(input, output);
    } else if (!strcmp(argv[1], "decompress")) {
        decompress(input, output);
    } else {
        printf("Invalid mode! Should be 'compress' or 'decompress'\n");
        return 1;
    }
    fclose(input);
    fclose(output);
    return 0;
}