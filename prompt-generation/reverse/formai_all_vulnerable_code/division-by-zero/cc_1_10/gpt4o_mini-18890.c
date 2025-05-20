//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(FILE *file, char *key, int keyLength) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file)) != EOF) {
        fseek(file, -1, SEEK_CUR); // Go back to the last read character
        ch = ch ^ key[i % keyLength]; // XOR the character with the key
        fputc(ch, file); // Write the encrypted character
        i++;
    }
    rewind(file); // Reset file pointer to the beginning
}

void processFile(const char *filename, const char *key) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    encryptDecrypt(file, (char *)key, strlen(key));

    printf("The file '%s' has been encrypted/decrypted successfully.\n", filename);
    fclose(file);
}

void displayMenu() {
    printf("Welcome to the Secure Document Management System\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice;
    char filename[256];
    char key[256];

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter the filename to encrypt: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline

                printf("Enter the encryption key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0; // Remove newline

                processFile(filename, key);
                break;

            case 2:
                printf("Enter the filename to decrypt: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline

                printf("Enter the decryption key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0; // Remove newline

                processFile(filename, key);
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}