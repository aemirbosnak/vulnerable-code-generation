//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the checksum of a string using the Fletcher-16 algorithm
unsigned short fletcher16(const char *str) {
    unsigned short sum1 = 0xffff;
    unsigned short sum2 = 0xffff;

    while (*str) {
        sum1 = (sum1 + *str++) % 65535;
        sum2 = (sum2 + sum1) % 65535;
    }

    return (sum2 << 8) | sum1;
}

// Calculate the checksum of a file using the Fletcher-16 algorithm
unsigned short fletcher16_file(const char *filename) {
    FILE *fp;
    unsigned short sum1 = 0xffff;
    unsigned short sum2 = 0xffff;
    unsigned char buffer[1024];
    size_t bytes_read;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return 0;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            sum1 = (sum1 + buffer[i]) % 65535;
            sum2 = (sum2 + sum1) % 65535;
        }
    }

    fclose(fp);

    return (sum2 << 8) | sum1;
}

// Calculate the checksum of an array of bytes using the Fletcher-16 algorithm
unsigned short fletcher16_bytes(const unsigned char *bytes, size_t length) {
    unsigned short sum1 = 0xffff;
    unsigned short sum2 = 0xffff;

    for (size_t i = 0; i < length; i++) {
        sum1 = (sum1 + bytes[i]) % 65535;
        sum2 = (sum2 + sum1) % 65535;
    }

    return (sum2 << 8) | sum1;
}

// Print a checksum in hexadecimal format
void print_checksum(unsigned short checksum) {
    printf("%04x\n", checksum);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <string|file|bytes>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "string") == 0) {
        if (argc < 3) {
            printf("Usage: %s string <string>\n", argv[0]);
            return 1;
        }

        print_checksum(fletcher16(argv[2]));
    } else if (strcmp(argv[1], "file") == 0) {
        if (argc < 3) {
            printf("Usage: %s file <filename>\n", argv[0]);
            return 1;
        }

        print_checksum(fletcher16_file(argv[2]));
    } else if (strcmp(argv[1], "bytes") == 0) {
        if (argc < 4) {
            printf("Usage: %s bytes <length> <bytes>\n", argv[0]);
            return 1;
        }

        size_t length = strtol(argv[2], NULL, 10);
        unsigned char *bytes = malloc(length);
        for (size_t i = 0; i < length; i++) {
            bytes[i] = strtol(argv[3 + i], NULL, 10);
        }

        print_checksum(fletcher16_bytes(bytes, length));
        free(bytes);
    } else {
        printf("Invalid argument: %s\n", argv[1]);
        return 1;
    }

    return 0;
}