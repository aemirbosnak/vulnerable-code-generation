//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 256
#define BITS_PER_BYTE 8

typedef struct Node {
    char symbol;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct MinHeap {
    int size;
    int capacity;
    Node** nodes;
} MinHeap;

typedef struct Code {
    char symbol;
    char* bits;
} Code;

void encode(const char* filename);
void decode(const char* filename);
Node* create_node(char symbol, int frequency);
MinHeap* create_min_heap(int capacity);
void insert_in_min_heap(MinHeap* min_heap, Node* node);
void swap_nodes(Node** a, Node** b);
void heapify(MinHeap* min_heap, int idx);
Node* extract_min(MinHeap* min_heap);
Node* build_huffman_tree(MinHeap* min_heap);
Code* create_huffman_codes(Node* root);
void get_code_helper(Node* node, char* bits, int idx, Code* codes);
void write_compressed_file(const char* filename, const char* outfile, Code* codes);
void write_header(FILE* fp, Code* codes);
int get_padded_length(int len);
char pack_byte(char* bits);
void write_bits(char* bits, int len, FILE* fp);
void write_uncompressed_file(const char* filename, const char* outfile, Node* root, int length);
void free_nodes(Node* node);
void free_min_heap(MinHeap* min_heap);
void free_codes(Code* codes);
void print_info(char* filename);

void encode(const char* filename) {
    FILE* fp_in = fopen(filename, "rb");
    if (!fp_in) {
        printf("Error: could not open file: %s\n", filename);
        return;
    }

    char outfile[strlen(filename)];
    strcpy(outfile, filename);
    strcat(outfile, ".huff");

    fseek(fp_in, 0L, SEEK_END);
    int length = ftell(fp_in);
    rewind(fp_in);

    int frequencies[BUFFER_SIZE] = {0};
    char buffer[length];
    fread(buffer, sizeof(char), length, fp_in);
    for (int i = 0; i < length; i++) {
        frequencies[buffer[i]]++;
    }

    MinHeap* min_heap = create_min_heap(BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (frequencies[i] > 0) {
            Node* node = create_node((char)i, frequencies[i]);
            insert_in_min_heap(min_heap, node);
        }
    }

    Node* root = build_huffman_tree(min_heap);
    Code* codes = create_huffman_codes(root);

    write_compressed_file(filename, outfile, codes);
    free_nodes(root);
    free_min_heap(min_heap);
    free_codes(codes);

    printf("Compression Complete!\n");
    print_info(filename);
}

void decode(const char* filename) {
    FILE* fp_in = fopen(filename, "rb");
    if (!fp_in) {
        printf("Error: could not open file: %s\n", filename);
        return;
    }

    fseek(fp_in, 0L, SEEK_END);
    int length = ftell(fp_in);
    rewind(fp_in);

    char outfile[strlen(filename)];
    strncpy(outfile, filename, strlen(filename) - 5);

    int num_bits_header = length - BUFFER_SIZE;
    char header[num_bits_header];
    fread(header, sizeof(char), num_bits_header, fp_in);
    Node* root = build_huffman_tree(NULL);
    int idx = 0;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (header[i] > 0) {
            char bits[BITS_PER_BYTE + 1] = {0};
            for (int j = BITS_PER_BYTE - 1; j >= 0; j--) {
                if (header[i] & (1 << j)) {
                    bits[BITS_PER_BYTE - j - 1] = '1';
                } else {
                    bits[BITS_PER_BYTE - j - 1] = '0';
                }
            }
            Code code = { (char)i, bits };
            get_code_helper(root, code.bits, 0, &code);
        }
    }

    Node* curr_node = root;
    char buffer[length - BUFFER_SIZE];
    fread(buffer, sizeof(char), length - BUFFER_SIZE, fp_in);
    int buffer_idx = 0;
    FILE* fp_out = fopen(outfile, "wb");
    while (buffer_idx < length - BUFFER_SIZE) {
        char byte = buffer[buffer_idx];
        for (int i = BITS_PER_BYTE - 1; i >= 0; i--) {
            if ((byte & (1 << i)) != 0) {
                curr_node = curr_node->right;
            } else {
                curr_node = curr_node->left;
            }
            if (curr_node->left == NULL && curr_node->right == NULL) {
                fwrite(&curr_node->symbol, sizeof(char), 1, fp_out);
                curr_node = root;
            }
        }
        buffer_idx++;
    }

    fclose(fp_out);
    fclose(fp_in);
    free_nodes(root);

    printf("Decompression Complete!\n");
    print_info(filename);
}

