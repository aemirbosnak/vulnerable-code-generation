//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encryptDecrypt(char *input, char *output, char key) {
    FILE *inputFile = fopen(input, "rb");
    FILE *outputFile = fopen(output, "wb");

    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    int read;
    char buffer[BUFFER_SIZE];

    while ((read = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        for (int i = 0; i < read; i++) {
            buffer[i] ^= key;  // XOR encryption/decryption
        }
        fwrite(buffer, 1, read, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void displayMenu() {
    printf("File Encryptor/Decryptor\n");
    printf("=========================\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("=========================\n");
}

int main() {
    int choice;
    char inputFile[100], outputFile[100];
    char key;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting program...\n");
            break;
        }

        printf("Enter the input file name: ");
        scanf("%s", inputFile);
        
        printf("Enter the output file name: ");
        scanf("%s", outputFile);

        printf("Enter a single character key for encryption: ");
        scanf(" %c", &key);  // note the space before %c to ignore any whitespace

        switch (choice) {
            case 1:
                encryptDecrypt(inputFile, outputFile, key);
                printf("File encrypted successfully!\n");
                break;
            case 2:
                encryptDecrypt(inputFile, outputFile, key);
                printf("File decrypted successfully!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}