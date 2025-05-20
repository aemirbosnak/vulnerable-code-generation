//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the content using XOR operation
void xorEncryptDecrypt(char *input, char *output, char key) {
    FILE *inFile = fopen(input, "rb");
    FILE *outFile = fopen(output, "wb");
    
    if (inFile == NULL || outFile == NULL) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile); // XOR operation
    }

    fclose(inFile);
    fclose(outFile);
}

// Function to display the menu
void displayMenu() {
    printf("File Encryptor/Decryptor\n");
    printf("-------------------------\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int choice;
    char inputFile[256];
    char outputFile[256];
    char key;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the input file name to encrypt: ");
                scanf("%s", inputFile);
                printf("Enter the output file name to store encrypted data: ");
                scanf("%s", outputFile);
                printf("Enter a single character key for encryption: ");
                scanf(" %c", &key); // Space before %c to consume previous newline
                xorEncryptDecrypt(inputFile, outputFile, key);
                printf("File encrypted successfully!\n");
                break;

            case 2:
                printf("Enter the input file name to decrypt: ");
                scanf("%s", inputFile);
                printf("Enter the output file name to store decrypted data: ");
                scanf("%s", outputFile);
                printf("Enter the same single character key used for encryption: ");
                scanf(" %c", &key);
                xorEncryptDecrypt(inputFile, outputFile, key);
                printf("File decrypted successfully!\n");
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");

    } while (choice != 3);

    return 0;
}