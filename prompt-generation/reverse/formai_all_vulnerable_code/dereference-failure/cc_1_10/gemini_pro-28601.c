//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    char filename[256];
    int size;
    char data[0];
} file_data;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("fstat");
        close(fd);
        return 1;
    }

    file_data *file = malloc(sizeof(file_data) + st.st_size);
    if (file == NULL) {
        perror("malloc");
        close(fd);
        return 1;
    }

    strcpy(file->filename, argv[1]);
    file->size = st.st_size;
    if (read(fd, file->data, st.st_size) < 0) {
        perror("read");
        free(file);
        close(fd);
        return 1;
    }

    close(fd);

    // Write the file data to a new file
    int fd_new = open("recovered.bin", O_WRONLY | O_CREAT, 0644);
    if (fd_new < 0) {
        perror("open");
        free(file);
        return 1;
    }

    if (write(fd_new, file, sizeof(file_data) + file->size) < 0) {
        perror("write");
        free(file);
        close(fd_new);
        return 1;
    }

    close(fd_new);

    free(file);

    printf("File data successfully recovered.\n");

    return 0;
}