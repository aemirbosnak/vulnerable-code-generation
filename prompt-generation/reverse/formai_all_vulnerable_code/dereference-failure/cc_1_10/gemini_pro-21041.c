//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Calculate the checksum of a buffer
uint16_t checksum(const void *buf, size_t len) {
    uint16_t sum = 0;
    const uint8_t *bytes = buf;

    for (size_t i = 0; i < len; i++) {
        sum += bytes[i];
    }

    return sum;
}

// Print the checksum of a buffer
void print_checksum(const void *buf, size_t len) {
    uint16_t sum = checksum(buf, len);

    printf("Checksum: 0x%04x\n", sum);
}

// Read a file into a buffer
void read_file(const char *filename, void **buf, size_t *len) {
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    *len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    *buf = malloc(*len);

    if (*buf == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    fread(*buf, *len, 1, fp);

    fclose(fp);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    void *buf;
    size_t len;

    read_file(argv[1], &buf, &len);

    print_checksum(buf, len);

    free(buf);

    return EXIT_SUCCESS;
}