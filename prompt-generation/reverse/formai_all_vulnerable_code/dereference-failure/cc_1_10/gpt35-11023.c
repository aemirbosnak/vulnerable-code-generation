//FormAI DATASET v1.0 Category: Compression algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000
#define MAX_CODE_SIZE 100

typedef struct {
    char symbol;
    char code[MAX_CODE_SIZE];
} Code;

int get_symbol_frequency(char *buffer, int size, char symbol) {
    int freq = 0;
    for(int i = 0; i < size; i++) {
        if(buffer[i] == symbol) {
            freq++;
        }
    }
    return freq;
}

void generate_code(Code *codes, int num_codes, char *code, int index, char *buffer, int size) {
    if(index == num_codes) {
        return;
    }
    for(int i = 0; i < size; i++) {
        if(strchr(code, buffer[i]) == NULL) {
            char new_code[MAX_CODE_SIZE];
            strncpy(new_code, code, strlen(code)+1);
            strncat(new_code, &buffer[i], 1);
            generate_code(codes, num_codes, new_code, index+1, buffer, size);
            if(index+1 == num_codes) {
                codes[i].symbol = buffer[i];
                strncpy(codes[i].code, new_code, strlen(new_code)+1);
            }
        }
    }
}

void write_bits(char *bits, int num_bits, FILE *compressed_file) {
    int num_bytes = num_bits / 8;
    if(num_bits % 8 != 0) {
        num_bytes++;
    }
    char byte = 0;
    int bit_count = 0;
    for(int i = 0; i < num_bits; i++) {
        if(bits[i] == '1') {
            byte |= 1 << (7 - bit_count);
        }
        bit_count++;
        if(bit_count == 8 || i+1 == num_bits) {
            fwrite(&byte, sizeof(char), 1, compressed_file);
            byte = 0;
            bit_count = 0;
        }
    }
}

void compress_file(char *input_file, char *output_file) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if(input == NULL || output == NULL) {
        printf("Failed to open files\n");
        return;
    }
    fseek(input, 0, SEEK_END);
    int size = ftell(input);
    rewind(input);
    char *buffer = (char*) malloc(sizeof(char) * size);
    fread(buffer, sizeof(char), size, input);
    int unique_symbols = 0;
    char unique[256];
    int frequency[256];
    memset(frequency, 0, sizeof(frequency));
    for(int i = 0; i < size; i++) {
        if(strchr(unique, buffer[i]) == NULL) {
            unique_symbols++;
            unique[unique_symbols-1] = buffer[i];
        }
        frequency[(int) buffer[i]]++;
    }
    Code codes[unique_symbols];
    for(int i = 0; i < unique_symbols; i++) {
        codes[i].symbol = ' ';
        memset(codes[i].code, 0, sizeof(codes[i].code));
    }
    generate_code(codes, unique_symbols, "", 0, unique, unique_symbols);
    for(int i = 0; i < unique_symbols; i++) {
        printf("'%c' has code %s\n", codes[i].symbol, codes[i].code);
    }
    char compressed_buffer[MAX_BUFFER_SIZE];
    memset(compressed_buffer, 0, sizeof(compressed_buffer));
    int bit_count = 0;
    int compressed_index = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < unique_symbols; j++) {
            if(buffer[i] == codes[j].symbol) {
                for(int k = 0; k < strlen(codes[j].code); k++) {
                    compressed_buffer[compressed_index++] = codes[j].code[k];
                    bit_count++;
                    if(bit_count == 8) {
                        write_bits(compressed_buffer, bit_count, output);
                        memset(compressed_buffer, 0, sizeof(compressed_buffer));
                        compressed_index = 0;
                        bit_count = 0;
                    }
                }
            }
        }
    }
    if(compressed_index > 0) {
        write_bits(compressed_buffer, bit_count, output);
    }
    fclose(input);
    fclose(output);
}

int main() {
    char input_file[] = "input.txt";
    char output_file[] = "output.bin";
    compress_file(input_file, output_file);
    return 0;
}