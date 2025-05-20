//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

typedef struct {
    unsigned int sum;
    unsigned int count;
} checksum_t;

void checksum_init(checksum_t *checksum) {
    checksum->sum = 0;
    checksum->count = 0;
}

void checksum_update(checksum_t *checksum, byte *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        checksum->sum += data[i];
        checksum->count++;
    }
}

unsigned int checksum_finalize(checksum_t *checksum) {
    return checksum->sum / checksum->count;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    byte *data = malloc(size);
    if (data == NULL) {
        perror("malloc");
        fclose(file);
        return EXIT_FAILURE;
    }

    if (fread(data, 1, size, file) != size) {
        perror("fread");
        free(data);
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);

    checksum_t checksum;
    checksum_init(&checksum);
    checksum_update(&checksum, data, size);
    unsigned int checksum_value = checksum_finalize(&checksum);

    free(data);

    printf("Checksum: %u\n", checksum_value);

    return EXIT_SUCCESS;
}