//FormAI DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption algorithm
void encryptFile(FILE *plaintextFile, FILE *cipherFile, char key) {
    char ch;
    while ((ch = fgetc(plaintextFile)) != EOF) {
        ch = ch + key;
        fputc(ch, cipherFile);
    }
    printf("File encryption completed successfully!\n");
}

int main() {
    // Get the file name from the user
    char fileName[100];
    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s", fileName);

    // Open the file for reading
    FILE *plaintextFile = fopen(fileName, "r");
    if (plaintextFile == NULL) {
        printf("Error: File \"%s\" not found.\n", fileName);
        exit(1);
    }

    // Create the output file
    char cipherFileName[100];
    sprintf(cipherFileName, "%s.enc", fileName);
    FILE *cipherFile = fopen(cipherFileName, "w");
    if (cipherFile == NULL) {
        printf("Error creating encrypted file.\n");
        exit(1);
    }

    // Get the encryption key from the user
    char encryptionKey[50];
    printf("Enter the encryption key (maximum 50 characters): ");
    scanf("%s", encryptionKey);

    // Encrypt the file
    int keyLength = strlen(encryptionKey);
    int i;
    for (i = 0; i < keyLength; i++) {
        encryptFile(plaintextFile, cipherFile, encryptionKey[i]);
    }

    // Close the file handles
    fclose(plaintextFile);
    fclose(cipherFile);

    return 0;
}