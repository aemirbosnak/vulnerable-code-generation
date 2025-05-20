//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *filename;
    int inode;
    int size;
} FileEntry;

void print_file_entries(FileEntry *files, int count) {
    for (int i = 0; i < count; i++) {
        printf("Filename: %s\nInode: %d\nSize: %d bytes\n", files[i].filename, files[i].inode, files[i].size);
    }
}

int main() {
    char *device = "/dev/sda1";
    int fd = open(device, O_RDONLY);
    if (fd == -1) {
        printf("Error opening device: %s\n", strerror(errno));
        return 1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        printf("Error getting device stats: %s\n", strerror(errno));
        return 1;
    }

    int block_size = sb.st_blksize;
    int num_blocks = sb.st_blocks;

    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        return 1;
    }

    FileEntry *files = malloc(num_blocks * sizeof(FileEntry));
    if (files == NULL) {
        printf("Error allocating memory for file entries\n");
        return 1;
    }

    for (int i = 0; i < num_blocks; i++) {
        lseek(fd, i * block_size, SEEK_SET);
        int bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1) {
            printf("Error reading block %d: %s\n", i, strerror(errno));
            return 1;
        }

        char *filename = strtok(buffer, "\n");
        int inode = atoi(strtok(NULL, "\n"));
        int size = atoi(strtok(NULL, "\n"));

        files[i].filename = filename;
        files[i].inode = inode;
        files[i].size = size;
    }

    print_file_entries(files, num_blocks);

    free(buffer);
    free(files);

    close(fd);
    return 0;
}