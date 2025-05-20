//FormAI DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program encrypts a C file using a secret key.

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid number of arguments\n");
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    char *key = "mysecretkey"; // Replace with your own secret key.
    char *infile = argv[1];
    char *outfile = argv[2];

    FILE *inf = fopen(infile, "r");
    if (!inf) {
        printf("Error opening input file\n");
        exit(1);
    }

    FILE *outf = fopen(outfile, "w");
    if (!outf) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Read input file into memory.
    fseek(inf, 0L, SEEK_END);
    long filesize = ftell(inf);
    fseek(inf, 0L, SEEK_SET);
    char *buffer = malloc(filesize + 1);
    fread(buffer, 1, filesize, inf);
    fclose(inf);

    // Encrypt file using secret key.
    int key_len = strlen(key);
    for (int i = 0; i < filesize; i++) {
        buffer[i] = buffer[i] ^ key[i % key_len];
    }

    // Write encrypted file to output file.
    fwrite(buffer, 1, filesize, outf);
    fclose(outf);

    free(buffer);

    printf("File encrypted successfully using secret key!\n");

    return 0;
}