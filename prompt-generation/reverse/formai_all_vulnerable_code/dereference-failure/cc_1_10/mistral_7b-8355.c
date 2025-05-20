//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: retro
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef unsigned char byte;
typedef uint16_t word;

#define CHECKSUM_SIZE 4

void swap_bytes(byte *data) {
    byte temp;
    temp = data[0];
    data[0] = data[1];
    data[1] = temp;
}

word calculate_checksum(const byte *data, size_t length) {
    word sum = 0;
    size_t i;

    for (i = 0; i < length; ++i) {
        sum += data[i];
    }

    for (i = 0; i < (length & ~1); i += 2) {
        swap_bytes((byte *)&sum + i);
        sum += (sum >> 8) & 0xFF;
    }

    if (length & 1) {
        sum += data[length - 1];
    }

    return sum;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    byte *buffer = malloc(file_size);
    size_t bytes_read = fread(buffer, 1, file_size, file);

    if (bytes_read != file_size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return 1;
    }

    fclose(file);

    word checksum = calculate_checksum(buffer, file_size);

    printf("File size: %lu bytes\n", file_size);
    printf("Checksum: ");
    for (size_t i = 0; i < CHECKSUM_SIZE; ++i) {
        printf("%04x", (checksum >> (8 * i)) & 0xFFFF);
        if (i < CHECKSUM_SIZE - 1) {
            printf(":");
        }
    }
    printf("\n");

    free(buffer);

    return 0;
}