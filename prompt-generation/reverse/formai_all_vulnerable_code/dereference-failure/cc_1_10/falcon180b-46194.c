//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt the file
void encryptFile(FILE *file) {
    char ch;
    int key = 10; // Encryption key

    while ((ch = fgetc(file))!= EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 26;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 26;
            }
        }
        fputc(ch, file);
    }
}

// Function to decrypt the file
void decryptFile(FILE *file) {
    char ch;
    int key = 10; // Decryption key

    while ((ch = fgetc(file))!= EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if (ch < 'a') {
                ch = ch + 26;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if (ch < 'A') {
                ch = ch + 26;
            }
        }
        fputc(ch, file);
    }
}

int main() {
    FILE *inFile, *outFile;
    char filename[100];
    int choice;

    printf("Enter the name of the file to encrypt/decrypt: ");
    scanf("%s", filename);

    // Open the input file
    inFile = fopen(filename, "r");
    if (inFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the output file
    printf("Enter the name of the output file: ");
    scanf("%s", filename);
    outFile = fopen(filename, "w");
    if (outFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Ask user for encryption or decryption
    printf("Enter your choice (1 for encryption, 2 for decryption): ");
    scanf("%d", &choice);

    // Encrypt or decrypt the file
    if (choice == 1) {
        encryptFile(inFile);
    } else if (choice == 2) {
        decryptFile(inFile);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    // Close the files
    fclose(inFile);
    fclose(outFile);

    printf("File encrypted/decrypted successfully!\n");
    return 0;
}