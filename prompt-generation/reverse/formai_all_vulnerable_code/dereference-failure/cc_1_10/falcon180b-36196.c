//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BLOCK_SIZE 512

typedef struct {
    int fd;
    char *filename;
    int block_size;
    int num_blocks;
    int current_block;
} File;

void read_block(File *file, int block_num, char *block_data) {
    lseek(file->fd, block_num * file->block_size, SEEK_SET);
    read(file->fd, block_data, file->block_size);
}

void write_block(File *file, int block_num, char *block_data) {
    lseek(file->fd, block_num * file->block_size, SEEK_SET);
    write(file->fd, block_data, file->block_size);
}

int is_valid_block(char *block_data) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        if (block_data[i] == 0x00) {
            return 0;
        }
    }
    return 1;
}

int find_free_block(File *file) {
    int i;
    for (i = 0; i < file->num_blocks; i++) {
        if (is_valid_block(file->filename + i * file->block_size)) {
            return -1;
        }
    }
    return i;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    File file;
    file.filename = argv[1];
    file.fd = open(file.filename, O_RDWR);
    if (file.fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    file.block_size = BLOCK_SIZE;
    file.num_blocks = file.fd / file.block_size;
    file.current_block = 0;

    int free_block = find_free_block(&file);
    if (free_block == -1) {
        printf("No free blocks available.\n");
        exit(1);
    }

    char *data = malloc(file.block_size);
    memset(data, 0x00, file.block_size);

    read_block(&file, free_block, data);
    write_block(&file, free_block, data);

    printf("Data recovery successful.\n");

    close(file.fd);
    free(data);
    return 0;
}