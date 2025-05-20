//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define CHUNK_SIZE 4096
#define MAX_FILE_SIZE (1024 * 1024 * 1024)

typedef uint32_t checksum_t;

static checksum_t calculate_checksum(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    size_t file_size = 0;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        fprintf(stderr, "File size is too large: %zu\n", file_size);
        exit(EXIT_FAILURE);
    }

    checksum_t checksum = 0;
    char *buffer = malloc(CHUNK_SIZE);
    if (!buffer) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, CHUNK_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            checksum += buffer[i];
        }
    }

    if (ferror(file)) {
        perror("fread");
        exit(EXIT_FAILURE);
    }

    fclose(file);
    free(buffer);

    return checksum;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    checksum_t checksum = calculate_checksum(argv[1]);

    printf("Checksum: %08" PRIX32 "\n", checksum);

    return EXIT_SUCCESS;
}