Node* create_node(char symbol, int frequency) {
    Node* node = calloc(1, sizeof(Node));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

MinHeap* create_min_heap(int capacity) {
    MinHeap* min_heap = calloc(1, sizeof(MinHeap));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->nodes = calloc(capacity, sizeof(Node*));
    return min_heap;
}

void insert_in_min_heap(MinHeap* min_heap, Node* node) {
    min_heap->nodes[++min_heap->size] = node;
    int curr_idx = min_heap->size;
    int parent_idx = curr_idx / 2;
    while (curr_idx > 1 && min_heap->nodes[curr_idx]->frequency < min_heap->nodes[parent_idx]->frequency) {
        swap_nodes(&min_heap->nodes[curr_idx], &min_heap->nodes[parent_idx]);
        curr_idx = parent_idx;
        parent_idx = curr_idx / 2;
    }
}

void swap_nodes(Node** a, Node** b) {
    Node* tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(MinHeap* min_heap, int idx) {
    int left_child_idx = 2 * idx;
    int right_child_idx = 2 * idx + 1;
    int smallest_child_idx = idx;
    if (left_child_idx <= min_heap->size && min_heap->nodes[left_child_idx]->frequency < min_heap->nodes[smallest_child_idx]->frequency) {
        smallest_child_idx = left_child_idx;
    }
    if (right_child_idx <= min_heap->size && min_heap->nodes[right_child_idx]->frequency < min_heap->nodes[smallest_child_idx]->frequency) {
        smallest_child_idx = right_child_idx;
    }
    if (smallest_child_idx != idx) {
        swap_nodes(&min_heap->nodes[idx], &min_heap->nodes[smallest_child_idx]);
        heapify(min_heap, smallest_child_idx);
    }
}

Node* extract_min(MinHeap* min_heap) {
    Node* node = min_heap->nodes[1];
    min_heap->nodes[1] = min_heap->nodes[min_heap->size--];
    heapify(min_heap, 1);
    return node;
}

Node* build_huffman_tree(MinHeap* min_heap) {
    if (min_heap->size == 1) {
        return min_heap->nodes[1];
    }
    while (min_heap->size > 1) {
        Node* left_node = extract_min(min_heap);
        Node* right_node = extract_min(min_heap);
        Node* internal_node = create_node('\0', left_node->frequency + right_node->frequency);
        internal_node->left = left_node;
        internal_node->right = right_node;
        insert_in_min_heap(min_heap, internal_node);
    }
    return min_heap->nodes[1];
}

Code* create_huffman_codes(Node* root) {
    char bits[BUFFER_SIZE + 1] = {0};
    Code* codes = calloc(BUFFER_SIZE, sizeof(Code));
    get_code_helper(root, bits, 0, codes);
    return codes;
}

void get_code_helper(Node* node, char* bits, int idx, Code* codes) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        codes[node->symbol].symbol = node->symbol;
        codes[node->symbol].bits = calloc(strlen(bits) + 1, sizeof(char));
        strcpy(codes[node->symbol].bits, bits);
        return;
    }
    bits[idx] = '0';
    get_code_helper(node->left, bits, idx + 1, codes);
    bits[idx] = '1';
    get_code_helper(node->right, bits, idx + 1, codes);
}

void write_compressed_file(const char* filename, const char* outfile, Code* codes) {
    FILE* fp_in = fopen(filename, "rb");
    if (!fp_in) {
        printf("Error: could not open file: %s\n", filename);
        return;
    }
    FILE* fp_out = fopen(outfile, "wb");

    char header[BUFFER_SIZE] = {0};
    int header_idx = 0;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (codes[i].bits != NULL) {
            header[i] = 1;
            header_idx++;
        }
    }

    write_header(fp_out, codes);

    fseek(fp_in, 0L, SEEK_END);
    int uncompressed_length = ftell(fp_in);
    rewind(fp_in);

    fwrite(&uncompressed_length, sizeof(int), 1, fp_out);

    int num_padded_bits = 0;
    int num_bits;
    char buffer[BUFFER_SIZE * BITS_PER_BYTE];
    char bits[BUFFER_SIZE * BITS_PER_BYTE + 1];
    int idx = 0;
    int buffer_idx = 0;
    while ((num_bits = fread(buffer, sizeof(char), BUFFER_SIZE, fp_in)) != 0) {
        for (int i = 0; i < num_bits; i++) {
            if (codes[buffer[i]].bits != NULL) {
                strcat(bits, codes[buffer[i]].bits);
                idx += strlen(codes[buffer[i]].bits);
                buffer_idx++;
                if (idx >= BUFFER_SIZE * BITS_PER_BYTE) {
                    write_bits(bits, idx, fp_out);
                    idx = 0;
                }
            }
        }
    }
    if (idx > 0) {
        num_padded_bits = BITS_PER_BYTE - (idx % BITS_PER_BYTE);
        for (int i = 0; i < num_padded_bits; i++) {
            strcat(bits, "0");
            idx++;
        }
        write_bits(bits, idx, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
}

void write_header(FILE* fp, Code* codes) {
    int num_cols = 0;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (codes[i].bits != NULL) {
            num_cols++;
        }
    }
    fwrite(&num_cols, sizeof(int), 1, fp);
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (codes[i].bits != NULL) {
            fwrite(&codes[i].symbol, sizeof(char), 1, fp);
            int len = strlen(codes[i].bits);
            fwrite(&len, sizeof(int), 1, fp);
            fwrite(codes[i].bits, sizeof(char), strlen(codes[i].bits), fp);
        }
    }
}

