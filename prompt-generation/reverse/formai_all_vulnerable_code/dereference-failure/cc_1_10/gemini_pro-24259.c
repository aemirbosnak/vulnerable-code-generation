//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 255

typedef struct {
    unsigned char code;
    unsigned int length;
} Code;

typedef struct {
    unsigned char *data;
    unsigned int size;
} Buffer;

Buffer* read_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    unsigned int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    unsigned char *data = malloc(size);
    fread(data, 1, size, fp);
    fclose(fp);
    Buffer *buffer = malloc(sizeof(Buffer));
    buffer->data = data;
    buffer->size = size;
    return buffer;
}

void write_file(const char *filename, Buffer *buffer) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }
    fwrite(buffer->data, 1, buffer->size, fp);
    fclose(fp);
}

Code* build_code_table(Buffer *buffer) {
    unsigned int *frequencies = calloc(256, sizeof(unsigned int));
    for (unsigned int i = 0; i < buffer->size; i++) {
        frequencies[buffer->data[i]]++;
    }
    unsigned int code_length[MAX_CODE_LENGTH + 1];
    memset(code_length, 0, sizeof(code_length));
    for (unsigned int i = 1; i <= MAX_CODE_LENGTH; i++) {
        for (unsigned int j = 0; j < 256; j++) {
            if (frequencies[j] == i) {
                code_length[i]++;
            }
        }
    }
    Code *code_table = malloc(sizeof(Code) * 256);
    unsigned int code = 0;
    unsigned int current_length = 0;
    for (unsigned int i = 1; i <= MAX_CODE_LENGTH; i++) {
        for (unsigned int j = 0; j < 256; j++) {
            if (frequencies[j] == i) {
                code_table[j].code = code;
                code_table[j].length = current_length = i;
                code += 1 << (current_length - 1);
            }
        }
        code <<= 1;
    }
    free(frequencies);
    return code_table;
}

Buffer* compress(Buffer *buffer, Code *code_table) {
    Buffer *compressed_buffer = malloc(sizeof(Buffer));
    compressed_buffer->data = malloc(buffer->size * 8);
    compressed_buffer->size = 0;
    unsigned int current_code = 0;
    unsigned int current_length = 0;
    for (unsigned int i = 0; i < buffer->size; i++) {
        unsigned int code = code_table[buffer->data[i]].code;
        unsigned int length = code_table[buffer->data[i]].length;
        while (current_length + length > 8) {
            compressed_buffer->data[compressed_buffer->size++] = current_code | (code >> (current_length + length - 8));
            code <<= current_length + length - 8;
            length -= current_length + length - 8;
            current_length = 8;
            current_code = 0;
        }
        current_code |= code << current_length;
        current_length += length;
    }
    if (current_length > 0) {
        compressed_buffer->data[compressed_buffer->size++] = current_code;
    }
    return compressed_buffer;
}

Buffer* decompress(Buffer *compressed_buffer, Code *code_table) {
    Buffer *decompressed_buffer = malloc(sizeof(Buffer));
    decompressed_buffer->data = malloc(compressed_buffer->size * 8);
    decompressed_buffer->size = 0;
    unsigned int current_code = 0;
    unsigned int current_length = 0;
    unsigned int i = 0;
    while (i < compressed_buffer->size) {
        current_code |= compressed_buffer->data[i++] << current_length;
        current_length += 8;
        while (current_length >= code_table[decompressed_buffer->size].length) {
            decompressed_buffer->data[decompressed_buffer->size++] = code_table[current_code >> (current_length - code_table[decompressed_buffer->size].length)].code;
            current_code &= (1 << (current_length - code_table[decompressed_buffer->size].length)) - 1;
            current_length -= code_table[decompressed_buffer->size].length;
        }
    }
    return decompressed_buffer;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <compress|decompress> <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    Buffer *buffer = read_file(argv[2]);
    if (buffer == NULL) {
        printf("Error: could not read input file\n");
        return 1;
    }
    Code *code_table = build_code_table(buffer);
    Buffer *compressed_buffer = NULL;
    Buffer *decompressed_buffer = NULL;
    if (strcmp(argv[1], "compress") == 0) {
        compressed_buffer = compress(buffer, code_table);
        write_file(argv[3], compressed_buffer);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompressed_buffer = decompress(buffer, code_table);
        write_file(argv[3], decompressed_buffer);
    } else {
        printf("Error: invalid operation\n");
        return 1;
    }
    free(buffer->data);
    free(buffer);
    free(code_table);
    if (compressed_buffer != NULL) {
        free(compressed_buffer->data);
        free(compressed_buffer);
    }
    if (decompressed_buffer != NULL) {
        free(decompressed_buffer->data);
        free(decompressed_buffer);
    }
    return 0;
}