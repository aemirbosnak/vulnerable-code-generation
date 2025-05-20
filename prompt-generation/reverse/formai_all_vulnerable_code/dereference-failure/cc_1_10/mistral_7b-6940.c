//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BUF_SIZE 4096

typedef struct {
    char *filename;
    off_t filesize;
    char *map_base;
} file_data_t;

file_data_t *open_file(const char *filename) {
    int fd;
    struct stat file_stat;
    file_data_t *data = calloc(1, sizeof(file_data_t));

    if ((fd = open(filename, O_RDONLY)) < 0) {
        perror("Failed to open file");
        free(data);
        return NULL;
    }

    if (fstat(fd, &file_stat) < 0) {
        perror("Failed to get file statistics");
        close(fd);
        free(data);
        return NULL;
    }

    data->filename = strdup(filename);
    data->filesize = file_stat.st_size;

    if ((data->map_base = mmap(NULL, data->filesize, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED) {
        perror("Failed to map file to memory");
        close(fd);
        free(data->filename);
        free(data);
        return NULL;
    }

    close(fd);

    return data;
}

int main(int argc, char **argv) {
    int i, chars_in_file = 0;
    file_data_t *file;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if ((file = open_file(argv[1])) == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    for (i = 0; i < file->filesize; ++i) {
        if (file->map_base[i] == '\0') {
            ++chars_in_file;
        }
    }

    printf("Number of characters in '%s': %ld\n", file->filename, (long)chars_in_file);

    munmap(file->map_base, file->filesize);
    free(file->filename);
    free(file);

    return EXIT_SUCCESS;
}