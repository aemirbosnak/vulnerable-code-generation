//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexdump_file(const char* filename, unsigned char* data, long length) {
    FILE* file;
    int i;
    int cols = 16;
    int rows = length / cols;
    int remaining = length % cols;
    file = fopen(filename, "wb");
    if (file == NULL) return;
    for (i = 0; i < rows; i++) {
        fwrite(data + cols * i, cols, 1, file);
        fwrite("\n", 1, 1, file);
    }
    if (remaining > 0) {
        fwrite(data + cols * rows, remaining, 1, file);
        fwrite("\n", 1, 1, file);
    }
    fclose(file);
}

void read_block(FILE* f, unsigned char* block, long start, long length) {
    fseek(f, start, SEEK_SET);
    fread(block, 1, length, f);
}

void recover_data(char* file_name, int block_size) {
    FILE* file;
    long size;
    unsigned char* data;
    long i;
    int num_blocks;
    unsigned char* block;
    int* block_status;

    file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s.\n", file_name);
        return;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    num_blocks = size / block_size;
    if (size % block_size != 0) num_blocks++;

    data = (unsigned char*) malloc(num_blocks * block_size);
    if (data == NULL) {
        printf("Error: could not allocate memory.\n");
        fclose(file);
        return;
    }

    block_status = (int*) malloc(num_blocks * sizeof(int));
    if (block_status == NULL) {
        printf("Error: could not allocate memory.\n");
        free(data);
        fclose(file);
        return;
    }

    for (i = 0; i < num_blocks; i++) {
        read_block(file, data + i * block_size, i * block_size, block_size);
        block_status[i] = 1;
    }

    block = (unsigned char*) malloc(block_size);
    if (block == NULL) {
        printf("Error: could not allocate memory.\n");
        free(data);
        free(block_status);
        fclose(file);
        return;
    }

    for (i = 0; i < num_blocks; i++) {
        if (block_status[i] == 0) continue;
        memcpy(block, data + i * block_size, block_size);
        hexdump_file("block.bin", block, block_size);
    }

    free(block);
    free(data);
    free(block_status);
    fclose(file);

    printf("Data recovery successful.\n");
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s file_name block_size\n", argv[0]);
        return 0;
    }

    int block_size = atoi(argv[2]);
    if (block_size <= 0) {
        printf("Error: invalid block size.\n");
        return 0;
    }

    recover_data(argv[1], block_size);

    return 0;
}