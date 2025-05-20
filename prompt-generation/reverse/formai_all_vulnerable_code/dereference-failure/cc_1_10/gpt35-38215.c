//FormAI DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

// Function to encrypt the input file
void encrypt_file(char *filename, char *key) {

    FILE *fp_in, *fp_out;
    char buffer[MAX_BUF_SIZE];
    char encrypted[MAX_BUF_SIZE];
    int key_index, i, n;

    // Open the input file
    fp_in = fopen(filename, "rb");

    // Create the output file
    char encrypted_file[strlen(filename) + 13];
    sprintf(encrypted_file, "encrypted_%s", filename);
    fp_out = fopen(encrypted_file, "wb");

    // Encrypt each block of MAX_BUF_SIZE bytes
    while ((n = fread(buffer, sizeof(char), MAX_BUF_SIZE, fp_in)) > 0) {
        key_index = 0;
        for (i = 0; i < n; i++) {
            encrypted[i] = buffer[i] ^ key[key_index];
            key_index++;
            if (key_index == strlen(key)) {
                key_index = 0;
            }
        }
        fwrite(encrypted, sizeof(char), n, fp_out);
    }

    // Close files
    fclose(fp_in);
    fclose(fp_out);

}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s filename key\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *key = argv[2];

    encrypt_file(filename, key);

    printf("%s has been encrypted using key %s\n", filename, key);

    return 0;

}