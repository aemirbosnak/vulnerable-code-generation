//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define VIRUS_SIGNATURE "I_AM_A_VIRUS"
#define CHUNK_SIZE 1024

typedef struct {
    char *filename;
    int fd;
    size_t size;
    char *buffer;
} file_info_t;

typedef struct {
    file_info_t *file;
    char *signature;
} scan_args_t;

void *scan_file(void *args) {
    scan_args_t *scan_args = (scan_args_t *)args;
    file_info_t *file = scan_args->file;
    char *signature = scan_args->signature;

    size_t offset = 0;
    while (offset < file->size) {
        size_t bytes_to_read = (file->size - offset < CHUNK_SIZE) ? file->size - offset : CHUNK_SIZE;
        ssize_t bytes_read = read(file->fd, file->buffer + offset, bytes_to_read);
        if (bytes_read < 0) {
            perror("read");
            return NULL;
        }
        char *match = strstr(file->buffer + offset, signature);
        if (match != NULL) {
            printf("Virus found in file: %s at offset: %zu\n", file->filename, match - file->buffer);
            return NULL;
        }
        offset += bytes_read;
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <virus_signature> <files...>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *signature = argv[1];
    pthread_t threads[argc - 2];
    file_info_t files[argc - 2];
    scan_args_t scan_args[argc - 2];
    for (int i = 0; i < argc - 2; i++) {
        files[i].filename = argv[i + 2];
        files[i].fd = open(files[i].filename, O_RDONLY);
        if (files[i].fd < 0) {
            perror("open");
            return EXIT_FAILURE;
        }
        struct stat statbuf;
        if (fstat(files[i].fd, &statbuf) < 0) {
            perror("fstat");
            return EXIT_FAILURE;
        }
        files[i].size = statbuf.st_size;
        files[i].buffer = malloc(files[i].size);
        if (files[i].buffer == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }
        scan_args[i].file = &files[i];
        scan_args[i].signature = signature;
        if (pthread_create(&threads[i], NULL, &scan_file, &scan_args[i]) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < argc - 2; i++) {
        pthread_join(threads[i], NULL);
        close(files[i].fd);
        free(files[i].buffer);
    }
    return EXIT_SUCCESS;
}