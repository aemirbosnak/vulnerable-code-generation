//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size we can handle

typedef struct {
    char *filename;
    char *checksum;
} FileChecksumPair;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    if (filesize > MAX_FILE_SIZE) {
        printf("Error: File is too large (%ld bytes)\n", filesize);
        fclose(file);
        return 1;
    }

    char *buffer = malloc(filesize + 1);
    if (!buffer) {
        printf("Error: Could not allocate memory for buffer\n");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, filesize, file);
    if (bytes_read!= filesize) {
        printf("Error: Could not read entire file\n");
        free(buffer);
        fclose(file);
        return 1;
    }

    buffer[filesize] = '\0';
    fclose(file);

    unsigned char checksum = 0;
    for (int i = 0; i < filesize; i++) {
        checksum += buffer[i];
    }

    char checksum_str[3];
    snprintf(checksum_str, 3, "%02X", checksum);

    FileChecksumPair pair = {.filename = argv[1],.checksum = checksum_str };
    printf("Filename: %s\nChecksum: %s\n", pair.filename, pair.checksum);

    free(buffer);
    return 0;
}