//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the file
void encryptFile(FILE *fp, FILE *ofp, int key) {
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch ^ key, ofp);
    }
}

// Function to decrypt the file
void decryptFile(FILE *fp, FILE *ofp, int key) {
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch ^ key, ofp);
    }
}

// Main function
int main() {
    // Open the file to be encrypted
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Open the output file
    FILE *ofp = fopen("output.txt", "w");
    if (ofp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Get the encryption key from the user
    int key;
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the file
    encryptFile(fp, ofp, key);

    // Close the files
    fclose(fp);
    fclose(ofp);

    // Open the encrypted file
    FILE *efp = fopen("output.txt", "r");
    if (efp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Open the decrypted output file
    FILE *dofp = fopen("decrypted.txt", "w");
    if (dofp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Decrypt the file
    decryptFile(efp, dofp, key);

    // Close the files
    fclose(efp);
    fclose(dofp);

    return 0;
}