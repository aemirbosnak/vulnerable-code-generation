//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

typedef struct {
    char *filename;
    int size;
    char *buffer;
} FileData;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        printf("Error getting file size: %s\n", strerror(errno));
        exit(1);
    }

    FileData *file = malloc(sizeof(FileData));
    file->filename = filename;
    file->size = st.st_size;
    file->buffer = malloc(st.st_size);

    if (read(fd, file->buffer, st.st_size)!= st.st_size) {
        printf("Error reading file: %s\n", strerror(errno));
        exit(1);
    }

    close(fd);

    printf("File recovery complete!\n");
    printf("Filename: %s\n", file->filename);
    printf("Size: %d bytes\n", file->size);

    return 0;
}