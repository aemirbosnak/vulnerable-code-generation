//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the checksum of a string using a simple algorithm
int calculate_checksum(char *str) {
    int checksum = 0;
    for (int i = 0; i < strlen(str); i++) {
        checksum += str[i];
    }
    return checksum;
}

// Print a formatted string representing the checksum of a file
void print_checksum(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *buffer = malloc(filesize);
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    fread(buffer, 1, filesize, fp);
    fclose(fp);

    int checksum = calculate_checksum(buffer);
    free(buffer);

    printf("Checksum of %s: %d\n", filename, checksum);
}

// Get the filename from the command line arguments
char *get_filename(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: no filename provided\n");
        exit(1);
    }
    return argv[1];
}

int main(int argc, char *argv[]) {
    char *filename = get_filename(argc, argv);
    print_checksum(filename);
    return 0;
}