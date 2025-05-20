//FormAI DATASET v1.0 Category: Compression algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define BUFFER_SIZE 4096

// Structure to hold the character frequency
typedef struct {
    unsigned int freq;
    unsigned char symbol;
} frequency;

// Comparator function for sorting frequencies in ascending order
int compare_freq(const void *p, const void *q) {
    const frequency *f1 = p;
    const frequency *f2 = q;
    return (int)(f1->freq - f2->freq);
}

// Traverse the Huffman tree to get the codes for each symbol
void generate_codes(int codes[], int code_length[], const unsigned char symbols[], frequency freqs[], unsigned int num_symbols, int root) {
    if (freqs[root].symbol != '\0') { // Leaf node
        for (unsigned int i = 0; i < num_symbols; i++) {
            if (symbols[i] == freqs[root].symbol) {
                codes[i] = root;
                code_length[i] = 1;
                return;
            }
        }
    }
    else { // Internal node
        int left_child = freqs[root].freq >> 16;
        int right_child = freqs[root].freq & 0xFFFF;
        generate_codes(codes, code_length, symbols, freqs, num_symbols, left_child);
        generate_codes(codes, code_length, symbols, freqs, num_symbols, right_child);
        for (unsigned int i = 0; i < num_symbols; i++) {
            if (codes[i] == left_child) {
                codes[i] = (root << 16) | 1;
                code_length[i]++;
            }
            else if (codes[i] == right_child) {
                codes[i] = root << 16;
                code_length[i]++;
            }
        }
    }
}

// Compresses the input file using a Huffman code
void compress_file(FILE *in_file, const char *output_file) {
    // First, compute the frequency of each symbol in the input file
    unsigned char buffer[BUFFER_SIZE];
    unsigned int frequencies[UCHAR_MAX + 1] = {0};
    size_t num_read;
    while ((num_read = fread(buffer, 1, BUFFER_SIZE, in_file)) > 0) {
        for (size_t i = 0; i < num_read; i++) {
            frequencies[buffer[i]]++;
        }
    }
    // Build the Huffman tree using a priority queue
    frequency pq[(UCHAR_MAX + 1) * 2 - 1];
    unsigned char symbols[UCHAR_MAX + 1];
    unsigned int num_symbols = 0;
    for (unsigned int i = 0; i <= UCHAR_MAX; i++) {
        if (frequencies[i] > 0) {
            pq[num_symbols].freq = frequencies[i];
            pq[num_symbols].symbol = symbols[num_symbols] = i;
            num_symbols++;
        }
    }
    while (num_symbols < ((UCHAR_MAX + 1) * 2 - 1)) {
        unsigned int min1 = num_symbols, min2 = num_symbols;
        for (unsigned int i = 0; i < num_symbols; i++) {
            if (pq[i].freq < pq[min1].freq) {
                min2 = min1;
                min1 = i;
            }
            else if (pq[i].freq < pq[min2].freq) {
                min2 = i;
            }
        }
        pq[num_symbols].freq = pq[min1].freq + pq[min2].freq;
        pq[num_symbols].symbol = '\0';
        pq[min1].freq = (min2 << 16) | (min1 & 0xFFFF);
        pq[min2] = pq[num_symbols];
        num_symbols++;
    }
    // Traverse the Huffman tree to get the codes for each symbol
    int codes[UCHAR_MAX + 1] = {0};
    int code_length[UCHAR_MAX + 1] = {0};
    generate_codes(codes, code_length, symbols, pq, num_symbols, num_symbols - 1);
    // Write the Huffman tree to the output file
    FILE *out_file = fopen(output_file, "wb");
    fwrite(&num_symbols, sizeof(num_symbols), 1, out_file);
    for (unsigned int i = 0; i < num_symbols; i++) {
        fwrite(&pq[i], sizeof(frequency), 1, out_file);
    }
    // Reset the input file to the beginning and compress the data
    rewind(in_file);
    size_t num_bits = 0;
    unsigned char bit_buffer = 0;
    while ((num_read = fread(buffer, 1, BUFFER_SIZE, in_file)) > 0) {
        for (size_t i = 0; i < num_read; i++) {
            int code = codes[buffer[i]];
            int length = code_length[buffer[i]];
            while (length > 0) {
                length--;
                bit_buffer |= ((code >> length) & 1) << (7 - num_bits);
                num_bits++;
                if (num_bits == 8) {
                    fwrite(&bit_buffer, 1, 1, out_file);
                    bit_buffer = 0;
                    num_bits = 0;
                }
            }
        }
    }
    if (num_bits > 0) {
        fwrite(&bit_buffer, 1, 1, out_file);
    }
    fclose(out_file);
}

