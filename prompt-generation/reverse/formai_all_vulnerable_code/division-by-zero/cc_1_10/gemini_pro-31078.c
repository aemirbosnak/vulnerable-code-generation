//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024

typedef struct {
    unsigned int sum;
    unsigned int count;
} checksum_t;

void checksum_init(checksum_t *checksum) {
    checksum->sum = 0;
    checksum->count = 0;
}

void checksum_update(checksum_t *checksum, const void *data, size_t size) {
    const unsigned char *bytes = (const unsigned char *)data;
    for (size_t i = 0; i < size; i++) {
        checksum->sum += bytes[i];
        checksum->count++;
    }
}

unsigned int checksum_final(checksum_t *checksum) {
    return checksum->sum / checksum->count;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    checksum_t checksum;
    checksum_init(&checksum);

    unsigned char buffer[CHUNK_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, CHUNK_SIZE, file)) > 0) {
        checksum_update(&checksum, buffer, bytes_read);
    }
    fclose(file);

    unsigned int checksum_value = checksum_final(&checksum);
    printf("Checksum: %u\n", checksum_value);

    return EXIT_SUCCESS;
}