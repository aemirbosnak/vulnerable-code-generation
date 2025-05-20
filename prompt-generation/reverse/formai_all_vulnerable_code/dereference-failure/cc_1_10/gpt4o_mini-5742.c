//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(FILE *inputFile, FILE *outputFile, char *key) {
    int keyLength = strlen(key);
    int i = 0;
    int ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch ^ key[i % keyLength], outputFile);
        i++;
    }
}

void displayMenu() {
    printf("========================================\n");
    printf("            File Encryptor              \n");
    printf("========================================\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("========================================\n");
}

int main() {
    char filename[100];
    char key[50];
    FILE *inputFile, *outputFile;
    int option;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter input filename to encrypt: ");
                scanf("%s", filename);
                printf("Enter output filename for encrypted data: ");
                char encryptedFilename[100];
                scanf("%s", encryptedFilename);
                printf("Enter encryption key: ");
                scanf("%s", key);

                inputFile = fopen(filename, "rb");
                outputFile = fopen(encryptedFilename, "wb");

                if (inputFile == NULL || outputFile == NULL) {
                    printf("Error opening files!\n");
                    return 1;
                }

                encryptDecrypt(inputFile, outputFile, key);

                printf("File encrypted successfully!\n");

                fclose(inputFile);
                fclose(outputFile);
                break;

            case 2:
                printf("Enter input filename to decrypt: ");
                scanf("%s", filename);
                printf("Enter output filename for decrypted data: ");
                char decryptedFilename[100];
                scanf("%s", decryptedFilename);
                printf("Enter decryption key: ");
                scanf("%s", key);

                inputFile = fopen(filename, "rb");
                outputFile = fopen(decryptedFilename, "wb");

                if (inputFile == NULL || outputFile == NULL) {
                    printf("Error opening files!\n");
                    return 1;
                }

                encryptDecrypt(inputFile, outputFile, key);

                printf("File decrypted successfully!\n");

                fclose(inputFile);
                fclose(outputFile);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    }

    return 0;
}