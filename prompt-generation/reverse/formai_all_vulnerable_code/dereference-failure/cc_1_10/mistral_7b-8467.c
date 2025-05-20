//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct {
    char *name;
    int fd;
    size_t size;
} FileHandle;

FileHandle read_file(const char *path, size_t *size) {
    int error = 0;
    FileHandle file = {0};

    if (!(file.name = strdup(path))) {
        error = 1;
        goto cleanup;
    }

    if ((file.fd = open(path, O_RDONLY)) < 0) {
        error = 1;
        perror("Error opening file");
        goto cleanup;
    }

    if (fseek(file.fd, 0, SEEK_END) < 0) {
        error = 1;
        perror("Error seeking end of file");
        goto cleanup;
    }

    file.size = ftell(file.fd);
    rewind(file.fd);

    if (size)
        *size = file.size;

cleanup:
    if (error) {
        if (file.name)
            free(file.name);
        if (file.fd >= 0)
            close(file.fd);
        file = (FileHandle){0};
    }

    return file;
}

void print_file_content(const FileHandle file) {
    char *buffer = NULL;
    size_t size;

    if (file.size > 0) {
        buffer = malloc(file.size);
        if (!buffer) {
            perror("Error allocating memory");
            goto cleanup;
        }

        size_t bytes_read = fread(buffer, 1, file.size, file.fd);
        if (bytes_read != file.size) {
            perror("Error reading file content");
            goto cleanup;
        }

        fwrite(buffer, 1, file.size, stdout);
    }

cleanup:
    if (buffer)
        free(buffer);
}

int main(int argc, char **argv) {
    FileHandle file;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if ((file = read_file(argv[1], NULL)) .size <= 0) {
        perror("Error reading file");
        return 1;
    }

    printf("File size: %ld bytes\n", file.size);
    print_file_content(file);

    if (file.fd >= 0)
        close(file.fd);

    free(file.name);
    return 0;
}