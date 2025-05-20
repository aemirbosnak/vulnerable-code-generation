//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECKSUM_SIZE 4
#define MAX_BUFFER_SIZE 1024

typedef unsigned char byte;

byte checksum(byte* data, size_t length) {
    byte sum[CHECKSUM_SIZE] = {0};
    size_t i = 0;

    for (i = 0; i < length; i++) {
        sum[0] += data[i];
        sum[1] += sum[0];
        for (size_t j = 0; j < CHECKSUM_SIZE; j++) {
            sum[j] = (sum[j] & 0xFF) + (sum[j+1] & 0xFF);
            sum[j+1] = sum[j] >> 8;
        }
    }

    return sum[0] << 8 | sum[1];
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    size_t data_length = strlen(argv[1]) + 1;
    byte* data = malloc(data_length);

    if (!data) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    memcpy(data, argv[1], data_length);

    byte calculated_checksum = checksum(data, data_length);
    byte given_checksum = strtoul(argv[2], NULL, 16);

    printf("Data: %s\n", data);
    printf("Calculated checksum: %04X\n", calculated_checksum);
    printf("Given checksum: %04X\n", given_checksum);

    free(data);

    if (calculated_checksum != given_checksum) {
        fprintf(stderr, "Checksum mismatch!\n");
        exit(EXIT_FAILURE);
    }

    printf("Checksums match! :)\n");

    return EXIT_SUCCESS;
}