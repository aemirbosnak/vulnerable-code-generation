//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define KEY_SIZE 16

// Function to encrypt a file using a key
void encryptFile(char *filename, char *key) {
    FILE *fp;
    FILE *fp2;
    char buffer[MAX_FILE_SIZE];
    int i, j;

    // Open the file to be encrypted
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Open the file to write the encrypted data to
    fp2 = fopen("encrypted.txt", "wb");
    if (fp2 == NULL) {
        printf("Error opening file encrypted.txt\n");
        exit(1);
    }

    // Read the file into a buffer
    fread(buffer, MAX_FILE_SIZE, 1, fp);

    // Encrypt the buffer using the key
    for (i = 0; i < strlen(buffer); i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            buffer[i] ^= key[j];
        }
    }

    // Write the encrypted buffer to the file
    fwrite(buffer, strlen(buffer), 1, fp2);

    // Close the files
    fclose(fp);
    fclose(fp2);
}

// Function to decrypt a file using a key
void decryptFile(char *filename, char *key) {
    FILE *fp;
    FILE *fp2;
    char buffer[MAX_FILE_SIZE];
    int i, j;

    // Open the file to be decrypted
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Open the file to write the decrypted data to
    fp2 = fopen("decrypted.txt", "wb");
    if (fp2 == NULL) {
        printf("Error opening file decrypted.txt\n");
        exit(1);
    }

    // Read the file into a buffer
    fread(buffer, MAX_FILE_SIZE, 1, fp);

    // Decrypt the buffer using the key
    for (i = 0; i < strlen(buffer); i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            buffer[i] ^= key[j];
        }
    }

    // Write the decrypted buffer to the file
    fwrite(buffer, strlen(buffer), 1, fp2);

    // Close the files
    fclose(fp);
    fclose(fp2);
}

int main() {
    char filename[] = "test.txt";
    char key[] = "1234567890123456";

    encryptFile(filename, key);
    decryptFile("encrypted.txt", key);

    return 0;
}