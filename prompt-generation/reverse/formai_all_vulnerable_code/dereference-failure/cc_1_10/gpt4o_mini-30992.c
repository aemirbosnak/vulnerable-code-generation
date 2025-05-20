//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BLOCK_SIZE 512
#define MAX_FILES 100
#define MAX_FILENAME 256

typedef struct {
    char filename[MAX_FILENAME];
    off_t start_block;
    size_t block_count;
} FileEntry;

int read_block(int fd, char *buffer, off_t block_number) {
    if (lseek(fd, block_number * BLOCK_SIZE, SEEK_SET) == -1) {
        perror("lseek error");
        return -1;
    }
    return read(fd, buffer, BLOCK_SIZE);
}

int recover_file(int fd, FileEntry *file) {
    char *block_buffer = malloc(BLOCK_SIZE);
    if (!block_buffer) {
        perror("malloc error");
        return -1;
    }

    FILE *output_file = fopen(file->filename, "wb");
    if (!output_file) {
        perror("fopen error");
        free(block_buffer);
        return -1;
    }

    for (size_t i = 0; i < file->block_count; i++) {
        if (read_block(fd, block_buffer, file->start_block + i) < 0) {
            fclose(output_file);
            free(block_buffer);
            return -1;
        }
        fwrite(block_buffer, sizeof(char), BLOCK_SIZE, output_file);
    }

    fclose(output_file);
    free(block_buffer);
    printf("Recovered file: %s\n", file->filename);
    return 0;
}

void print_help() {
    printf("C Data Recovery Tool\n");
    printf("Usage: recover <device_file> <start_block> <total_blocks>\n");
    printf("Example: recover /dev/sda 1024 10\n");
    printf("Notes: \n");
    printf(" - The first recovered file will be named 'recovered_file_1.bin'.\n");
    printf(" - Recovery proceeds for the specified range of blocks.\n");
}

int main(int argc, char **argv) {
    if (argc != 4) {
        print_help();
        return EXIT_FAILURE;
    }

    const char *device_file = argv[1];
    off_t start_block = atoll(argv[2]);
    size_t total_blocks = atoll(argv[3]);

    int fd = open(device_file, O_RDONLY);
    if (fd < 0) {
        perror("Could not open device file");
        return EXIT_FAILURE;
    }

    FileEntry recovered_files[MAX_FILES];
    size_t recovered_file_count = 0;

    for (size_t i = 0; i < total_blocks; i++) {
        FileEntry *current_file = &recovered_files[recovered_file_count];

        snprintf(current_file->filename, MAX_FILENAME, "recovered_file_%zu.bin", recovered_file_count + 1);
        current_file->start_block = start_block + i;
        current_file->block_count = 1; // Here we assume one file per block of data

        if (recover_file(fd, current_file) < 0) {
            printf("Failed to recover file from block %zu\n", start_block + i);
        } else {
            recovered_file_count++;
        }
    }

    close(fd);
    printf("Total files recovered: %zu\n", recovered_file_count);
    return EXIT_SUCCESS;
}