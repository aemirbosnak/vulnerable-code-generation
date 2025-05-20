//FormAI DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_BLOCK 512

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: data-recovery-tool <file_name> <start_byte> <end_byte>\n");
        return 1;
    }
    
    char *file_name = argv[1];
    long int start_byte = atol(argv[2]);
    long int end_byte = atol(argv[3]);
    
    if (start_byte < 0 || end_byte < 0 || start_byte > end_byte) {
        printf("Invalid start or end byte position.\n");
        return 1;
    }
    
    FILE* file = fopen(file_name, "rb");
    if (!file) {
        printf("Unable to open file '%s'.\n", file_name);
        return 1;
    }
    
    fseek(file, start_byte, SEEK_SET);
    
    long int bytes_to_read = end_byte - start_byte + 1;
    long int blocks_to_read = (bytes_to_read + BYTES_PER_BLOCK - 1) / BYTES_PER_BLOCK;
    
    char *data = malloc(blocks_to_read * BYTES_PER_BLOCK);
    if (!data) {
        printf("Unable to allocate memory for data.\n");
        return 1;
    }
    
    size_t read_count = fread(data, BYTES_PER_BLOCK, blocks_to_read, file);
    if (read_count != blocks_to_read) {
        printf("Unable to read all data from file.\n");
        free(data);
        return 1;
    }
    
    printf("Data recovered from bytes %ld to %ld:\n", start_byte, end_byte);
    for (int i = 0; i < bytes_to_read; i++) {
        printf("%02x ", data[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    
    free(data);
    fclose(file);
    return 0;
}