//FormAI DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define ENCRYPTION_KEY 23

int main(int argc, char *argv[]) {
    // Check if filename is provided as command-line argument
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open file for reading in binary mode
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        return 1;
    }

    // Determine file size
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the file buffer
    unsigned char *buffer = malloc(fsize);
    if (buffer == NULL) {
        printf("Error: cannot allocate memory for buffer\n");
        return 1;
    }

    // Read file into buffer
    fread(buffer, fsize, 1, fp);
    fclose(fp);

    // Encrypt file buffer
    for (int i = 0; i < fsize; i++) {
        buffer[i] ^= ENCRYPTION_KEY;
    }

    // Open file for writing in binary mode
    fp = fopen(argv[1], "wb");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        free(buffer);
        return 1;
    }

    // Write encrypted buffer to file
    fwrite(buffer, fsize, 1, fp);
    fclose(fp);

    printf("File %s encrypted successfully\n", argv[1]);
    free(buffer);
    return 0;
}