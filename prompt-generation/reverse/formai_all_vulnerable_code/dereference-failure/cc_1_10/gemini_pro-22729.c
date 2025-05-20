//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024 * 1024

typedef struct {
    char *data;
    size_t size;
} recovered_file;

recovered_file *read_file(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == -1) {
        perror("stat");
        return NULL;
    }

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return NULL;
    }

    recovered_file *file = malloc(sizeof(recovered_file));
    if (file == NULL) {
        perror("malloc");
        close(fd);
        return NULL;
    }

    file->data = malloc(st.st_size);
    if (file->data == NULL) {
        perror("malloc");
        close(fd);
        free(file);
        return NULL;
    }

    file->size = st.st_size;
    if (read(fd, file->data, st.st_size) != st.st_size) {
        perror("read");
        close(fd);
        free(file->data);
        free(file);
        return NULL;
    }

    close(fd);
    return file;
}

void write_file(const char *filename, const char *data, size_t size) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return;
    }

    if (write(fd, data, size) != size) {
        perror("write");
        close(fd);
        return;
    }

    close(fd);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    recovered_file *file = read_file(filename);
    if (file == NULL) {
        fprintf(stderr, "Failed to read file: %s\n", filename);
        return 1;
    }

    char *new_filename = malloc(strlen(filename) + 5);
    if (new_filename == NULL) {
        perror("malloc");
        free(file->data);
        free(file);
        return 1;
    }

    sprintf(new_filename, "%s.recovered", filename);

    write_file(new_filename, file->data, file->size);
    free(new_filename);
    free(file->data);
    free(file);

    printf("File recovered: %s\n", new_filename);
    return 0;
}