int get_padded_length(int len) {
    int num_padded_bits = 0;
    if (len % BITS_PER_BYTE != 0) {
        num_padded_bits = BITS_PER_BYTE - (len % BITS_PER_BYTE);
    }
    return len + num_padded_bits;
}

char pack_byte(char* bits) {
    char byte = 0;
    for (int i = 0; i < BITS_PER_BYTE; i++) {
        if (bits[i] == '1') {
            byte |= 1 << (BITS_PER_BYTE - 1 - i);
        }
    }
    return byte;
}

void write_bits(char* bits, int len, FILE* fp) {
    int padded_len = get_padded_length(len);
    char buffer[padded_len / BITS_PER_BYTE];
    int buffer_idx = 0;
    for (int i = 0; i < len; i += BITS_PER_BYTE) {
        char byte[BITS_PER_BYTE + 1] = {0};
        strncpy(byte, &bits[i], BITS_PER_BYTE);
        buffer[buffer_idx++] = pack_byte(byte);
    }
    fwrite(buffer, sizeof(char), buffer_idx, fp);
}

void write_uncompressed_file(const char* filename, const char* outfile, Node* root, int length) {
    FILE* fp_in = fopen(filename, "rb");
    if (!fp_in) {
        printf("Error: could not open file: %s\n", filename);
        return;
    }
    fseek(fp_in, BUFFER_SIZE, SEEK_SET);
    char buffer[length];
    fread(buffer, sizeof(char), length, fp_in);
    fclose(fp_in);
    FILE* fp_out = fopen(outfile, "wb");
    Node* curr_node = root;
    for (int i = 0; i < length; i++) {
        if (buffer[i] & 0x80) {
            curr_node = curr_node->right;
        } else {
            curr_node = curr_node->left;
        }
        if (curr_node->left == NULL && curr_node->right == NULL) {
            fwrite(&curr_node->symbol, sizeof(char), 1, fp_out);
            curr_node = root;
        }
        buffer[i] <<= 1;
    }
    fclose(fp_out);
}

void free_nodes(Node* node) {
    if (node == NULL) {
        return;
    }
    free_nodes(node->left);
    free_nodes(node->right);
    free(node);
}

void free_min_heap(MinHeap* min_heap) {
    for (int i = 1; i <= min_heap->size; i++) {
        free(min_heap->nodes[i]);
    }
    free(min_heap->nodes);
    free(min_heap);
}

void free_codes(Code* codes) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (codes[i].bits != NULL) {
            free(codes[i].bits);
        }
    }
    free(codes);
}

void print_info(char* filename) {
    FILE* fp_in = fopen(filename, "rb");
    if (!fp_in) {
        printf("Error: could not open file: %s\n", filename);
        return;
    }
    fseek(fp_in, 0L, SEEK_END);
    int uncompressed_length = ftell(fp_in) - BUFFER_SIZE;
    fclose(fp_in);

    char outfile[strlen(filename)];
    strncpy(outfile, filename, strlen(filename) - 5);
    fp_in = fopen(outfile, "rb");
    if (!fp_in) {
        printf("Error: could not open file: %s\n", filename);
        return;
    }
    fseek(fp_in, 0L, SEEK_END);
    int compressed_length = ftell(fp_in) - BUFFER_SIZE - sizeof(int);
    fclose(fp_in);

    printf("Original Size: %d bytes\n", uncompressed_length);
    printf("Compressed Size: %d bytes\n", compressed_length);
    double compression_ratio = (double)compressed_length / uncompressed_length;
    printf("Compression Ratio: %.2f\n", compression_ratio);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s [-c | -d] [filename]\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "-c") == 0) {
        encode(argv[2]);
    } else if (strcmp(argv[1], "-d") == 0) {
        decode(argv[2]);
    }
    return 0;
}