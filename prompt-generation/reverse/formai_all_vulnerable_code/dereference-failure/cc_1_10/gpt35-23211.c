//FormAI DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

void encrypt(char *filename, char *key) {
    FILE *fpin, *fpout;
    char *out_filename = strcat(filename, ".enc");
    int key_len = strlen(key);
    char buffer[MAX_LEN];
    int i, j = 0, buffer_len;

    // Open input file
    if ((fpin = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Cannot open input file\n");
        exit(1);
    }

    // Open output file
    if ((fpout = fopen(out_filename, "wb")) == NULL) {
        fprintf(stderr, "Cannot open output file\n");
        exit(1);
    }

    // Read input file and encrypt data 
    while ((buffer_len = fread(buffer, sizeof(char), MAX_LEN, fpin)) > 0) {
        for (i = 0; i < buffer_len; i++) {
            buffer[i] ^= key[j];
            j = (j + 1) % key_len;
        }
        fwrite(buffer, sizeof(char), buffer_len, fpout);
    }

    // Close files
    fclose(fpin);
    fclose(fpout);

    // Delete original file
    if (remove(filename) != 0) {
        fprintf(stderr, "Cannot delete file\n");
        exit(1);
    }

    printf("File encryption successful\n");
}

void decrypt(char *filename, char *key) {
    FILE *fpin, *fpout;
    char *out_filename = strtok(filename, ".enc");
    int key_len = strlen(key);
    char buffer[MAX_LEN];
    int i, j = 0, buffer_len;

    // Open input file
    if ((fpin = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Cannot open input file\n");
        exit(1);
    }

    // Open output file
    if ((fpout = fopen(out_filename, "wb")) == NULL) {
        fprintf(stderr, "Cannot open output file\n");
        exit(1);
    }

    // Read input file and decrypt data 
    while ((buffer_len = fread(buffer, sizeof(char), MAX_LEN, fpin)) > 0) {
        for (i = 0; i < buffer_len; i++) {
            buffer[i] ^= key[j];
            j = (j + 1) % key_len;
        }
        fwrite(buffer, sizeof(char), buffer_len, fpout);
    }

    // Close files
    fclose(fpin);
    fclose(fpout);

    // Delete encrypted file
    if (remove(filename) != 0) {
        fprintf(stderr, "Cannot delete file\n");
        exit(1);
    }

    printf("File decryption successful\n");
}

int main(int argc, char *argv[]) {
    char *filename, *key;
    int i;

    // Check command line arguments
    if (argc != 4 || (strcmp(argv[1], "encrypt") != 0 && strcmp(argv[1], "decrypt") != 0)) {
        fprintf(stderr, "Usage: encyptor <encrypt/decrypt> <filename> <key>\n");
        exit(1);
    }

    // Get filename and key
    filename = argv[2];
    key = argv[3];

    // Validate key (must be alphanumeric)
    for (i = 0; i < strlen(key); i++) {
        if (!isalnum(key[i])) {
            fprintf(stderr, "Invalid key\n");
            exit(1);
        }
    }

    // Encrypt or decrypt file
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(filename, key);
    } else {
        decrypt(filename, key);
    }

    return 0;
}