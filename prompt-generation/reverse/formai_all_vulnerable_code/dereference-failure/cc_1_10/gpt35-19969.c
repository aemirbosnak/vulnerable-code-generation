//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 1000
#define MAX_DICT_SIZE 256
 
typedef struct node {
    int freq;
    unsigned char data;
    struct node *left;
    struct node *right;
} Node;

typedef struct heap {
    int size;
    Node* data[MAX_HEAP_SIZE];
} Heap;

typedef struct dict {
    char code[9];
    int size;
} Dict;

void init_heap(Heap* heap) {
    heap->size = 0;
}

void swap(Node** a, Node** b) {
    Node* tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify_down(Heap* heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
 
    if (left < heap->size && heap->data[left]->freq < heap->data[smallest]->freq) {
        smallest = left;
    }
 
    if (right < heap->size && heap->data[right]->freq < heap->data[smallest]->freq) {
        smallest = right;
    }
 
    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        heapify_down(heap, smallest);
    }
}
 
void heapify_up(Heap* heap, int index) {
    int parent = (index - 1) / 2;
 
    if (index && heap->data[index]->freq < heap->data[parent]->freq) {
        swap(&heap->data[index], &heap->data[parent]);
        heapify_up(heap, parent);
    }
}
 
void insert(Heap* heap, Node* node) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("\nHeap is full, can't insert more nodes\n");
        return;
    }
 
    heap->data[heap->size++] = node;
    heapify_up(heap, heap->size - 1);
}
 
Node* remove_min(Heap* heap) {
    if (!heap->size) {
        printf("\nHeap is empty, can't remove node\n");
        return NULL;
    }

    Node* node = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapify_down(heap, 0);

    return node;
}

Node* build_tree(int* freq_table) {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    init_heap(heap);
 
    for (int i = 0; i < MAX_DICT_SIZE; i++) {
        if (freq_table[i]) {
            Node* node = (Node*) malloc(sizeof(Node));
            node->freq = freq_table[i];
            node->data = i;
            node->left = NULL;
            node->right = NULL;
            insert(heap, node);
        }
    }
 
    while (heap->size > 1) {
        Node* node1 = remove_min(heap);
        Node* node2 = remove_min(heap);
 
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->freq = node1->freq + node2->freq;
        new_node->left = node1;
        new_node->right = node2;
        insert(heap, new_node);
    }
 
    return remove_min(heap);
}

void build_dict(Node* node, Dict* dict, int code_size) {
    if (node == NULL)
        return;

    if (node->left == NULL && node->right == NULL) {
        dict[node->data].size = code_size;
        dict[node->data].code[code_size] = '\0';
        return;
    }

    dict[node->data].size = code_size;
    dict[node->data].code[code_size] = '\0';

    dict[node->left->data].code[code_size] = '0';
    build_dict(node->left, dict, code_size + 1);

    dict[node->right->data].code[code_size] = '1';
    build_dict(node->right, dict, code_size + 1);
}

void encode_file(char* in_filename, char* out_filename, Dict* dict) {
    FILE* in_file = fopen(in_filename, "rb");
    FILE* out_file = fopen(out_filename, "wb");

    unsigned char byte = 0;
    int bits_written = 0;

    while (1) {
        byte = fgetc(in_file);
        if (feof(in_file))
            break;

        int size = dict[byte].size;
        char* code = dict[byte].code;

        for (int i = 0; i < size; i++) {
            if (bits_written == 8) {
                fputc(byte, out_file);
                byte = 0;
                bits_written = 0;
            }

            if (code[i] == '0') {
                byte <<= 1;
            } else {
                byte <<= 1;
                byte += 1;
            }

            bits_written++;
        }
    }

    if (bits_written)
        fputc(byte << (8 - bits_written), out_file);

    fclose(in_file);
    fclose(out_file);
}

void decode_file(char* in_filename, char* out_filename, Node* root) {
    FILE* in_file = fopen(in_filename, "rb");
    FILE* out_file = fopen(out_filename, "wb");

    Node* node = root;
    unsigned char byte = 0;
    int bits_read = 0;

    while (1) {
        byte = fgetc(in_file);
        if (feof(in_file))
            break;

        int bit = 0;
        for (int i = 0; i < 8; i++) {
            bit = (byte & (1 << (7 - i))) ? 1 : 0;

            if (bit == 0) {
                node = node->left;
            } else {
                node = node->right;
            }

            if (node->left == NULL && node->right == NULL) {
                fputc(node->data, out_file);
                node = root;
            }
        }
    }

    fclose(in_file);
    fclose(out_file);
}

int main() {
    char* in_filename = "input.txt";
    char* out_filename = "output.bin";

    FILE* in_file = fopen(in_filename, "rb");
    if (in_file == NULL) {
        printf("\nError opening input file\n");
        return 1;
    }

    fseek(in_file, 0L, SEEK_END);
    long int file_size = ftell(in_file);
    fseek(in_file, 0L, SEEK_SET);

    int freq_table[MAX_DICT_SIZE] = { 0 };
    unsigned char byte = 0;

    for (int i = 0; i < file_size; i++) {
        byte = fgetc(in_file);
        freq_table[byte]++;
    }

    fclose(in_file);

    Node* root = build_tree(freq_table);

    Dict dict[MAX_DICT_SIZE];
    for (int i = 0; i < MAX_DICT_SIZE; i++) {
        dict[i].size = 0;
        dict[i].code[0] = '\0';
    }

    build_dict(root, dict, 0);

    encode_file(in_filename, out_filename, dict);

    char* out_filename_decoded = "output_decoded.txt";
    decode_file(out_filename, out_filename_decoded, root);

    printf("\nHuffman coding completed successfully!\n");

    return 0;
}