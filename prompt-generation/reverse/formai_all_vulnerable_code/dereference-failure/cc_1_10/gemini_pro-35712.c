//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculates the checksum of a given string using the Fletcher-32 algorithm.
unsigned long checksum(const char *str) {
    unsigned long sum1 = 0, sum2 = 0;
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++) {
        sum1 += str[i];
        sum2 += sum1;
    }

    return (sum1 << 16) | (sum2 & 0xFFFF);
}

// Calculates the checksum of a given file using the Fletcher-32 algorithm.
unsigned long checksum_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 0;
    }

    unsigned long sum1 = 0, sum2 = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        sum1 += c;
        sum2 += sum1;
    }

    fclose(fp);

    return (sum1 << 16) | (sum2 & 0xFFFF);
}

// Prints the checksum of a given string or file.
void print_checksum(const char *input, int is_file) {
    unsigned long checksum_value;

    if (is_file) {
        checksum_value = checksum_file(input);
    } else {
        checksum_value = checksum(input);
    }

    printf("Checksum: %lu\n", checksum_value);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string> or <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (argc == 2) {
        print_checksum(argv[1], 0);
    } else {
        print_checksum(argv[1], 1);
    }

    return EXIT_SUCCESS;
}