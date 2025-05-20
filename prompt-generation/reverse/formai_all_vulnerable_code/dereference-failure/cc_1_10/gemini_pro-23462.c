//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
} Buffer;

Buffer read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = malloc(size);
    if (!data) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (fread(data, 1, size, file) != size) {
        perror("fread");
        exit(EXIT_FAILURE);
    }

    fclose(file);

    return (Buffer) { .data = data, .size = size };
}

void write_file(const char *filename, Buffer buffer) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    if (fwrite(buffer.data, 1, buffer.size, file) != buffer.size) {
        perror("fwrite");
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Buffer buffer = read_file(argv[1]);

    // Perform data recovery here

    write_file(argv[2], buffer);

    return EXIT_SUCCESS;
}