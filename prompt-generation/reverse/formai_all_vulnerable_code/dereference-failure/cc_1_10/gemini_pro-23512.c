//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint16_t checksum(void *buf, size_t len) {
    uint16_t sum = 0;
    uint8_t *bytes = (uint8_t *)buf;

    for (size_t i = 0; i < len; i++) {
        sum += bytes[i];
    }

    return sum;
}

uint16_t checksum16(void *buf, size_t len) {
    uint16_t sum = 0;
    uint16_t *words = (uint16_t *)buf;

    for (size_t i = 0; i < len / 2; i++) {
        sum += words[i];
    }

    return sum;
}

uint32_t checksum32(void *buf, size_t len) {
    uint32_t sum = 0;
    uint32_t *words = (uint32_t *)buf;

    for (size_t i = 0; i < len / 4; i++) {
        sum += words[i];
    }

    return sum;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(fp, 0, SEEK_END);
    size_t len = ftell(fp);
    rewind(fp);

    void *buf = malloc(len);
    if (buf == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    fread(buf, len, 1, fp);

    uint16_t checksum_8 = checksum(buf, len);
    uint16_t checksum_16 = checksum16(buf, len);
    uint32_t checksum_32 = checksum32(buf, len);

    printf("Checksum (8-bit): 0x%04x\n", checksum_8);
    printf("Checksum (16-bit): 0x%04x\n", checksum_16);
    printf("Checksum (32-bit): 0x%08x\n", checksum_32);

    free(buf);
    fclose(fp);

    return EXIT_SUCCESS;
}