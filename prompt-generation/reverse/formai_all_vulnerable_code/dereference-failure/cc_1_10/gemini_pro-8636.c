//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encrypt(char *filename, char *password) {
    // Open the file to be encrypted
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    // Allocate memory for the plaintext
    char *plaintext = malloc(filesize + 1);
    if (plaintext == NULL) {
        printf("Error allocating memory for plaintext\n");
        exit(1);
    }

    // Read the plaintext from the file
    fread(plaintext, 1, filesize, file);
    fclose(file);

    // Generate a salt for the encryption
    char salt[16];
    if (RAND_bytes(salt, 16) != 1) {
        printf("Error generating salt\n");
        exit(1);
    }

    // Derive the encryption key from the password and salt
    unsigned char key[32];
    if (PKCS5_PBKDF2_HMAC_SHA1(password, strlen(password), salt, 16, 1000, key, 32) != 1) {
        printf("Error deriving encryption key\n");
        exit(1);
    }

    // Encrypt the plaintext
    unsigned char ciphertext[filesize];
    if (AES_encrypt(plaintext, filesize, key, ciphertext) != 1) {
        printf("Error encrypting plaintext\n");
        exit(1);
    }

    // Write the ciphertext to the file
    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fwrite(ciphertext, 1, filesize, file);
    fclose(file);

    // Free the memory
    free(plaintext);
}

// Function to decrypt a file
void decrypt(char *filename, char *password) {
    // Open the file to be decrypted
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    // Read the ciphertext from the file
    char *ciphertext = malloc(filesize);
    if (ciphertext == NULL) {
        printf("Error allocating memory for ciphertext\n");
        exit(1);
    }

    fread(ciphertext, 1, filesize, file);
    fclose(file);

    // Generate the salt from the ciphertext
    char salt[16];
    memcpy(salt, ciphertext, 16);

    // Derive the encryption key from the password and salt
    unsigned char key[32];
    if (PKCS5_PBKDF2_HMAC_SHA1(password, strlen(password), salt, 16, 1000, key, 32) != 1) {
        printf("Error deriving encryption key\n");
        exit(1);
    }

    // Decrypt the ciphertext
    unsigned char plaintext[filesize];
    if (AES_decrypt(ciphertext, filesize, key, plaintext) != 1) {
        printf("Error decrypting ciphertext\n");
        exit(1);
    }

    // Write the plaintext to the file
    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fwrite(plaintext, 1, filesize, file);
    fclose(file);

    // Free the memory
    free(ciphertext);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s encrypt|decrypt filename password\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2], argv[3]);
    } else {
        printf("Invalid operation: %s\n", argv[1]);
        return 1;
    }

    return 0;
}