//FormAI DATASET v1.0 Category: Data recovery tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define BLOCK_SIZE 512

typedef struct {
    int file_size;
    int num_blocks;
    char *block_list;
} file_data;

void recover_file_data(char *disk_image, char *file_name, file_data *file)
{
    FILE *fp = fopen(disk_image, "r");
    if (!fp) {
        printf("Failed to open disk image '%s'\n", disk_image);
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    int disk_size = ftell(fp);
    rewind(fp);

    int fd = fileno(fp);
    off_t offset = 0;
    char buf[BLOCK_SIZE];
    bool found_file = false;
    bool found_eof = false;
    while (offset < disk_size && !found_eof) {
        if (pread(fd, buf, BLOCK_SIZE, offset) != BLOCK_SIZE) {
            printf("Failed to read block at offset %ld\n", offset);
            exit(1);
        }
        if (memcmp(buf, "\x89PNG\r\n\x1A\n", 8) == 0) {
            char *name = buf + 24; // Skip header data
            if (strcmp(name, file_name) == 0) {
                memcpy(&file->file_size, buf + 8, sizeof(file->file_size));
                memcpy(&file->num_blocks, buf + 12, sizeof(file->num_blocks));
                file->block_list = malloc(file->num_blocks);
                memcpy(file->block_list, buf + 16, file->num_blocks);
                found_file = true;
            }
        } else if (memcmp(buf, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16) == 0) {
            found_eof = true;
        }
        offset += BLOCK_SIZE;
    }
    fclose(fp);
    if (!found_file) {
        printf("Failed to find file '%s'\n", file_name);
        exit(1);
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("USAGE: %s <disk_image> <file_name>\n", argv[0]);
        exit(1);
    }
    file_data file;
    recover_file_data(argv[1], argv[2], &file);
    printf("Recovered data for file '%s':\n", argv[2]);
    printf("\tFile size: %d bytes\n", file.file_size);
    printf("\tNumber of blocks: %d\n", file.num_blocks);
    printf("\tBlock list: %s\n", file.block_list);
    free(file.block_list);
    return 0;
}