//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void checksum(unsigned char *buffer, int size) {
    unsigned int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += buffer[i];
    }
    sum = (sum & 0xFFFF) + (sum >> 16);
    sum = (sum & 0xFFFF) + (sum >> 16);
    printf("Checksum: 0x%X\n", sum);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t read_bytes;
    unsigned char checksum_buffer[8];

    while ((read_bytes = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        checksum(buffer, read_bytes);
        memset(buffer, 0, BUFFER_SIZE);
    }

    if (feof(file)) {
        if (ferror(file)) {
            perror("Error reading file");
            fclose(file);
            return 1;
        }
    } else {
        perror("Unexpected end of file");
        fclose(file);
        return 1;
    }

    fclose(file);

    // Calculate checksum for the command line arguments
    checksum((unsigned char *)argv[0], strlen(argv[0]) + 1);
    checksum((unsigned char *)argv[1], strlen(argv[1]) + 1);

    // Print final checksum
    checksum((unsigned char *)"\0", 1);

    return 0;
}