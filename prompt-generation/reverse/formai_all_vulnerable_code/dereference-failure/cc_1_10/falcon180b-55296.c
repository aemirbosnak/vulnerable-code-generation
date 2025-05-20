//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_SIZE 1000000
#define MAX_BLOCK_SIZE 1024

typedef struct {
    char* file_path;
    unsigned char* checksum;
    size_t file_size;
} file_info_t;

void usage(char* program_name) {
    printf("Usage: %s <file_path> <block_size>\n", program_name);
}

void calculate_checksum(file_info_t* file_info) {
    FILE* file = fopen(file_info->file_path, "rb");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", file_info->file_path);
        exit(1);
    }

    unsigned char buffer[MAX_BLOCK_SIZE];
    size_t bytes_read = 0;
    unsigned char checksum = 0;

    while ((bytes_read = fread(buffer, 1, MAX_BLOCK_SIZE, file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            checksum += buffer[i];
        }
    }

    fclose(file);

    file_info->checksum = (unsigned char)checksum;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        usage(argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    int block_size = atoi(argv[2]);

    if (block_size <= 0 || block_size > MAX_BLOCK_SIZE) {
        printf("Error: invalid block size\n");
        usage(argv[0]);
        return 1;
    }

    file_info_t file_info = {
       .file_path = file_path,
       .checksum = (unsigned char)0,
       .file_size = 0
    };

    calculate_checksum(&file_info);

    printf("File: %s\n", file_info.file_path);
    printf("Checksum: %02X\n", file_info.checksum);
    printf("File size: %zu bytes\n", file_info.file_size);

    return 0;
}