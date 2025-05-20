//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE 1024 * 1024 * 1024 // 1 GB

typedef struct {
    char filename[32];
    size_t blocks;
    size_t size;
} FileHeader;

typedef struct {
    char magic[4]; // "FSH"
    FileHeader header;
    char data[BLOCK_SIZE - 8]; // 8 bytes for header
} FileSystemHeader;

int main() {
    FILE *input = fopen("input.bin", "rb");
    if (input == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    FILE *output = fopen("output.bin", "wb");
    if (output == NULL) {
        printf("Error: Output file could not be created.\n");
        return 1;
    }

    size_t blocks = 0;
    FileSystemHeader *header = (FileSystemHeader *) malloc(BLOCK_SIZE);
    memset(header, 0, BLOCK_SIZE);

    while (fgets(header->header.filename, 32, input)!= NULL) {
        fread(&header->header.size, sizeof(size_t), 1, input);
        fread(&header->header.blocks, sizeof(size_t), 1, input);

        if (header->header.size > MAX_FILE_SIZE) {
            printf("Error: File %s is too large.\n", header->header.filename);
            return 1;
        }

        size_t data_size = header->header.size % BLOCK_SIZE;
        if (data_size == 0) {
            data_size = BLOCK_SIZE;
        }

        header->header.size += data_size;
        header->header.blocks += (header->header.size / BLOCK_SIZE) + 1;
        blocks += header->header.blocks;

        memcpy(header->data, "", data_size);
        fwrite(header, BLOCK_SIZE, 1, output);
    }

    printf("Recovered %zu files.\n", blocks);

    fclose(input);
    fclose(output);

    free(header);

    return 0;
}