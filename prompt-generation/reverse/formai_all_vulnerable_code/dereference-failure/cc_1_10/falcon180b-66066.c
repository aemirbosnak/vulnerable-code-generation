//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Checksum calculation function
unsigned short calc_checksum(char *data, int length) {
    unsigned short sum = 0;
    for (int i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum % 256;
}

// Read input file and calculate checksum
int main(int argc, char **argv) {
    FILE *fp;
    char *filename = argv[1];
    char *buffer = NULL;
    size_t bufsize = 0;
    size_t bytes_read = 0;
    unsigned short checksum = 0;

    // Open input file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s.\n", filename);
        exit(1);
    }

    // Read entire file into buffer
    while ((bytes_read = fread(buffer + bufsize, 1, MAX_LINE_LENGTH - bufsize, fp))!= 0) {
        bufsize += bytes_read;
        buffer = realloc(buffer, bufsize + 1);
    }
    buffer[bufsize] = '\0';

    // Calculate checksum
    checksum = calc_checksum(buffer, strlen(buffer));

    // Print checksum
    printf("Checksum of %s is %04X.\n", filename, checksum);

    // Close input file
    fclose(fp);
    free(buffer);
    return 0;
}