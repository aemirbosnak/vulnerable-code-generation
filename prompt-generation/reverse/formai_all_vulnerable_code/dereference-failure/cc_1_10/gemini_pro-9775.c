//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>

#define PAGE_SIZE 4096

typedef struct {
    char *name;
    size_t size;
    char *data;
} file_t;

static file_t *open_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return NULL;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        return NULL;
    }

    file_t *file = malloc(sizeof(file_t));
    if (file == NULL) {
        perror("malloc");
        close(fd);
        return NULL;
    }

    file->name = strdup(filename);
    if (file->name == NULL) {
        perror("strdup");
        free(file);
        close(fd);
        return NULL;
    }

    file->size = st.st_size;
    file->data = mmap(NULL, file->size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file->data == MAP_FAILED) {
        perror("mmap");
        free(file->name);
        free(file);
        close(fd);
        return NULL;
    }

    close(fd);
    return file;
}

static void close_file(file_t *file) {
    munmap(file->data, file->size);
    free(file->name);
    free(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file_t *file = open_file(argv[1]);
    if (file == NULL) {
        return EXIT_FAILURE;
    }

    printf("File: %s\n", file->name);
    printf("Size: %zu\n", file->size);

    // Scan the file for deleted files.
    char *ptr = file->data;
    char *end = file->data + file->size;
    while (ptr < end) {
        // Look for the magic number that identifies a deleted file.
        if (*ptr == 0xE5 && *(ptr + 1) == 0x9A) {
            // Found a deleted file.
            size_t size = *(ptr + 2) | (*(ptr + 3) << 8) | (*(ptr + 4) << 16) | (*(ptr + 5) << 24);
            char *name = ptr + 6;

            // Print the name and size of the deleted file.
            printf("Deleted file: %s\n", name);
            printf("Size: %zu\n", size);

            // Skip to the next deleted file.
            ptr += size + 6;
        } else {
            // Not a deleted file.
            ptr++;
        }
    }

    close_file(file);
    return EXIT_SUCCESS;
}