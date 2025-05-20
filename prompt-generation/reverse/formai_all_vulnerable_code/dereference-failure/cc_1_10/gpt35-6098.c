//FormAI DATASET v1.0 Category: File Encyptor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_KEY_SIZE 16

void encryptFile(char *filename, char *key) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Create output filename: append ".enc" to original filename
    char outfilename[MAX_FILENAME_SIZE];
    strcpy(outfilename, filename);
    strcat(outfilename, ".enc");

    // Open output file
    FILE *outfp = fopen(outfilename, "wb");
    if (outfp == NULL) {
        printf("Error creating encrypted file.");
        exit(1);
    }

    // Write the size of the file to the encrypted file
    fwrite(&filesize, sizeof(long), 1, outfp);

    // Encrypt the file content byte by byte
    int c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF) {
        int encrypted_byte = c ^ key[i];
        fputc(encrypted_byte, outfp);
        i = (i + 1) % MAX_KEY_SIZE;
    }

    fclose(fp);
    fclose(outfp);
}

void decryptFile(char *filename, char *key) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // Get size of file
    long filesize;
    fread(&filesize, sizeof(long), 1, fp);

    // Create output filename: remove ".enc" from original filename
    char outfilename[MAX_FILENAME_SIZE];
    strncpy(outfilename, filename, strlen(filename) - 4);
    outfilename[strlen(filename) - 4] = '\0';

    // Open output file
    FILE *outfp = fopen(outfilename, "wb");
    if (outfp == NULL) {
        printf("Error creating decrypted file.");
        exit(1);
    }

    // Decrypt file content byte by byte
    int c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF) {
        int decrypted_byte = c ^ key[i];
        fputc(decrypted_byte, outfp);
        i = (i + 1) % MAX_KEY_SIZE;
    }

    fclose(fp);
    fclose(outfp);
}

int main() {
    printf("This is a file encryptor program.\n");
    printf("Enter the path to the file you want to encrypt: ");
    char filename[MAX_FILENAME_SIZE];
    fgets(filename, MAX_FILENAME_SIZE, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove the newline character

    printf("Enter the encryption key: ");
    char key[MAX_KEY_SIZE];
    fgets(key, MAX_KEY_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove the newline character

    encryptFile(filename, key);
    printf("Encryption successful. Encrypted file created at %s.enc\n", filename);

    printf("\nEnter the path to the file you want to decrypt: ");
    fgets(filename, MAX_FILENAME_SIZE, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove the newline character

    printf("Enter the decryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove the newline character

    decryptFile(filename, key);
    printf("Decryption successful. Decrypted file created at %s\n", filename);

    return 0;
}