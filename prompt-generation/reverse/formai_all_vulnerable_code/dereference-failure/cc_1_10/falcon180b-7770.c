//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE (1024 * 1024 * 1024) // 1GB

typedef struct {
    char *filename;
    FILE *fp;
    unsigned char *buffer;
    int blocks_read;
    int file_size;
} file_t;

void read_file(file_t *file) {
    int bytes_read;
    unsigned char block[BLOCK_SIZE];
    while ((bytes_read = fread(block, 1, BLOCK_SIZE, file->fp)) > 0) {
        if (file->blocks_read >= MAX_FILE_SIZE) {
            printf("File size exceeds 1GB.\n");
            exit(1);
        }
        memcpy(&file->buffer[file->blocks_read * BLOCK_SIZE], block, bytes_read);
        file->blocks_read++;
        file->file_size += bytes_read;
    }
}

void write_file(file_t *file) {
    FILE *out_fp;
    int bytes_written;
    out_fp = fopen(file->filename, "wb");
    if (out_fp == NULL) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }
    bytes_written = fwrite(file->buffer, 1, file->blocks_read * BLOCK_SIZE, out_fp);
    if (bytes_written!= file->blocks_read * BLOCK_SIZE) {
        printf("Error: Could not write all data to output file.\n");
        exit(1);
    }
    fclose(out_fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    file_t file;
    file.filename = argv[1];
    file.fp = fopen(file.filename, "rb");
    if (file.fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    file.buffer = malloc(MAX_FILE_SIZE);
    if (file.buffer == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }
    file.blocks_read = 0;
    read_file(&file);
    write_file(&file);
    free(file.buffer);
    fclose(file.fp);
    return 0;
}