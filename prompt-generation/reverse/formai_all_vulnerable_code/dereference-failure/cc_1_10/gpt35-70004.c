//FormAI DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *fileName, char *key) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Unable to open file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    char encryptedFileName[strlen(fileName) + 4];

    strcpy(encryptedFileName, fileName);
    strcat(encryptedFileName, ".enc");

    FILE *encryptedFile = fopen(encryptedFileName, "w");

    while ((read = getline(&line, &len, file)) != -1) {
        int lineLength = strlen(line);
        for (int i = 0; i < lineLength; i++) {
            line[i] ^= key[i % strlen(key)];
        }

        fputs(line, encryptedFile);
    }

    fclose(file);
    fclose(encryptedFile);
}

void decrypt(char *fileName, char *key) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Unable to open file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    char decryptedFileName[strlen(fileName) - 4];

    int fileNameLength = strlen(fileName);

    for (int i = 0; i < fileNameLength - 4; i++) {
        decryptedFileName[i] = fileName[i];
    }

    decryptedFileName[strlen(fileName) - 4] = '\0';

    FILE *decryptedFile = fopen(decryptedFileName, "w");

    while ((read = getline(&line, &len, file)) != -1) {
        int lineLength = strlen(line);
        for (int i = 0; i < lineLength; i++) {
            line[i] ^= key[i % strlen(key)];
        }

        fputs(line, decryptedFile);
    }

    fclose(file);
    fclose(decryptedFile);
}

int main() {
    char fileName[50];
    char key[50];
    int choice;

    printf("Welcome to File Encryptor\n");
    printf("==========================\n\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the file name: ");
                scanf("%s", fileName);

                printf("\nEnter the key: ");
                scanf("%s", key);

                encrypt(fileName, key);

                printf("\nFile encrypted successfully.\n\n");
                break;

            case 2:
                printf("\nEnter the file name: ");
                scanf("%s", fileName);

                printf("\nEnter the key: ");
                scanf("%s", key);

                decrypt(fileName, key);

                printf("\nFile decrypted successfully.\n\n");
                break;

            case 3:
                printf("\nThank you for using File Encryptor.\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please enter a valid choice.\n\n");
                break;
        }
    }

    return 0;
}