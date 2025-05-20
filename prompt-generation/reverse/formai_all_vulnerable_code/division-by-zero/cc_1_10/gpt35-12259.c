//FormAI DATASET v1.0 Category: File Encyptor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt file
void encrypt(char* filename, char* key) {
    // Open the file in read mode
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open file %s", filename);
        exit(1);
    }

    // Create a new file with ".enc" extension
    char encrypted_file[100];
    sprintf(encrypted_file, "%s.enc", filename);
    FILE *enc_file = fopen(encrypted_file, "wb+");
    if (enc_file == NULL) {
        printf("Error: Failed to create encrypted file");
        fclose(fp);
        exit(1);
    }
    
    // Set encryption key
    int key_length = strlen(key);

    // Read the contents of the file and encrypt each byte
    int c;
    int i = 0;
    while ((c = getc(fp)) != EOF) {
        int encrypted = c ^ key[i % key_length];
        putc(encrypted, enc_file);
        i++;
    }

    // Close files
    fclose(fp);
    fclose(enc_file);

    printf("Encryption complete. Encrypted file is %s\n", encrypted_file);
}

// Function to decrypt file
void decrypt(char* filename, char* key) {
    // Open the encrypted file in read mode
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open encrypted file %s", filename);
        exit(1);
    }

    // Create a new file by removing ".enc" from filename
    int filename_length = strlen(filename);
    char decrypted_file[100];
    strncpy(decrypted_file, filename, filename_length - 4);
    decrypted_file[filename_length - 4] = '\0';
    FILE *dec_file = fopen(decrypted_file, "wb+");
    if (dec_file == NULL) {
        printf("Error: Failed to create decrypted file");
        fclose(fp);
        exit(1);
    }

    // Set decryption key
    int key_length = strlen(key);

    // Read the contents of the encrypted file and decrypt each byte
    int c;
    int i = 0;
    while ((c = getc(fp)) != EOF) {
        int decrypted = c ^ key[i % key_length];
        putc(decrypted, dec_file);
        i++;
    }

    // Close files
    fclose(fp);
    fclose(dec_file);

    printf("Decryption complete. Decrypted file is %s\n", decrypted_file);
}

int main() {
    char filename[100], key[100];
    int choice;

    // Get filename and key from user
    printf("Enter the filename to encrypt/decrypt: ");
    scanf("%s", filename);
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    // Print menu
    printf("\nMenu:\n");
    printf("1. Encrypt file\n");
    printf("2. Decrypt file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform operation based on user choice
    switch(choice) {
        case 1:
            encrypt(filename, key);
            break;
        case 2:
            decrypt(filename, key);
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}