//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 1000

// Function to encrypt the file
void encryptFile(char *fileName, char *key) {
    FILE *file;
    FILE *encryptedFile;
    char ch;
    int keyIndex = 0;

    encryptedFile = fopen("encrypted_file.txt", "wb");

    if (encryptedFile == NULL) {
        printf("Cannot create encrypted file\n");
        exit(1);
    }

    file = fopen(fileName, "rb");

    if (file == NULL) {
        printf("Cannot open file\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = (ch + key[keyIndex % strlen(key)]) % 26 + 'A';
        } else if (isdigit(ch)) {
            ch = (ch + key[keyIndex % strlen(key)]) % 10 + '0';
        } else {
            ch = ch;
        }
        fputc(ch, encryptedFile);
        keyIndex++;
    }

    fclose(file);
    fclose(encryptedFile);
}

// Function to decrypt the file
void decryptFile(char *fileName, char *key) {
    FILE *file;
    FILE *decryptedFile;
    char ch;
    int keyIndex = 0;

    decryptedFile = fopen("decrypted_file.txt", "wb");

    if (decryptedFile == NULL) {
        printf("Cannot create decrypted file\n");
        exit(1);
    }

    file = fopen(fileName, "rb");

    if (file == NULL) {
        printf("Cannot open file\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = (ch - key[keyIndex % strlen(key)]) % 26 + 'A';
        } else if (isdigit(ch)) {
            ch = (ch - key[keyIndex % strlen(key)]) % 10 + '0';
        } else {
            ch = ch;
        }
        fputc(ch, decryptedFile);
        keyIndex++;
    }

    fclose(file);
    fclose(decryptedFile);
}

// Function to generate a random key
void generateRandomKey(char *key) {
    int i;

    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'A';
    }
}

int main() {
    char fileName[MAX_FILE_NAME_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the file name and key from the user
    printf("Enter the file name: ");
    scanf("%s", fileName);
    printf("Enter the key: ");
    scanf("%s", key);

    // Generate a random key if the user didn't provide one
    if (strlen(key) == 0) {
        generateRandomKey(key);
        printf("Generated key: %s\n", key);
    }

    // Encrypt the file
    encryptFile(fileName, key);
    printf("File encrypted successfully!\n");

    // Decrypt the file
    decryptFile("encrypted_file.txt", key);
    printf("File decrypted successfully!\n");

    return 0;
}