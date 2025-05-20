//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the text using Caesar cipher
void encrypt(char* text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (isupper(ch)) {
            text[i] = (ch + key - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            text[i] = (ch + key - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
    }
}

// Function to decrypt the text using Caesar cipher
void decrypt(char* text, int key) {
    encrypt(text, 26 - key); // Reversing the key for decryption
}

// Function to display the menu choices
void displayMenu() {
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

// Function to process file I/O
void processFile(char* filename, int key, int mode) {
    FILE* file;
    if (mode == 1) {
        file = fopen(filename, "r");
        if (file == NULL) {
            fprintf(stderr, "Could not open file %s for reading.\n", filename);
            return;
        }

        char *text = (char *)malloc(1024 * sizeof(char));
        fread(text, sizeof(char), 1024, file);
        fclose(file);

        encrypt(text, key);

        file = fopen(filename, "w");
        if (file == NULL) {
            fprintf(stderr, "Could not open file %s for writing.\n", filename);
            free(text);
            return;
        }
        fwrite(text, sizeof(char), strlen(text), file);
        fclose(file);
        printf("File %s encrypted successfully.\n", filename);
        free(text);
    } else {
        file = fopen(filename, "r");
        if (file == NULL) {
            fprintf(stderr, "Could not open file %s for reading.\n", filename);
            return;
        }

        char *text = (char *)malloc(1024 * sizeof(char));
        fread(text, sizeof(char), 1024, file);
        fclose(file);

        decrypt(text, key);

        file = fopen(filename, "w");
        if (file == NULL) {
            fprintf(stderr, "Could not open file %s for writing.\n", filename);
            free(text);
            return;
        }
        fwrite(text, sizeof(char), strlen(text), file);
        fclose(file);
        printf("File %s decrypted successfully.\n", filename);
        free(text);
    }
}

// The main function, where our journey begins
int main() {
    int choice;
    char filename[100];
    int key;

    printf("Welcome to the great encryptor of Sherlock Holmes.\n");
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the great encryptor. Until next time!\n");
            break;
        }

        if (choice < 1 || choice > 3) {
            fprintf(stderr, "Invalid choice. Please choose a valid option.\n");
            continue;
        }

        printf("Enter the filename to process: ");
        scanf("%s", filename);

        printf("Enter the encryption key (between 1 and 25): ");
        scanf("%d", &key);
        if (key < 1 || key > 25) {
            fprintf(stderr, "Invalid key. Please enter a key between 1 and 25.\n");
            continue;
        }

        processFile(filename, key, choice);
    }

    return 0;
}