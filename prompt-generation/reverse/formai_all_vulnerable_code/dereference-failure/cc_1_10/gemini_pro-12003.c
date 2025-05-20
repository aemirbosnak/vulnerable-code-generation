//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum of a string
unsigned short checksum(const char *str) {
    unsigned short sum = 0;
    while (*str) {
        sum += *str++;
    }
    return sum;
}

// Function to calculate the checksum of a file
unsigned short file_checksum(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return 0;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(size);
    if (buffer == NULL) {
        fclose(file);
        return 0;
    }

    fread(buffer, 1, size, file);
    fclose(file);

    unsigned short sum = checksum(buffer);

    free(buffer);

    return sum;
}

// Function to print the checksum of a string or file
void print_checksum(const char *str, const char *filename) {
    if (filename != NULL) {
        printf("Checksum of file %s: %u\n", filename, file_checksum(filename));
    } else {
        printf("Checksum of string %s: %u\n", str, checksum(str));
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [string or file]\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        print_checksum(argv[1], NULL);
    } else {
        for (int i = 1; i < argc; i++) {
            print_checksum(NULL, argv[i]);
        }
    }

    return 0;
}