// Decompresses the input file using a Huffman code
void decompress_file(const char *input_file, FILE *out_file) {
    // Read the Huffman tree from the input file
    unsigned int num_symbols;
    fread(&num_symbols, sizeof(num_symbols), 1, stdin);
    frequency pq[(UCHAR_MAX + 1) * 2 - 1];
    memset(pq, 0, sizeof(pq));
    for (unsigned int i = 0; i < num_symbols; i++) {
        fread(&pq[i], sizeof(frequency), 1, stdin);
    }
    // Build the Huffman tree from the read data
    unsigned char buffer[BUFFER_SIZE];
    unsigned char symbols[UCHAR_MAX + 1];
    unsigned int num_leaf_nodes = 0;
    for (unsigned int i = 0; i < num_symbols; i++) {
        if (pq[i].symbol != '\0') {
            symbols[num_leaf_nodes++] = pq[i].symbol;
        }
    }
    int root = num_symbols - 1;
    while (num_leaf_nodes > 1) {
        int min1 = root, min2 = root;
        for (int i = 0; i < num_symbols; i++) {
            if (pq[i].freq < pq[min1].freq) {
                min2 = min1;
                min1 = i;
            }
            else if (pq[i].freq < pq[min2].freq) {
                min2 = i;
            }
        }
        pq[num_symbols].freq = pq[min1].freq + pq[min2].freq;
        pq[num_symbols].symbol = '\0';
        pq[min1].freq = (min2 << 16) | (num_symbols & 0xFFFF);
        pq[min2] = pq[num_symbols];
        num_symbols++;
        num_leaf_nodes--;
    }
    // Decompress the data using the Huffman tree
    int bit_buffer = 0;
    int num_bits = 0;
    int node = root;
    while (fread(buffer, 1, BUFFER_SIZE, stdin) > 0) {
        for (size_t i = 0; i < BUFFER_SIZE; i++) {
            for (int j = 7; j >= 0; j--) {
                if (num_bits == 0) {
                    node = root;
                }
                if ((buffer[i] >> j) & 1) {
                    node = pq[node].freq & 0xFFFF;
                }
                else {
                    node = pq[node].freq >> 16;
                }
                if (pq[node].symbol != '\0') {
                    fwrite(&pq[node].symbol, 1, 1, out_file);
                    num_bits = 0;
                }
                else {
                    num_bits++;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <compress/decompress> <input file> <output file>\n", argv[0]);
        return 1;
    }
    FILE *in_file = fopen(argv[2], "rb");
    if (in_file == NULL) {
        fprintf(stderr, "Error: could not open input file '%s'\n", argv[2]);
        return 1;
    }
    if (strcmp(argv[1], "compress") == 0) {
        compress_file(in_file, argv[3]);
    }
    else if (strcmp(argv[1], "decompress") == 0) {
        FILE *out_file = fopen(argv[3], "wb");
        decompress_file(argv[2], out_file);
        fclose(out_file);
    }
    else {
        fprintf(stderr, "Error: invalid mode '%s'\n", argv[1]);
        return 1;
    }
    fclose(in_file);
    return 0;
}