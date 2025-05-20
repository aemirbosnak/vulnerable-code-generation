//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE (1024*1024*1024) // 1GB

typedef struct {
    char *filename;
    FILE *file;
    uint32_t block_size;
    uint32_t num_blocks;
    uint8_t *data;
} file_info;

file_info *open_file(char *filename) {
    file_info *info = malloc(sizeof(file_info));
    info->filename = filename;
    info->file = fopen(filename, "rb");
    if (info->file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fseek(info->file, 0, SEEK_END);
    info->num_blocks = (uint32_t)ftell(info->file) / BLOCK_SIZE;
    info->block_size = BLOCK_SIZE;
    info->data = malloc(info->num_blocks * BLOCK_SIZE);
    if (info->data == NULL) {
        printf("Error: could not allocate memory for file data\n");
        exit(1);
    }
    fseek(info->file, 0, SEEK_SET);
    return info;
}

void close_file(file_info *info) {
    fclose(info->file);
    free(info->data);
    free(info);
}

void write_block(file_info *info, uint32_t block_num, uint8_t *data) {
    fseek(info->file, block_num * BLOCK_SIZE, SEEK_SET);
    fwrite(data, BLOCK_SIZE, 1, info->file);
}

bool read_block(file_info *info, uint32_t block_num, uint8_t *data) {
    fseek(info->file, block_num * BLOCK_SIZE, SEEK_SET);
    size_t bytes_read = fread(data, BLOCK_SIZE, 1, info->file);
    if (bytes_read!= 1) {
        printf("Error: could not read block %d\n", block_num);
        return false;
    }
    return true;
}

void print_hex(uint8_t *data, uint32_t size) {
    for (int i = 0; i < size; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");
}

int main() {
    char filename[256];
    printf("Enter filename: ");
    scanf("%s", filename);
    file_info *info = open_file(filename);
    uint8_t *data = malloc(info->num_blocks * BLOCK_SIZE);
    memset(data, 0, info->num_blocks * BLOCK_SIZE);
    for (int i = 0; i < info->num_blocks; i++) {
        if (!read_block(info, i, &data[i*BLOCK_SIZE])) {
            close_file(info);
            free(data);
            return 1;
        }
    }
    close_file(info);
    printf("File data:\n");
    print_hex(data, info->num_blocks * BLOCK_SIZE);
    free(data);
    return 0;
}