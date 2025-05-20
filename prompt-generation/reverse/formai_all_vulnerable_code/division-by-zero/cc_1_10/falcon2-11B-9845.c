//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encrypt(char *filename, char *key) {
    // Open the file for reading
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for encrypted file
    char *encrypted = (char*) malloc(size);
    if (encrypted == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    // Read the file into encrypted
    fread(encrypted, 1, size, fp);

    // Encrypt the file
    char temp;
    for (int i = 0; i < size; i++) {
        temp = encrypted[i];
        encrypted[i] = (temp ^ key[i % strlen(key)]);
    }

    // Close the file
    fclose(fp);

    // Write the encrypted file to disk
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fwrite(encrypted, 1, size, fp);
    fclose(fp);

    // Free the memory
    free(encrypted);
}

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc!= 3) {
        printf("Usage: %s filename key\n", argv[0]);
        exit(1);
    }

    // Encrypt the file
    encrypt(argv[1], argv[2]);

    return 0;
}