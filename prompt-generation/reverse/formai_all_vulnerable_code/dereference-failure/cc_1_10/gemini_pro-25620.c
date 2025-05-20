//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define CHUNK_SIZE 4096

typedef struct {
    char *data;
    size_t size;
} Chunk;

typedef struct {
    int fd;
    size_t offset;
    size_t size;
    Chunk *chunks;
    int num_chunks;
} File;

File *open_file(const char *path) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return NULL;
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("fstat");
        close(fd);
        return NULL;
    }

    File *file = malloc(sizeof(File));
    file->fd = fd;
    file->offset = 0;
    file->size = st.st_size;
    file->chunks = NULL;
    file->num_chunks = 0;

    return file;
}

void close_file(File *file) {
    if (file->chunks != NULL) {
        for (int i = 0; i < file->num_chunks; i++) {
            free(file->chunks[i].data);
        }
        free(file->chunks);
    }
    close(file->fd);
    free(file);
}

int read_chunk(File *file, Chunk *chunk) {
    if (file->offset + CHUNK_SIZE > file->size) {
        chunk->size = file->size - file->offset;
    } else {
        chunk->size = CHUNK_SIZE;
    }

    chunk->data = malloc(chunk->size);
    if (chunk->data == NULL) {
        perror("malloc");
        return -1;
    }

    ssize_t bytes_read = read(file->fd, chunk->data, chunk->size);
    if (bytes_read < 0) {
        perror("read");
        free(chunk->data);
        return -1;
    }

    file->offset += bytes_read;
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    File *input_file = open_file(argv[1]);
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    File *output_file = open_file(argv[2]);
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        close_file(input_file);
        return EXIT_FAILURE;
    }

    Chunk chunk;
    while (read_chunk(input_file, &chunk) == 0) {
        if (write(output_file->fd, chunk.data, chunk.size) < 0) {
            perror("write");
            close_file(input_file);
            close_file(output_file);
            return EXIT_FAILURE;
        }

        free(chunk.data);
    }

    close_file(input_file);
    close_file(output_file);

    return EXIT_SUCCESS;
}