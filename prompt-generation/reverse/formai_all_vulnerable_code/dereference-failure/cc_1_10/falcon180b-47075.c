//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BLOCK_SIZE 512
#define FILE_SIZE 1024

typedef struct {
    char filename[FILE_SIZE];
    int filesize;
    int blockcount;
    char *data;
} file_t;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    int fd;
    struct stat statbuf;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    if (fstat(fd, &statbuf) == -1) {
        printf("Error getting file status: %s\n", filename);
        exit(1);
    }

    file_t *file = malloc(sizeof(file_t));
    strncpy(file->filename, filename, FILE_SIZE);
    file->filesize = statbuf.st_size;
    file->blockcount = file->filesize / BLOCK_SIZE;
    if (file->filesize % BLOCK_SIZE!= 0) {
        file->blockcount++;
    }

    file->data = malloc(file->blockcount * BLOCK_SIZE);

    int bytes_read = read(fd, file->data, file->blockcount * BLOCK_SIZE);
    if (bytes_read!= file->blockcount * BLOCK_SIZE) {
        printf("Error reading file: %s\n", filename);
        exit(1);
    }

    close(fd);

    printf("File Name: %s\n", file->filename);
    printf("File Size: %d bytes\n", file->filesize);
    printf("Block Count: %d\n", file->blockcount);

    int i;
    for (i = 0; i < file->blockcount; i++) {
        printf("Block %d:\n", i);
        printf("%s\n", file->data + i * BLOCK_SIZE);
    }

    free(file->data);
    free(file);

    return 0;
}