//FormAI DATASET v1.0 Category: File Encyptor ; Style: Linus Torvalds
/*
 * C File Encyptor example program
 * Written by [Your Name]
 * Inspired by Linus Torvalds code style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *in_file, *out_file;
    char *in_filename, *out_filename, *key;
    int key_len, i;
    unsigned char buffer[BUFFER_SIZE];

    /* Check command line arguments */
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Get file names and key */
    in_filename = argv[1];
    out_filename = argv[2];
    key = argv[3];
    key_len = strlen(key);

    /* Open input file */
    in_file = fopen(in_filename, "rb");
    if (in_file == NULL) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    /* Open output file */
    out_file = fopen(out_filename, "wb");
    if (out_file == NULL) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    /* Encrypt file */
    while (fread(buffer, 1, BUFFER_SIZE, in_file) > 0) {
        for (i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] ^= key[i % key_len];
        }
        fwrite(buffer, 1, BUFFER_SIZE, out_file);
    }

    /* Clean up */
    fclose(in_file);
    fclose(out_file);

    return 0;
}